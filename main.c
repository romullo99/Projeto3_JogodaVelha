#include <stdio.h>

// Função que imprime o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |", tabuleiro[i][j]);
        }
        printf("\n-------------\n");
    }
    printf("\n");
}

void desenvolvedor(){
    printf("|------------------------------|\n");
    printf("|     Software feito por       |\n");
    printf("|------------------------------|\n");
    printf("|        Rômullo Moura         |\n");
    printf("|------------------------------|\n");
    printf("|        Pablo Craveiro        |\n");
    printf("|------------------------------|\n");
}

// Função que verifica se algum jogador venceu
int verificarVencedor(char tabuleiro[3][3], char jogador) {
    // Verificação de linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;
        }
    }

    // Verificação de diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;  // Diagonal principal do tabuleiro
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;  // Diagonal secundária do tabuleiro
    }

    return 0;  // Se nenhum jogador tiver preenchido as diagonais, não há vencedor
}

// Função que realiza as jogadas
void realizarJogada(char tabuleiro[3][3], int linha, int coluna, char jogador, char nomeJogador[]) {
    // Verificação se a posição desejada está disponível para ser jogada.
    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        printf("%s jogou na posição (%d, %d).\n", nomeJogador, linha + 1, coluna + 1);
    } else {
        printf("\n Posição inválida ou já ocupada, por favor, escolha outra posição para realizar a jogada.\n");
    }
}

int jogadaValida(char tabuleiro[3][3], int linha, int coluna) {
    // Verifica se a linha e a coluna estão com os valores determinados na jogada
    // e se a posição está vazia (ainda não foi marcada por X ou O)

    printf("\n");
    return (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ');
}

int main() {
    char jogador;
    char tabuleiro[3][3];
    int opcao;

    do {
        // Inicialização do tabuleiro
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tabuleiro[i][j] = ' ';
            }
        }

        desenvolvedor();

        char nomeJogador1[50], nomeJogador2[50];
        int jogadas = 0;
        int linha, coluna;
        printf("Digite o nome do Jogador 1: ");
        scanf("%s", nomeJogador1);
        printf("Digite o nome do Jogador 2: ");
        scanf("%s", nomeJogador2);
        printf("%s, escolha se quer começar com 'X' ou '0': ", nomeJogador1);
        printf("\n");
        scanf(" %c", &jogador);

        do {
            imprimirTabuleiro(tabuleiro);

            // Solicita a jogada do jogador
            do {
                printf("%s, insira a linha e a coluna da sua jogada (1-3 separados por espaço): ", (jogador == 'X') ? nomeJogador1 : nomeJogador2);
                scanf("%d %d", &linha, &coluna);

                if (!jogadaValida(tabuleiro, linha - 1, coluna - 1)) {
                    printf("\nPosição inválida ou já ocupada, por favor, escolha outra posição para realizar a jogada.\n");
                }

            } while (!jogadaValida(tabuleiro, linha - 1, coluna - 1));

            // Realizar a jogada e verifica se o espaço está disponível
            realizarJogada(tabuleiro, linha - 1, coluna - 1, jogador, (jogador == 'X') ? nomeJogador1 : nomeJogador2);

            // Incrementar o número de jogadas
            jogadas++;

            // Realiza a validação das diagonais e colunas para saber se algum jogador venceu
            if (verificarVencedor(tabuleiro, jogador)) {
                imprimirTabuleiro(tabuleiro);
                printf("%s venceu!\n", (jogador == 'X') ? nomeJogador1 : nomeJogador2);
                break;
            }

            // Verificar empate
            if (jogadas == 3 * 3) {
                imprimirTabuleiro(tabuleiro);
                printf("Empate!\n");
                break;
            }

            // Alternar entre os jogadores
            jogador = (jogador == 'X') ? '0' : 'X';

        } while (1);

        printf("Deseja recomeçar o jogo? (1 - Sim, 0 - Não): ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    return 0;
}
