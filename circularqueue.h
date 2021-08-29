//
// Created by bauti on 8/29/2021.
//

#ifndef INC_193R_GUIA1_CIRCULARQUEUE_H
#define INC_193R_GUIA1_CIRCULARQUEUE_H

#define TYPE int
#define SIZE 10

typedef struct circularQueue{
    TYPE queue[SIZE];
    int current;
    int first;
} CircularQueue;

void initializeQueue(CircularQueue* cQueue);
void enqueue(CircularQueue* cQueue, TYPE value);
TYPE dequeue(CircularQueue* cQueue);
int full(CircularQueue* cQueue);
int empty(CircularQueue* cQueue);
int next(int index);


#endif //INC_193R_GUIA1_CIRCULARQUEUE_H
