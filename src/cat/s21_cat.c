#include "s21_cat.h"

#include <stdio.h>
#include <string.h>

void print_symbol(int current_char, int *empty_printed, int *line_number,
                  int *at_line_start, char *flags) {
  int flag_b = strchr(flags, 'b') != NULL;
  int flag_n = strchr(flags, 'n') != NULL;
  int flag_s = strchr(flags, 's') != NULL;
  int flag_e = strchr(flags, 'e') != NULL;
  int flag_E = strchr(flags, 'E') != NULL;
  int flag_t = strchr(flags, 't') != NULL;
  int flag_T = strchr(flags, 'T') != NULL;
  int flag_v = strchr(flags, 'v') != NULL;

  if (flag_e || flag_t) flag_v = 1;

  if (current_char == '\n') {
    if (flag_s && *empty_printed > 1) {
      return;
    }
    *empty_printed += 1;
  } else {
    *empty_printed = 0;
  }

  if (*at_line_start) {
    if (flag_b && current_char != '\n') {
      printf("%6d\t", *line_number);
      (*line_number)++;
    } else if (flag_n && !flag_b) {
      printf("%6d\t", *line_number);
      (*line_number)++;
    }
  }

  if (current_char == '\t' && (flag_t || flag_T)) {
    printf("^I");
    *at_line_start = 0;
    return;
  }

  if (current_char == '\n') {
    if (flag_e || flag_E) putchar('$');
    putchar('\n');
    *at_line_start = 1;
    return;
  }

  if (flag_v) {
    if (current_char == 0) {
      printf("^@\n");
      *at_line_start = 1;
      return;
    }
    if (current_char == 127) {
      current_char = '?';
      printf("^%c", current_char);
      *at_line_start = 0;
      return;
    }
    if (current_char != '\n' && current_char != 10 && current_char < 32) {
      current_char = current_char + 64;
      printf("^%c", current_char);
      *at_line_start = 0;
      return;
    }
    if (current_char > 127 && current_char < 160) {
      current_char = current_char - 64;
      printf("M-^%c", current_char);
      *at_line_start = 0;
      return;
    }
    if (current_char > 159 && current_char < 255) {
      current_char = current_char - 128;
      printf("M-%c", current_char);
      *at_line_start = 0;
      return;
    }
  }

  *at_line_start = 0;
  printf("%c", current_char);
}

void print_file(const char *filename, char *flags, int *line_number) {
  FILE *f;
  if (filename == NULL || strcmp(filename, "-") == 0) {
    f = stdin;
  } else {
    f = fopen(filename, "r");
    if (!f) {
      perror(filename);
      return;
    }
  }

  int at_line_start = 1;
  int current_char = 0;
  int empty_printed = 0;

  while ((current_char = fgetc(f)) != EOF) {
    print_symbol(current_char, &empty_printed, line_number, &at_line_start,
                 flags);
  }

  if (f != stdin) fclose(f);
}