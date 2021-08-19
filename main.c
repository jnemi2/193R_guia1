#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main() {
    printf("Hello, World!\n");

    List* stock = newList();
    append(stock, newProduct(1, 30, "Paracetamol", 1.1));
    append(stock, newProduct(2, 60, "Aspirin", 1.0));
    append(stock, newProduct(3, 10, "Morphine", 14.2));

    for (int i = 0; i < stock->length; i++)
        printf("%s, ", read(stock, i)->name);
    printf("\n");




    clear(stock);
    return 0;
}
