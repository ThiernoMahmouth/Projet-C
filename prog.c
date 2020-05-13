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
    void afficherParc();
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

        scanf("%d", &choix1);
    }
    while(choix1 <0 || choix1>2);
    switch(choix1)
    {
        case 1: 
                //menu1: 
                printf("Fonctionnalites\n");
                printf("1. Creer Machine\n");
                printf("2: Ajouter machine\n");
                printf("3: Retirer machine\n");
                printf("4: Afficher machine\n");
                printf("5: Installer client\n");
                printf("6: Desinstaller client\n");
                printf("7: Installer serveur\n");
                printf("8: Desinstaller serveur\n");
                printf("9: Retour\n");
                scanf("%d",&choix11);
                Machine *m1 = malloc(sizeof(Machine));
                if (m1 = NULL){
                    return NULL;
                }
                listeMachine *liste1 = malloc(sizeof(listeMachine));
                if (liste1 = NULL){
                    return NULL;
                }
                switch(choix11)
                {
                    case 1: m1 = creer_machine();
                    break;
                    case 2: ajouter_machine(liste1);
                    break;
                    case 3: supprimerMachine(liste1, m1);
                    break;
                    case 4: afficherParc();
                    break;
                    case 5: installerClient(m1);
                    break;
                    case 6: desinstallerClient(m1);
                    break;
                    case 7: installerServeur(m1);
                    break;
                    case 8: desinstallerServeur(m1);
                    break;
                    case 9: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        case 2:
                //menu2: 
                printf("Fonctionnalites\n");
                printf("1: Ajouter Machine \n");
                printf("2: Retirer Machine\n");
                printf("3: Ping\n");
                printf("4: Afficher\n");
                printf("5: DHCP\n");
                printf("6: Retour\n");
                scanf("%d",&choix12);
                listeMachine *listeReseau = malloc(sizeof(listeMachine));
                if (listeReseau = NULL){
                    return NULL;
                }
                Reseau *reseau = malloc(sizeof(Reseau));
                if (reseau = NULL){
                    return NULL;
                }
                reseau = creerReseau();
                switch(choix12)
                {
                    
                    case 1: ajouter_machine(listeReseau);
                    break; 
                    case 2: retirerMachineReseau(reseau, m1);
                    break;
                    case 3: ping();
                    break;
                    case 4: afficherReseau();
                    break;
                    case 5: DHCP(reseau, m1);
                    break;
                    case 6: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        
        default: printf("Fin\n");
    }

    
}