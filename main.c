#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "printar.h"
void menu(Arvore* arvore) {
    int opcao, valor;

    while (1) {
        if (arvore == NULL) {
            limparTerminal();
            printf("Nenhuma árvore criada ainda. Por favor, crie uma nova árvore\n");
            opcao = 5;
        }else{
            exibirMenu();   
            imprimirArvore(arvore);
            printf("\n\nEscolha uma opção: ");
            scanf("%d", &opcao);
        }

        switch (opcao) {
            case 1:  // Adicionar vértice
                if (arvore == NULL) {
                    printf("Por favor, crie uma árvore primeiro (opção 4).\n");
                } else {
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    arvore = inserir(arvore, valor);
                }
                break;

            case 2:  // Retirar vértice
                if (arvore == NULL) {
                    printf("Nenhuma árvore criada ainda.\n");
                } else {
                    printf("Digite o valor a ser removido: ");
                    scanf("%d", &valor);
                    arvore = removerArvore(arvore, valor);
                }
                break;

            case 3:  // Apagar toda a árvore
                if (arvore == NULL) {
                    printf("Nenhuma árvore criada ainda.\n");
                } else {
                    char confirmar;
                    printf("Tem certeza que deseja apagar a árvore?\nDigite S para sim e N para não\n>> ");
                    scanf(" %c%*c",&confirmar);

                    if(confirmar == 'N' || confirmar == 'n') break;

                    liberarArvore(arvore);
                    arvore = NULL;
                    printf("Árvore apagada com sucesso!\n");
                }
                break;

            case 5: 
                char *aux = (char*) malloc(10000 * sizeof(char));
                printf("Digite os valores da árvore (pressione Enter para finalizar):\n");

                    printf(">> ");
                    scanf("%[^\n]%*c", aux);

                    char *valores = (char*) malloc(strlen(aux) * sizeof(char));

                    strcpy(valores,aux);    
                    free(aux);

                    processarValores(valores,&arvore);
                    free(valores);

                break;

            case 4:  // Sair
                if (arvore != NULL) {
                    liberarArvore(arvore);
                }
                printf("Saindo do programa...\n");
                return;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
}

int main() {
    Arvore* arvore = NULL;
    menu(arvore);
    return 0;
}
