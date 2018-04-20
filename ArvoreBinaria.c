#include <stdio.h>

#define PRE_ORDEM 0
#define EM_ORDEM 1
#define POS_ORDEM 2

typedef struct no {
    int info;
    struct no *esquerda, *direita;

}Arvore;

Arvore *criar();
Arvore *destruir(Arvore *arvore);
int *arvoreVazia(Arvore *arvore);
int *pertence(Arvore *arvore);
void imprimir(Arvore *arvore);

int main() {
    printf("Hello, World!\n");
    return 0;
}