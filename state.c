// Copyright 2017 Alexandre Cesar

#include "state.h"
#include <stdlib.h>

state_t* new_state(clock_service_t* clock_service) {
  state_t* state = malloc(sizeof(state_t));
  state->clock_service = clock_service;
  state->count = 0;
  state->sum = 0;
  return state;
}
void state_add(state_t* state, uint64_t value) {
  state->count++;
  state->sum += state->clock_service->count - value;
}
