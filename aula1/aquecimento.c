#include <stdio.h>

int main() {
    // Printa 10 linhas com os números de 1 ao número da linha
    int i = 0;
    int j = 0;
    int max = 10;
    int lista_num[5000];

    for (i = 0; i < max; i++) {
        lista_num[i] = i + 1;

        for (j = 0; lista_num[j] != 0; j++) {
            fprintf(stdout, "%d ", lista_num[j]);
        }

        fprintf(stdout, "\n");
    }

    return 0;
}
