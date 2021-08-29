#include <stdio.h>
#include <string.h>
#include "list.h"


int main() {
    List* words = newList();

    char text[200];
    char* token;
    printf("Type something: ");
    gets(text);
    printf("\n");
    token = strtok(text, " ");

    while (token != NULL){
        Node* aux = (Node *) words->first;
        if (aux != NULL) {
            for (; aux->next != NULL && (strcmp(token, aux->value.word) != 0); aux = (Node *) aux->next) {}
            if (strcmp(token, aux->value.word) == 0){
                aux->value.frequency++;
            }else{
                append(words, token);
            }

        }else{
            append(words, token);
        }
        token = strtok(NULL, " ");
    }

    Node* aux;
    for (aux = (Node*) words->first; aux != NULL; aux = (Node *) aux->next){
        printf("Word | frequency: %s | %d\n", aux->value.word, aux->value.frequency);
    }

    clear(words);

    return 0;
}
