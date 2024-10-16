#include <stdio.h>
#include <stdlib.h>
#include "printar.h"

Arvore* novaArvore(int valor) {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->valor = valor;
    arvore->esquerda = NULL;
    arvore->direita = NULL;
    return arvore;
}

Arvore* inserir(Arvore* arvore, int valor) {
    if (arvore == NULL) return novaArvore(valor);

    if (valor <= arvore->valor)
        arvore->esquerda = inserir(arvore->esquerda, valor);
    else
        arvore->direita = inserir(arvore->direita, valor);

    return arvore;
}

void processarValores(char* valores, Arvore** arvore) {
    char valor[20];
    int i = 0; 
    int j = 0;
    
    while (valores[i] != '\0') {
        if (valores[i] >= '0' && valores[i] <= '9') {

            valor[j++] = valores[i]; 

        } else if (valores[i] == ' ' || valores[i + 1] == '\0') {
            if (j > 0) { // Verifica se temos um número para processar
                valor[j] = '\0'; // Finaliza a string
                int aux = 0;

            for(int k = 0; k<j; k++){
                aux *= 10;
                aux += valor[k] - '0';
            }

            if (*arvore == NULL) {
                *arvore = novaArvore(aux);
            } else {
                inserir(*arvore, aux);
            }
        
            j = 0; 
        }
        }
        i++;
    }
     if (j > 0) {
        valor[j] = '\0';
        int aux = 0;

        for (int k = 0; k < j; k++) {
            aux *= 10;
            aux += valor[k] - '0';
        }

        if (*arvore == NULL) {
            *arvore = novaArvore(aux);
        } else {
            inserir(*arvore, aux);
        }
    }

}

Arvore* valorMinimo(Arvore* arvore) {
    Arvore* atual = arvore;

    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}

Arvore * removerArvore(Arvore* arvore, int valor) {
    if (arvore == NULL) return arvore;

    if (valor < arvore->valor)
        arvore->esquerda = removerArvore(arvore->esquerda, valor);
    else if (valor > arvore->valor)
        arvore->direita = removerArvore(arvore->direita, valor);
    else {
        if (arvore->esquerda == NULL) {
            Arvore* temp = arvore->direita;
            free(arvore);
            return temp;
        }
        else if (arvore->direita == NULL) {
            Arvore* temp = arvore->esquerda;
            free(arvore);
            return temp;
        }

        Arvore* temp = valorMinimo(arvore->direita);
        arvore->valor = temp->valor;
        arvore->direita = removerArvore(arvore->direita, temp->valor);
    }
    return arvore;
}

void liberarArvore(Arvore* arvore) {
    if (arvore == NULL) return;
    
    liberarArvore(arvore->esquerda);
    liberarArvore(arvore->direita);
    
    free(arvore);
}
