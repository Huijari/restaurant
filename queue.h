// Copyright 2017 Alexandre Cesar

#ifndef QUEUE_H
#define QUEUE_H

#include <inttypes.h>

typedef uint64_t queue_value_t;
typedef struct queue_t queue_t;
struct queue_t {
  queue_value_t value;
  queue_t* next;
};

queue_t* empty_queue();
queue_t* queue_push(queue_t* queue, queue_value_t value);
queue_t* queue_pop(queue_t* queue);
queue_value_t queue_peek(queue_t* queue);

#endif
