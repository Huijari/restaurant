// Copyright 2017 Alexandre Cesar

#ifndef BANDEJA_SERVICE_H
#define BANDEJA_SERVICE_H

#include "arroz_service.h"
#include "queue.h"
#include "stack.h"
#include <inttypes.h>

#define BANDEJA_NUM_QUEUES 1
#define BANDEJA_MAX_PLATES 30
#define BANDEJA_RESTOCK_QUANTITY 10
#define BANDEJA_RESTOCK_INTERVAL 12

typedef struct bandeja_service_t bandeja_service_t;
struct bandeja_service_t {
  arroz_service_t* arroz_service;
  queue_t** queues;
  stack_t* bandejas;
  int count;
};

bandeja_service_t* new_bandeja_service(arroz_service_t* arroz_service);
void bandeja_step(bandeja_service_t* bandeja_service);
void bandeja_add(bandeja_service_t* bandeja_service, uint64_t value);

#endif


