#include <stdio.h>
#include <string.h>
#include "list.h"


int main() {
    List* people = newList();

    append(people, "Elizabeth", 95);
    append(people, "Philip", 99);
    append(people, "Charles", 72);
    append(people, "William", 39);
    append(people, "George", 8);

    Node* aux;
    for (aux = (Node*) people->first; aux != NULL; aux = (Node *) aux->next){
        printf("%s - age %d\n", aux->value.name, aux->value.age);
    }
    printf("Average age: %.1f\n", averageAge(people));

    clear(people);

    return 0;
}
