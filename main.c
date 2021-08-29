#include <stdio.h>
#include "circularqueue.h"


int main() {
    printf("Hello, World!\n");
    CircularQueue queue;
    initializeQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);

    while (!empty(&queue)){
        printf("%d, ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}
