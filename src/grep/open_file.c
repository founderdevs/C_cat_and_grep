#include "open_file.h"

#include "is_matching_line.h"

void open_file(const char *filename, char *flags, size_t file_count,
               char **search_patterns, size_t *search_patterns_count) {
  FILE *file = fopen(filename, "r");
  char *line = NULL;
  size_t len = 0;
  size_t matching_line_count = 0;
  int matching_file = 0;
  int number_line = 1;

  int flag_e = strchr(flags, 'e') != NULL;
  int flag_i = strchr(flags, 'i') != NULL;
  int flag_v = strchr(flags, 'v') != NULL;
  int flag_c = strchr(flags, 'c') != NULL;
  int flag_l = strchr(flags, 'l') != NULL;
  int flag_n = strchr(flags, 'n') != NULL;
  int flag_h = strchr(flags, 'h') != NULL;
  int flag_s = strchr(flags, 's') != NULL;

  int flags_off = !flag_e && !flag_c && !flag_l && !flag_n;

  if (file == NULL) {
    if (!flag_s)
      fprintf(stderr, "s21_grep: %s: No such file or directory\n", filename);
  } else {
    while (getline(&line, &len, file) != -1) {
      int found = is_matching_line(line, flag_i, search_patterns,
                                   search_patterns_count);
      int linelen = strlen(line);
      int has_newline = (line[linelen - 1] == '\n');
      if (flag_v) found = !found;

      matching_line_count += found;

      if (found) matching_file = 1;

      if (flag_l) {
        flag_n = 0;
        flag_c = 0;
      }

      if (flag_c) flag_n = 0;

      if (file_count > 1 && !flag_h) {
        if (flag_n && found && has_newline)
          printf("%s:%d:%s", filename, number_line, line);
        else if (flag_n && found)
          printf("%s:%d:%s\n", filename, number_line, line);
        if (flag_e && found && has_newline)
          printf("%s:%s", filename, line);
        else if (flag_e && found)
          printf("%s:%s\n", filename, line);
        if (flags_off && found && has_newline)
          printf("%s:%s", filename, line);
        else if (flags_off && found)
          printf("%s:%s\n", filename, line);
      } else {
        if (flag_n && found && has_newline)
          printf("%d:%s", number_line, line);
        else if (flag_n && found)
          printf("%d:%s\n", number_line, line);
        if (flag_e && found && has_newline)
          printf("%s", line);
        else if (flag_e && found)
          printf("%s", line);
        if (flags_off && found && has_newline)
          printf("%s", line);
        else if (flags_off && found)
          printf("%s", line);
      }

      number_line++;
    }

    if (flag_l && matching_file) printf("%s\n", filename);

    if (file_count > 1 && !flag_h) {
      if (flag_c) printf("%s:%zu\n", filename, matching_line_count);
    } else {
      if (flag_c) printf("%zu\n", matching_line_count);
      free(line);
    }

    fclose(file);
  }
}