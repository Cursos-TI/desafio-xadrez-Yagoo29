#include <stdio.h>

int main() {
    // Simulação do movimento da Torre (for)
    int casasTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // Simulação do movimento do Bispo (while)
    int casasBispo = 5;
    int contadorBispo = 1;
    printf("\nMovimento do Bispo:\n");
    while (contadorBispo <= casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // Simulação do movimento da Rainha (do-while)
    int casasRainha = 8;
    int contadorRainha = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    int casasBaixo = 2;
    int casasEsquerda = 1;

     printf("\nMovimento do Cavalo:\n");
     
     for (int i = 1; i <= casasBaixo; i++) {
        printf("Baixo\n");
        }

        int contadorEsquerda = 0;
        while (contadorEsquerda < casasEsquerda) {
            printf("Esquerda\n");
            contadorEsquerda++;
            }

    return 0;
}