#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------
//  STRUCT DA SALA (NÓ DA ÁRVORE BINÁRIA)
//---------------------------------------------
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

//---------------------------------------------
//  Função: criarSala
//  Objetivo: alocar dinamicamente uma sala
//---------------------------------------------
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

//---------------------------------------------
//  Função: explorarSalas
//  Objetivo: permitir ao jogador navegar pela
//            árvore binária interativamente.
//---------------------------------------------
void explorarSalas(Sala *atual) {
    
    while (atual != NULL) {
        printf("\nVocê está agora em: ** %s **\n", atual->nome);

        // Se a sala não tem caminhos, acabou a exploração
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("\n🚪 Você chegou ao fim deste caminho da mansão.\n");
            return;
        }

        printf("\nEscolha o caminho:\n");
        if (atual->esq != NULL) printf("  (e) Ir para a esquerda -> %s\n", atual->esq->nome);
        if (atual->dir != NULL) printf("  (d) Ir para a direita  -> %s\n", atual->dir->nome);
        printf("  (s) Sair da exploração\n");
        printf("\nDigite sua opção: ");

        char opcao;
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        } else if (opcao == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        } else if (opcao == 's') {
            printf("\n👋 Você decidiu sair da mansão.\n");
            return;
        } else {
            printf("\n⚠️  Caminho inválido. Tente novamente.\n");
        }
    }
}

//---------------------------------------------
//  Função principal: monta o mapa da mansão
//  e inicia a exploração.
//---------------------------------------------
int main() {
    // Criando a árvore binária fixa da mansão
    Sala *hall = criarSala("Hall de Entrada");

    hall->esq = criarSala("Sala de Estar");
    hall->dir = criarSala("Cozinha");

    hall->esq->esq = criarSala("Biblioteca");
    hall->esq->dir = criarSala("Jardim");

    hall->dir->esq = criarSala("Despensa");
    hall->dir->dir = criarSala("Porão");

    printf("=====================================\n");
    printf(" 🔎 Detective Quest – Exploração da Mansão\n");
    printf("=====================================\n");
    
    explorarSalas(hall);

    printf("\nFim da exploração. Obrigado por jogar!\n");

    return 0;
}