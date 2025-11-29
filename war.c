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

    Territorio *territorios = NULL; // Ponteiro para array dinâmico de territórios
    int totalTerritorios = 0;       // Contador do número total de territórios
    int opcao, i;                   // opcao: escolha do menu; i: variável de controle dos loops

    // Definir a quantidade de territórios
    printf("-=-=-=- CADASTRO DE TERRITÓRIOS -=-=-=-\n");
    printf("Digite a quantidade: ");
    scanf("%d", &totalTerritorios);
    limparBufferEntrada();

    territorios = (Territorio *)malloc(totalTerritorios * sizeof(Territorio));

    // Verificação de erro na alocação de memória
    if (territorios == NULL)
    {
        printf("Erro na alocação de memória!\n");
        liberarMemoria(territorios);
        return 1;
    }
    else if (totalTerritorios < 2) // Verifição de quantidade minima de territórios para o cadastro
    {
        printf("Quantidade de territórios insuficiente! São necessários pelo menos 2 territórios.\n");
    }
    else // Cadastro de territórios
    {
        for (i = 0; i < totalTerritorios; i++)
        {
            printf("\n-=-=-=- TERRITÓRIO %d -=-=-=-\n", i + 1);

            printf("Digite o nome: ");
            fgets(territorios[i].nome, 30, stdin);
            removerQuebraLinha(territorios[i].nome);

            printf("Digite a cor: ");
            fgets(territorios[i].cor, 10, stdin);
            removerQuebraLinha(territorios[i].cor);

            printf("Digite a quantidade de tropas: ");
            scanf("%d", &territorios[i].tropas);
            limparBufferEntrada();
        }
    }

    //

    return 0;
}