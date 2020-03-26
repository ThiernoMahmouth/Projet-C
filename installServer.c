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


    
    void installerServeur(Machine *ordi, int nbre)
    {
        //Tableau contenant le nom des serveurs
        char **tab_chaine= (char**) malloc(nbre*sizeof(char*));
            for(int i=0; i<nbre; i++)
            {
                tab_chaine[i]=(char *) malloc(25);
            }
            //Saisie des noms de serveurs
            for(int i=0; i<nbre; i++)
            {
                printf("Nom du serveur %d: ", i+1);
                scanf("%s",tab_chaine[i]);
            }

        listeServeurs *(*serverList)=&(ordi->liste_serveurs);
        listeServeurs *dernier=malloc(sizeof(listeServeurs));
        if(*serverList==NULL)
        {
            listeServeurs *n=malloc(sizeof(listeServeurs));
            if (n!= NULL)
            {
                n->nom_serveur=tab_chaine[0];
                n->next=NULL;
                *serverList=n;                
            } 
            for(int j=1; j<nbre;j++)
            {
                listeServeurs *m=malloc(sizeof(listeServeurs));
                if(m!= NULL)
                {
                    m->nom_serveur=tab_chaine[j];
                    m->next=NULL;
                    //Parcourt jusqu'au dernier element de la liste
                    dernier=*serverList;
                    while(dernier->next != NULL)
                    {
                        dernier=dernier->next;
                    }
                    //Ajouter le nouvel element a la fin
                    dernier->next=m;
                }
                
            }
        }
        else
        {
            for(int i=0; i<nbre;i++)
            {
                listeServeurs *m=malloc(sizeof(listeServeurs));
                if(m!= NULL)
                {
                    m->nom_serveur=tab_chaine[i];
                    m->next=NULL;
                    //Parcourt jusqu'au dernier element de la liste
                    dernier=*serverList;
                    while(dernier->next != NULL)
                    {
                        dernier=dernier->next;
                    }
                    //Ajouter le nouvel element a la fin
                    dernier->next=m;
                }
                
            }
        }
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
        /*
        //Ecriture dans le fichier
        FILE *file=fopen("fic.txt","r+");
        if(file != NULL)
        {
            char ligne[255];
            while(fgets(ligne, sizeof(ligne), file)!=NULL)
            {
                char
                if (ligne[0]==itoa(ordi->id))
                {
                    char *sousChaine= strstr(ligne,"],[");
                    fseek(file,,SEEK_CUR);
                    for (listeServeurs *data = *serverList; data != NULL; data = data->next)
                    {
                        printf("%s ", data->nom_serveur);
                    }

                }
            }
        }
        */
    }
    void afficherServeurs(Machine *ordi)
    {
        listeServeurs *(*serverList)=&ordi->liste_serveurs;
        for (listeServeurs *data = *serverList; data != NULL; data = data->next)
        {
            printf("%s ", data->nom_serveur);
        }
        printf("\n");
    }
    /*void showServers(Machine *ordi)
    {
        FILE *file=fopen("fic.txt","r");
        if(file != NULL)
        {
            char ligne[255];
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if (ligne[0]==itoa(ordi->id))
                {
                    char *sousChaine= strstr(ligne,"],[");
                    printf("%s\n",sousChaine);
                }
    }
    */
    int main()
    {
    void installerServeur(Machine* , int );
    void afficherServeurs(Machine*);
    void showServers(Machine*);

        Machine pc;
        pc.id=1;
        pc.nom="sama PC";
        pc.adresseMac="adresse mac";
        pc.adresseIp="adresse ip";
        pc.etat=NON;
        pc.liste_serveurs=NULL;
        
        installerServeur(&pc,3);
        afficherServeurs(&pc);
        //showServers(&pc);
                
                
            
    }