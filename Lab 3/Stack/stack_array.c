#include <stdlib.h>

#include "element.h"
#include "stack.h"
#define STACK_SIZE 1000

struct Stack {
    int top;
    Element data[STACK_SIZE];
};

Stack *newStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL) s->top = -1;
    return s;
}

bool push(Stack *s, Element e) {
    if (s->top == STACK_SIZE - 1) return false;
    s->data[++(s->top)] = e;
    return true;
}

Element *top(Stack *stack) {
    if (stack->top == -1) return NULL;
    return &stack->data[stack->top];
}
// Returns a pointer to the top element. Returns NULL if stack is empty

Element *pop(Stack *stack) {
    if (stack->top == -1) return NULL;
    Element *tp = &stack->data[stack->top];
    stack->top--;
    return tp;
}
// Pops the top element and returns true. Returns false if stack is empty

bool isEmpty(Stack *stack) { return stack->top == -1; }
// Returns true if stack is empty. Returns false otherwise

void freeStack(Stack *stack) { free(stack); }