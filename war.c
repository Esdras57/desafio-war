#include <stdio.h>
#include <string.h>

// Constante Global

#define MAX_TERRITORIOS 5

// Estrutura (struct)
struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

// Limpar Buffer de entrada

void limpaBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    struct Territorio territorio[MAX_TERRITORIOS];

    // Entrada de dados dos Territorios

    printf("====================================\n");
    printf("----- Cadastro dos Territórios -----\n");
    printf("====================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {

        printf("----- Território %d -----\n", i + 1);

        printf("Digite o nome do território: \n");
        fgets(territorio[i].nome, 20, stdin);

        printf("Digite a cor do exercito: \n");
        fgets(territorio[i].cor, 10, stdin);

        // Remover quebra de linha
        territorio[i].nome[strcspn(territorio[i].nome, "\n")] = '\0';
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = '\0';

        printf("Digite o numero de tropas: \n");
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

        printf("\n");
    }

    return 0;
}