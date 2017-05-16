// Copyright 2017 Alexandre Cesar

#include "restaurant_service.h"
#include <assert.h>
#include <stdlib.h>

restaurant_service_t* new_restaurant_sercice(ficha_service_t* ficha_service, clock_service_t* clock_service) {
  assert(RESTAURANT_MAX_TIME != 0);

  restaurant_service_t* restaurant_service = malloc(sizeof(restaurant_service_t));
  restaurant_service->ficha_service = ficha_service;
  restaurant_service->clock_service = clock_service;
  return restaurant_service;
}
void restaurant_step(restaurant_service_t* restaurant_service) {
  assert(restaurant_service != NULL);

  ficha_step(restaurant_service->ficha_service);
  for (int i = 0; i < RESTAURANT_ENTRIES_BY_TICK; i++)
    ficha_add(
      restaurant_service->ficha_service,
      restaurant_service->clock_service->count
    );
  clock_step(restaurant_service->clock_service);
}
bool restaurant_closed(restaurant_service_t* restaurant_service) {
  return restaurant_service->clock_service->count >= RESTAURANT_MAX_TIME;
}
