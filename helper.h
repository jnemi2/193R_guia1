//
// Created by bauti on 8/28/2021.
//

#ifndef INC_193R_GUIA1_HELPER_H
#define INC_193R_GUIA1_HELPER_H

typedef struct client {
    int zoneNum;
    char name[25];
    char street[20];
    int streetNum;
    char userType;
    float totConsumed;
} Client;

void setClientInfo(Client* clients, int index, int zone, char* name, char* st, int stNum, char type, float totConsumed);
void clientsOverMinConsumption(Client* clients, int totClients, int maxZoneNum, float minConsumption);
void printZoneData(Client* clients, int totClients, int maxZoneNum, float minConsumption);

#endif //INC_193R_GUIA1_HELPER_H
