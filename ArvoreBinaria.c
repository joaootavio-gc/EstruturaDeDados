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
Arvore *busca(Arvore *arvore, int info);
void imprimir(Arvore *arvore, int forma);
void imprimirPreOrdem(Arvore *arvore);
void imprimirEmOrdem(Arvore *arvore);
void imprimirPosOrdem(Arvore *arvore);
Arvore *inserir(Arvore *arvore, int info);
void remover(Arvore *arvore, int info);
int contarElementos(Arvore *arvore);

int main() {
    int opcao=-1, elemento, resultado;
    Arvore *arvore;

    while(opcao != 0){

        printf("\nEscolha uma das opcoes:\n");
        printf("0 - Sair do programa\n");
        printf("1 - Criar arvore vazia\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Procurar elemento\n");
        printf("5 - Acessar elemento\n");
        printf("6 - Eliminar arvore\n");
        printf("7 - Mostrar arvore\n");

        scanf("%d", &opcao);
        system("clear");

        switch(opcao){
            case 0:
                return 0;
            case 1:
                arvore = criarVazia();
                printf("Lista criada com sucesso!\n");
                break;
            case 2:
                printf("Digite o elemento: ");
                scanf("%d", &elemento);
                resultado = inserirElemento(elemento);
                if(resultado != -1)
                    printf("O elemento foi inserido com sucesso");
                else
                    printf("Lista cheia ou vazia!\n");
                break;
            case 3:
                printf("Informe o elemento da lista: ");
                scanf("%d", &elemento);
                removerElemento(elemento) ? printf("Elemento eliminado com sucesso!\n") : printf("Elemento nao encontrado!\n");//operador ternário
                break;
            case 4:
                printf("Digite o elemento: ");
                scanf("%d", &elemento);
                resultado = procurarElemento(elemento);
                if(resultado != -1)
                    printf("O elemento foi encontrado na posicao %d da lista.\n", resultado);
                else
                    printf("Elemento nao encontrado na lista.\n");
                break;
            case 5:
                printf("Digite a posicao: ");
                scanf("%d", &elemento);
                resultado = acessarElemento(elemento);
                if(resultado != -1)
                    printf("Elemento da posicao %d: %d", elemento, resultado);
                break;
            case 6:
                eliminarLista();
                printf("A lista foi eliminada com sucesso!\n");
                break;
            case 7:
                imprimirLista();
        }
    }
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

Arvore *busca(Arvore *arvore, int info){
    if(arvore == NULL || arvore->info == info)
        return arvore;
    if(arvore->info > info)
        return busca(arvore->esquerda, info);
    else
        return busca(arvore->direita, info);
}

void imprimir(Arvore *arvore, int forma){
    printf("Estado da arvore ");
    switch (forma){
        case PRE_ORDEM:
            imprimirPreOrdem(arvore);
            break;
        case EM_ORDEM:
            imprimirEmOrdem(arvore);
            break;
        case POS_ORDEM:
            imprimirPosOrdem(arvore);
            break;

    }
}

void imprimirPreOrdem(Arvore *arvore){
    printf("- Pre ordem\n");
    if(!arvoreVazia(arvore)){
        printf("%d", arvore->info);
        imprimirPreOrdem(arvore->esquerda);
        imprimirPreOrdem(arvore->direita);
    }
}

void imprimirEmOrdem(Arvore *arvore){
    printf("- Em ordem\n");
    if(!arvoreVazia(arvore)){
        imprimirEmOrdem(arvore->esquerda);
        printf("%d", arvore->info);
        imprimirEmOrdem(arvore->direita);
    }
}

void imprimirPosOrdem(Arvore *arvore){
    printf("- Pos ordem\n");
    if(!arvoreVazia(arvore)){
        imprimirPosOrdem(arvore->esquerda);
        imprimirPosOrdem(arvore->direita);
        printf("%d", arvore->info);
    }
}

int contarElementos(Arvore *arvore){
    if (!arvore)
        return 0;
    return contarElementos(arvore->esquerda) + contarElementos(arvore->direita) + 1;
}

Arvore *inserir(Arvore *arvore, int info){
    Arvore *aux1 = NULL, *aux2 = arvore;
    while (aux2 != NULL){
        aux1 = aux2;
        if(info < aux2->info)
            aux2 = aux2->esquerda;
        else
            aux2 = aux2->direita;
    }
    if (aux1 == NULL)
        return criar(info,NULL,NULL);
    else
        if (info < aux2->info)
            aux1->esquerda = criar(info, NULL, NULL);
        else
            aux1->direita = criar(info, NULL, NULL);
    return arvore;
}

void remover(Arvore *arvore, int info){

}