#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"

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
        updateFile(ordi);
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
    