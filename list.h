//
// Created by bauti on 8/19/2021.
//

#ifndef INC_193R_GUIA1_LIST_H
#define INC_193R_GUIA1_LIST_H

typedef struct property {
    char neighborhood[25];
    unsigned int rooms;
    float price;
} Property;

#define TYPE Property

typedef struct node
{
    TYPE value;
    struct Node* next;
} Node;

typedef struct list
{
    int length;
    struct Node* first;
} List;

/*
 * Create: newNode(..), newList(), append(..), insert(..)
 * Read: read(..)
 * Update: join(..)
 * Delete: delete(..), clear(..)
 *
 */

Node* newNode(char* neighborhood, int rooms, float price);
List* newList();
void append(List *list, char* neighborhood, int rooms, float price);
void insert(List*, char* neighborhood, int rooms, float price, int);
TYPE* read(List*, int);
void join(List*, List*);
void delete(List*, int);
void clear(List*);

void filter(List* homes);

#endif //INC_193R_GUIA1_LIST_H
