// Copyright 2017 Alexandre Cesar

#ifndef SALADA_SERVICE_H
#define SALADA_SERVICE_H

#include "queue.h"
#include "state.h"
#include <inttypes.h>

#define SALADA_NUM_QUEUES 1

typedef struct salada_service_t salada_service_t;
struct salada_service_t {
  state_t* state;
  queue_t** queues;
};

salada_service_t* new_salada_service(state_t* state);
void salada_step(salada_service_t* salada_service);
void salada_add(salada_service_t* salada_service, uint64_t value);

#endif
