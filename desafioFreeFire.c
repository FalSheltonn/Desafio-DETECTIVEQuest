#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

/*
   Struct Item:
   Representa um objeto do inventário do jogador,
   contendo nome, tipo e quantidade.
*/
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

/*
    Função: inserirItem
    Objetivo: cadastrar um novo item no inventário.
*/
void inserirItem(Item inventario[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nInventario cheio! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n=== Cadastro de Item ===\n");
    
    printf("Nome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item (arma, municao, cura...): ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    inventario[*total] = novo;
    (*total)++;

    printf("\nItem cadastrado com sucesso!\n");
}

/*
   Função: listarItens
   Objetivo: exibir todos os itens cadastrados.
*/
void listarItens(Item inventario[], int total) {
    printf("\n=== Itens na Mochila ===\n");

    if (total == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("[%d] Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1,
               inventario[i].nome,
               inventario[i].tipo,
               inventario[i].quantidade);
    }
}

/*
    Função: buscarItem
    Objetivo: localizar um item pelo nome usando busca sequencial.
*/
void buscarItem(Item inventario[], int total) {
    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < total; i++) {
        if (strcmp(inventario[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   inventario[i].nome,
                   inventario[i].tipo,
                   inventario[i].quantidade);
            return;
        }
    }

    printf("\nItem nao encontrado.\n");
}

/*
    Função: removerItem
    Objetivo: excluir um item pelo nome e reorganizar o vetor.
*/
void removerItem(Item inventario[], int *total) {
    if (*total == 0) {
        printf("\nInventario vazio! Nada a remover.\n");
        return;
    }

    char nomeRemove[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeRemove);

    for (int i = 0; i < *total; i++) {
        if (strcmp(inventario[i].nome, nomeRemove) == 0) {

            // Deslocamento dos itens
            for (int j = i; j < *total - 1; j++) {
                inventario[j] = inventario[j + 1];
            }

            (*total)--;

            printf("\nItem removido com sucesso!\n");
            return;
        }
    }

    printf("\nItem nao encontrado.\n");
}

/*
    Função principal: exibe menu e controla o fluxo do programa.
*/
int main() {
    Item inventario[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n=====================\n");
        printf(" Inventario do Jogador\n");
        printf("=====================\n");
        printf("1 - Cadastrar Item\n");
        printf("2 - Remover Item\n");
        printf("3 - Listar Itens\n");
        printf("4 - Buscar Item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(inventario, &totalItens);
                break;
            case 2:
                removerItem(inventario, &totalItens);
                break;
            case 3:
                listarItens(inventario, totalItens);
                break;
            case 4:
                buscarItem(inventario, totalItens);
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}