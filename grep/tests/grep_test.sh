#!/bin/bash

ECHO "test 1 no flag:"
./s21_grep 1 ./tests/a.txt ./tests/b.txt > s21_grep.txt
grep 1 ./tests/a.txt ./tests/b.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 2 -e:"
./s21_grep -e qwe ./tests/test1grep.txt > s21_grep.txt
grep -e qwe ./tests/test1grep.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 3 -i:"
./s21_grep -i qWe ./tests/test1grep.txt > s21_grep.txt
grep -i qWe ./tests/test1grep.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 4 -v:"
./s21_grep -v 35 ./tests/b.txt > s21_grep.txt
grep -v 35 ./tests/b.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 4.1 -v:"
./s21_grep -v 1 ./tests/a.txt ./tests/b.txt > s21_grep.txt
grep -v 1 ./tests/a.txt ./tests/b.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 5 -c:"
./s21_grep -c w ./tests/test2grep.txt > s21_grep.txt
grep -c w ./tests/test2grep.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 5.1 -c:"
./s21_grep -c w ./tests/test1grep.txt ./tests/test2grep.txt > s21_grep.txt
grep -c w ./tests/test1grep.txt ./tests/test2grep.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 6 -l:"
./s21_grep -l 1 ./tests/a.txt ./tests/b.txt > s21_grep.txt
grep -l 1 ./tests/a.txt ./tests/b.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 7 -n:"
./s21_grep -n ww ./tests/test1grep.txt ./tests/test2grep.txt  > s21_grep.txt
grep -n ww ./tests/test1grep.txt ./tests/test2grep.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 8 -h:"
./s21_grep -h qwe ./tests/test1grep.txt > s21_grep.txt
grep -h qwe ./tests/test1grep.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 9 -s:"
./s21_grep -s qwe no_file.txt > s21_grep.txt
grep -s qwe no_file.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 10 -f:"
./s21_grep -f ./tests/a.txt ./tests/b.txt > s21_grep.txt
grep -f ./tests/a.txt ./tests/b.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"
ECHO "test 10.1 -f:"
./s21_grep -f ./tests/a.txt ./tests/b.txt ./tests/c.txt > s21_grep.txt
grep -f ./tests/a.txt ./tests/b.txt ./tests/c.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
ECHO "---------------------------------------------"