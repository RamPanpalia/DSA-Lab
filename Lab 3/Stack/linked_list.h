#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "element.h"
// #include "bool.h"

struct node {
    Element data;
    struct node *next;
};
typedef struct node node;
typedef node *NODE;

struct linked_list {
    int count;
    NODE head;
};
typedef struct linked_list linked_list;
typedef linked_list *LIST;

LIST createNewList();

NODE createNewNode(Element data);

void insertNodeIntoList(NODE node, LIST list);

void removeFirstNode(LIST list);

void destroyList(LIST list);
#endif