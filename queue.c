// Copyright 2017 Alexandre Cesar

#include "queue.h"
#include <assert.h>
#include <stdlib.h>

queue_t* empty_queue() {
  return NULL;
}
queue_t* queue_push(queue_t* queue, queue_value_t value) {
  if (queue_is_empty(queue)) {
    queue_t* new_queue = malloc(sizeof(queue_t));
    new_queue->value = value;
    new_queue->next = empty_queue();
    return new_queue;
  }
  queue->next = queue_push(queue->next, value);
  return queue;
}
queue_t* queue_pop(queue_t* queue) {
  assert(!queue_is_empty(queue));
  queue_t* new_queue = queue->next;
  free(queue);
  return new_queue;
}
queue_value_t queue_peek(queue_t* queue) {
  assert(!queue_is_empty(queue));
  return queue->value;
}
uint64_t queue_size(queue_t* queue) {
  if (queue_is_empty(queue))
    return 0;
  return 1 + queue_size(queue->next);
}
bool queue_is_empty(queue_t* queue) {
  return queue == empty_queue();
}
