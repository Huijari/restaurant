// Copyright 2017 Alexandre Cesar

#include "ficha_service.h"
#include <assert.h>
#include <stdlib.h>

ficha_service_t* new_ficha_service(bandeja_service_t* bandeja_service) {
  assert(FICHA_NUM_QUEUES != 0);

  ficha_service_t* ficha_service = malloc(sizeof(ficha_service_t));
  ficha_service->bandeja_service = bandeja_service;
  ficha_service->queues = calloc(sizeof(queue_t), FICHA_NUM_QUEUES);
  for (int i = 0; i < FICHA_NUM_QUEUES; i++)
    ficha_service->queues[i] = empty_queue();
  return ficha_service;
}
void ficha_step(ficha_service_t* ficha_service) {
  assert(ficha_service != NULL);

  bandeja_step(ficha_service->bandeja_service);
  for (int i = 0; i < FICHA_NUM_QUEUES; i++)
    if (!queue_is_empty(ficha_service->queues[i])) {
      uint64_t value = queue_peek(ficha_service->queues[i]);
      bandeja_add(
        ficha_service->bandeja_service,
        value
      );
      ficha_service->queues[i] = queue_pop(ficha_service->queues[i]);
    }
}
void ficha_add(ficha_service_t* ficha_service, uint64_t value) {
  assert(ficha_service != NULL);

  int min = 0;
  uint64_t min_size = queue_size(ficha_service->queues[min]);
  for (int i = 1; i < FICHA_NUM_QUEUES; i++) {
    uint64_t size = queue_size(ficha_service->queues[i]);
    if (size < min_size) {
      min_size = size;
      min = i;
    }
  }

  ficha_service->queues[min] = queue_push(
    ficha_service->queues[min],
    value
  );
}

