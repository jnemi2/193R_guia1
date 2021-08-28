#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

#define TOT_CLIENTS 5
#define MAX_ZONE 2

int main() {
    printf("Hello, World!\n");
    Client clients[TOT_CLIENTS];
    setClientInfo(clients, 0, 1, "Mike", "Hollister", 5201, 'P', 115);
    setClientInfo(clients, 1, 2, "Nathan", "Alondra drive", 1301, 'C', 50);
    setClientInfo(clients, 2, 1, "Noah", "Dundas", 4201, 'C', 75);
    setClientInfo(clients, 3, 2, "Harper", "Kennedy", 1969, 'C', 70);
    setClientInfo(clients, 4, 0, "Erin", "Durham", 2021, 'P', 170);
    clientsOverMinConsumption(clients, TOT_CLIENTS, MAX_ZONE, 7);
    printf("\n");
    printZoneData(clients, TOT_CLIENTS, MAX_ZONE, 7);

    return 0;
}
