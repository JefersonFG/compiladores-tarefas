#include <stdlib.h>

typedef struct {
    int starting_line;
    int sum;
} parenthesis_level;

typedef struct {
    int capacity;
    int top;
    parenthesis_level* items;
} pl_stack;

pl_stack* newStack(int capacity) {
    pl_stack* stack = (pl_stack*) malloc(sizeof(pl_stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (parenthesis_level*) malloc(sizeof(parenthesis_level) * capacity);

    return stack;
}

void freeStack(pl_stack* stack) {
    free(stack->items);
    free(stack);
}

int isEmpty(pl_stack* stack) {
    if (stack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(pl_stack* stack) {
    if (stack->top == stack->capacity - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Retorna se foi bem sucedido, level é preenchido se for bem sucedido
int peek(pl_stack* stack, parenthesis_level** level) {
    if (isEmpty(stack)) {
        return 0;
    }

    *level = &stack->items[stack->top];
    return 1;
}

// Retorna se foi bem sucedido ou não, level é preenchido se for bem sucedido
int pop(pl_stack* stack, parenthesis_level** level) {
    if (!peek(stack, level)) {
        return 0;
    }

    stack->top--;
    return 1;
}

// Retorna se foi bem sucedido ou não
int push(pl_stack* stack, parenthesis_level level) {
    if (isFull(stack)) {
        return 0;
    }

    stack->top++;
    stack->items[stack->top] = level;
    return 1;
}
