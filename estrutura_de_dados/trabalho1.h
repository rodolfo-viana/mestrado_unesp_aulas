#ifndef LISTA_H
#define LISTA_H

// Tamanho máximo da lista
#define MAX 100

// Tipo de dado armazenado na lista
typedef int TipoItem;

// Estrutura da lista
typedef struct {
    TipoItem itens[MAX];
    int tamanho;
} Lista;

// Inicializa uma lista vazia
void criar_lista(Lista *l);

// Verifica se a lista está vazia
int lista_vazia(Lista *l);

// Verifica se a lista está cheia
int lista_cheia(Lista *l);

// Retorna o número de elementos na lista
int tamanho_lista(Lista *l);

// Localiza um elemento e retorna sua posição (-1 se não encontrar)
int localizar_elemento(Lista *l, TipoItem item);

// Acessa o elemento na posição especificada (posições de 0 a tamanho-1)
// Se bem-sucedido, armazena o elemento em 'elemento' e retorna 1; caso contrário, retorna 0.
int acessar_elemento(Lista *l, int posicao, TipoItem *elemento);

// Insere um elemento no final da lista
// Retorna 1 se sucesso, 0 se falha
int inserir_elemento(Lista *l, TipoItem item);

// Insere um elemento em uma posição específica
// Retorna 1 se sucesso, 0 se falha
int inserir_elemento_posicao(Lista *l, TipoItem item, int posicao);

// Remove um elemento pelo valor (primeira ocorrência)
// Retorna 1 se sucesso, 0 se falha
int remover_elemento(Lista *l, TipoItem item);

// Remove um elemento pela posição
// Retorna 1 se sucesso, 0 se falha
int remover_elemento_posicao(Lista *l, int posicao);

// Imprime todos os elementos da lista
void imprimir_lista(Lista *l);

#endif /* LISTA_H */
