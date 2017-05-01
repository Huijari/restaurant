// Copyright 2017 Alexandre Cesar

#ifndef GUARNICAO_SERVICE_H
#define GUARNICAO_SERVICE_H

#include "queue.h"
#include "salada_service.h"
#include <inttypes.h>

#define GUARNICAO_NUM_QUEUES 1

typedef struct guarnicao_service_t guarnicao_service_t;
struct guarnicao_service_t {
  salada_service_t* salada_service;
  queue_t** queues;
};

guarnicao_service_t* new_guarnicao_service(salada_service_t* salada_service);
void guarnicao_step(guarnicao_service_t* guarnicao_service);
void guarnicao_add(guarnicao_service_t* guarnicao_service, uint64_t value);

#endif

