#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_args(int argc, char **argv, char *flags, char **search_patterns,
                size_t *search_patterns_count);

#endif