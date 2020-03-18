#include<stdio.h>
#include<stdlib.h>

    void ajouterMachine()
    {
        printf("Machine ajoutee!\n");
    }
    void retirerMachine()
    {
        printf("Machine retiree!\n");
    }
    void afficherMachine()
    {
        printf("Liste Machines\n");
    }
    void installerClient()
    {
        printf("Client installe!\n");
    }
    void desinstallerClient()
    {
        printf("Client desinstalle!\n");
    }
    void installerServeur()
    {
        printf("Serveur installe!\n");
    }
    void desinstallerServeur()
    {
        printf("Serveur desinstalle!\n");
    }

    typedef struct listeClients
        {
            char* nom_client;
            struct listeClients *next;
        } listeClients
    typedef struct listeServeurs
        {
            char* nom_serveur;
            struct listeServeurs *next;
        } listeServeurs
    typedef struct Machine 
    {
        int id;
        char* nom;
        enum estConnecte {NON, OUI};
        char* adresseMac;
        char* adresseIp;
        listeClients *liste_clients;
        listeServeurs *liste_serveurs;
    } Machine
    typedef struct listeMachine
    {
        Machine machine;
        struct listeMachine *next;
    } listeMachine
    typedef struct parc 
    {
        char* nom_parc;
        listeMachine *liste_machines;
    }

int main()
{
    int choix1,choix11,choix12;
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
                menu1: printf("Fonctionnalites\n");
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
                switch(choix11)
                {
                    case 1: ajouterMachine();
                    break;
                    case 2: retirerMachine();
                    break;
                    case 3: afficherMachine();
                    break;
                    case 4: installerClient();
                    break;
                    case 5: desinstallerClient();
                    break;
                    case 6: installerServeur();
                    break;
                    case 7: desinstallerServeur();
                    break;
                    case 9: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        case 2:
                menu2: printf("Fonctionnalites\n");
                printf("1: Ajouter \n");
                printf("2: Retirer \n");
                printf("3: Ping\n");
                printf("4: Afficher\n");
                printf("5: Autre\n");
                printf("6: Retour\n");
                scanf("%d",&choix12);
                switch(choix12)
                {
                    case 6: goto debut;
                    break;
                    default: printf("Choix note!!");
                }
        break;
        
        default: printf("Fin\n");
    }

    
}