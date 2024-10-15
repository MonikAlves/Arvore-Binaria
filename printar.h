#include "arvore.h"
#ifndef __PRINTAR_H__
#define __PRINTAR_H__

typedef struct asciinode {
    struct asciinode * esquerda, * direita;
    int edge_length;  // comprimento da aresta
    int height;       // altura do nó
    int lablen;       // comprimento do label
    int parent_dir;   // -1 = esquerda, 1 = direita, 0 = raiz
    char label[11];   // valor do nó convertido em string
} asciinode;

void limparTerminal();
void exibirMenu();
void print_level(asciinode *nodo, int x, int nivel);
void compute_lprofile(asciinode *nodo, int x, int y);
void compute_rprofile(asciinode *nodo, int x, int y);
void compute_edge_lengths(asciinode *nodo);
asciinode * build_ascii_tree_recursive(Arvore * t);
asciinode * build_ascii_tree(Arvore * t);
void free_ascii_tree(asciinode *nodo);
void imprimirArvore(Arvore* root);


#endif