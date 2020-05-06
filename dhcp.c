#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "donneesCommunes.c"
#include "ajouter.c"

Reseau *DHCP (Reseau *reseau, Machine *m1){
    srand(time(NULL));
    int number = 0, unique = 0;
    char* ip = "";
    char* lastDigits = "";
    printf("Tentative de connection...\n");
    listeMachine *positionMachine  (listeMachine *listemachine);
    listeMachine *positionFinale = positionMachine (reseau->liste_machines);
    strcpy (ip, reseau->addrese);
    ip[strlen(ip)-1] = 0; //suprime le dernier charactere de l'adresse donc le 0
    do{
        number = rand()%255;
        sprintf(lastDigits, "%d", number); //conversion de int a char
        strcat(ip ,lastDigits);
        for (listeMachine *tmp = reseau; tmp != NULL; tmp = tmp->next){
            if (tmp->machine->adresseIp = ip){
                unique = unique++;
            }
        }
        if (unique = 0){
            positionFinale->next = m1;
        }
    }while(unique != 0);
    printf("Connexion réussit.\n");
    return reseau;
}