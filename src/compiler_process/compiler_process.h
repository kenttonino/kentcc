#ifndef COMPILER_PROCESS_H
#define COMPILER_PROCESS_H
#include "./compiler_process.c"
#include "./types.h"

extern CompilerProcess* compile_process_create(const char* in_filename, const char* out_filename, int flags);

#endif
