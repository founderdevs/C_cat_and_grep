#include "is_matching_line.h"

int is_matching_line(char *line, int flag_i, char **search_patterns,
                     size_t *search_patterns_count) {
  regex_t regex;
  int reg_sense = flag_i ? REG_ICASE : 0;
  int found = 0;

  for (size_t i = 0; i < *search_patterns_count; ++i) {
    int reg = regcomp(&regex, search_patterns[i], reg_sense);

    if (reg != 0) {
      continue;
    }

    if (regexec(&regex, line, 0, NULL, 0) == 0) {
      found++;
    }

    regfree(&regex);
    if (found) break;
  }

  return found;
}