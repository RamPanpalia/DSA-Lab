#include <stdlib.h>
#include "linked_list.h"

LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    return myList;
}

NODE createNewNode(Element data){
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->data = data;
    return myNode;
}

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

void removeFirstNode(LIST list){
    NODE *tbd=list->head;
    list->head=list->head->next;
    free(tbd);
}

void destroyList(LIST list){
    while(list->head!=NULL){
        removeFirstNode(list);
    }
}