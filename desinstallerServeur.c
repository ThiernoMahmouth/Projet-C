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

    void updateFile(Machine *ordi)
        {
            FILE *file=fopen("fic.txt","r+");
                if(file != NULL)
                {
                    char ligne[1000];
                    while(fgets(ligne, sizeof(ligne), file)!= NULL)
                    {
                        if (ligne[0]==itoa(ordi->id))
                        {
                            //attributs dans l'ordre
                            fprintf("%d, %s, %s, %s, %s",ordi->id,ordi->nom,ordi->adresseMac,ordi->etat,ordi->adresseIp);
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

                        }
                    }
                }
        }
        void desinstallerServeur(Machine *ordi, char *serverName)
        {
            listeServeurs *(*serverList)=&(ordi->liste_serveurs);
            listeServeurs *precedent= NULL;
            listeServeurs *courant=*serverList;
            while(courant)
            {
                listeServeurs *suivant=courant->next;
                if (courant->nom_serveur==serverName)
                {
                    //suppession
                    free(courant);
                    //pointe sur ...
                    if (precedent!=NULL)
                    {
                        precedent->next=suivant;
                    }
                    else    //c le 1er element de la liste donc il n'a pas de precedent
                    {
                        *serverList=suivant;
                    }
                }
                else
                {
                    precedent=courant;
                }
                courant=suivant;
            }
        }