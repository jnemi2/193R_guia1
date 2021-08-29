//
// Created by bauti on 8/29/2021.
//

#include <stdio.h>
#include "circularqueue.h"


void initializeQueue(CircularQueue* cQueue) {
    cQueue->current = 0;
    cQueue->first = 0;
}

void enqueue(CircularQueue *cQueue, int value) {
    if (isFull(cQueue))
        printf("Error: unable to enqueue element in isFull circular queue\n");
    else{
        cQueue->queue[cQueue->current] = value;
        cQueue->current = next(cQueue->current);
    }
}

TYPE dequeue(CircularQueue *cQueue) {
    TYPE toRetrieve = -1;
    if (!isEmpty(cQueue)){
        toRetrieve = cQueue->queue[cQueue->first];
        cQueue->first = next(cQueue->first);
    }
    return toRetrieve;
}

int isFull(CircularQueue *cQueue) {
    if (next(cQueue->current) == cQueue->first)
        return 1;
    return 0;
}

int isEmpty(CircularQueue* cQueue) {
    if (cQueue->current == cQueue->first)
        return 1;
    return 0;
}

int next(int index) {
    return (index + 1)%SIZE;
}
