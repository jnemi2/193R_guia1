//
// Created by bauti on 8/19/2021.
//

#include <stdio.h>
#include "validate.h"


int getIntBetween(int min, int max, char* errorMsg) {
    int aux;
    scanf("%d", &aux);
    while (aux < min || aux > max)
    {
        printf("%s\n", errorMsg);
        scanf("%d", &aux);
    }
    return aux;
}

int getIntOver(int min, char* errorMsg) {
    int aux;
    scanf("%d", &aux);
    while (aux < min)
    {
        printf("%s\n", errorMsg);
        scanf("%d", &aux);
    }
    return aux;
}
