// Copyright 2017 Alexandre Cesar

#include "guarnicao_service.h"
#include <assert.h>
#include <stdlib.h>

guarnicao_service_t* new_guarnicao_service(salada_service_t* salada_service) {
  assert(GUARNICAO_NUM_QUEUES != 0);

  guarnicao_service_t* guarnicao_service = malloc(sizeof(guarnicao_service_t));
  guarnicao_service->salada_service = salada_service;
  guarnicao_service->queues = calloc(sizeof(queue_t), GUARNICAO_NUM_QUEUES);
  for (int i = 0; i < GUARNICAO_NUM_QUEUES; i++)
    guarnicao_service->queues[i] = empty_queue();
  return guarnicao_service;
}
void guarnicao_step(guarnicao_service_t* guarnicao_service) {
  assert(guarnicao_service != NULL);

  salada_step(guarnicao_service->salada_service);
  for (int i = 0; i < GUARNICAO_NUM_QUEUES; i++)
    if (!queue_is_empty(guarnicao_service->queues[i])) {
      uint64_t value = queue_peek(guarnicao_service->queues[i]);
      salada_add(
        guarnicao_service->salada_service,
        value
      );
      guarnicao_service->queues[i] = queue_pop(guarnicao_service->queues[i]);
    }
}
void guarnicao_add(guarnicao_service_t* guarnicao_service, uint64_t value) {
  assert(guarnicao_service != NULL);

  int min = 0;
  uint64_t min_size = queue_size(guarnicao_service->queues[min]);
  for (int i = 1; i < GUARNICAO_NUM_QUEUES; i++) {
    uint64_t size = queue_size(guarnicao_service->queues[i]);
    if (size < min_size) {
      min_size = size;
      min = i;
    }
  }

  guarnicao_service->queues[min] = queue_push(
    guarnicao_service->queues[min],
    value
  );
}
