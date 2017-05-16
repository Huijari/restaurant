// Copyright 2017 Alexandre Cesar

#ifndef FICHA_SERVICE_H
#define FICHA_SERVICE_H

#include "bandeja_service.h"
#include "queue.h"
#include <inttypes.h>

#define FICHA_NUM_QUEUES 1

typedef struct ficha_service_t ficha_service_t;
struct ficha_service_t {
  bandeja_service_t* bandeja_service;
  queue_t** queues;
};

ficha_service_t* new_ficha_service(bandeja_service_t* bandeja_service);
void ficha_step(ficha_service_t* ficha_service);
void ficha_add(ficha_service_t* ficha_service, uint64_t value);

#endif



