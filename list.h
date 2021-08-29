//
// Created by bauti on 8/19/2021.
//

#ifndef INC_193R_GUIA1_LIST_H
#define INC_193R_GUIA1_LIST_H

typedef struct word {
    char word[35];
    int frequency;
} Word;

#define TYPE Word

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

Node* newNode(char* word);
List* newList();
void append(List *list, char* word);
void insert(List*, char* word, int);
TYPE* read(List*, int);
void join(List*, List*);
void delete(List*, int);
void clear(List*);


#endif //INC_193R_GUIA1_LIST_H
