#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101

typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)malloc(MAX_LENGTH * sizeof(char));
    stack->top = -1;
    stack->capacity = MAX_LENGTH;
    return stack;
}

void push(Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

char matchBracket(char openBracket) {
    switch (openBracket) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return '\0';
    }
}

int checkBrackets(char* str) {
    Stack* stack = createStack();
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (isEmpty(stack)) {
                free(stack->data);
                free(stack);
                return 0;
            }
            char top = pop(stack);
            if (str[i]!= matchBracket(top)) {
                free(stack->data);
                free(stack);
                return 0;
            }
        }
    }
    int result = isEmpty(stack);
    free(stack->data);
    free(stack);
    return result;
}

int main() {
    char str[MAX_LENGTH];
    scanf("%s", str);
    if (checkBrackets(str)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
