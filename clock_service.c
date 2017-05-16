// Copyright 2017 Alexandre Cesar

#include "clock_service.h"
#include <assert.h>
#include <stdlib.h>

clock_service_t* new_clock_service(ficha_service_t* ficha_service) {
  assert(CLOCK_ENTRIES_BY_TICK != 0);

  clock_service_t* clock_service = malloc(sizeof(clock_service_t));
  clock_service->ficha_service = ficha_service;
  clock_service->count = 0;
  return clock_service;
}
void clock_step(clock_service_t* clock_service) {
  assert(clock_service != NULL);

  ficha_step(clock_service->ficha_service);
  for (int i = 0; i < CLOCK_ENTRIES_BY_TICK; i++)
    ficha_add(
      clock_service->ficha_service,
      clock_service->count
    );
  clock_service->count++;
}
