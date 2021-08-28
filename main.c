#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

#define TOTAL_ACCOUNTS 100

int main() {
    printf("Hello, World!\n");
    Account accounts[TOTAL_ACCOUNTS];
    loadAccounts(accounts, TOTAL_ACCOUNTS);
    printf("Ingrese los movimientos de hoy:\n");
    processMovements(accounts, TOTAL_ACCOUNTS);

    return 0;
}
