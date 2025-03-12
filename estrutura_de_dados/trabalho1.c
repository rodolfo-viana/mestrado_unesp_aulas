#include <stdio.h>
#include "trabalho1.h"

// Inicializa uma lista vazia
void criar_lista(Lista *l)
{
    if (l == NULL)
        return;
    l->tamanho = 0;
}

// Verifica se a lista está vazia
int lista_vazia(Lista *l)
{
    if (l == NULL)
        return 1; // Considera vazia se o ponteiro for nulo
    return (l->tamanho == 0);
}

// Verifica se a lista está cheia
int lista_cheia(Lista *l)
{
    if (l == NULL)
        return 0; // Se l for nulo, não pode estar cheia
    return (l->tamanho == MAX);
}

// Retorna o número de elementos na lista
int tamanho_lista(Lista *l)
{
    if (l == NULL)
        return 0;
    return l->tamanho;
}

// Localiza um elemento e retorna sua posição (-1 se não encontrar)
int localizar_elemento(Lista *l, TipoItem item)
{
    if (l == NULL)
        return -1;
    for (int i = 0; i < l->tamanho; i++)
    {
        if (l->itens[i] == item)
        {
            return i;
        }
    }
    return -1;
}

// Acessa o elemento na posição especificada
// Retorna 1 se a operação for bem-sucedida e 0 caso contrário.
int acessar_elemento(Lista *l, int posicao, TipoItem *elemento)
{
    if (l == NULL || elemento == NULL)
        return 0;
    if (posicao < 0 || posicao >= l->tamanho)
        return 0;
    *elemento = l->itens[posicao];
    return 1;
}

// Insere um elemento no final da lista
int inserir_elemento(Lista *l, TipoItem item)
{
    if (l == NULL)
        return 0;

    if (lista_cheia(l))
    {
        return 0;
    }

    l->itens[l->tamanho] = item;
    l->tamanho++;
    return 1;
}

// Insere um elemento em uma posição específica
int inserir_elemento_posicao(Lista *l, TipoItem item, int posicao)
{
    if (l == NULL)
        return 0;

    if (lista_cheia(l))
    {
        return 0;
    }

    if (posicao < 0 || posicao > l->tamanho)
    {
        return 0;
    }

    for (int i = l->tamanho; i > posicao; i--)
    {
        l->itens[i] = l->itens[i - 1];
    }

    l->itens[posicao] = item;
    l->tamanho++;
    return 1;
}

// Remove um elemento pelo valor (primeira ocorrência)
int remover_elemento(Lista *l, TipoItem item)
{
    if (l == NULL)
        return 0;
    int pos = localizar_elemento(l, item);
    if (pos == -1)
    {
        return 0;
    }
    return remover_elemento_posicao(l, pos);
}

// Remove um elemento pela posição
int remover_elemento_posicao(Lista *l, int posicao)
{
    if (l == NULL)
        return 0;
    if (lista_vazia(l))
    {
        return 0;
    }
    if (posicao < 0 || posicao >= l->tamanho)
    {
        return 0;
    }

    for (int i = posicao; i < l->tamanho - 1; i++)
    {
        l->itens[i] = l->itens[i + 1];
    }
    l->tamanho--;
    return 1;
}

// Imprime todos os elementos da lista
void imprimir_lista(Lista *l)
{
    if (l == NULL)
        return;
    if (lista_vazia(l))
    {
        return;
    }
    for (int i = 0; i < l->tamanho; i++)
    {
        printf("%d ", l->itens[i]);
    }
}
