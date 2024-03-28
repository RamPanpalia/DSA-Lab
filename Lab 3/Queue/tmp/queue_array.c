#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include"element.h"
#include"queue.h"

#define QUEUE_SIZE 1000

struct Queue{
    int front;
    int rear;int n;
    Element data[QUEUE_SIZE];
};

Queue *createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front=0;
    q->rear=0;
    q->n=0;
    return q;
}

int size(Queue *queue){
    return queue->n;
}

bool isEmpty(Queue *q){
    return (q->n==0);
}

bool enqueue(Queue *queue, Element element){
    if(size(queue)==QUEUE_SIZE-1){
        return false;
    }
    else{
        queue->data[queue->rear]=element;
        queue->rear = (queue->rear+1) % QUEUE_SIZE;
        queue->n = queue->n + 1;
        return true;
    }
}

bool dequeue(Queue *q){
    if(isEmpty(q)){
        return false;
    }
    else{
        q->front = (q->front+1) % QUEUE_SIZE ;
        q->n = (q->n -1);
        return false;
    }
}

Element *front(Queue *q){
    if(isEmpty(q)){
        return NULL;
    }
    else{
        return q->data+q->front;
    }
}

void destroyQueue(Queue *queue){
    free(queue);
    return;
}
