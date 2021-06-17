#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");
    List* list = newList();
    List* list2 = newList();

    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    append(list, 5);

    append(list2, 6);
    append(list2, 7);
    append(list2, 8);
    append(list2, 9);
    append(list2, 10);

    join(list, list2);

    for (int i = 0; i < list->length; i++)
        printf("%d, ", read(list, i));
    printf("\n");

    clear(list);

    return 0;
}
