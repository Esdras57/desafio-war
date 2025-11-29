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

// Função para simular ataque

void atacar(Territorio *atacante, Territorio *defensor)
{
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("Dados:\n");
    printf("Atacante tirou %d, Defensor tirou %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) // Vitória do território atacante
    {
        printf("Atacante venceu!\n");
        printf("Exército %s conquistou %s!\n", atacante->cor, defensor->nome);

        strcpy(defensor->cor, atacante->cor); // Alterar a cor do território conquistado

        // Transferência de tropas
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;

        printf("Tropas transferidas: %d\n", tropasTransferidas);
    }
    else // Vitória do território defensor
    {
        printf("Defensor venceu!\n");
        atacante->tropas--;
        printf("%s perdeu 1 tropa\n", atacante->nome);
    }
}

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

        // Menu
        do
        {
            printf("\n-=-=-=- WAR -=-=-=-\n");
            printf("1 - Mostrar territórios\n");
            printf("2 - Iniciar ataque\n");
            printf("0 - Sair\n");

            printf("Escolha uma opção: ");
            scanf("%d", opcao);
            limparBufferEntrada();

            switch (opcao)
            {
            case 1: // Lista de territórios
                for (i = 0; i < totalTerritorios; i++)
                {
                    printf("%d. %s (Exército %s, Tropas: %d)\n", i + 1, territorios[i].nome, territorios[i].cor, territorios[i].cor);
                }
                break;

            case 2: // Fase de ataque
                for (i = 0; i < totalTerritorios; i++)
                {
                    printf("%d. %s (Exército %s, Tropas: %d)\n", i + 1, territorios[i].nome, territorios[i].cor, territorios[i].cor);
                }

                int atacante, defensor;

                printf("Escolha o território atacante (1 a %d, ou 0 para sair): ", totalTerritorios);
                scanf("%d", &atacante);
                limparBufferEntrada();

                printf("Escolha o território defensor (1 a %d, para sair): ", totalTerritorios);
                scanf("%d", &defensor);
                limparBufferEntrada();

                // Validações
                if (atacante == 0 || defensor == 0)
                {
                    printf("Saindo...\n");
                    break;
                }
                else if (atacante == defensor)
                {
                    printf("Não é possível atacar o próprio território!\n");
                    break;
                }
                else if (territorios[atacante - 1].tropas < 2)
                {
                    printf("Território atacante precisa ter pelo menos 2 tropas!\n");
                    break;
                }
                else if (strcmp(territorios[atacante - 1].cor, territorios[defensor - 1].cor) == 0)
                {
                    printf("Não é possível atacar territórios do mesmo exército!\n");
                    break;
                }
                else
                {
                    printf("\n-=-=-=- ATAQUE -=-=-=-");
                    printf("Atacante: %s (%s) - %d tropas\n", territorios[atacante - 1].nome, territorios[atacante - 1].cor, territorios[atacante - 1].tropas);
                    printf("Defensor: %s (%s) - %d tropas\n", territorios[defensor - 1].nome, territorios[defensor - 1].nome, territorios[defensor - 1].tropas);

                    atacar(&territorios[atacante - 1], &territorios[defensor - 1]);
                }
                break;
            }
        } while (opcao != 0);

        return 0;
    }
}