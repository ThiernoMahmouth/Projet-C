#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fonctions.c"

int main()
{
        Machine pc;
        char *serveur;
        //int nbServerIns,nbClientIns;
        pc.id=1;
        pc.nom="sama PC";
        pc.adresseMac="adresse mac";
        pc.adresseIp="adresse ip";
        pc.etat=NON;
        pc.liste_serveurs=NULL;
        pc.liste_clients=NULL;
        // *****************Serveur********************//
        installerServeur(&pc);
        afficherServeurs(&pc);
        char **tab=(char**) malloc(sizeof(char*));
        tab[0]=(char *) malloc(25);
        printf("Nom du serveur a desinstaller: ");
        scanf("%s",tab[0]);
        desinstallerServeur(&pc,tab[0]);
        afficherServeurs(&pc);
        // *******************Client*****************///////
        installerClient(&pc);
        afficherClients(&pc);
        tab[1]=(char *) malloc(25);
        printf("Nom du client a desinstaller: ");
        scanf("%s",tab[1]);
        desinstallerClient(&pc,tab[1]);
        afficherClients(&pc);
}

