#ifndef COMPILER_PROCESS_H
#define COMPILER_PROCESS_H
#include "./types.h"

extern CompilerProcess* compiler_process_create(const char* in_filename, const char* out_filename, int flags);

#endif
