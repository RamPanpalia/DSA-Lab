#include"linked_list.h"
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    LIST list;
};

Queue *createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q!=NULL){
        q->list = createNewList();
    }
    return q;
}

bool enqueue(Queue *q, Element e){
    NODE n1 = createNewNode(e);
    insertNodeAtEnd(n1,q->list);
    return true;
}

bool dequeue(Queue *q){
    if(q->list->count==0){
        return false;
    }
    else{
        removeFirstNode(q->list);
        return true;
    }
}

Element *front(Queue *q){
    if(q->list->count==0){
        return NULL;
    }
    NODE temp = (q->list)->head;
    Element *ele = (Element *) malloc(sizeof(struct Element));
    ele->float_value = temp->data.float_value;
    ele->int_value = temp->data.int_value;
    return ele;
}

int size(Queue *q){
    return q->list->count;
}

bool isEmpty(Queue *q){
    return (q->list->count==0);
}

void destroyQueue(Queue *queue){
    free(queue);
}