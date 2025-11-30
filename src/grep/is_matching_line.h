#ifndef MATCHING_LINE_H
#define MATCHING_LINE_H

#include <regex.h>
#include <stdio.h>
#include <string.h>

int is_matching_line(char *line, int flag_i, char **search_patterns,
                     size_t *search_patterns_count);

#endif