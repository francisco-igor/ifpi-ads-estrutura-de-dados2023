#include "../arv.h"
#include <math.h>

int cheia(Arv a) {
    return nos(a) == (int)pow(2, altura(a)) - 1;
}

int main() {
    Arv g = cria('G', NULL, NULL);
    Arv f = cria('F', NULL, NULL);
    Arv e = cria('E', NULL, NULL);
    Arv d = cria('D', NULL, NULL);
    Arv c = cria('C', f, g);
    Arv b = cria('B', d, e);
    Arv a = cria('A', b, c);

    printf("%d", cheia(a)); // 1
    destroi(&a);

    return 0;
}
