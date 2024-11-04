#ifndef __ARVORE_H__
#define __ARVORE_H__

typedef struct arvore {
    int valor;
    struct arvore* esquerda;
    struct arvore* direita;
} Arvore;

Arvore* novaArvore(int valor);
Arvore* inserir(Arvore* arvore, int valor);
int busca(Arvore* arvore, int valor);
Arvore* remover(Arvore* arvore, int valor);
void liberarArvore(Arvore* arvore); 

#endif