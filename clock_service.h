// Copyright 2017 Alexandre Cesar

#ifndef CLOCK_SERVICE_H
#define CLOCK_SERVICE_H

#include <inttypes.h>

typedef struct clock_service_t clock_service_t;
struct clock_service_t {
  uint64_t count;
};

clock_service_t* new_clock_service();
void clock_step(clock_service_t* clock_service);

#endif


