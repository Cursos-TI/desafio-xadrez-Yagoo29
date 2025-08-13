#include <stdio.h>

/* ============================
   Funções recursivas
   ============================ */

/*
 * moverTorreDireitaRec: imprime "Direita" 'casas' vezes recursivamente.
 * Caso-base: casas <= 0 -> retorna (encerra a recursão).
 */
void moverTorreDireitaRec(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorreDireitaRec(casas - 1);
}

/*
 * moverBispoCimaDireitaRec: imprime "Cima Direita" 'casas' vezes recursivamente.
 * Representa a combinação de um passo vertical (cima) + um passo horizontal (direita).
 */
void moverBispoCimaDireitaRec(int casas) {
    if (casas <= 0) return;
    printf("Cima Direita\n");
    moverBispoCimaDireitaRec(casas - 1);
}

/*
 * moverRainhaEsquerdaRec: imprime "Esquerda" 'casas' vezes recursivamente.
 */
void moverRainhaEsquerdaRec(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainhaEsquerdaRec(casas - 1);
}

/* ============================
   Versão com loops aninhados para o Bispo
   - Loop EXTERNO: vertical (cima)
   - Loop INTERNO: horizontal (direita)
   Observação: Continuamos imprimindo "Cima Direita" por passo,
   conforme o padrão do projeto para movimentos diagonais.
   ============================ */
void moverBispoLoopsAninhados(int passosDiagonais) {
    for (int passoVertical = 1; passoVertical <= passosDiagonais; passoVertical++) {
        /* Para cada unidade vertical (Cima), fazemos a parte horizontal (Direita).
           Mantemos 1 iteração no horizontal para representar 1 passo de diagonal. */
        for (int passoHorizontal = 0; passoHorizontal < 1; passoHorizontal++) {
            /* Poderíamos imprimir "Cima\n" e "Direita\n" separadamente,
               mas o padrão do projeto é "Cima Direita" em uma linha por casa. */
            printf("Cima Direita\n");
        }
    }
}

/* ============================
   Cavalo com loops complexos
   - Objetivo: 2 para CIMA e 1 para DIREITA
   - Usa loops aninhados, múltiplas variáveis/condições, e break/continue
   - Saída esperada: "Cima", "Cima", "Direita"
   ============================ */
void moverCavaloCimaDireita() {
    int casasCima = 2;
    int casasDireita = 1;

    printf("Movimento do Cavalo (loops complexos):\n");

    /* Loop EXTERNO controla a componente vertical (Cima) com múltiplas condições:
       - i começa em 1 e vai até casasCima
       - também paramos se detectarmos que já fizemos a parte horizontal */
    int direitaRealizada = 0; // flag para garantir que movemos 1 vez à direita
    for (int i = 1; i <= casasCima && !direitaRealizada; i++) {
        printf("Cima\n"); // cada iteração sobe uma casa

        /* Loop INTERNO controla a parte horizontal (Direita).
           Usamos uma condição combinada e controlamos fluxo com break/continue. */
        int j = 0;
        while (j <= casasDireita) {
            /* Só pode ir para a direita DEPOIS de completar as duas subidas.
               Se ainda não é a última subida, não mova para a direita. */
            if (i < casasCima) {
                /* Ainda subindo: não movimentamos horizontalmente nesta altura. */
                /* Podemos usar 'continue' para explicitar a intenção:
                   mas como não queremos um loop infinito, quebramos o while. */
                // continue; // evitaria avançar j, mas causaria loop infinito
                break; // sai do while, segue para a próxima subida
            }

            /* Aqui i == casasCima: é a hora de fazer a parte horizontal. */
            if (j < casasDireita) {
                printf("Direita\n");
                j++;
                direitaRealizada = 1; // marcamos que o passo horizontal foi feito
                break;                // saímos do while após 1 passo à direita
            } else {
                break; // segurança: nada a fazer
            }
        }
    }
}

int main() {
    /* ============================
       Parâmetros (fixos no código)
       ============================ */
    int casasTorre = 5;       // Torre: 5 para a Direita (recursivo)
    int casasBispo = 5;       // Bispo: 5 na diagonal Cima-Direita (recursivo)
    int casasRainha = 8;      // Rainha: 8 para a Esquerda (recursivo)
    int passosBispoLoops = 5; // Bispo (loops aninhados): 5 passos de diagonal

    /* ============================
       Torre (recursivo)
       ============================ */
    printf("Movimento da Torre (recursivo):\n");
    moverTorreDireitaRec(casasTorre);

    /* Linha em branco para separar peças */
    printf("\n");

    /* ============================
       Bispo (recursivo)
       ============================ */
    printf("Movimento do Bispo (recursivo):\n");
    moverBispoCimaDireitaRec(casasBispo);

    /* Linha em branco para separar peças */
    printf("\n");

    /* ============================
       Rainha (recursivo)
       ============================ */
    printf("Movimento da Rainha (recursivo):\n");
    moverRainhaEsquerdaRec(casasRainha);

    /* Linha em branco para separar peças */
    printf("\n");

    /* ============================
       Cavalo (loops complexos)
       ============================ */
    moverCavaloCimaDireita();

    /* Linha em branco para separar peças */
    printf("\n");

    /* ============================
       Bispo (loops aninhados)
       - Requisito específico: loop externo vertical, interno horizontal
       ============================ */
    printf("Movimento do Bispo (loops aninhados):\n");
    moverBispoLoopsAninhados(passosBispoLoops);

    return 0;
}
