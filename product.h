//
// Created by bauti on 8/19/2021.
//

#ifndef INC_193R_GUIA1_PRODUCT_H
#define INC_193R_GUIA1_PRODUCT_H

typedef struct product
{
    int code;
    int quantity;
    char name[25];
    float price;
} Product;

//Product* newProduct();
Product* newProduct(int, int, char*, float);

#endif //INC_193R_GUIA1_PRODUCT_H
