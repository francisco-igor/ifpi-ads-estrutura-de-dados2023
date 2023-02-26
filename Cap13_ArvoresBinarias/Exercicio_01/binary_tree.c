#include "./fila.h"

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
    printf("<%d", a -> item);
    imprime(a -> esq);
    imprime(a -> dir);
    printf(">");
  }
}

int main() {
  Arv f = arv_cria(6, NULL, NULL);
  Arv e = arv_cria(5, NULL, NULL);
  Arv d = arv_cria(4, NULL, NULL);
  Arv c = arv_cria(3, NULL, f);
  Arv b = arv_cria(2, d, e);
  Arv a = arv_cria(1, b, c);

  imprime(a);
  destroif(&a);
  
  return 0;
}
