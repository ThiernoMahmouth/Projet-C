#include<stdio.h>
#include<stdlib.h>
#include "donneesCommunes.c"


    void installerClient(Machine *ordi, int nbre)
    {
        //Tableau contenant le nom des serveurs
        char **tab_chaine= (char**) malloc(nbre*sizeof(char*));
            for(int i=0; i<nbre; i++)
            {
                tab_chaine[i]=(char *) malloc(25);
            }
            //Saisie des noms de client
            for(int i=0; i<nbre; i++)
            {
                printf("Nom du client %d: ", i+1);
                scanf("%s",tab_chaine[i]);
            }

        listeClients *(*clientList)=&(ordi->liste_clients);
        listeClients *dernier=malloc(sizeof(listeClients));
        if(*clientList==NULL)
        {
            listeClients *n=malloc(sizeof(listeClients));
            if (n!= NULL)
            {
                n->nom_client=tab_chaine[0];
                n->next=NULL;
                *clientList=n;                
            } 
            for(int j=1; j<nbre;j++)
            {
                listeClients *m=malloc(sizeof(listeClients));
                if(m!= NULL)
                {
                    m->nom_client=tab_chaine[j];
                    m->next=NULL;
                    //Parcourt jusqu'au dernier element de la liste
                    dernier=*clientList;
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
                listeClients *m=malloc(sizeof(listeClients));
                if(m!= NULL)
                {
                    m->nom_client=tab_chaine[i];
                    m->next=NULL;
                    //Parcourt jusqu'au dernier element de la liste
                    dernier=*clientList;
                    while(dernier->next != NULL)
                    {
                        dernier=dernier->next;
                    }
                    //Ajouter le nouvel element a la fin
                    dernier->next=m;
                }
                
            }
        }
        updateFile(ordi);
    }
