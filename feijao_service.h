// Copyright 2017 Alexandre Cesar

#ifndef FEIJAO_SERVICE_H
#define FEIJAO_SERVICE_H

#include "queue.h"
#include "guarnicao_service.h"
#include <inttypes.h>

#define FEIJAO_NUM_QUEUES 1

typedef struct feijao_service_t feijao_service_t;
struct feijao_service_t {
  guarnicao_service_t* guarnicao_service;
  queue_t** queues;
};

feijao_service_t* new_feijao_service(guarnicao_service_t* guarnicao_service);
void feijao_step(feijao_service_t* feijao_service);
void feijao_add(feijao_service_t* feijao_service, uint64_t value);

#endif

