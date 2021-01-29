#include <stdio.h>

const char* input_file_name = "in1.txt";

int main() {
    int value = 0;
    int sum = 0;

    FILE* input_file = fopen(input_file_name, "r");

    while (fscanf(input_file, "%d", &value) != EOF) {
        sum++;
    }

    fprintf(stdout, "Numero de valores no arquivo: %d", sum);

    fclose(input_file);
    return 0;
}
