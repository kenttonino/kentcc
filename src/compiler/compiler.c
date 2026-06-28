#include "../compiler_process/compiler_process.h"
#include "./types.h"

/*
 *  This will handle the compiling of C source code to executable.
 *
 *  in_filename -> The name of the C program that we are going to compile.
 *  out_filename -> The name of the executable file that we are going to output.
 *  flags -> It sets the rules on how we will compile the program.
 * */
int compile_file(const char* in_filename, const char* out_filename, int flags) {
  CompilerProcess* compiler_process = compiler_process_create(in_filename, out_filename, flags);
  if (compiler_process == NULL) {
    return COMPILER_FAILED_WITH_ERRORS;
  }

  // TODO: Below are the necessary steps that we need to implement.
  // Perform lexical analysis.
  // Perform parsing.
  // Perform code generation.

  return COMPILER_FILE_COMPILED_OK;
}
