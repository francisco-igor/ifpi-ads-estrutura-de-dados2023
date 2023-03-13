#include "../arv.h"

int eb(Arv a) {
    if (a != NULL) {
        if (a -> sae == NULL && a -> sad == NULL) {
            return 1;
        }
        if (a -> sae == NULL || a -> sad == NULL) {
            return 0;
        }
        int esq = eb(a -> sae);
        int dir = eb(a -> sad);

        return (esq == 1) && (dir == 1);

    } else {
        return 0;
    }
}

int main() {
    // Arvore estritamente binaria
    Arv g = cria('G', NULL, NULL);
    Arv f = cria('F', NULL, NULL);
    Arv e = cria('E', NULL, NULL);
    Arv d = cria('D', NULL, NULL);
    Arv c = cria('C', f, g);
    Arv b = cria('B', d, e);
    Arv a = cria('A', b, c);

    // Arvore nao binaria
    Arv h = cria('A', cria('B', NULL, cria('D', NULL, NULL)), cria('C', cria('E', NULL, NULL), NULL));

    printf("%d", eb(a)); // 1
    printf("%d", eb(h)); // 0
    destroi(&a);
    destroi(&h);

    return 0;
}
