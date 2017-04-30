// Copyright 2017 Alexandre Cesar

#ifndef STACK_H
#define STACK_H

#include <inttypes.h>
#include <stdbool.h>

typedef uint64_t stack_value_t;
typedef struct stack_t stack_t;
struct stack_t {
  stack_value_t value;
  stack_t* next;
};

stack_t* empty_stack();
stack_t* stack_push(stack_t* stack, stack_value_t value);
stack_t* stack_pop(stack_t* stack);
stack_value_t stack_peek(stack_t* stack);
bool stack_is_empty(stack_t* stack);

#endif
