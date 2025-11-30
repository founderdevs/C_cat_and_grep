CC = gcc
FLAGS = -Wall -Werror -Wextra
SHELL := /bin/bash
FILE1 = main.c
FILE2 = open_file.h
#PATTERN = args.txt
SRCS = main.c open_file.c parse_args.c is_matching_line.c

all: s21_grep

s21_grep: $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o s21_grep

testing:
	diff -s -y --suppress-common-lines <(./s21_grep l $(FILE1)) <(grep l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -e l -e g $(FILE1)) <(grep -e l -e g $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -i l $(FILE1)) <(grep -i l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -v l $(FILE1) $(FILE2)) <(grep -v l $(FILE1) $(FILE2))
	diff -s -y --suppress-common-lines <(./s21_grep -c l $(FILE1)) <(grep -c l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -l l $(FILE1)) <(grep -l l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -n l $(FILE1)) <(grep -n l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -h l $(FILE1) $(FILE2)) <(grep -h l $(FILE1) $(FILE2))
	diff -s -y --suppress-common-lines <(./s21_grep -s l $(FILE1)) <(grep -s l $(FILE1))
#	diff -s -y --suppress-common-lines <(./s21_grep -f $(PATTERN) $(FILE1) $(FILE2)) <(grep -f $(PATTERN) $(FILE1) $(FILE2))
#	diff -s -y --suppress-common-lines <(./s21_grep -o l $(FILE1)) <(grep -o l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -iv l $(FILE1)) <(grep -iv l $(FILE1))
	diff -s -y --suppress-common-lines <(./s21_grep -in l $(FILE1)) <(grep -in l $(FILE1))
#	diff -s -y --suppress-common-lines <(./s21_grep -oc l $(FILE1) $(FILE2)) <(grep -oc l $(FILE1) $(FILE2))
#	diff -s -y --suppress-common-lines <(./s21_grep -ol l $(FILE1)) <(grep -ol l $(FILE1))
clean:
	rm -rf  s21_grep
