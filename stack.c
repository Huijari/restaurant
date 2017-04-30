// Copyright 2017 Alexandre Cesar

#include "stack.h"
#include <assert.h>
#include <stdlib.h>

stack_t* empty_stack() {
  return NULL;
}
stack_t* stack_push(stack_t* stack, stack_value_t value) {
  stack_t* new_stack = malloc(sizeof(stack));
  new_stack->value = value;
  new_stack->next = stack;
  return new_stack;
}
stack_t* stack_pop(stack_t* stack) {
  assert(!stack_is_empty(stack));
  stack_t* new_stack = stack->next;
  free(stack);
  return new_stack;
}
stack_value_t stack_peek(stack_t* stack) {
  assert(!stack_is_empty(stack));
  return stack->value;
}
bool stack_is_empty(stack_t* stack) {
  return stack == empty_stack();
}
