#include <stdio.h>
#include <stdlib.h>

#define PRE_ORDEM 0
#define EM_ORDEM 1
#define POS_ORDEM 2

typedef struct no {
    int info;
    struct no *esquerda, *direita;

}Arvore;

Arvore *criarVazia();
Arvore *criar(int info, Arvore *esquerda, Arvore *direita);
Arvore *destruir(Arvore *arvore);
int arvoreVazia(Arvore *arvore);
int pertence(Arvore *arvore, int info);
void imprimir(Arvore *arvore, int forma);

int main() {
    printf("Hello, World!\n");
    return 0;
}

Arvore *criarVazia(){
    return NULL;
}

Arvore *criar(int info, Arvore *esquerda, Arvore *direita){
    Arvore *nova = (Arvore*) malloc(sizeof(Arvore));
    nova->info = info;
    nova->esquerda = esquerda;
    nova->direita = direita;
    return nova;
}

int arvoreVazia(Arvore *arvore){
    return arvore == NULL;
}

Arvore *destruir(Arvore *arvore){
    if(!arvoreVazia(arvore)){
        destruir(arvore->esquerda);
        destruir(arvore->direita);
        free(arvore);
    }
    return NULL;
}

int pertence(Arvore *arvore, int info){
    if(arvoreVazia(arvore))
        return 0;
    return arvore->info == info || pertence(arvore->esquerda, info) || pertence(arvore->direita, info);
}