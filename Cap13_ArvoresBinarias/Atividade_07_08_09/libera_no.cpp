#include <iostream>

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
} Arv;

Arv *arvore(char x, Arv *e, Arv *d){
	Arv *novo=(Arv*)malloc(sizeof(Arv));
	novo -> esq = e;
	novo -> dir = d;
	novo -> info = x;
	return novo;
}

void imprime(Arv *n){			
	if (n != NULL) {	
		std::cout << "<" << n -> info;
		imprime(n -> esq);
		imprime(n -> dir);
		std::cout << ">";
	} else {
		std::cout << "<>";
	}
}

int calculaQuantNos(Arv *no) {
	if (no == NULL) {
    return 0;
  	} else {
    	int esq = calculaQuantNos(no -> esq);
    	int dir = calculaQuantNos(no -> dir);

    	return 1 + esq + dir;
  	}
}

int calculaQuantNosFolha(Arv *no) {
	if (no == NULL) {
        return 0;
    } else {
        int esq = calculaQuantNosFolha(no -> esq);
        int dir = calculaQuantNosFolha(no -> esq);

        if (no -> esq == NULL && no -> dir == NULL) {
            return 1 + esq + dir;
        } else {
            return 0 + esq + dir;
        }
    }
}

int alturaArvore(Arv *no) {	        
	if (no == NULL) {
        return 0;
    } else {
        int esq = alturaArvore(no -> esq);
        int dir = alturaArvore(no -> dir);

        if (esq > dir) {
            return 1 + esq;
        } else {
            return 1 + dir;
        }
    }
}

int procura(Arv *no, char valor) {
	if (no == NULL) {
        return 0;
	}
	if (no -> info == valor) {
		return 1;
	}
	else {
		int esq = procura(no -> esq, valor);
    	int dir = procura(no -> dir, valor);

    	return esq + dir;
	}
}

void destroiArvore(Arv **no) {
	if (*no != NULL) {
		destroiArvore(&((*no) -> esq));
		destroiArvore(&((*no) -> dir));
		free(*no);
		*no = NULL;
  	}
}

// remove o no procurado. Se o no tiver filhos, remova tambem os filhos		
void removeSubArvore(Arv **no, char valor) {
	if (*no == NULL) {
    	return;
  	}
	if ((*no) -> info == valor) {
		destroiArvore(no);
	} else {
		removeSubArvore(&((*no) -> esq), valor);
		removeSubArvore(&((*no) -> dir), valor);
	}
}
	        
int main() {
 	Arv *c = arvore('c', NULL, NULL);
	Arv *z = arvore('z', 0, 0);
 	Arv *o = arvore('o', c, z);

	// imprime a arvore
	imprime(o);
	std::cout << std::endl;

	// imprime a quantidade de nos
	std::cout << calculaQuantNos(o) << std::endl;

	// imprime a quantidade de folhas
	std::cout << calculaQuantNosFolha(o) << std::endl;

	// imprime a altura da arvore
	std::cout << alturaArvore(o) << std::endl;

	// retorna quantas vezes o no foi encontrado
	std::cout << procura(o, 'c') << std::endl;

	// remove uma subarvore
	removeSubArvore(&o, 'z');
	imprime(o);

	// destroi a arvore
	destroiArvore(&o);

	return 0;
}
