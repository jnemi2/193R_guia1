//
// Created by bauti on 6/17/2021.
//

#ifndef BASE_PROJECT_LIST_H
#define BASE_PROJECT_LIST_H
#define TYPE int

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


#endif //BASE_PROJECT_LIST_H
