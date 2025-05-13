#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrarMenu() {
    printf("\n====== MENU - Lista com Cabeçalho ======\n");
    printf("1. Inserir no início\n");
    printf("2. Reverter lista\n");
    printf("3. Remover valor\n");
    printf("4. Imprimir lista\n");
    printf("5. Obter maior elemento\n"); 
    printf("6. Obter menor elemento\n");
    printf("7. Concatenar listas\n"); 
    printf("8. Copiar lista\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Lista* lista = criarLista();
    int opcao, valor, resultado;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o valor a inserir no início: ");
            scanf("%d", &valor);
            inserirInicio(lista, valor);
            break;

        case 2:
            reverterLista(lista);
            printf("Lista revertida com sucesso.\n");
            break;

        case 3:
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            resultado = remover(lista, valor);
            if (resultado)
                printf("Valor removido com sucesso.\n");
            else
                printf("Valor não encontrado.\n");
            break;

        case 4:
            printf("Conteúdo da lista:\n");
            imprimirLista(lista);
            break;

        case 5:
            if (estaVazia(lista))
                printf("A lista está vazia.\n");
            else
                printf("O maior elemento é: %d\n", obterMaior(lista));
            break;

        case 6:
            if (estaVazia(lista))
                printf("A lista está vazia.\n");
            else
                printf("O menor elemento é: %d\n", obterMenor(lista));
            break;

        case 7: {
            Lista* l2 = criarLista();
            int qtd, val;
            printf("Quantos elementos deseja inserir na nova lista a ser concatenada? ");
            scanf("%d", &qtd);
            for (int i = 0; i < qtd; i++) {
                printf("Digite o valor %d: ", i + 1);
                scanf("%d", &val);
                inserirInicio(l2, val);
            }
            concatenarListas(lista, l2);
            printf("Listas concatenadas com sucesso.\n");
            break;
        }

        case 8: {
            if (estaVazia(lista)) {
                printf("A lista está vazia. Nada para copiar.\n");
                break;
            }
            Lista* copia = copiarLista(lista);
            printf("Lista copiada:\n");
            imprimirLista(copia);
            liberarLista(copia);
            break;
        }

        case 0:
            liberarLista(lista);
            printf("Encerrando programa.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}