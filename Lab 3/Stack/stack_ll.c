#include "linked_list.h"
#include "stack.h"
#include "linked_list.c"

#include <stdlib.h>
#define STACK_SIZE 1000

struct Stack
{
    LIST my_lst;
};

Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL)
        s->my_lst->count = 0;
    return s;
}

bool push(Stack *s, Element e)
{
    // create list then add a node with element e to it and then return true or false based on the insert function from the linked_list
    NODE myNode = createNewNode(e);
    insertNodeIntoList(myNode,s->my_lst);
    return true;
}

Element *top(Stack *stack){
    if(stack->my_lst->count==0) return NULL;
    Element *tp= &stack->my_lst->head->data;
    return tp;
} 
// Returns a pointer to the top element. Returns NULL if stack is empty

Element *pop(Stack *stack){
    if(stack->my_lst->count==0) return NULL;
    Element *tp= &stack->my_lst->head->data;
    removeFirstNode(stack->my_lst);
    return tp;
}
// Pops the top element and returns true. Returns false if stack is empty

bool isEmpty(Stack *stack){
    return stack->my_lst->count==0;
}
// Returns true if stack is empty. Returns false otherwise

void freeStack(Stack *stack){
    // destroyList(stack->my_lst);
    free(stack);
} 