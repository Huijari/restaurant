# Restaurant
> Trabalho Prático I - AEDS II
> Alexandre Cesar



## Introdução

O problema se resume em simular um período de almoço no bandejão da UFMG, contando com uma fila para compra de fichas, uma fila para pegar a bandeja, e servir a comida (arroz, feijão, guarnição, salada). As bandejas também são contabilizadas e repostas num intervalo determinado.

## Configuração

Foram implementadas diversas configurações para possibilitar uma interatividades em análises posteriores. Elas são listadas abaixo:

- `RESTAURANT_MAX_TIME` Número de minutos em que o bandejão ficará aberto. *default: 4 \* 60*
- `RESTAURANT_ENTRIES_BY_TICK` Número de pessoas que entram na fila a cada minuto. *default: 2*
- `FICHA_NUM_QUEUES` Número de filas/caixas para compra de fichas. *default: 1*
- `BANDEJA_NUM_QUEUES` Número de filas para retirada de bandejas. *default: 1*
- `BANDEJA_MAX_PLATES` Número máximo de bandejas na pilha. *default: 30*
- `BANDEJA_RESTOCK_QUANTITY` Número de bandejas repostas de uma vez. *default: 10*
- `BANDEJA_RESTOCK_INTERVAL` Intervalo de tempo para reposição de bandejas. *default: 12*
- `ARROZ_NUM_QUEUES` Número de filas para servir arroz. *default: 1*
- `FEIJAO_NUM_QUEUES` Número de filas para servir feijão. *default: 1*
- `GUARNICAO_NUM_QUEUES` Número de filas para servir guarnição. *default: 1*
- `SALADA_NUM_QUEUES` Número de filas para servir salada. *default: 1*

## Compilação & Execução

O arquivo Makefile define duas regras de build:

`restaurant` Faz a build do executável.

`run` Executa o programa.

*Obs.: para compilação foi utilizado o clang, mas o código é compatível também com o gcc*

## Estruturas de Dados

Foi utilizado uma abordagem um pouco mais funcional na implementação das estruturas de dados fila e pilha (queue e stack no caso).

### Queue

`queue_t* empty_queue();` Retorna uma nova fila. **O(1)**.
`queue_t* queue_push(queue_t* queue, queue_value_t value);` Retorna uma fila com o novo elemento inserido no final. **O(n)**.
`queue_t* queue_pop(queue_t* queue);` Retorna uma fila com o primeiro elemento removido. **O(1).**
`queue_value_t queue_peek(queue_t* queue);` Retorna o primeiro elemento da fila. **O(1).**
`uint64_t queue_size(queue_t* queue);` Retorna o tamanho da fila. **O(n)**.
`bool queue_is_empty(queue_t* queue);` Retorna se a fila está vazia. **O(1)**.

### Stack

`stack_t* empty_stack();` Retorna uma nova pilha. **O(1)**.
`stack_t* stack_push(stack_t* stack, stack_value_t value);` Retorna uma pilha com o novo elemento inserido no topo. **O(1)**.
`stack_t* stack_pop(stack_t* stack);` Retorna uma pilha com o elemento do topo removido. **O(1)**.
`stack_value_t stack_peek(stack_t* stack);` Retorna o elemento do topo da pilha. **O(1)**.
`uint64_t stack_size(stack_t* stack);` Retorna o tamanho da pilha. **O(n)**.
`bool stack_is_empty(stack_t* stack);` Retorna se a pilha está vazia. **O(1)**;

## Implementação

Foram criadas estrutudas para cada etapa do processamento, exemplo: `arroz_service`. Assim, um elemento (no caso a pessoa) com o valor do tempo em que ela entrou na fila, percorre todas as estruturas até passar pela salada e então ao contados (`state`), onde são contabilizadas. Para saber o tempo em que uma pessoa passou na fila é subtraído do tempo atual o valor armazenado no elemento:

```
void state_add(state_t* state, uint64_t value) {
  state->count++;
  state->sum += state->clock_service->count - value;
}
```

Após passados `RESTAURANT_MAX_TIME` minutos (iterações), é mostrado o resultado final no formato:

```
Count  Sum	Average
0	   0	0
```

(Quantidade de pessoas que conseguiram servir o almoço, total de tempo gasto pelas pessoas, tempo médio gasto por cada pessoa).

## Resultados

### #1

```
RESTAURANT_MAX_TIME = 4 * 60
RESTAURANT_ENTRIES_BY_TICK = 2
FICHA_NUM_QUEUES = 1
BANDEJA_NUM_QUEUES = 1
BANDEJA_MAX_PLATES = 30
BANDEJA_RESTOCK_QUANTITY = 10
BANDEJA_RESTOCK_INTERVAL = 12
ARROZ_NUM_QUEUES = 1
FEIJAO_NUM_QUEUES = 1
GUARNICAO_NUM_QUEUES = 1
SALADA_NUM_QUEUES = 1
```

```
Count	Sum	    Average
234	    15093	64.500000
```

### #2

```
RESTAURANT_MAX_TIME = 4 * 60
RESTAURANT_ENTRIES_BY_TICK = 2
FICHA_NUM_QUEUES = 2
BANDEJA_NUM_QUEUES = 2
BANDEJA_MAX_PLATES = 30
BANDEJA_RESTOCK_QUANTITY = 10
BANDEJA_RESTOCK_INTERVAL = 12
ARROZ_NUM_QUEUES = 2
FEIJAO_NUM_QUEUES = 2
GUARNICAO_NUM_QUEUES = 2
SALADA_NUM_QUEUES = 2
```

```
Count	Sum	    Average
468	    2808	6.000000
```

### #3

```
RESTAURANT_MAX_TIME = 4 * 60
RESTAURANT_ENTRIES_BY_TICK = 2
FICHA_NUM_QUEUES = 1
BANDEJA_NUM_QUEUES = 2
BANDEJA_MAX_PLATES = 60
BANDEJA_RESTOCK_QUANTITY = 15
BANDEJA_RESTOCK_INTERVAL = 10
ARROZ_NUM_QUEUES = 1
FEIJAO_NUM_QUEUES = 1
GUARNICAO_NUM_QUEUES = 1
SALADA_NUM_QUEUES = 1
```

```
Count	Sum	    Average
234	    1404	6.000000
```

## Conclusão

Obviamente a solução mais eficiente é adicionar mais filas e caixas ao bandejão, o número de bandejas original não afeta muito para quantidades pequenas de filas/pessoas mas apresenta um funil para maiores quantidades. Com a inclusão dos custos de tais melhorias e de manutenção a análise poderia ser muito mais profunda.