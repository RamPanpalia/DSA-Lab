#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
#include"element.h"

LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc (sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    myList->tail=NULL;
    return myList;
}

NODE createNewNode(Element e){
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->data.float_value=e.float_value;
    myNode->data.int_value=e.int_value;
    myNode->next=NULL;
    return myNode;
}

void insertNodeIntoList(NODE node, LIST list){
    if(list->count==0){
        list->head = node;
        list->tail = node;
        node->next=NULL;
        list->count++;
    }
    else{
        node->next = list->head;
        list->head = node;
        list->count++; 
    }
}

void removeFirstNode(LIST l1){
    if(l1->count==0){
        printf("Linkedlist is empty\n");
        return;
    }
    NODE temp = l1->head;
    l1->head = l1->head->next;
    l1->count--;
    free(temp);
    return;
}

void destroyList(LIST list){
    free(list->head);
    list->head=NULL;
}

void insertNodeAtEnd(NODE node, LIST list){
    if(list->count==0){
        list->head = node;
        list->tail = node;
        node->next=NULL;
        list->count++;
    }
    else{
        list->tail->next = node;
        list->tail = node;
        list->count++;
    }
}