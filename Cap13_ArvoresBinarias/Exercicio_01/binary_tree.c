#include "./fila.h"

void emnivel(Arv a) {
  if (a == NULL) return;
  Fila f = fila(3);
  enfileira(a, f);
  while (!vaziaf(f)) {
    a = desenfileira(f);
    printf("%d ", a -> item);
    if (a -> esq != NULL) enfileira(a -> esq, f);
    if (a -> dir != NULL) enfileira(a -> dir, f);
  }
  destroif(&f);
}

Arv arv_cria(char n, Arv sae, Arv sad) {
  Arv p = malloc(1*sizeof(struct arv));
  p -> item = n;
  p -> esq = sae;
  p -> dir = sad;
  return p;
}

int main() {
  Arv f = arv_cria(6, NULL, NULL);
  Arv e = arv_cria(5, NULL, NULL);
  Arv d = arv_cria(4, NULL, NULL);
  Arv c = arv_cria(3, NULL, f);
  Arv b = arv_cria(2, d, e);
  Arv a = arv_cria(1, b, c);

  emnivel(a);

  return 0;
}
