#!/bin/bash

ECHO "test 1 no flag:"
./s21_cat ./tests/a.txt ./tests/b.txt > s21_cat.txt
cat ./tests/a.txt ./tests/b.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
ECHO "---------------------------------------------"
ECHO "test 2 -b:"
./s21_cat -e ./tests/d.txt > s21_cat.txt
cat -e ./tests/d.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
ECHO "---------------------------------------------"
ECHO "test 3 -e:"
./s21_cat -e ./tests/a.txt > s21_cat.txt
cat -e ./tests/a.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
ECHO "---------------------------------------------"
ECHO "test 4 -n:"
./s21_cat -n ./tests/b.txt > s21_cat.txt
cat -n ./tests/b.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
ECHO "---------------------------------------------"
ECHO "test 5 -s:"
./s21_cat -s ./tests/c.txt > s21_cat.txt
cat -s ./tests/c.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
ECHO "---------------------------------------------"
ECHO "test 6 -t:"
./s21_cat -t ./tests/a.txt ./tests/b.txt > s21_cat.txt
cat -t ./tests/a.txt ./tests/b.txt > cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
ECHO "---------------------------------------------"