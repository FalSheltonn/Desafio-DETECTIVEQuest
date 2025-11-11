#include <stdio.h>
#include <string.h>

/*
   Struct Territorio:
   Representa um território com nome, cor do exército e quantidade de tropas.
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor que armazena 5 territórios
    Territorio territorios[5];

    printf("========================================\n");
    printf("      Sistema de Cadastro de Territorios\n");
    printf("========================================\n\n");

    // Cadastro dos 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do territorio %d:\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf("%s", territorios[i].nome);

        printf("Digite a cor do exercito: ");
        scanf("%s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("----------------------------------------\n");
    }

    // Exibição dos dados cadastrados
    printf("\n========== TERRITORIOS CADASTRADOS ==========\n");

    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf(" Nome: %s\n", territorios[i].nome);
        printf(" Cor do exercito: %s\n", territorios[i].cor);
        printf(" Tropas: %d\n", territorios[i].tropas);
        printf("--------------------------------------------\n");
    }

    return 0;
}