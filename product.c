//
// Created by bauti on 8/19/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "product.h"

/*
Product* new_Product()
{
    Product* aux = (Product*) malloc(sizeof (Product));
    if (aux == NULL){
        printf("Not enough memory\n");
        exit(-1);
    }
    return aux;
}*/

Product* newProduct(int code, int quantity, char* name, float price)
{
    Product* aux = (Product*) malloc(sizeof (Product));
    if (aux == NULL){
        printf("Not enough memory\n");
        exit(-1);
    }
    aux->code = code;
    aux->quantity = quantity;
    aux->price = price;
    strcpy(aux->name, name);
    return aux;
}