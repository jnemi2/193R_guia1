//
// Created by bauti on 8/19/2021.
//

#include <stdio.h>
#include "client.h"
#include "validate.h"

void showOptions(List* stock)
{
    for (int i = 0; i < stock->length; i++)
        printf("%d- %s %f\n", i+1, read(stock, i)->name, read(stock, i)->price);
    printf("\n");
}

List* selectProducts(List* stock)
{
    List* myList = newList();
    int selection;
    int quantity;
    do
    {
        printf("Indique los productos que desea comprar:\nIngrese 0 para salir.\n");
        showOptions(stock);
        selection = getIntBetween(0, stock->length, "Error: seleccione una opcion valida");
        if (selection != 0) {
            printf("Ingrese la cantidad a comprar\n");
            quantity = getIntOver(0, "Error: cantidad incorrecta");
            Product *selected = read(stock, selection - 1);
            append(myList, newProduct(selected->code, quantity, selected->name, selected->price));
        }
    } while (selection != 0);

    return myList;
}

void sell(List* stock)
{
    List* purchaseList;
    purchaseList = selectProducts(stock);
    sort(purchaseList);
    for (int i = 0; i < purchaseList->length; i++) {
        Product* prod = read(purchaseList, i);
        printf("(%d) %s: %d units x $%f = $%f\n", prod->code, prod->name,
               prod->quantity, prod->price, prod->price * prod->quantity);
    }
    printf("\n");

    clear(purchaseList);
}