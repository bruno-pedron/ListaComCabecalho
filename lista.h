#ifndef LISTA_H

#define LISTA_H


typedef struct No {

int dado;

struct No* prox;

} No;


typedef struct {

No* cabeca; // Nó de cabeçalho

} Lista;


Lista* criarLista();

//insere um valor no início da lista
void inserirInicio(Lista* lista, int valor);

//inverte a ordem dos elementos da lista
void reverterLista(Lista* lista);

void imprimirLista(Lista* lista);

//remove um valor espeçífico da lista
int remover(Lista* lista, int valor);

//percorre a lista e retorna o maior valor armazenado
int obterMaior(Lista* lista);

//percorre a lista e retorna o menor valor armazenado
int obterMenor(Lista* lista);

int estaVazia(Lista* lista);

//cria uma cópia profunda da lista
Lista* copiarLista(Lista* lista);

void concatenarListas(Lista* l1, Lista* l2);

void liberarLista(Lista* lista);


#endif