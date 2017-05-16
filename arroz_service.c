// Copyright 2017 Alexandre Cesar

#include "arroz_service.h"
#include <assert.h>
#include <stdlib.h>

arroz_service_t* new_arroz_service(feijao_service_t* feijao_service) {
  assert(ARROZ_NUM_QUEUES != 0);

  arroz_service_t* arroz_service = malloc(sizeof(arroz_service_t));
  arroz_service->feijao_service = feijao_service;
  arroz_service->queues = calloc(sizeof(queue_t), ARROZ_NUM_QUEUES);
  for (int i = 0; i < ARROZ_NUM_QUEUES; i++)
    arroz_service->queues[i] = empty_queue();
  return arroz_service;
}
void arroz_step(arroz_service_t* arroz_service) {
  assert(arroz_service != NULL);

  feijao_step(arroz_service->feijao_service);
  for (int i = 0; i < ARROZ_NUM_QUEUES; i++)
    if (!queue_is_empty(arroz_service->queues[i])) {
      uint64_t value = queue_peek(arroz_service->queues[i]);
      feijao_add(
        arroz_service->feijao_service,
        value
      );
      arroz_service->queues[i] = queue_pop(arroz_service->queues[i]);
    }
}
void arroz_add(arroz_service_t* arroz_service, uint64_t value) {
  assert(arroz_service != NULL);

  int min = 0;
  uint64_t min_size = queue_size(arroz_service->queues[min]);
  for (int i = 1; i < ARROZ_NUM_QUEUES; i++) {
    uint64_t size = queue_size(arroz_service->queues[i]);
    if (size < min_size) {
      min_size = size;
      min = i;
    }
  }

  arroz_service->queues[min] = queue_push(
    arroz_service->queues[min],
    value
  );
}
