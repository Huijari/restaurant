// Copyright 2017 Alexandre Cesar

#include "state.h"
#include <stdlib.h>

state_t* empty_state() {
  state_t* state = malloc(sizeof(state_t));
  state->count = 0;
  state->sum = 0;
  return state;
}
void state_add(state_t* state, uint64_t value) {
  state->count++;
  state->sum += value;
}
