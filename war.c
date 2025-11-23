#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define o número máximo de territórios no sistema:
#define MAX_TERRITORIOS 5
// define o número máximo de caracteres das strings:
#define TAM_STRING 30
// estrutura para representar um território:
struct  territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};
// Função para limpar o buffer de entrada (stdin)
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main(){
    //array estático para armazenar os territórios:
    struct territorio sistema[MAX_TERRITORIOS];
     // Contador de territórios cadastrados
    int TotalTerritorios = 0;
    int opcao;

    do{
         printf("_________________________________\n");
        printf(" TERRITÓRIOS:\n");
        printf("1 - Cadastra novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("0 - Sair\n");
        printf("__________________________________\n");
        printf("Escolha uma opção:");

        // Leitura da opção e limpeza do buffer
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                printf("**Cadastro de Novo Território**\n\n");

                if (TotalTerritorios < MAX_TERRITORIOS) {
                    // --- Leitura das strings com fgets (inclui \n) ---
                    printf("Digite o nome do Território: ");
fgets(sistema[TotalTerritorios].nome, TAM_STRING, stdin);

printf("Digite o Nome da Cor do Território: ");
fgets(sistema[TotalTerritorios].cor, TAM_STRING, stdin);

// remove \n das strings
sistema[TotalTerritorios].nome[strcspn(sistema[TotalTerritorios].nome, "\n")] = '\0';
sistema[TotalTerritorios].cor[strcspn(sistema[TotalTerritorios].cor, "\n")] = '\0';

printf("Digite a quantidade de tropas: ");
scanf("%d", &sistema[TotalTerritorios].tropas);
limparBufferEntrada(); // Limpa o buffer após o scanf

                    TotalTerritorios++;
                     printf("\nTerritório cadastrado com sucesso!\n");
                } else {
                    printf("Sistema Cheio! Não é possível cadastrar mais territórios.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 2: 
                printf("___ Lista de Territórios Cadastrados____\n\n");

                if (TotalTerritorios == 0) {
                    printf("Nenhum território cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < TotalTerritorios; i++) {
                        printf("___________________________\n");
                        //Mostra o número do território
                        printf("Território: %d\n", i + 1); 
                        printf("Nome: %s\n", sistema[i].nome); 
                        printf("Cor: %s\n", sistema[i].cor);
                        printf("Tropas: %d\n", sistema[i].tropas);
                    }
                    printf("_______________________________\n");

                    }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
                
            default:
                printf("\nOpção Inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }

    } while (opcao != 0);

    return 0;
}
