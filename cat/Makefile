CC=gcc
CFLAGS=-Wall -Wextra -Werror

s21_cat:
	$(CC) $(CFLAGS) myCat.c -o s21_cat

testing:
	sh ./tests/cat_test.sh

clean:
	rm s21_cat

rebuild:
	make clean
	make