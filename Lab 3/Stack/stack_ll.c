#include <stdlib.h>

#include "linked_list.c"
#include "linked_list.h"
#include "stack.h"
#define STACK_SIZE 1000

struct Stack {
    LIST my_lst;
};

Stack *newStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL) s->my_lst->count = 0;
    return s;
}

bool push(Stack *s, Element e) {
    NODE myNode = createNewNode(e);
    insertNodeIntoList(myNode, s->my_lst);
    return true;
}

Element *top(Stack *stack) {
    if (stack->my_lst->count == 0) return NULL;
    Element *tp = &stack->my_lst->head->data;
    return tp;
}

Element *pop(Stack *stack) {
    if (stack->my_lst->count == 0) return NULL;
    Element *tp = &stack->my_lst->head->data;
    removeFirstNode(stack->my_lst);
    return tp;
}

bool isEmpty(Stack *stack) { return stack->my_lst->count == 0; }

void freeStack(Stack *stack) {
    free(stack);
}