#include <stdio.h>
#include "trabalho1.h"

int main()
{
    Lista minhaLista;
    int posicao, elemento, resultado;

    printf("=== TESTE DO TAD LISTA COM ALOCAÇÃO ESTÁTICA SEQUENCIAL ===\n\n");

    // Inicializa a lista
    printf("Criando lista...\n");
    criar_lista(&minhaLista);
    printf("Lista criada com sucesso!\n\n");

    // Verifica se a lista está vazia
    printf("Verificando se a lista está vazia...\n");
    if (lista_vazia(&minhaLista))
    {
        printf("A lista está vazia!\n\n");
    }
    else
    {
        printf("A lista não está vazia!\n\n");
    }

    // Inserindo elementos no final da lista
    printf("Inserindo elementos no final da lista...\n");
    int elementosArr[] = {11, 24, 37, 42, 59};
    int e = sizeof(elementosArr) / sizeof(elementosArr[0]);
    for (int i = 0; i < e; i++)
    {
        inserir_elemento(&minhaLista, elementosArr[i]);
    }
    printf("Itens inseridos com sucesso!\n\n");

    // Verificar se a lista está cheia
    printf("Checando se a lista está cheia...\n");
    if (lista_cheia(&minhaLista))
    {
        printf("A lista está cheia.\n\n");
    }
    else
    {
        printf("A lista não está cheia.\n\n");
    }

    // Imprime a lista
    printf("Imprimindo lista...\n");
    imprimir_lista(&minhaLista);
    printf("\nLista impressa!\n\n");

    // Contagem de elementos
    printf("Calculando tamanho da lista...\n");
    printf("%d\n", tamanho_lista(&minhaLista));
    printf("Tamanho calculado!\n\n");

    // Localização de elemento
    printf("Localizando elementos na lista...\n");
    int valoresProcurados[] = {42, 60};
    int v = sizeof(valoresProcurados) / sizeof(valoresProcurados[0]);

    for (int i = 0; i < v; i++)
    {
        elemento = valoresProcurados[i];
        posicao = localizar_elemento(&minhaLista, elemento);
        printf("Elemento %d: ", elemento);
        if (posicao != -1)
        {
            printf("Elemento %d na posição %d\n", elemento, posicao);
        }
        else
        {
            printf("O elemento %d não foi encontrado na lista\n", elemento);
        }
    }
    printf("\n");

    // Acessar elemento por posição
    printf("Acessando elementos por posição na lista...\n");
    int posicoes[] = {2, 7};
    int p = sizeof(posicoes) / sizeof(posicoes[0]);

    for (int i = 0; i < p; i++)
    {
        posicao = posicoes[i];
        printf("Posição %d: ", posicao);
        if (acessar_elemento(&minhaLista, posicao, &elemento))
        {
            printf("Posição %d contém elemento %d\n", posicao, elemento);
        }
        else
        {
            printf("Não existe elemento na posição %d\n", posicao);
        }
    }
    printf("\n");

    // Inserir elemento em posição específica
    printf("Inserindo o elemento 25 na posição 2...\n");
    inserir_elemento_posicao(&minhaLista, 25, 2);
    printf("Inserido com sucesso!\n");
    imprimir_lista(&minhaLista);
    printf("\n\n");

    // Remover elemento por valor
    printf("Removendo o elemento 24...\n");
    resultado = remover_elemento(&minhaLista, 24);
    if (resultado)
    {
        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("Falha ao remover o elemento!\n");
    }
    imprimir_lista(&minhaLista);
    printf("\n\n");

    // Remover elemento por posição
    printf("Removendo o elemento na posição 3...\n");
    resultado = remover_elemento_posicao(&minhaLista, 3);
    if (resultado)
    {
        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("Falha ao remover o elemento!\n");
    }
    imprimir_lista(&minhaLista);
    printf("\n");

    printf("\n=== FIM DO TESTE ===\n");

    return 0;
}
