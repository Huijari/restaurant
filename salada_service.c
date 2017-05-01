// Copyright 2017 Alexandre Cesar

#include "salada_service.h"
#include <assert.h>
#include <stdlib.h>

salada_service_t* new_salada_service(state_t* state) {
  assert(SALADA_NUM_QUEUES != 0);

  salada_service_t* salada_service = malloc(sizeof(salada_service_t));
  salada_service->state = state;
  salada_service->queues = calloc(sizeof(queue_t), SALADA_NUM_QUEUES);
  for (int i = 0; i < SALADA_NUM_QUEUES; i++)
    salada_service->queues[i] = empty_queue();
  return salada_service;
}
void salada_step(salada_service_t* salada_service) {
  assert(salada_service != NULL);

  for (int i = 0; i < SALADA_NUM_QUEUES; i++)
    if (!queue_is_empty(salada_service->queues[i])) {
      uint64_t value = queue_peek(salada_service->queues[i]);
      state_add(
        salada_service->state,
        value
      );
      salada_service->queues[i] = queue_pop(salada_service->queues[i]);
    }
}
void salada_add(salada_service_t* salada_service, uint64_t value) {
  assert(salada_service != NULL);

  int min = 0;
  uint64_t min_size = queue_size(salada_service->queues[min]);
  for (int i = 1; i < SALADA_NUM_QUEUES; i++) {
    uint64_t size = queue_size(salada_service->queues[i]);
    if (size < min_size) {
      min_size = size;
      min = i;
    }
  }

  salada_service->queues[min] = queue_push(
    salada_service->queues[min],
    value
  );
}
