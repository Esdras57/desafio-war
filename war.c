#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura dos territorios
typedef struct
{
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

// Função para remover quebra de linha
void removerQuebraLinha(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

// Função para limpar o buffer de entrada
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    Territorio *todosTerritorios = NULL; // ✅ Array para TODOS os territórios
    int totalTerritorios = 0;            // ✅ Total de territórios (todos)
    int novosCadastros = 0;              // ✅ Quantos cadastrar agora
    int i, opcao;

    do
    {
        // Menu de opções
        printf("\n=== WAR ===\n");
        printf("1 - Definir quantidade e cadastrar territórios\n");
        printf("2 - Listar todos os territórios cadastrados\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            printf("\nDigite a quantidade de territórios para cadastrar: ");
            scanf("%d", &novosCadastros);
            limparBuffer();

            // ✅ Expandir o array para incluir os novos territórios
            todosTerritorios = (Territorio *)realloc(todosTerritorios,
                                                     (totalTerritorios + novosCadastros) * sizeof(Territorio));

            if (todosTerritorios == NULL)
            {
                printf("Erro na alocação de memória!\n");
                return 1;
            }

            // ✅ Cadastrar os novos territórios
            for (i = 0; i < novosCadastros; i++)
            {
                int indice = totalTerritorios + i; // Índice no array total

                printf("\n----- Território %d -----\n", indice + 1);

                printf("Digite o nome do territorio: ");
                fgets(todosTerritorios[indice].nome, 30, stdin);
                removerQuebraLinha(todosTerritorios[indice].nome);

                printf("Digite a cor do territorio: ");
                fgets(todosTerritorios[indice].cor, 20, stdin);
                removerQuebraLinha(todosTerritorios[indice].cor);

                printf("Digite o número de tropas: ");
                scanf("%d", &todosTerritorios[indice].tropas);
                limparBuffer();
            }

            totalTerritorios += novosCadastros; // ✅ Atualizar total

            if (novosCadastros == 1)
            {
                printf("\n%d território cadastrado com sucesso!\n", novosCadastros);
            }
            else
            {
                printf("\n%d territórios cadastrados com sucesso!\n", novosCadastros);
            }

            printf("Total de territórios: %d\n", totalTerritorios);
            break;

        case 2:
            if (totalTerritorios == 0)
            {
                printf("\nNenhum território cadastrado ainda!\n");
            }
            else
            {
                printf("\n----- Lista de TODOS os Territórios -----\n");

                // ✅ Mostrar TODOS os territórios
                for (int i = 0; i < totalTerritorios; i++)
                {
                    printf("Território %d:\n", i + 1);
                    printf("Nome: %s\n", todosTerritorios[i].nome);
                    printf("Cor: %s\n", todosTerritorios[i].cor);
                    printf("Tropas: %d\n", todosTerritorios[i].tropas);
                    printf("====================================\n");
                }

                printf("\nTotal: %d territórios cadastrados.\n", totalTerritorios);
            }
            break;

        case 0:
            printf("\nSaindo do sistema...\n");
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
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
    if (todosTerritorios != NULL)
    {
        free(todosTerritorios);
    }

    return 0;
}