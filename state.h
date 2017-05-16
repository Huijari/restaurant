// Copyright 2017 Alexandre Cesar

#ifndef STATE_H
#define STATE_H

#include "clock_service.h"
#include <inttypes.h>

typedef struct state_t state_t;
struct state_t {
  clock_service_t* clock_service;
  uint64_t count;
  uint64_t sum;
};

state_t* new_state(clock_service_t* clock_service);
void state_add(state_t* state, uint64_t value);

#endif
