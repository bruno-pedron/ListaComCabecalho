#include <stdio.h>

#include <stdlib.h>

#include "lista.h"


Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho
    lista->cabeca->prox = NULL;

    return lista;
}


void inserirInicio(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

void reverterLista(Lista* lista) {
    No* ant = NULL;
    No* atual = lista->cabeca->prox;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->prox; // armazena o próximo nó
        atual->prox = ant; // inverte o ponteiro
        ant = atual; // move o ponteiro anterior para frente
        atual = proximo; // move o ponteiro atual para frente
    }
    lista->cabeca->prox = ant; // atualiza a cabeça da lista
}

int obterMaior(Lista* lista) {
    No* atual = lista->cabeca->prox;
    int maior = atual->dado;
    if (lista->cabeca->prox == NULL) {
        printf("Lista vazia.\n");
        return -1; // Ou qualquer valor sentinela
    }

    while (atual != NULL) {
        if (atual->dado > maior) {
            maior = atual->dado;
        }
        atual = atual->prox;
    }
    return maior;
}

int obterMenor(Lista* lista) {
    No* atual = lista->cabeca->prox;
    int menor = atual->dado;
    if (lista->cabeca->prox == NULL) {
        printf("Lista vazia.\n");
        return -1; // Ou qualquer valor sentinela
    }

    while (atual != NULL) {
        if (atual->dado < menor) {
            menor = atual->dado;
        }
        atual = atual->prox;
    }
    return menor;
}

int estaVazia(Lista* lista) {
    if (lista->cabeca->prox == 0) return 1;
    else return 0;
}

Lista* copiarLista(Lista* lista) {
    Lista* novaLista = criarLista();
    No* atual = lista->cabeca->prox;
    No* ultimo = novaLista->cabeca;

    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual->dado;
        novo->prox = NULL;
        ultimo->prox = novo;
        ultimo = novo;
        atual = atual->prox;
    }

    return novaLista;
}

void concatenarListas(Lista* l1, Lista* l2){
    No* atual = l1->cabeca;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = l2->cabeca->prox;
    l2->cabeca->prox = NULL;
}

void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}


int remover(Lista* lista, int valor) {
    No* ant = lista->cabeca;
    No* atual = ant->prox;

    while (atual != NULL && atual->dado != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0; // não encontrado
    ant->prox = atual->prox;
    free(atual);
    return 1; // removido com sucesso
}


void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}