#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "s21_cat.h"

int main(int argc, char **argv) {
  char flags[8] = {0};

  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {"number", no_argument, NULL, 'n'},
      {NULL, 0, NULL, 0}};

  int opt_index = 0;
  int opt;
  int line_number = 1;

  while ((opt = getopt_long(argc, argv, "bnsetvET", long_options,
                            &opt_index)) != -1) {
    if (!strchr(flags, opt)) {
      int len = strlen(flags);
      flags[len] = opt;
      flags[len + 1] = '\0';
    }
  }

  if (optind == argc) {
    print_file(NULL, flags, &line_number);
    return 0;
  }

  for (int i = optind; i < argc; ++i) {
    print_file(argv[i], flags, &line_number);
  }

  return 0;
}
