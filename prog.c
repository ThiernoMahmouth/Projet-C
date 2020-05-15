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
    Reseau *reseau;

    //fonctions choix 2
    Reseau *creerReseau();
    void ajouterMachine(Reseau *rsx,Machine *pc);
    void retirerMachine(Reseau *rsx, Machine *ordi);
    void ping();
    void afficherReseau();
do {

    debut:do{
    printf("***************************** Menu principal *****************************\n");
    printf("1: Gerer le parc\n");
    printf("2: Gerer le reseau\n");
    printf("3: Quitter l'application\n");
    scanf("%d", &choix1);
    }while (choix1 <0 || choix1>3);
    switch(choix1)
    {
        case 1: 
                menu1: 
                printf("---------------------------------------Gerer Parc-------------------------------\n");
                printf("1. Creer Machine\n");
                printf("2: Ajouter machine\n");
                printf("3: Retirer machine\n");
                printf("4: Afficher parc\n");
                printf("5: Selectionner Machine\n");
                
                printf("6: Retour\n");
                scanf("%d",&choix11);
                Machine *m1 = malloc(sizeof(Machine));
                if (m1 = NULL){
                    return NULL;
                }
                listeMachine *liste1 = malloc(sizeof(listeMachine));
                Machine pc,ordi;

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
                            select:
                            printf("Machine selectionne!\n");
                            printf("1: Installer client\n");
                            printf("2: Desinstaller client\n");
                            printf("3: Installer serveur\n");
                            printf("4: Desinstaller serveur\n");
                            printf("5: ping\n");
                            printf("6: Ajouter au reseau\n");
                            printf("7: Retirer du reseau\n");
                            printf("8: Retour\n");
                            scanf("%d",&repS);
                            switch (repS)
                            {
                            case 1: 
                                installerClient(&pc);
                                goto select;
                            break;
                            case 2: 
                                desinstallerClient(&pc);
                                goto select;
                            break;
                            case 3: 
                                installerServeur(&pc);
                                goto select;
                            break;
                            case 4: 
                                desinstallerServeur(&pc);
                                goto select;
                            break;
                            case 5: 
                                ping();
                                goto select;
                            break;
                            case 6: 
                                ajouterMachineReseau(&pc);
                                goto select;
                            break;
                            case 7: 
                                retirerMachineReseau(&pc);
                                goto select;
                            break;
                            default: goto menu1;
                                break;
                            }

                        }
                            break;
                    
                    case 6: goto debut;
                    break;
                    default: 
                        printf("Choix indisponible!!");
                        goto  debut;
                    
                }
        break;
        case 2:
                menu2: 
                printf("---------------------------------------Gerer Reseau-------------------------------\n");
                printf("1: Ajouter Machine \n");
                printf("2: Retirer Machine\n");
                printf("3: Ping\n");
                printf("4: Afficher\n");
                printf("5: DHCP\n");
                printf("6: Retour\n");
                scanf("%d",&choix12);
                /*listeMachine *listeReseau = malloc(sizeof(listeMachine));
                if (listeReseau = NULL){
                    return NULL;
                }
                Reseau *reseau = malloc(sizeof(Reseau));
                if (reseau = NULL){
                    return NULL;
                }
                reseau->addrese="192.168.140.0" ;
                reseau->masque="/24";*/
                //reseau->liste_machines=initialiserReseau();
                switch(choix12)
                {
                    case 1: 
                        ordi= getMachine();
                        if(ordi.id>0)
                        {
                            ajouterMachineReseau(&ordi);
                        }
                    break; 
                    case 2: 
                        ordi= getMachine();
                        if(ordi.id>0)
                        {
                            retirerMachineReseau(&ordi);
                        }
                    
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
        case 3: 
            printf("Vous venez de quitter\nMerci!\n");
            return 0;
        break;
        default: 
            printf("Choix indisponible\n");
            goto debut;
        break;
    }
}while(true);
    
}
