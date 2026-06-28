#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>

// Atleast 20 vector element spaces in reserve before reallocating memory.
#define VECTOR_ELEMENT_INCREMENT 20

enum
{
    VECTOR_FLAG_PEEK_DECREMENT = 0b00000001
};

typedef struct Vector {
  // Pointer to the allocated memory holding the elements.
  // It can store any data type.
  void* data;
  // Every call reads data[peek_index], and then increments peek_index.
  // Think of this as an iterator.
  int peek_index;
  // Used for sequential reading.
  // Unlike peek_index, it may not automatically advance depending on the implementation.
  int read_index;
  // Usually the last valid allocated index or current capacity boundary.
  int max_index;
  // Number of elements currently stored in the vector.
  int count;
  // Stores option bits controlling vector behavior.
  int flags;
  // Element size in bytes.
  // E.g. sizeof(Token).
  size_t element_size;
  // Stack of saved vector states.
  struct Vector* saves;
} Vector;

extern Vector* vector_create(size_t element_size);
extern void vector_push(Vector* vector, void* element);
extern void vector_set_peek_pointer(Vector *vector, int index);
extern void* vector_peek(Vector* vector);

#endif
