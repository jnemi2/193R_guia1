//
// Created by bauti on 8/27/2021.
//

#include <stdio.h>
#include "helper.h"

void loadAccounts(Account * accounts, int total) {
    for (int i = 0; i < total; i++){
        accounts[i].accountNum = i;
        accounts[i].balance = 100 + (i*7)%25;
    }
}

int validateInt(int min, int max, char* errorMsg){
    int input;
    do {
        scanf("%d", &input);
        if (input > max || input < min)
            printf("%s: ", errorMsg);
    } while (input > max || input < min);
    return input;
}

float validatePositive(char* errorMsg) {
    float input;
    do {
        scanf("%f", &input);
        if (input < 0)
            printf("%s: ", errorMsg);
    } while (input < 0);
    return input;
}

void processMovements(Account * accounts, int total) {
    int accountNum, movType;
    int maxMovAccountNum = -1;
    float maxMov = 0;
    float amount;
    float totalCredits = 0;
    float totalDebits = 0;
    printf("Ingrese el numero de cuenta que registra movimiento (-1 para salir): ");
    accountNum = validateInt(-1, total, "Error. Ingrese un numero de cuenta valido");
    while (accountNum != -1){
        printf("Ingrese '1' para entrada o '2' para salida: ");
        movType = validateInt(1, 2, "Error. Ingrese '1' para entrada o '2' para salida");
        printf("Ingrese el importe del movimiento: ");
        amount = validatePositive("Error. El importe debe ser positivo");
        if (movType == 2) {
            totalDebits += amount;
            amount = amount * -1;
        } else {
            totalCredits += amount;
        }
        accounts[accountNum].balance += amount;
        if (amount > maxMov) { // Update max movement
            maxMov = amount;
            maxMovAccountNum = accountNum;
        }

        //Next account
        printf("Ingrese el numero de cuenta que registra movimiento (-1 para salir): ");
        accountNum = validateInt(-1, total, "Error. Ingrese un numero de cuenta valido");
    }
    if (!(totalCredits == 0 && totalDebits == 0)) {
        printMovements(accounts, total, totalCredits, totalDebits, maxMovAccountNum, maxMov);
    }
}

void printMovements(Account* accounts, int total, float totCred, float totDeb, int maxAccount, float maxTransfer) {
    printf("\nFinal balance:\n");
    for (int i = 0; i < total; i++)
        printf("Account number: %d | Balance: $%.2f\n", accounts[i].accountNum, accounts[i].balance);
    printf("\nTotal Credits: $%.2f | Total Debits: $%.2f\n", totCred, totDeb);
    printf("\nMaximum movement registered:\n");
    printf("Account number: %d | ", maxAccount);
    printf("amount: $%.2f | type of transfer: ", maxTransfer);
    if (maxTransfer > 0)
        printf("credit\n");
    else
        printf("debit\n");
}

