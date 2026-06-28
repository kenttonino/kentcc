#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

void* vector_at(Vector* vector, int index) {
  return vector->data + (index * vector->element_size);
}

void vector_resize_for_index(Vector* vector, int start_index, int total_elements) {
  if (start_index + total_elements < vector->max_index) {
    return;
  }

  vector->data = realloc(vector->data, ((start_index + total_elements + VECTOR_ELEMENT_INCREMENT) * vector->element_size));
  assert(vector->data);
  vector->max_index = start_index + total_elements;
}

void vector_resize_for(Vector* vector, int total_elements) {
  vector_resize_for_index(vector, vector->read_index, total_elements);
}

void vector_resize(Vector* vector) {
  vector_resize_for(vector, 0);
};

void vector_push(Vector* vector, void* element) {
  void *ptr = vector_at(vector, vector->read_index);
  memcpy(ptr, element, vector->element_size);

  vector->read_index++;
  vector->count++;

  if (vector->read_index >= vector->max_index) {
    vector_resize(vector);
  }
}

void vector_set_peek_pointer(Vector *vector, int index) {
  vector->peek_index = index;
}

static bool vector_in_bounds_for_at(Vector* vector, int index) {
  return (index >= 0 && index < vector->read_index);
};

void* vector_peek_no_increment(Vector* vector) {
  if (!vector_in_bounds_for_at(vector, vector->peek_index)) {
    return NULL;
  }

  void* ptr = vector_at(vector, vector->peek_index);
  return ptr;
};

void* vector_peek(Vector *vector) {
  void* ptr = vector_peek_no_increment(vector);
  if (ptr == NULL) {
    return NULL;
  }

  if (vector->flags & VECTOR_FLAG_PEEK_DECREMENT) {
    vector->peek_index--;
  } else {
    vector->peek_index++;
  }

  return ptr;
}
