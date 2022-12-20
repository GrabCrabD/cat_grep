#ifndef GREP_MY_CAT_H_
#define GREP_MY_CAT_H_

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

#endif