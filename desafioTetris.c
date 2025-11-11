#include <stdio.h>
#include <stdlib.h>

#define TAM 5   // Tamanho fixo da fila

/*
   Struct Peca:
   Representa uma peça do Tetris com tipo ('I', 'O', 'T', 'L') e id único.
*/
typedef struct {
    char nome;
    int id;
} Peca;

/*
   Struct Fila:
   Representa a fila circular das peças futuras do Tetris.
*/
typedef struct {
    Peca itens[TAM];
    int inicio;
    int fim;
    int quantidade;
} Fila;


/*
   gera um caractere de peça aleatório: I, O, T ou L.
*/
char gerarTipoPeca() {
    char tipos[4] = {'I', 'O', 'T', 'L'};
    return tipos[rand() % 4];
}

/*
   Gera automaticamente uma Peca com tipo e id únicos.
*/
Peca gerarPeca(int id) {
    Peca p;
    p.nome = gerarTipoPeca();
    p.id = id;
    return p;
}

/*
   Inicializa a fila circular.
*/
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

/*
   Verifica se a fila está cheia.
*/
int filaCheia(Fila *f) {
    return f->quantidade == TAM;
}

/*
   Verifica se a fila está vazia.
*/
int filaVazia(Fila *f) {
    return f->quantidade == 0;
}

/*
   Insere uma nova peça no final da fila (enqueue).
*/
void enqueue(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Nao e possivel inserir nova peca.\n");
        return;
    }

    f->fim = (f->fim + 1) % TAM;
    f->itens[f->fim] = p;
    f->quantidade++;

    printf("Peca [%c %d] inserida com sucesso!\n", p.nome, p.id);
}

/*
   Remove a peça da frente da fila (dequeue).
*/
void dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nao ha peca para jogar.\n");
        return;
    }

    Peca removida = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->quantidade--;

    printf("Peca jogada: [%c %d]\n", removida.nome, removida.id);
}

/*
   Exibe o estado atual da fila.
*/
void exibirFila(Fila *f) {
    printf("\n=== Fila de Pecas ===\n");

    if (filaVazia(f)) {
        printf("[FILA VAZIA]\n");
        return;
    }

    int idx = f->inicio;
    for (int i = 0; i < f->quantidade; i++) {
        Peca p = f->itens[idx];
        printf("[%c %d] ", p.nome, p.id);
        idx = (idx + 1) % TAM;
    }

    printf("\n=====================\n");
}

/*
   Função principal: monta a fila inicial e abre o menu interativo.
*/
int main() {
    Fila fila;
    inicializarFila(&fila);

    int idGlobal = 0;

    // Preenche a fila inicialmente com 5 peças
    for (int i = 0; i < TAM; i++) {
        enqueue(&fila, gerarPeca(idGlobal++));
    }

    int opcao;

    do {
        exibirFila(&fila);

        printf("\nAcoes Disponiveis:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                dequeue(&fila);
                break;

            case 2:
                enqueue(&fila, gerarPeca(idGlobal++));
                break;

            case 0:
                printf("Encerrando o jogo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}