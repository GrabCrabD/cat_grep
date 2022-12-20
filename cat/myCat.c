#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int b;
  int E;
  int n;
  int s;
  int T;
  int v;
} flags;

void reading(int argc, char **argv);
void bfunc(int argc, char **argv);
void sfunc(int argc, char **argv);
void efunc(int argc, char **argv, flags *FLAG);
void nfunc(int argc, char **argv);
void tfunc(int argc, char **argv, flags *FLAG);
void getflags(int argc, char **argv, flags *);
void inputmanager(int argc, char **argv, flags *);

int main(int argc, char **argv) {
  flags FLAG = {0, 0, 0, 0, 0, 0};
  getflags(argc, argv, &FLAG);
  inputmanager(argc, argv, &FLAG);
  return 0;
}

void getflags(int argc, char **argv, flags *FLAG) {
  int rez = 0;

  const struct option long_options[] = {
      {"number-nonblank", no_argument, &FLAG->b, 1},
      {"number", no_argument, &FLAG->n, 1},
      {"squeeze-blank", no_argument, &FLAG->s, 1},
      {NULL, 0, NULL, 0}};

  while ((rez = getopt_long(argc, argv, "benstvTE", long_options, NULL)) !=
         -1) {
    if (rez == 'b') {
      FLAG->b = 1;
    } else if (rez == 'e') {
      FLAG->E = 1;
      FLAG->v = 1;
    } else if (rez == 'n') {
      FLAG->n = 1;
    } else if (rez == 's') {
      FLAG->s = 1;
    } else if (rez == 't') {
      FLAG->T = 1;
      FLAG->v = 1;
    } else if (rez == 'v') {
      FLAG->v = 1;
    } else if (rez == 'T') {
      FLAG->T = 1;
    } else if (rez == 'E') {
      FLAG->E = 1;
    }
  }
}

void inputmanager(int argc, char **argv, flags *FLAG) {
  if (FLAG->n) {
    nfunc(argc, argv);
  } else if (FLAG->b) {
    bfunc(argc, argv);
  } else if (FLAG->s) {
    sfunc(argc, argv);
  } else if (FLAG->T) {
    tfunc(argc, argv, FLAG);
  } else if (FLAG->E) {
    efunc(argc, argv, FLAG);
  } else {
    reading(argc, argv);
  }
}

void nfunc(int argc, char **argv) {
  int count = 1;
  FILE *f;
  char str[250];
  for (int i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, 200, f)) {
          printf("%6d\t", count);
          printf("%s", str);
          count++;
        }
      }
      fclose(f);
    }
  }
}

void reading(int argc, char **argv) {
  FILE *f;
  char str[250];
  for (int i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, 200, f)) printf("%s", str);
      }
      fclose(f);
    }
  }
}

void tfunc(int argc, char **argv, flags *FLAG) {
  FILE *f;
  char c;
  for (int i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      c = fgetc(f);
      while (!feof(f)) {
        if (c == '\t') {
          printf("^I");
        } else if ((FLAG->v) && ((c < 9) || (c > 10 && c <= 31))) {
          c += 64;
          printf("^%c", c);
        } else if ((FLAG->v) && (c == 127)) {
          printf("^?");
        } else {
          printf("%c", c);
        }
        c = fgetc(f);
      }
      fclose(f);
    }
  }
}

void efunc(int argc, char **argv, flags *FLAG) {
  FILE *f;
  char c;
  for (int i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      c = fgetc(f);
      while (!feof(f)) {
        if (c == '\n') {
          printf("$");
          printf("%c", c);
        } else if ((FLAG->v) && ((c < 9) || (c > 10 && c <= 31))) {
          c += 64;
          printf("^%c", c);
        } else if ((FLAG->v) && (c == 127)) {
          printf("^?");
        } else {
          printf("%c", c);
        }
        c = fgetc(f);
      }
      fclose(f);
    }
  }
}

void bfunc(int argc, char **argv) {
  int count = 1;
  FILE *f;
  char str[250];
  for (int i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, 200, f)) {
          if (str[0] != '\n') {
            printf("%6d\t", count);
            printf("%s", str);
            count++;
          } else {
            printf("%s", str);
          }
        }
      }
      fclose(f);
    }
  }
}

void sfunc(int argc, char **argv) {
  FILE *f;
  char c, next;
  int count = 0;
  for (int i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      c = fgetc(f);
      while (!feof(f)) {
        if (c == '\n') {
          putchar(c);
          next = fgetc(f);
          while (next == '\n') {
            next = fgetc(f);
            count++;
          }
          if (feof(f)) {
            break;
          }
          if (count) {
            printf("\n");
            count = 0;
          }
          putchar(next);
        } else {
          printf("%c", c);
        }
        c = fgetc(f);
      }
      fclose(f);
    }
  }
}