CC=gcc
CFLAGS=-Wall -Wextra -Werror

s21_grep:
	$(CC) $(CFLAGS) myGrep.c -o s21_grep

testing:
	sh ./tests/grep_test.sh

clean:
	rm s21_grep

rebuild:
	make clean
	make