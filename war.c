#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    Territorio *territorio = NULL;
    int numTerritorios = 0;
    int i, opcao;

    do
    {
        // Menu de opções
        printf("\n=== WAR ===\n");
        printf("1 - Definir quantidade e cadastrar territórios\n");
        printf("2 - Listar territórios cadastrados\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1: // Liberar memória anterior se existir
            if (territorio != NULL)
            {
                free(territorio);
            }

            printf("\nDigite a quantidade de itens para cadastrar: ");
            scanf("%d", &numTerritorios);
            limparBuffer();

            territorio = (Territorio *)malloc(numTerritorios * sizeof(Territorio));

            if (territorio == NULL)
            {
                printf("Erro na alocação de memória!\n");
                return 1;
            }
            // Cadastrar territórios
            for (i = 0; i < numTerritorios; i++)
            {
                printf("\n----- Território %d -----\n", i + 1);

                printf("Digite o nome: ");
                fgets(territorio[i].nome, 30, stdin);
                removerQuebraLinha(territorio[i].nome);
                printf("Digite a cor: ");
                fgets(territorio[i].cor, 10, stdin);
                removerQuebraLinha(territorio[i].cor);

                printf("Digite o número de tropas: ");
                scanf("%d", &territorio[i].tropas);
                limparBuffer();
            }

            printf("\n%d territórios cadastrados com sucesso!\n", numTerritorios);
            break;

        case 2:

            if (territorio == NULL || numTerritorios == 0)
            {
                printf("\nNenhum território cadastrado!\n");
            }
            else
            {
                printf("----- Lista dos Territórios -----\n");

                for (int i = 0; i < numTerritorios; i++)
                {
                    printf("Território %d:\n", i + 1);
                    printf("Nome: %s\n", territorio[i].nome);
                    printf("Cor: %s\n", territorio[i].cor);
                    printf("Tropas: %d\n", territorio[i].tropas);
                    printf("====================================\n");
                }
            }
            break;

        case 0:

            printf("\nSaindo do sistema...\n");
            break;

        default:

            printf("\n Opção inválida! Tente novamente.\n");
            break;
        }

        // Pausa para o usuário ler as mensagens (exceto ao sair)
        if (opcao != 0)
        {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcao != 0);

    // Liberar memória
    if (territorio != NULL)
    {
        free(territorio);
    }

    return 0;
}