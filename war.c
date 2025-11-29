#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do território
typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para liberar a memória

void liberarMemoria(Territorio *mapa)
{
    if (mapa != NULL)
    {
        free(mapa);
    }
}

// Função para remover a quebra de linha

void removerQuebraLinha(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

// Função para limpar o buffer de entrada

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{

    Territorio *territorio = NULL; // Ponteiro para array dinâmico de territórios
    int totalTerritorios = 0;      // Contador do número total de territórios
    int opcao, i;                  // opcao: escolha do menu; i: variável de controle dos loops

    printf("-=-=-=- CADASTRO DE TERRITÓRIOS -=-=-=-\n");
    printf("Digite a quantidade: ");
    printf("%d", &totalTerritorios);
    limparBufferEntrada();

    return 0;
}