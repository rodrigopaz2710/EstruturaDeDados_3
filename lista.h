#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *cabeca;
    int tamanho;
} Lista;

void criar_lista(Lista *lista);
int lista_vazia(Lista *lista);
int obter_tamanho(Lista *lista);
int obter_elemento(Lista *lista, int posicao);
void modificar_elemento(Lista *lista, int posicao, int valor);
int inserir_elemento(Lista *lista, int posicao, int valor);
int remover_elemento(Lista *lista, int posicao);
void imprimir_lista(Lista *lista);

#endif 
