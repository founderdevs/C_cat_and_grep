#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "open_file.h"
#include "parse_args.h"

int main(int argc, char **argv) {
  char flags[8] = {0};
  char *search_patterns[100] = {0};
  size_t search_patterns_count = 0;
  size_t file_count = 0;
  int file_index;

  parse_args(argc, argv, flags, search_patterns, &search_patterns_count);

  if (strchr(flags, 'e')) {
    file_index = optind;
  } else {
    file_index = optind + 1;
  }

  file_count = argc - file_index;

  for (int i = file_index; i < argc; ++i) {
    open_file(argv[i], flags, file_count, search_patterns,
              &search_patterns_count);
  }

  return 0;
}
