// Copyright 2017 Alexandre Cesar

#ifndef RESTAURANT_SERVICE_H
#define RESTAURANT_SERVICE_H

#include "clock_service.h"
#include "ficha_service.h"
#include "queue.h"
#include <inttypes.h>
#include <stdbool.h>

#define RESTAURANT_MAX_TIME 4 * 60

typedef struct restaurant_service_t restaurant_service_t;
struct restaurant_service_t {
  ficha_service_t* ficha_service;
  clock_service_t* clock_service;
};

restaurant_service_t* new_restaurant_service(ficha_service_t* ficha_service, clock_service_t* clock_service);
void restaurant_step(restaurant_service_t* restaurant_service);
bool restaurant_closed(restaurant_service_t*);

#endif


