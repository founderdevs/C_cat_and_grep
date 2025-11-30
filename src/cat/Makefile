CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra
SHELL := /bin/bash
FILE1 = ../first_file.txt

all: s21_cat

s21_cat: s21_cat.c main.c
	$(CC) $(FLAGS) s21_cat.c main.c -o s21_cat

testing:
	diff -s -y --suppress-common-lines <(./s21_cat $(FILE1)) <(cat  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat --squeeze-blank  $(FILE1)) <(cat --squeeze-blank  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -s  $(FILE1)) <(cat -s  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat --number-nonblank  $(FILE1)) <(cat --number-nonblank  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -e  $(FILE1)) <(cat -e  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -t  $(FILE1)) <(cat -t  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -v  $(FILE1)) <(cat -v  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat --number  $(FILE1)) <(cat --number  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -E  $(FILE1)) <(cat -E  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -T  $(FILE1)) <(cat -T  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -b -n $(FILE1)) <(cat -b -n $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -v -n  $(FILE1)) <(cat -v -n  $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_cat -v -n -b -s -t -e -n -E -T  $(FILE1)) <(cat -v -n -b -s -t -e -n -E -T  $(FILE1))
clean:
	rm -rf  s21_cat
