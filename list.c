//
// Created by bauti on 8/19/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *newNode(TYPE val)
{
    Node* aux = (Node*) malloc(sizeof (Node));
    if (aux == NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    aux->value = val;
    aux->next = NULL;
    return aux;
}

List *newList()
{
    List* aux = (List*) malloc(sizeof (List));
    if (aux == NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    aux->length = 0;
    aux->first = NULL;
    return aux;
}

void append(List *list, TYPE value)
{
    Node *element = (Node *) newNode(value);
    Node *aux = (Node *) list->first;
    if (aux == NULL)
    {
        list->first = (struct Node *) element;
    }
    else
    {
        for (; aux->next != NULL; aux = (Node *) aux->next) {}
        aux->next = (struct Node *) element;
    }
    list->length = list->length + 1;
}

void insert(List *list, TYPE value, int index)
{
    if (index < 0 || index >= list->length)
        printf("Index out of range\n");
    else
    {
        Node *element = newNode(value);
        if (index == 0)
        {   //Insertion in first position
            element->next = list->first;
            list->first = (struct Node *) element;
        }
        else
        {   //Insertion in any position other than first
            Node *previous = (Node *) list->first;
            for (int i = 1; i < index; i++)
            {
                previous = (Node *) previous->next;
            }
            element->next = previous->next;
            previous->next = (struct Node *) element;
        }

        list->length = list->length + 1;
    }
}

TYPE read(List *list, int index)
{
    Node *aux = NULL;
    if (index < 0 || index >= list->length)
        printf("Index out of range\n");
    else
    {
        aux = (Node *) list->first;
        for (int i = 0; i < index; i++)
            aux = (Node *) aux->next;
    }
    return aux->value;
}

void join(List *list, List *extra)
{
    Node *aux = (Node *) list->first;
    for (; aux->next != NULL; aux = (Node *) aux->next) {} //aux now has the last element of list
    aux->next = extra->first; //both lists are now linked
    list->length = list->length + extra->length;
    extra->first = NULL;
    free(extra); //once the content of the extra list is delegated to list, extra is freed
}

void delete(List *list, int index)
{
    if (index < 0 || index >= list->length)
        printf("Index out of range\n");
    else
    {
        Node *aux = (Node *) list->first;
        if (index == 0) //Delete first element
            list->first = aux->next;
        else    //Delete any element other than first
        {
            Node *prev = (Node *) list->first;
            for (int i = 1; i < index; i++) //prev will end up with the previous element
                prev = (Node *) prev->next;          //of the one that is to be deleted
            aux = (Node *) prev->next;
            prev->next = aux->next;
        }

        free(aux);
        list->length = list->length - 1;
    }
}

void clear(List *list)
{
    Node *aux;
    for (; list->first != NULL; free(aux))
    {
        aux = (Node *) list->first;
        list->first = aux->next;
    }
    free(list);
}

List *merge(List *list1, List *list2) {
    List* result = newList();
    Node* aux1 = (Node*) list1->first;
    Node* aux2 = (Node*) list2->first;
    while (aux1 != NULL && aux2 != NULL){
        if (aux1->value < aux2->value){
            append(result, aux1->value);
            aux1 = (Node*) aux1->next;
        }else{
            append(result, aux2->value);
            aux2 = (Node*) aux2->next;
        }
    }
    if (aux1 == NULL)
        aux1 = aux2;
    for (;aux1 != NULL; aux1 = (Node*) aux1->next)
        append(result, aux1->value);

    result->length = list1->length + list2->length;
    return result;
}

int find(Node* node, int currentIndex, int value) {
    if (node == NULL){
        //Element not found
        return -1;
    }else if (node->value == value){
        //Element found
        return currentIndex;
    }else
        return (find((Node*) node->next, currentIndex+1, value));
}

void insertOrdered(List* list, int value) {
    Node* aux = (Node*) list->first;
    Node* toInsert = newNode(value);
    if (aux == NULL)
        list->first = (struct Node *) newNode(value);
    else{
        Node* tempNext;
        for (; aux != NULL; aux = (Node *) aux->next) {
            tempNext = (Node *) aux->next;
            if (tempNext == NULL || (value < tempNext->value && value >= aux->value))
                break;
        }
        toInsert->next = (struct Node *) tempNext;
        aux->next = (struct Node * ) toInsert;
    }

    list->length = list->length + 1;
}

void removeOccurrences(List *list, int value) {
    Node* aux = (Node*) list->first;
    Node* auxNext = (Node*) aux->next;
    Node* toDelete;

    for (; aux != NULL; aux = (Node*) aux->next){
        auxNext = (Node*) aux->next;
        if (auxNext != NULL && auxNext->value == value){
            //delete auxNext
            toDelete = auxNext;
            aux->next = auxNext->next;
            auxNext->next = NULL;
            free(auxNext);
            list->length = list->length - 1;
        }
    }
    Node* first = (Node*) list->first;
    if (first->value == value){
        list->first = (struct Node *) first->next;
        free(first);
        list->length = list->length - 1;
    }
}
