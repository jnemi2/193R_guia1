//
// Created by bauti on 8/19/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node *newNode(char* word, int age)
{
    Node* aux = (Node*) malloc(sizeof (Node));
    if (aux == NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    strcpy(aux->value.name, word);
    aux->value.age = age;
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

void append(List *list, char* word, int age)
{
    Node *element = (Node *) newNode(word, age);
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

void insert(List *list, char* word, int age, int index)
{
    if (index < 0 || index >= list->length)
        printf("Index out of range\n");
    else
    {
        Node *element = newNode(word, age);
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

TYPE* read(List *list, int index)
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
    return &(aux->value);
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

float averageAge(List * people) {
    float average = 0;
    for (Node* aux = (Node*) people->first; aux != NULL; aux = (Node*) aux->next){
        average += (float) aux->value.age;
    }
    if (people->length != 0)
        average = average / (float) people->length;
    return average;
}
