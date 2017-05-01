// Copyright 2017 Alexandre Cesar

#include "feijao_service.h"
#include <assert.h>
#include <stdlib.h>

feijao_service_t* new_feijao_service(guarnicao_service_t* guarnicao_service) {
  assert(FEIJAO_NUM_QUEUES != 0);

  feijao_service_t* feijao_service = malloc(sizeof(feijao_service_t));
  feijao_service->guarnicao_service = guarnicao_service;
  feijao_service->queues = calloc(sizeof(queue_t), FEIJAO_NUM_QUEUES);
  for (int i = 0; i < FEIJAO_NUM_QUEUES; i++)
    feijao_service->queues[i] = empty_queue();
  return feijao_service;
}
void feijao_step(feijao_service_t* feijao_service) {
  assert(feijao_service != NULL);

  for (int i = 0; i < FEIJAO_NUM_QUEUES; i++)
    if (!queue_is_empty(feijao_service->queues[i])) {
      uint64_t value = queue_peek(feijao_service->queues[i]);
      guarnicao_add(
        feijao_service->guarnicao_service,
        value
      );
      feijao_service->queues[i] = queue_pop(feijao_service->queues[i]);
    }
}
void feijao_add(feijao_service_t* feijao_service, uint64_t value) {
  assert(feijao_service != NULL);

  int min = 0;
  uint64_t min_size = queue_size(feijao_service->queues[min]);
  for (int i = 1; i < FEIJAO_NUM_QUEUES; i++) {
    uint64_t size = queue_size(feijao_service->queues[i]);
    if (size < min_size) {
      min_size = size;
      min = i;
    }
  }

  feijao_service->queues[min] = queue_push(
    feijao_service->queues[min],
    value
  );
}
