#ifndef COMPILER_H
#define COMPILER_H
#include "./compiler.c"

extern int compile_file(const char* in_filename, const char* out_filename, int flags);

#endif
