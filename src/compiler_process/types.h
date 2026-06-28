#ifndef COMPILER_PROCESS_TYPES_H
#define COMPILER_PROCESS_TYPES_H
#include <stdio.h>

typedef struct {
  FILE* file;
  const char* abs_path;
} CompilerFile;

typedef struct {
  int flags;
  CompilerFile in_file;
  FILE* out_file;
} CompilerProcess;

#endif
