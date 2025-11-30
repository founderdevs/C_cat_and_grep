#include "parse_args.h"

void parse_args(int argc, char **argv, char *flags, char **search_patterns,
                size_t *search_patterns_count) {
  int opt;
  size_t len = 0;

  while ((opt = getopt(argc, argv, "e:ivclnhs")) != -1) {
    if (!strchr(flags, opt)) {
      flags[len] = (char)opt;
      len++;
    }

    if (opt == 'e') {
      search_patterns[*search_patterns_count] = strdup(optarg);
      (*search_patterns_count)++;
    }
  }

  if (*search_patterns_count == 0 && optind < argc - 1) {
    search_patterns[*search_patterns_count] = strdup(argv[optind]);
    (*search_patterns_count)++;
  }
}