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
        scanf("%s", territorio[i].nome);

        printf("Digite a cor do exercito: \n");
        scanf("%s", territorio[i].cor);

        printf("Digite o numero de tropas: \n");
        scanf("%d", &territorio[i].tropas);

        printf("\n");
    }

    // Exibir os dados cadastrados

    printf("====================================\n");
    printf("----- Lista dos Territórios -----\n");
    printf("====================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {
        printf("Território %d\n:", i + 1);
        printf("Nome: %s\n", territorio[i].nome);
        printf("Nome: %s\n", territorio[i].cor);
        printf("Nome: %d\n", territorio[i].tropas);
        printf("====================================\n");

        printf("\n");
    }

    return 0;
}