#include "lista.h"

void criar_lista(Lista *lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

int lista_vazia(Lista *lista) {
    return lista->tamanho == 0;
}

int obter_tamanho(Lista *lista) {
    return lista->tamanho;
}

Nodo* obter_nodo(Lista *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        return NULL; // Posição inválida
    }
    Nodo *atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual;
}

int obter_elemento(Lista *lista, int posicao) {
    Nodo *nodo = obter_nodo(lista, posicao);
    if (nodo != NULL) {
        return nodo->dado;
    }
    return -1; // Indicativo de erro
}

void modificar_elemento(Lista *lista, int posicao, int valor) {
    Nodo *nodo = obter_nodo(lista, posicao);
    if (nodo != NULL) {
        nodo->dado = valor;
    }
}

int inserir_elemento(Lista *lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        return 0; // Falha na inserção
    }

    Nodo *novo_nodo = (Nodo*) malloc(sizeof(Nodo));
    if (novo_nodo == NULL) {
        return 0; 
    }
    novo_nodo->dado = valor;

    if (posicao == 1) {
        novo_nodo->proximo = lista->cabeca;
        lista->cabeca = novo_nodo;
    } else {
        Nodo *anterior = obter_nodo(lista, posicao - 1);
        novo_nodo->proximo = anterior->proximo;
        anterior->proximo = novo_nodo;
    }

    lista->tamanho++;
    return 1; 
}

int remover_elemento(Lista *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        return 0; 
    }

    Nodo *remover;
    if (posicao == 1) {
        remover = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
    } else {
        Nodo *anterior = obter_nodo(lista, posicao - 1);
        remover = anterior->proximo;
        anterior->proximo = remover->proximo;
    }

    free(remover);
    lista->tamanho--;
    return 1;
}

void imprimir_lista(Lista *lista) {
    Nodo *atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}
