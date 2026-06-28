#include <stdlib.h>
#include <stdio.h>
#include "./vector.h"

Vector* vector_create_no_saves(size_t esize)
{
    Vector *vector = calloc(sizeof(Vector), 1);
    vector->data = malloc(esize * VECTOR_ELEMENT_INCREMENT);
    vector->max_index = VECTOR_ELEMENT_INCREMENT;
    vector->read_index = 0;
    vector->peek_index = 0;
    vector->element_size = esize;
    vector->count = 0;
    return vector;
}

Vector* vector_create(size_t element_size) {
  Vector* vector = vector_create_no_saves(element_size);
  vector->saves = vector_create_no_saves(sizeof(Vector));
  return vector;
}
