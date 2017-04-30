// Copyright 2017 Alexandre Cesar

#include "queue.h"
#include <stdlib.h>

queue_t* empty_queue() {
  return NULL;
}
queue_t* queue_push(queue_t* queue, queue_value_t value) {
  if (queue == empty_queue()) {
    queue_t* new_queue = malloc(sizeof(queue_t));
    new_queue->value = value;
    new_queue->next = empty_queue();
    return new_queue;
  }
  queue->next = queue_push(queue->next, value);
  return queue;
}
queue_t* queue_pop(queue_t* queue) {
  if (queue == empty_queue())
    return empty_queue();
  queue_t* new_queue = queue->next;
  free(queue);
  return new_queue;
}
queue_value_t queue_peek(queue_t* queue) {
  if (queue != empty_queue())
    return queue->value;
  return 0; 
}
