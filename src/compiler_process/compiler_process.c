#include <stdlib.h>
#include <stdio.h>
#include "./types.h"

CompilerProcess* compiler_process_create(const char* in_filename, const char* out_filename, int flags) {
  FILE* in_file = fopen(in_filename, "r");
  if (in_file == NULL) {
    return NULL;
  }

  FILE* out_file = NULL;
  if (out_filename) {
    out_file = fopen(out_filename, "w");
    if (out_file == NULL) {
      return NULL;
    }
  }

  CompilerProcess* compiler_process = calloc(1, sizeof(CompilerProcess));
  compiler_process->flags = flags;
  compiler_process->in_file.file = in_file;
  compiler_process->out_file = out_file;

  return compiler_process;
};
