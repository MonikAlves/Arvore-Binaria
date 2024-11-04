#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "print.h"

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

int busca(Arvore* arvore, int valor){
    if (arvore == NULL) return -1;
    int passos = 0;

    if (valor < arvore->valor)
        passos = busca(arvore->esquerda, valor);
    else if(valor > arvore->valor)
        passos = busca(arvore->direita, valor);

    if(passos == -1) return passos;
    else return passos + 1;

}

Arvore* valorMinimo(Arvore* arvore) {
    Arvore* atual = arvore;

    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}

Arvore * remover(Arvore* arvore, int valor) {
    if (arvore == NULL) return arvore;

    if (valor < arvore->valor)
        arvore->esquerda = remover(arvore->esquerda, valor);
    else if (valor > arvore->valor)
        arvore->direita = remover(arvore->direita, valor);
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
        arvore->direita = remover(arvore->direita, temp->valor);
    }
    return arvore;
}

void liberarArvore(Arvore* arvore) {
    if (arvore == NULL) return;
    
    liberarArvore(arvore->esquerda);
    liberarArvore(arvore->direita);
    
    free(arvore);
}
