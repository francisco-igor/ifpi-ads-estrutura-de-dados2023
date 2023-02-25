#include <stdio.h>
#include <stdlib.h>

#define avanca(i) (i = (i + 1) % F->max)

typedef struct arv {
  char item;
  struct arv *esq;
  struct arv *dir;
} *Arv;

typedef Arv Itempf;

typedef struct fila {
  int max;
  int total;
  int inicio;
  int final;
  Itempf *item;
} * Fila;

Fila fila(int m) {
  Fila F = (Fila)malloc(sizeof(struct fila));
  F->max = m;
  F->total = 0;
  F->inicio = 0;
  F->final = 0;
  F->item = (Itempf *)malloc(m * sizeof(Itempf));
  return F;
}

int vaziaf(Fila F) { return (F->total == 0); }

int cheiaf(Fila F) { return (F->total == F->max); }

void enfileira(Itempf x, Fila F) {
  if (cheiaf(F)) {
    puts("Fila cheia!");
    abort();
  }
  F->item[F->final] = x;
  avanca(F->final);
  F->total++;
}

Itempf desenfileira(Fila F) {
  if (vaziaf(F)) {
    puts("Fila vazia!");
    abort();
  }
  Itempf x = F->item[F->inicio];
  avanca(F->inicio);
  F->total--;
  return x;
}

void destroif(Fila *G) {
  free((*G)->item);
  free(*G);
  *G = NULL;
}
