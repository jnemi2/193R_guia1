//
// Created by bauti on 8/27/2021.
//

#ifndef INC_193R_GUIA1_HELPER_H
#define INC_193R_GUIA1_HELPER_H

typedef struct account{
    int accountNum;
    float balance;
} Account;

void loadAccounts(Account*, int);
void processMovements(Account*, int);
void printMovements(Account* accounts, int total, float totCred, float totDeb, int maxAccount, float maxTransfer);
int validateInt(int, int, char*);
float validatePositive(char*);

#endif //INC_193R_GUIA1_HELPER_H
