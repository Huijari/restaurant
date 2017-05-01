// Copyright 2017 Alexandre Cesar

#ifndef ARROZ_SERVICE_H
#define ARROZ_SERVICE_H

#include "queue.h"
#include "feijao_service.h"
#include <inttypes.h>

#define ARROZ_NUM_QUEUES 1

typedef struct arroz_service_t arroz_service_t;
struct arroz_service_t {
  feijao_service_t* feijao_service;
  queue_t** queues;
};

arroz_service_t* new_arroz_service(feijao_service_t* feijao_service);
void arroz_step(arroz_service_t* arroz_service);
void arroz_add(arroz_service_t* arroz_service, uint64_t value);

#endif

