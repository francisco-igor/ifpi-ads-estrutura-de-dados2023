#include "../arv.h"

int igual(Arv a, Arv b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    else {
        if (a -> item != b -> item) {
            return 0;
        } else {
            int esq = igual(a -> sae, b -> sae);
            int dir = igual(a -> sad, b -> sad);

            return (esq == 1) && (dir == 1);
        }
    }
}

int main() {
    Arv e = cria('E', NULL, NULL);
    Arv d = cria('D', NULL, NULL);
    Arv c = cria('C', e, NULL);
    Arv b = cria('B', NULL, d);
    Arv a = cria('A', b, c);

    Arv f = cria('A', cria('B', NULL, cria('D', NULL, NULL)), cria('C', cria('E', NULL, NULL), NULL));

    printf("%d", igual(a, f)); // 1
    destroi(&a);
    destroi(&f);

    return 0;
}
