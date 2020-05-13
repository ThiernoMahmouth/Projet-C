#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fonctions.c"


int main()
{
    int choix1,choix11,choix12;
    int a;
    //foncttions choix 1
    listeMachine ajouter_machine(listeMachine *listemachine);
    void supprimerMachine(listeMachine *machines, Machine *m1);
    void installerClient(Machine *ordi);
    void desinstallerClient(Machine *ordi);
    void installerServeur();
    void desinstallerServeur(Machine *ordi );

    //fonctions choix 2
    Reseau *creerReseau();
    void ajouterMachine(Reseau *rsx,Machine *pc);
    void retirerMachine(Reseau *rsx, Machine *ordi);
    void ping();
    void afficherReseau();
    debut:do
    {
        printf("Menu principal\n");
        printf("1: Gerer le parc\n");
        printf("2: Gerer le reseau\n");
        printf("3: Simuler des echanges entre clients et serveurs\n");

        scanf("%d", &choix1);
    }
    while(choix1 <0 || choix1>3);
    switch(choix1)
    {
        case 1: 
                //menu1: 
                printf("Fonctionnalites\n");
                printf("1: Ajouter une machine\n");
                printf("2: Retirer une machine\n");
                printf("3: Afficher une machine\n");
                printf("4: Installer un client\n");
                printf("5: Desinstaller un client\n");
                printf("6: Installer un serveur\n");
                printf("7: Desinstaller un serveur\n");
                printf("8: Autre\n");
                printf("9: Retour\n");
                scanf("%d",&choix11);
                Machine *m1 = malloc(sizeof(Machine));
                if (m1 = NULL){
                    return 1;
                }
                listeMachine *liste1 = malloc(sizeof(listeMachine));
                if (liste1 = NULL){
                    return 1;
                }
                switch(choix11)
                {
                    case 1: ajouter_machine(liste1);
                    break;
                    case 2: supprimerMachine(liste1, m1);
                    break;
                    case 3: afficherMachine();
                    break;
                    case 4: installerClient(m1);
                    break;
                    case 5: desinstallerClient(m1);
                    break;
                    case 6: installerServeur();
                    break;
                    case 7: desinstallerServeur(m1);
                    break;
                    case 9: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        case 2:
                //menu2: 
                printf("Fonctionnalites\n");
                printf("1: Ajouter \n");
                printf("2: Retirer \n");
                printf("3: Ping\n");
                printf("4: Afficher\n");
                printf("5: Retour\n");
                scanf("%d",&choix12);
                listeMachine *liste1 = malloc(sizeof(listeMachine));
                if (liste1 = NULL){
                    return 1;
                }
                Reseau *reseau = malloc(sizeof(Reseau));
                if (reseau = NULL){
                    return 1;
                }
                reseau = creerReseau();
                switch(choix12)
                {
                    case 1: ajouter_machine(liste1);
                    break; 
                    case 2: retirerMachineReseau(reseau, m1);
                    break;
                    case 3: ping();
                    break;
                    case 4: afficherReseau();
                    break;
                    case 5: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        
        default: printf("Fin\n");
    }

    
}