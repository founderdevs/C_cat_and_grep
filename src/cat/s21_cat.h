#ifndef S21_CAT_H
#define S21_CAT_H

void print_symbol(int current_char, int *empty_printed, int *line_number,
                  int *at_line_start, char *flags);
void print_file(const char *filename, char *flags, int *line_number);

#endif
