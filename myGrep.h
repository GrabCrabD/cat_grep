#ifndef GREP_MY_GREP_H_
#define GREP_MY_GREP_H_

#define buff_size 101010

void efunc(int delimetr, int argc, char **argv);
void vfunc(int delimetr, int argc, char **argv);
void ifunc(int delimetr, int argc, char **argv);
void cfunc(int delimetr, int argc, char **argv);
void nfunc(int delimetr, int argc, char **argv);
void lfunc(int delimetr, int argc, char **argv);
void hfunc(int delimetr, int argc, char **argv);
void ofunc(int delimetr, int argc, char **argv);
void ffunc(int delimetr, int argc, char **argv);
void sfunc(int delimetr, int argc, char **argv);
void switchfunc(int delimetr, int argc, char **argv);
int delifunc(int argc, char **argv);
int supforofunc(char *str, char *pattern);
int regexfunc(char *str, char *pattern);

#endif