#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//structures
typedef enum {NON, OUI} esConnecte;

typedef struct listeClients
        {
            char* nom_client;
            struct listeClients *next;
        } listeClients;

    typedef struct listeServeurs
        {
            char* nom_serveur;
            struct listeServeurs *next;
        } listeServeurs;

    typedef struct Machine 
    {
        int id;
        char* nom;
        esConnecte connection;
        char* adresseMac;
        char* adresseIp;
        listeClients *liste_clients;
        listeServeurs *liste_serveurs;
    } Machine;

    typedef struct listeMachine
    {
        Machine *machine;
        struct listeMachine *next;
    } listeMachine;

    typedef struct parc 
    {
        char* nom_parc;
        listeMachine *liste_machines;
    } Parc;


    supprimerMachine(listeMachine *machines, Machine *m1){
        for (listeMachine *tmp = machines; tmp != NULL; tmp = tmp->next ){
            if (tmp->machine->nom = m1->nom){
                free(tmp);
            }
        }
    }