#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void open_file(const char *filename, char *flags, size_t file_count,
               char **search_patterns, size_t *search_patterns_count);

#endif