// Copyright 2017 Alexandre Cesar

#include "arroz_service.h"
#include "bandeja_service.h"
#include "clock_service.h"
#include "feijao_service.h"
#include "guarnicao_service.h"
#include "restaurant_service.h"
#include "salada_service.h"
#include "state.h"
#include <stdio.h>

int main(int argc, char** argv) {
  clock_service_t* clock = new_clock_service();
  state_t* state = new_state(clock);
  restaurant_service_t* restaurant = new_restaurant_service(
    new_ficha_service(
      new_bandeja_service(
        new_arroz_service(
          new_feijao_service(
            new_guarnicao_service(
              new_salada_service(
                state
              )
            )
          )
        )
      )
    ),
    clock
  );

  while (!restaurant_closed(restaurant))
    restaurant_step(restaurant);

  printf("Count\tSum\tAverage\n");
  printf(
    "%lu\t%lu\t%lf\n",
    state->count,
    state->sum,
    (double) state->sum / state->count
  );
}
