#include <stdlib.h>
#include "linked_list.h"

LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    return myList;
}
// This function allocates memory for a new list and returns a pointer to it.
// The list is empty and the count is set to 0.

NODE createNewNode(Element data){
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->data = data;
    return myNode;
}
// This function allocates memory for a new node and returns a pointer to it.
// The next pointer is set to NULL and the data is set to the value passed in.

void insertNodeIntoList(NODE node, LIST list){
    list->count++;
    node->next=list->head;
    list->head=node;
}

void insertNodeAtEnd(NODE node, LIST list){
    NODE hd=list->head;
    while(hd->next!=NULL){
        hd=hd->next;
    }
    list->head->next=NULL;

}
// This function inserts a node at the beginning of the list.

void removeFirstNode(LIST list){
    NODE *tbd=list->head;
    list->head=list->head->next;
    free(tbd);
}
// This function removes the first node from the list.

// void insertNodeAtEnd(NODE node, LIST list); // Not required for stack. Required for Queue
// This function inserts a node at the end of the list.

void destroyList(LIST list){
    while(list->head!=NULL){
        removeFirstNode(list);
    }
}