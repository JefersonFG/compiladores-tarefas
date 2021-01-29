#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* input_file_name = "in2.txt";

int main() {
    char *line = NULL;
    int size = 0;
    int value = 0;
    int sum = 0;
    char* token;
    char* end;
    int line_end = 0;

    FILE* input_file = fopen(input_file_name, "r");

    while (getline(&line, &size, input_file) != -1) {
        // Se linha vazia ou com um caracter só (\n, ;), pula
        if (strlen(line) < 2) {
            continue;
        }
        // Se linha termina com \n o remove
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = 0;
        }
        // Se após a remoção do \n a linha termina com ponto e vírgula marca para finalizar a contagem
        if (line[strlen(line)-1] == ';') {
            line_end = 1;
        }

        token = strtok(line, " \t");

        while (token) {
            value = strtol(token, &end, 10);

            if (value != 0) {
                sum++;
            }
            
            token = strtok(NULL, " \t");
        }

        if (line_end) {
            fprintf(stdout, "%d ", sum);
            sum = 0;
            line_end = 0;
        }
    }

    fclose(input_file);
    return 0;
}
