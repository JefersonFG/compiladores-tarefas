#include "task4.h"
#include <stdio.h>
#include <string.h>

const char* input_file_name = "aula1/in4.txt";

int main() {
    int current_line = 0;
    char *line = NULL;
    size_t size = 0;
    char* token;
    char* end;
    int value = 0;
    int mark_to_remove = 0;
    pl_stack* stack = newStack(10);
    
    FILE* input_file = fopen(input_file_name, "r");

    while (getline(&line, &size, input_file) != -1) {
        current_line++;

        token = strtok(line, " \t\n");

        while (token) {
            if (token[0] == '(') {
                parenthesis_level new_level;
                new_level.starting_line = current_line;
                new_level.sum = 0;
                if (!push(stack, new_level)) {
                    fprintf(stderr, "Error pushing to the stack, stack full\n");
                    return 1;
                }
                // Remove parenteses do início
                token = token + 1;
            }

            if (token[strlen(token) - 1] == ')') {
                parenthesis_level* current_level = NULL;
                if (!peek(stack, &current_level)) {
                    // Empty stack
                    fprintf(stdout, "Found closing parenthesis without opening\n");
                } else {
                    mark_to_remove = 1;
                    // Remove parenteses do final
                    token[strlen(token) - 1] = 0;
                }
            }
            value = strtol(token, &end, 10);
            if (value != 0) {
                parenthesis_level* level = NULL;
                if (!peek(stack, &level)) {
                    // Empty stack
                    fprintf(stdout, "Found value %d outside of parenthesis\n", value);
                } else {
                    level->sum += value;
                }
            }

            if (mark_to_remove) {
                parenthesis_level* current_level = NULL;
                if (!pop(stack, &current_level)) {
                    fprintf(stderr, "Couldn't remove last level from top of the stack\n");
                    break;
                }
                fprintf(stdout, "Level started on line %d has sum %d\n", current_level->starting_line, current_level->sum);
                mark_to_remove = 0;
            }
            
            token = strtok(NULL, " \t\n");
        }
    }

    free(line);
    freeStack(stack);
    fclose(input_file);
    return 0;
}
