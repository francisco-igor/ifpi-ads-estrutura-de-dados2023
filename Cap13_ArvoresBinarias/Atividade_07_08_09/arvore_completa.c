#include "../arv.h"
#include <math.h>

int completa(Arv a) {
    int alt = altura(a);
    int no = nos(a);

    return (no > alt && (no <= (int)pow(2, alt) - 1));
}

int main() {
    Arv g = cria('G', NULL, NULL);
    Arv f = cria('F', NULL, NULL);
    Arv e = cria('E', NULL, NULL);
    Arv d = cria('D', NULL, NULL);
    Arv c = cria('C', f, g);
    Arv b = cria('B', d, e);
    Arv a = cria('A', b, c);

    printf("%d", completa(a)); // 1
    destroi(&a);

    return 0;
}
