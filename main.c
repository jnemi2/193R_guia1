#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");
    List* numbers = newList();
    append(numbers, 7);
    append(numbers, 9);
    append(numbers, 21);
    append(numbers, 14);
    append(numbers, 2015);
    append(numbers, 454);
    append(numbers, 294);
    append(numbers, 5);

    for (int i = 0; i < numbers->length; i++)
        printf("%d, ", read(numbers, i));
    printf("\n");
    int minIndex = findMin(numbers);
    printf("Eliminating min: %d", read(numbers, minIndex));
    delete(numbers, minIndex);
    int maxIndex = findMax(numbers);
    printf(" & max: %d\n", read(numbers, maxIndex));
    delete(numbers, maxIndex);
    for (int i = 0; i < numbers->length; i++)
        printf("%d, ", read(numbers, i));
    printf("\n");

    clear(numbers);
    return 0;
}
