// Copyright 2017 Alexandre Cesar

#ifndef CLOCK_SERVICE_H
#define CLOCK_SERVICE_H

#include "ficha_service.h"
#include <inttypes.h>

#define CLOCK_ENTRIES_BY_TICK 2

typedef struct clock_service_t clock_service_t;
struct clock_service_t {
  ficha_service_t* ficha_service;
  uint64_t count;
};

clock_service_t* new_clock_service(ficha_service_t* ficha_service);
void clock_step(clock_service_t* clock_service);

#endif


