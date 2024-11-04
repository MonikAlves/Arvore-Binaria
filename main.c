#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "print.h"

void menu(Arvore* arvore) {
    int opcao;
    char valor[10000];
    int numero,passos = -2;

    while (1) {
        if (arvore == NULL) {
            limparTerminal();
            printf("Nenhuma árvore criada ainda. Por favor, crie uma nova árvore\n");
            opcao = 6;
        }else{
            exibirMenu();   
            if(passos != -2){
                if(passos == -1) printf("O numero %d não esta na arvore\n\n",numero);
                else printf("Para achar o numero %d foi necessario %d passos\n\n",numero,passos);
                passos = -2;
            }
            imprimirArvore(arvore);
            printf("\n\nEscolha uma opção: ");
            scanf("%d%*c", &opcao);
        }

        switch (opcao) {
            case 1:  // Adicionar vértice
                printf("Digite os valores a serem inseridos:\n>> ");
                while (1){
                    scanf("%s",valor);
                    if (!strcmp(valor,"!")) break;
                    arvore = inserir(arvore,atoi(valor));
                }
                break;
            case 2:  // Remover vértice
                printf("Digite os valores a serem inseridos:\n>> ");
                while (1){
                    scanf("%s",valor);
                    if (!strcmp(valor,"!")) break;
                    arvore = remover(arvore,atoi(valor));
                }
                break;
                
            case 3:  // Buscar vértice
                printf("Digite o numero a ser procurado:\n>> ");
                scanf("%d%*c",&numero);
                passos = busca(arvore,numero);

                break;

            case 4:  // Apagar toda a árvore
                if (arvore == NULL) {
                    printf("Nenhuma árvore criada ainda.\n");
                } else {
                    char confirmar;
                    printf("Tem certeza que deseja apagar a árvore atual?\nDigite S para sim e N para não\n>> ");
                    scanf(" %c%*c",&confirmar);

                    if(confirmar == 'N' || confirmar == 'n') break;

                    liberarArvore(arvore);
                    arvore = NULL;
                    printf("Árvore apagada com sucesso!\n");
                }
                break;

            case 5:  // Sair

                if (arvore != NULL) {
                    liberarArvore(arvore);
                }
                printf("Saindo do programa...\n");
                return;

            case 6: 

                printf("Digite os valores a serem inseridos:\n>> ");
                while (1){
                    scanf("%s",valor);
                    if (!strcmp(valor,"!")) break;
                    arvore = inserir(arvore,atoi(valor));
                }

                break;


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
