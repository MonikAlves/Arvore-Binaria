# Sistema de Árvore Binária
[Descrição](#descrição) | [Funcionalidades](#funcionalidades) | [Limitações](#limitações) | [Exemplo visual](#exemplo-visual) | [Instruções para Uso](#instruções-para-uso)

## Descrição
Este projeto implementa um sistema de árvore binária que aceita e manipula números inteiros. Ele oferece funcionalidades de adicionar, remover e apagar todos os nós da árvore, além de permitir a exibição da estrutura da árvore de forma gráfica e organizada.

## Funcionalidades
- Inserção de Números:
  - O sistema permite a inserção de números inteiros na árvore binária. Esses números são organizados de acordo com as regras da árvore binária, onde os números menores ou iguais que o nó raiz vão para a subárvore à esquerda e os maiores vão para a subárvore à direita.

- Remoção de Números
  - O usuário pode remover números específicos da árvore. O sistema cuida da reorganização da árvore para manter as propriedades da árvore binária após a remoção.

- Apagar a Árvore
  - Caso o usuário deseje, a árvore inteira pode ser apagada, removendo todos os nós e liberando a memória associada.

## Limitações
Por enqunato a árvore binária só aceita números inteiros.
Operações de inserção e remoção estão limitadas à manutenção da estrutura da árvore binária simples.
Não há suporte para inserção ou manipulação de valores não numéricos.

## Exemplo visual
<img src="imagem/exemplo.png" alt="Texto Alternativo" width="600"/>

## Instruções para Uso
1. **Compilação**: Compile o código-fonte usando um compilador C padrão.
2. **Execução**: Execute o programa e siga as instruções no console para inserir e alterar valores nas células, quando tiver a opção de adicionar uma arvore coloque os numeros separados apenas com espaçoes. Exemplo: "2 7 8 15 92"

### Como Compilar
Para compilar o programa, use o seguinte comando no terminal:
```bash
gcc main.c bibliotecas/*.c -I"bibliotecas" -o Main
```
Esse comando compila os arquivos main.c, arvore.c e printar.c e gera o executável main.

### Como Executar
Após compilar, execute o programa com o seguinte comando:

```bash
./Main
```
Isso iniciará o menu interativo, onde você poderá adicionar, remover ou apagar a árvore binária.
