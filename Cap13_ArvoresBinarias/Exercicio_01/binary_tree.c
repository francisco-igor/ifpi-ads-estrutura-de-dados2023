#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
  char item;
  struct arv *esq;
  struct arv *dir;
} *Arv;

Arv arv_cria(char n, Arv sae, Arv sad) {
  Arv p = malloc(1*sizeof(struct arv));
  p -> item = n;
  p -> esq = sae;
  p -> dir = sad;
  return p;
}

void imprime(Arv a) {
  if (a == NULL) {
    printf("");
  } else {
    printf("<%c", a -> item);
    imprime(a -> esq);
    imprime(a -> dir);
    printf(">");
  }
}

int main() {
  Arv f = arv_cria('F', NULL, NULL);
  Arv e = arv_cria('E', NULL, NULL);
  Arv d = arv_cria('D', NULL, NULL);
  Arv c = arv_cria('C', NULL, f);
  Arv b = arv_cria('B', d, e);
  Arv a = arv_cria('A', b, c);

  imprime(a);
  
  return 0;
}
