// Copyright 2017 Alexandre Cesar

#include "clock_service.h"
#include <assert.h>
#include <stdlib.h>

clock_service_t* new_clock_service() {
  clock_service_t* clock_service = malloc(sizeof(clock_service_t));
  clock_service->count = 0;
  return clock_service;
}
void clock_step(clock_service_t* clock_service) {
  assert(clock_service != NULL);

  clock_service->count++;
}
