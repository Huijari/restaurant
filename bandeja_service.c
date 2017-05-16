// Copyright 2017 Alexandre Cesar

#include "bandeja_service.h"
#include <assert.h>
#include <stdlib.h>

bandeja_service_t* new_bandeja_service(arroz_service_t* arroz_service) {
  assert(BANDEJA_NUM_QUEUES != 0);

  bandeja_service_t* bandeja_service = malloc(sizeof(bandeja_service_t));
  bandeja_service->arroz_service = arroz_service;
  bandeja_service->queues = calloc(sizeof(queue_t), BANDEJA_NUM_QUEUES);
  for (int i = 0; i < BANDEJA_NUM_QUEUES; i++)
    bandeja_service->queues[i] = empty_queue();
  bandeja_service->bandejas = empty_stack();
  bandeja_service->count = 0;
  return bandeja_service;
}
void bandeja_step(bandeja_service_t* bandeja_service) {
  assert(bandeja_service != NULL);

  arroz_step(bandeja_service->arroz_service);

  if (bandeja_service->count % BANDEJA_RESTOCK_INTERVAL == 0) {
    int diff = BANDEJA_MAX_PLATES - stack_size(bandeja_service->bandejas);
    int amount = diff < BANDEJA_RESTOCK_QUANTITY ? diff : BANDEJA_RESTOCK_QUANTITY;
    for (int i = 0; i < amount; i++)
      bandeja_service->bandejas = stack_push(bandeja_service->bandejas, i);
  }
  bandeja_service->count = (bandeja_service->count) % BANDEJA_RESTOCK_INTERVAL;

  for (int i = 0; i < BANDEJA_NUM_QUEUES; i++)
    if (!queue_is_empty(bandeja_service->queues[i]) && !stack_is_empty(bandeja_service->bandejas)) {
      uint64_t value = queue_peek(bandeja_service->queues[i]);
      arroz_add(
        bandeja_service->arroz_service,
        value
      );
      bandeja_service->queues[i] = queue_pop(bandeja_service->queues[i]);
    }
}
void bandeja_add(bandeja_service_t* bandeja_service, uint64_t value) {
  assert(bandeja_service != NULL);

  int min = 0;
  uint64_t min_size = queue_size(bandeja_service->queues[min]);
  for (int i = 1; i < BANDEJA_NUM_QUEUES; i++) {
    uint64_t size = queue_size(bandeja_service->queues[i]);
    if (size < min_size) {
      min_size = size;
      min = i;
    }
  }

  bandeja_service->queues[min] = queue_push(
    bandeja_service->queues[min],
    value
  );
}
