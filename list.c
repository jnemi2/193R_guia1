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

void swap(TYPE aux1, TYPE aux2)
{
    TYPE temp = aux1;
    *aux1 = *aux2;
    *aux2 = *temp;
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

        free(aux->value); //Since value is a pointer, this line should delete the actual content of the element
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
        free(aux->value); //Since value is a pointer, this line should delete the actual content of the element
        list->first = aux->next;
    }
    free(list);
}

void sort(List* list)
{
    int i, j;
    for (i = 0; i < list->length-1; i++)
        for (j = 0; j < list->length-i-1; j++)
        {
            if (read(list, j)->code > read(list, j+1)->code)
                swap(read(list, j), read(list, j+1));
        }
}