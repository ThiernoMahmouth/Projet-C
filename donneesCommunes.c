#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        enum estConnecte {NON, OUI} etat;
        char* adresseMac;
        char* adresseIp;
        listeClients *liste_clients;
        listeServeurs *liste_serveurs;
    } Machine;
    typedef struct listeMachine
    {
        Machine machine;
        struct listeMachine *next;
    } listeMachine;
    typedef struct parc 
    {
        char* nom_parc;
        listeMachine *liste_machines;
    } parc;

void afficherServeurs(Machine *ordi)
{
    listeServeurs *(*serverList)=&ordi->liste_serveurs;
    for (listeServeurs *data = *serverList; data != NULL; data = data->next)
    {
        printf("%s ", data->nom_serveur);
    }
    printf("\n");
}
void afficherClients(Machine *ordi)
{
    listeClients *(*clientList)=&ordi->liste_clients;
    for (listeClients *data = *clientList; data != NULL; data = data->next)
    {
        printf("%s ", data->nom_client);
    }
    printf("\n");
}

//Persistance des donnees
void updateFile(Machine *ordi)
{
    FILE *file=fopen("fic.txt","r+");
    if(file != NULL)
    {
        char ligne[1000];
        int nbLigne=1;
        while(fgets(ligne, sizeof(ligne), file)!= NULL)
        {
            if (nbLigne==ordi->id)
            {
                //attributs dans l'ordre
                fprintf(file,"%d, %s",ordi->id,ordi->nom);
                //Liste clients
                fputs(", [",file);
                for (listeClients *data = ordi->liste_clients; data != NULL; data = data->next)
                {
                    fprintf(file, "%s, ", data->nom_client);
                }
                fputs("]\n",file);
                //Liste des serveurs
                fputc('[',file);
                for (listeServeurs *data = ordi->liste_serveurs; data != NULL; data = data->next)
                {
                    fprintf(file, "%s, ", data->nom_serveur);
                }
                fputs("]\n",file);
                break;
            }
            nbLigne++;
        }
    }
            
}


        
