#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constante Global

#define MAX_TERRITORIOS 5

// Estrutura (struct)
typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Remover quebra de linha

void removerQuebraLinha(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

// Limpar Buffer de entrada

void limpaBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    Territorio territorio[MAX_TERRITORIOS];

    // Entrada de dados dos Territorios

    printf("====================================\n");
    printf("----- Cadastro dos Territórios -----\n");
    printf("====================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {

        printf("----- Território %d -----\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorio[i].nome, 30, stdin);
        removerQuebraLinha(territorio[i].nome);

        printf("Digite a cor do exercito: ");
        fgets(territorio[i].cor, 10, stdin);
        removerQuebraLinha(territorio[i].cor);

        printf("Digite o numero de tropas: ");
        scanf("%d", &territorio[i].tropas);
        limpaBufferEntrada();

        printf("\n");
    }

    // Exibir os dados cadastrados

    printf("====================================\n");
    printf("----- Lista dos Territórios -----\n");
    printf("====================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorio[i].nome);
        printf("Cor: %s\n", territorio[i].cor);
        printf("Tropas: %d\n", territorio[i].tropas);
        printf("====================================\n");
    }

    return 0;
}