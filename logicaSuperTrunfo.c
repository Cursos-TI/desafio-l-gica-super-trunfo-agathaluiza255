#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
    int defesa;
} Carta;

void limparTela() {
    // limpa tela (funciona em Windows)
    system("cls || clear");
}

void mostrarCarta(Carta c) {
    printf("\n--- Carta: %s ---\n", c.nome);
    printf("1. Força: %d\n", c.forca);
    printf("2. Velocidade: %d\n", c.velocidade);
    printf("3. Inteligência: %d\n", c.inteligencia);
    printf("4. Defesa: %d\n", c.defesa);
}

/*----------------------------------------------------
 DESAFIO 1 – Comparação simples com IF / IF-ELSE
----------------------------------------------------*/
void desafio1() {
    limparTela();
    printf("===== DESAFIO 1: Comparar UM atributo =====\n");

    Carta jogador = {"Superman", 100, 80, 70, 90};
    Carta maquina = {"Batman", 85, 70, 95, 85};

    mostrarCarta(jogador);
    int opcao;
    printf("\nEscolha o atributo para comparar (1 a 4): ");
    scanf("%d", &opcao);

    int valorJog, valorMaq;

    if (opcao == 1) {
        valorJog = jogador.forca;
        valorMaq = maquina.forca;
    } else if (opcao == 2) {
        valorJog = jogador.velocidade;
        valorMaq = maquina.velocidade;
    } else if (opcao == 3) {
        valorJog = jogador.inteligencia;
        valorMaq = maquina.inteligencia;
    } else if (opcao == 4) {
        valorJog = jogador.defesa;
        valorMaq = maquina.defesa;
    } else {
        printf("Opção inválida!\n");
        return;
    }

    printf("\n%s (%d) vs %s (%d)\n", jogador.nome, valorJog, maquina.nome, valorMaq);

    if (valorJog > valorMaq)
        printf("Você venceu!\n");
    else if (valorJog < valorMaq)
        printf("Você perdeu!\n");
    else
        printf("Empate!\n");
}

/*----------------------------------------------------
 DESAFIO 2 – Múltiplos atributos com operadores lógicos
 e estruturas encadeadas + switch
----------------------------------------------------*/
void desafio2() {
    limparTela();
    printf("===== DESAFIO 2: Comparar múltiplos atributos =====\n");

    Carta jogador = {"Mulher-Maravilha", 90, 90, 85, 88};
    Carta maquina = {"Flash", 70, 100, 75, 65};

    mostrarCarta(jogador);

    int opcao;
    printf("\nEscolha um modo de comparação:\n");
    printf("1 - Força + Velocidade\n");
    printf("2 - Inteligência + Defesa\n");
    printf("3 - Todos os atributos\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    int somaJog = 0, somaMaq = 0;

    switch (opcao) {
        case 1:
            somaJog = jogador.forca + jogador.velocidade;
            somaMaq = maquina.forca + maquina.velocidade;
            break;
        case 2:
            somaJog = jogador.inteligencia + jogador.defesa;
            somaMaq = maquina.inteligencia + maquina.defesa;
            break;
        case 3:
            somaJog = jogador.forca + jogador.velocidade + jogador.inteligencia + jogador.defesa;
            somaMaq = maquina.forca + maquina.velocidade + maquina.inteligencia + maquina.defesa;
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("\nPontuação %s = %d\n", jogador.nome, somaJog);
    printf("Pontuação %s = %d\n", maquina.nome, somaMaq);

    if (somaJog > somaMaq)
        printf("🎉 Você venceu!\n");
    else if (somaJog < somaMaq)
        printf("💀 A máquina venceu!\n");
    else
        printf("🤝 Empate!\n");
}

/*----------------------------------------------------
 DESAFIO 3 – Comparação de DOIS atributos
 usando operador ternário e decisão aninhada
----------------------------------------------------*/
void desafio3() {
    limparTela();
    printf("===== DESAFIO 3: Comparar DOIS atributos =====\n");

    Carta jogador = {"Lanterna Verde", 80, 85, 90, 70};
    Carta maquina = {"Aquaman", 85, 75, 70, 85};

    mostrarCarta(jogador);

    int op1, op2;
    printf("\nEscolha o primeiro atributo (1 a 4): ");
    scanf("%d", &op1);
    printf("Escolha o segundo atributo (1 a 4, diferente do primeiro): ");
    scanf("%d", &op2);

    if (op1 < 1 || op1 > 4 || op2 < 1 || op2 > 4 || op1 == op2) {
        printf("Opções inválidas!\n");
        return;
    }

    int valorJog1, valorJog2, valorMaq1, valorMaq2;

    // Acesso dinâmico de atributos via if encadeado
    valorJog1 = (op1 == 1) ? jogador.forca :
                (op1 == 2) ? jogador.velocidade :
                (op1 == 3) ? jogador.inteligencia : jogador.defesa;

    valorJog2 = (op2 == 1) ? jogador.forca :
                (op2 == 2) ? jogador.velocidade :
                (op2 == 3) ? jogador.inteligencia : jogador.defesa;

    valorMaq1 = (op1 == 1) ? maquina.forca :
                (op1 == 2) ? maquina.velocidade :
                (op1 == 3) ? maquina.inteligencia : maquina.defesa;

    valorMaq2 = (op2 == 1) ? maquina.forca :
                (op2 == 2) ? maquina.velocidade :
                (op2 == 3) ? maquina.inteligencia : maquina.defesa;

    int somaJog = valorJog1 + valorJog2;
    int somaMaq = valorMaq1 + valorMaq2;

    printf("\nPontuação total %s = %d\n", jogador.nome, somaJog);
    printf("Pontuação total %s = %d\n", maquina.nome, somaMaq);

    (somaJog > somaMaq) ? printf("🎉 Você venceu!\n") :
    (somaJog < somaMaq) ? printf("💀 A máquina venceu!\n") :
                           printf("🤝 Empate!\n");
}

/*----------------------------------------------------
 PROGRAMA PRINCIPAL
----------------------------------------------------*/
int main() {
    int opcao;

    do {
        printf("\n=========================================\n");
        printf("     SUPER TRUNFO - ESTÁCIO (em C)\n");
        printf("=========================================\n");
        printf("1 - Desafio 1 (if e if-else)\n");
        printf("2 - Desafio 2 (switch e if-else if)\n");
        printf("3 - Desafio 3 (operador ternário)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desafio1();
                break;
            case 2:
                desafio2();
                break;
            case 3:
                desafio3();
                break;
            case 0:
                printf("\nSaindo do jogo... Até mais!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

        printf("\nPressione ENTER para continuar...\n");
        getchar(); getchar();
        limparTela();
    } while (opcao != 0);

    return 0;
}
