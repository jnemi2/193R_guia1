//
// Created by bauti on 8/28/2021.
//

#include "helper.h"
#include <stdio.h>
#include <string.h>

void setClientInfo(Client *clients, int index, int zone, char *name, char *st, int stNum, char type, float totConsumed) {
    clients[index].zoneNum = zone;
    strcpy(clients[index].name, name);
    strcpy(clients[index].street, st);
    clients[index].streetNum = stNum;
    clients[index].userType = type;
    clients[index].totConsumed = totConsumed;
}

void clientsOverMinConsumption(Client *clients, int totClients, int maxZoneNum, float minConsumption) {
    for (int z = 0; z <= maxZoneNum; z++){
        printf("Zone %d:\n", z);
        for (int c = 0; c < totClients; c++){
            if (clients[c].zoneNum == z && clients[c].totConsumed >= minConsumption){
                printf("User %c, %s. %d %s. Total consumed $%.2f\n", clients[c].userType, clients[c].name,
                       clients[c].streetNum, clients[c].street, clients[c].totConsumed);
            }
        }
    }
}

void printZoneData(Client *clients, int totClients, int maxZoneNum, float minConsumption) {
    float averageConsumption, totRevenue;
    int qClients, maxConsumptionClient, qPMin, qCMin;
    for (int z = 0; z <= maxZoneNum; z++){
        totRevenue = 0;
        qClients = 0;
        qPMin = 0;
        qCMin = 0;
        maxConsumptionClient = -1;
        for (int c = 0; c < totClients; c++){
            if (clients[c].zoneNum == z){
                qClients++;
                totRevenue += clients[c].totConsumed;
                if (maxConsumptionClient == -1 || clients[c].totConsumed > clients[maxConsumptionClient].totConsumed)
                    maxConsumptionClient = c;
                if (clients[c].totConsumed >= minConsumption){
                    if (clients[c].userType == 'P')
                        qPMin++;
                    else
                        qCMin++;
                }
            }
        }
        if (qClients > 0)
            averageConsumption = totRevenue / qClients;
        printf("Zone %d>> average consumption $%.2f, best client address %d %s. "
               "Tot rev $%.2f. Total users type P|C: %d|%d\n", z, averageConsumption,
               clients[maxConsumptionClient].streetNum, clients[maxConsumptionClient].street, totRevenue, qPMin, qCMin);
    }
}
