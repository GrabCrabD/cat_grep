#include "myGrep.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int delimetr = 0;
  delimetr = delifunc(argc, argv);
  switchfunc(delimetr, argc, argv);
  return 0;
}

int delifunc(int argc, char **argv) {
  int delimetr = 0;
  for (int i = argc - 1; i > 0; i--) {
    if (argv[i][0] == '-') {
      delimetr = i;
      break;
    }
  }
  return delimetr;
}

void switchfunc(int delimetr, int argc, char **argv) {
  int rez = 0;
  int no_flags = 1;
  while ((rez = getopt(argc, argv, "eivclnhsfo")) != -1) {
    if (rez == 'e') {
      efunc(delimetr, argc, argv);
    } else if (rez == 'i') {
      ifunc(delimetr, argc, argv);
    } else if (rez == 'v') {
      vfunc(delimetr, argc, argv);
    } else if (rez == 'c') {
      cfunc(delimetr, argc, argv);
    } else if (rez == 'l') {
      lfunc(delimetr, argc, argv);
    } else if (rez == 'n') {
      nfunc(delimetr, argc, argv);
    } else if (rez == 'h') {
      hfunc(delimetr, argc, argv);
    } else if (rez == 's') {
      sfunc(delimetr, argc, argv);
    } else if (rez == 'f') {
      ffunc(delimetr, argc, argv);
    } else if (rez == 'o') {
      ofunc(delimetr, argc, argv);
    } else {
      printf("flag unkwoned\n");
    }
    no_flags = 0;
  }
  if (no_flags) efunc(delimetr, argc, argv);
}

void efunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
          status = regexfunc(str, argv[delimetr + 1]);
          if (status == 0) {
            if (argc - 1 > delimetr + 2) {
              printf("%s:%s\n", argv[i], str);
            } else {
              printf("%s\n", str);
            }
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void vfunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int status = 0;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
          status = regexfunc(str, argv[delimetr + 1]);
          if (status != 0) {
            if (argc - 1 > delimetr + 2) {
              printf("%s:%s\n", argv[i], str);
            } else {
              printf("%s\n", str);
            }
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void cfunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int count = 0;
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          status = regexfunc(str, argv[delimetr + 1]);
          if (status == 0) {
            count++;
          }
        }
      }
      if (argc - 1 > delimetr + 2) {
        printf("%s:%d\n", argv[i], count);
        count = 0;
      } else {
        printf("%d\n", count);
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void ifunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
          regex_t re;
          regcomp(&re, argv[delimetr + 1], REG_ICASE);
          status = regexec(&re, str, 0, NULL, 0);
          regfree(&re);
          if (status == 0) {
            if (argc - 1 > delimetr + 2) {
              printf("%s:%s\n", argv[i], str);
            } else {
              printf("%s\n", str);
            }
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void nfunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int count = 0;
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
          count++;
          status = regexfunc(str, argv[delimetr + 1]);
          if (status == 0) {
            if (argc - 1 > delimetr + 2) {
              printf("%s:%d:%s\n", argv[i], count, str);
            } else {
              printf("%d:", count);
              printf("%s\n", str);
            }
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
    count = 0;
  }
}

void lfunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          status = regexfunc(str, argv[delimetr + 1]);
          if (status == 0) {
            printf("%s\n", argv[i]);
            break;
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void hfunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
          status = regexfunc(str, argv[delimetr + 1]);
          if (status == 0) {
            printf("%s\n", str);
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void ofunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          for (int k = 0; k < supforofunc(str, argv[delimetr + 1]); k++) {
            if (argc - 1 > delimetr + 2) {
              printf("%s:%s\n", argv[i], argv[delimetr + 1]);
            } else {
              printf("%s\n", argv[delimetr + 1]);
            }
          }
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void ffunc(int delimetr, int argc, char **argv) {
  FILE *f;
  FILE *fp;
  char str[buff_size], str2[buff_size];
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {  // файл в котором ищу
        if (fgets(str, sizeof(str), f)) {
          fp = fopen(argv[delimetr + 1], "r");
          if (fp != NULL) {
            while (!feof(fp)) {  // файл с паттерном
              if (fgets(str2, sizeof(str2), fp)) {
                if (str2[strlen(str2) - 1] == '\n') {
                  str2[strlen(str2) - 1] = 0;
                }
                status = regexfunc(str, str2);
                if (status == 0) {
                  if (argc - 1 > delimetr + 2) {
                    printf("%s:%s", argv[i], str);
                  } else {
                    printf("%s", str);
                  }
                  break;
                }
              }
            }
            fclose(fp);
          } else {
            fprintf(stderr, "grep: %s: No such file or directory\n",
                    argv[delimetr + 1]);
            break;
          }
        }
      }
      printf("\n");
      fclose(f);
    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
    }
  }
}

void sfunc(int delimetr, int argc, char **argv) {
  FILE *f;
  char str[buff_size];
  int status = 1;
  for (int i = delimetr + 2; i < argc; i++) {
    f = fopen(argv[i], "r");
    if (f != NULL) {
      while (!feof(f)) {
        if (fgets(str, sizeof(str), f)) {
          if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
          status = regexfunc(str, argv[delimetr + 1]);
          if (status == 0) {
            if (argc - 1 > delimetr + 2) {
              printf("%s:%s\n", argv[i], str);
            } else {
              printf("%s\n", str);
            }
          }
        }
      }
      fclose(f);
    }
  }
}

int supforofunc(char *str, char *pattern) {
  int count = 0;
  size_t len = strlen(pattern);
  char *tmp = str;
  while ((tmp = strstr(tmp, pattern))) {
    count++;
    tmp += len;
  }
  return count;
}

int regexfunc(char *str, char *pattern) {
  regex_t re;
  regcomp(&re, pattern, 0);
  int answer = regexec(&re, str, 0, NULL, 0);
  regfree(&re);
  return answer;
}