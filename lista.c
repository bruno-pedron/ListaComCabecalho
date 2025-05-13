#include <stdio.h>

#include <stdlib.h>

#include "lista.h"


// Função para criar uma nova lista com nó de cabeçalho
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho
    lista->cabeca->prox = NULL; // inicializa a lista como vazia

    return lista;
}

// Função para inserir um elemento no início da lista
void inserirInicio(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->dado = valor; // atribui o valor ao nó
    novo->prox = lista->cabeca->prox; // aponta para o primeiro nó atual
    lista->cabeca->prox = novo; // atualiza o ponteiro do nó de cabeçalho
}

// Função para reverter a ordem dos elementos da lista
void reverterLista(Lista* lista) {
    No* ant = NULL; // ponteiro para o nó anterior
    No* atual = lista->cabeca->prox; // ponteiro para o nó atual
    No* proximo;

    while (atual != NULL) {
        proximo = atual->prox; // armazena o próximo nó
        atual->prox = ant; // inverte o ponteiro do nó atual
        ant = atual; // move o ponteiro anterior para frente
        atual = proximo; // move o ponteiro atual para frente
    }
    lista->cabeca->prox = ant; // atualiza o início da lista
}

// Função para obter o maior valor presente na lista
int obterMaior(Lista* lista) {
    No* atual = lista->cabeca->prox;
    if (atual == NULL) { // verifica se a lista está vazia
        printf("Lista vazia.\n");
        return -1; // retorna um valor sentinela
    }

    int maior = atual->dado; // inicializa com o primeiro valor
    while (atual != NULL) {
        if (atual->dado > maior) { // verifica se o valor atual é maior
            maior = atual->dado;
        }
        atual = atual->prox; // avança para o próximo nó
    }
    return maior;
}

// Função para obter o menor valor presente na lista
int obterMenor(Lista* lista) {
    No* atual = lista->cabeca->prox;
    if (atual == NULL) { // verifica se a lista está vazia
        printf("Lista vazia.\n");
        return -1; // retorna um valor sentinela
    }

    int menor = atual->dado; // inicializa com o primeiro valor
    while (atual != NULL) {
        if (atual->dado < menor) { // verifica se o valor atual é menor
            menor = atual->dado;
        }
        atual = atual->prox; // avança para o próximo nó
    }
    return menor;
}

// Função para verificar se a lista está vazia
int estaVazia(Lista* lista) {
    return lista->cabeca->prox == NULL; // retorna 1 se vazia, 0 caso contrário
}

// Função para criar uma cópia da lista
Lista* copiarLista(Lista* lista) {
    Lista* novaLista = criarLista(); // cria uma nova lista
    No* atual = lista->cabeca->prox; // ponteiro para percorrer a lista original
    No* ultimo = novaLista->cabeca; // ponteiro para o último nó da nova lista

    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No)); // cria um novo nó
        novo->dado = atual->dado; // copia o valor
        novo->prox = NULL; // inicializa o próximo como NULL
        ultimo->prox = novo; // adiciona o novo nó ao final da nova lista
        ultimo = novo; // atualiza o ponteiro do último nó
        atual = atual->prox; // avança para o próximo nó da lista original
    }

    return novaLista;
}

// Função para concatenar duas listas
void concatenarListas(Lista* l1, Lista* l2) {
    No* atual = l1->cabeca;

    // Percorre até o final da primeira lista
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Conecta o final da primeira lista ao início da segunda
    atual->prox = l2->cabeca->prox;
    l2->cabeca->prox = NULL; // esvazia a segunda lista
}

// Função para imprimir os elementos da lista
void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        printf("%d -> ", atual->dado); // imprime o valor do nó
        atual = atual->prox; // avança para o próximo nó
    }
    printf("NULL\n"); // indica o final da lista
}

// Função para remover um elemento da lista
int remover(Lista* lista, int valor) {
    No* ant = lista->cabeca; // ponteiro para o nó anterior
    No* atual = ant->prox; // ponteiro para o nó atual

    // Procura o nó com o valor especificado
    while (atual != NULL && atual->dado != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0; // valor não encontrado
    ant->prox = atual->prox; // remove o nó da lista
    free(atual); // libera a memória do nó removido
    return 1; // indica que o valor foi removido com sucesso
}

// Função para liberar toda a memória alocada pela lista
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual; // armazena o nó atual
        atual = atual->prox; // avança para o próximo nó
        free(temp); // libera a memória do nó atual
    }
    free(lista); // libera a memória da estrutura da lista
}