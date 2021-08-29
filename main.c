#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    printf("Hello, World!\n");
    List* list1 = newList();
    List* list2 = newList();
    append(list1, 1);
    append(list1, 3);
    append(list1, 5);
    append(list1, 7);
    append(list1, 9);
    append(list1, 10);
    append(list1, 14);
    append(list2, 2);
    append(list2, 8);
    append(list2, 11);
    append(list2, 12);
    append(list2, 13);

    printf("List1:\n");
    for (int i = 0; i < list1->length; i++)
        printf("%d, ", read(list1, i));
    printf("\nList2:\n");
    for (int j = 0; j < list2->length; j++)
        printf("%d, ", read(list2, j));

    //MERGE
    List* result = merge(list1, list2);
    printf("\nMerged:\n");
    for (int k = 0; k < result->length; k++)
        printf("%d, ", read(result, k));
    printf("\n");

    //FIND
    printf("\nIndex of 7: %d\n", find((Node*) result->first, 0, 7));

    //INSERT ORDERED
    insertOrdered(result, 100);
    insertOrdered(result, 4);
    insertOrdered(result, 1);

    //REMOVE OCCURRENCES
    removeOccurrences(result, 1);
    removeOccurrences(result, 5);
    for (int k = 0; k < result->length; k++)
        printf("%d, ", read(result, k));
    printf("\n");

    clear(list1);
    clear(list2);
    clear(result);

    return 0;
}
