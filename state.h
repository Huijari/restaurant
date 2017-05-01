// Copyright 2017 Alexandre Cesar

#ifndef STATE_H
#define STATE_H

#include <inttypes.h>

typedef struct state_t state_t;
struct state_t {
  uint64_t count;
  uint64_t sum;
};

state_t* empty_state();
void state_add(state_t* state, uint64_t value);

#endif
