#include <stdio.h>
#include "./utils/vector.h"

int main(void) {
  Vector* vector = vector_create(sizeof(int));
  int x = 50;

  vector_push(vector, &x);
  x = 20;
  vector_push(vector, &x);

  vector_set_peek_pointer(vector, 0);
  int* ptr = vector_peek(vector);
  while (ptr) {
    printf("%i: \n", *ptr);
    ptr = vector_peek(vector);
  }

  return 0;
}
