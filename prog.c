#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fonctions.c"


int main()
{
    int choix1,choix11,choix12,repS;
    int a;
    //foncttions choix 1
    Machine *creer_machine();
    listeMachine ajouter_machine(listeMachine *listemachine);
    void supprimerMachine(listeMachine *machines, Machine *m1);
    void afficherParc();
    Machine getMachine();
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
do {
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
                menu1: 
                printf("Fonctionnalites\n");
                printf("1. Creer Machine\n");
                printf("2: Ajouter machine\n");
                printf("3: Retirer machine\n");
                printf("4: Afficher parc\n");
                printf("5: Selectionner Machine\n");
                
                printf("10: Retour\n");
                scanf("%d",&choix11);
                Machine *m1 = malloc(sizeof(Machine));
                if (m1 = NULL){
                    return NULL;
                }
                listeMachine *liste1 = malloc(sizeof(listeMachine));
                Machine pc;

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
                    case 5: 
                        pc= getMachine();
                        if(pc.id>0)
                        {
                            printf("Machine selectionne!\n");
                            printf("1: Installer client\n");
                            printf("2: Desinstaller client\n");
                            printf("3: Installer serveur\n");
                            printf("4: Desinstaller serveur\n");
                            printf("5: Retour\n");
                            scanf("%d",&repS);
                            switch (repS)
                            {
                            case 1: installerClient(&pc);
                            break;
                            case 2: desinstallerClient(&pc);
                            break;
                            case 3: installerServeur(&pc);
                            break;
                            case 4: desinstallerServeur(&pc);
                            break;
                            default: goto menu1;
                                break;
                            }

                        }
                            break;
                    
                    case 10: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        case 2:
                menu2: 
                printf("Fonctionnalites\n");
                printf("1: Creer Reseau\n");
                printf("2: Ajouter Machine \n");
                printf("3: Retirer Machine\n");
                printf("4: Ping\n");
                printf("5: Afficher\n");
                printf("6: DHCP\n");
                printf("7: Retour\n");
                scanf("%d",&choix12);
                listeMachine *listeReseau = malloc(sizeof(listeMachine));
                if (listeReseau = NULL){
                    return NULL;
                }
                Reseau *reseau = malloc(sizeof(Reseau));
                if (reseau = NULL){
                    return NULL;
                }
                switch(choix12)
                {
                    case 1: reseau = creerReseau(reseau);
                    case 2: ajouter_machine(listeReseau);
                    break; 
                    case 3: retirerMachineReseau(reseau, m1);
                    break;
                    case 4: ping();
                    break;
                    case 5: afficherReseau();
                    break;
                    case 6: DHCP(reseau, m1);
                    break;
                    case 7: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        
        default: printf("Fin\n");
    }
}while(true);
    
}
