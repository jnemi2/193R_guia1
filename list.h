//
// Created by bauti on 8/19/2021.
//

#ifndef INC_193R_GUIA1_LIST_H
#define INC_193R_GUIA1_LIST_H
#include "product.h"

#define TYPE Product*

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

Node* newNode(TYPE);
List* newList();
void append(List*, TYPE);
void insert(List*, TYPE, int);
TYPE read(List*, int);
void join(List*, List*);
void delete(List*, int);
void clear(List*);

#endif //INC_193R_GUIA1_LIST_H
