#include <stdio.h>
#include <stdlib.h>

typedef struct arv *Arv;

struct arv {
  char item;
  struct arv *sae;
  struct arv *sad;
};

Arv cria(char a, Arv sae, Arv sad) {
  Arv p = (Arv)malloc(sizeof(struct arv));
  p -> item = a;
  p -> sae = sae;
  p -> sad = sad;
  return p;
}

int nos(Arv a) {
  if (a == NULL) {
    return 0;
  } else {
    int esq = nos(a -> sae);
    int dir = nos(a -> sad);

    return 1 + esq + dir;
  }
}

int altura(Arv a) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = altura(a -> sae);
        int dir = altura(a -> sad);

        if (esq > dir) {
            return 1 + esq;
        } else {
            return 1 + dir;
        }
    }
}

void destroi(Arv *a) {
  if (*a != NULL) {
    destroi(&((*a) -> sae));
    destroi(&((*a) -> sad));
    free(*a);
    *a = NULL;
  }
}
