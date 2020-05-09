#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"

        //***********Intallation de serveurs**************************
    void installerServeur(Machine *ordi)
    {
        int nbre;
        printf("Nombre de servers a installer: ");
        scanf("%d",&nbre); 
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
        //***********Desintallation d'un serveur**************************
        void desinstallerServeur(Machine *ordi )
        {
            char* serverName;
            printf("Nom du serveur a desinstaller: ");
            scanf("%s",serverName);
            listeServeurs *(*serverList)=&(ordi->liste_serveurs);
            listeServeurs *precedent= NULL;
            int i=0;
            for(listeServeurs *courant=*serverList; courant!= NULL; courant=courant->next)
            {
                listeServeurs *suivant=courant->next;
                if (!strcmp(courant->nom_serveur,serverName))
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
        
            }
        }
        //***********Installation de Clients**************************
    void installerClient(Machine *ordi)
    {
        int nbre;
        printf("Nombre de Clients a installer: ");
        scanf("%d",&nbre); 
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
        //***********Desinstallation de Clients**************************
    void desinstallerClient(Machine *ordi)
        {
            char* clientName;
            printf("Nom du client a desinstaller: ");
            scanf("%s",clientName);
            listeClients *(*clientList)=&(ordi->liste_clients);
            listeClients *precedent= NULL;
            int i=0;
            for(listeClients *courant=*clientList; courant!= NULL; courant=courant->next)
            {
                listeClients *suivant=courant->next;
                if (!strcmp(courant->nom_client,clientName))
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
                        *clientList=suivant;
                    }
                }
                
                else
                {
                    precedent=courant;
                }
        
            }
        }
        //*******************Ajouter une Machine au reseau***************//
        void ajouterMachineReseau(Reseau *reseau,Machine pc)
        {
            listeMachine *(*MachineList)=&(reseau->liste_machines);
            listeMachine *n=malloc(sizeof(listeMachine));
            if (n!= NULL)
            {
                n->machine=pc;
                n->next=NULL;
            }
            if(*MachineList==NULL)
            {
                *MachineList=n;              
            }
            else
            {
                    //Parcourt jusqu'au dernier element de la liste
                listeMachine *dernier=malloc(sizeof(listeMachine));
                dernier=*MachineList;
                while(dernier->next != NULL)
                {
                    dernier=dernier->next;
                }
                //Ajouter le nouvel element a la fin
                dernier->next=n;
            }
            FILE *file=fopen("reseau.txt","a+");
            if(file != NULL)
            {
            //attributs dans l'ordre
                fprintf(file,"%d, %s, %s, %s\n",pc.id,pc.nom,pc.adresseIp,pc.adresseMac);       
            }
            fclose(file);
        }
        //*******************Retirer une Machine du reseau***************//
    void retirerMachineReseau(Reseau *rsx, Machine ordi)
    {
        listeMachine *(*machineList)=&(rsx->liste_machines);
        listeMachine *precedent= NULL;
        int i=0;
        for(listeMachine *courant=*machineList; courant!= NULL; courant=courant->next)
        {
            listeMachine *suivant=courant->next;
            if (!strcmp(courant->machine.nom,ordi.nom))
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
                    *machineList=suivant;
                }
            }
            else
            {
                precedent=courant;
            }
        }
        FILE *file=fopen("reseau.txt","r");
        if(file != NULL)
        {
            char ligne[100];
            int nbLigne=0;
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if (nbLigne==0) continue;
                else
                {
                    char mot[5];
                    int i=0;
                    while(ligne[i]!=',')
                    {
                        mot[i]=ligne[i];
                        i++;
                    }
                    printf("%s",mot);
                    printf("\n");
                    nbLigne++;
                }
                
                //rewind(file);
            }
            fclose(file);
    }
    /************* PING par passage de l'adresse IP ***********************/
    void ping(char *param)
    {
        FILE *file=fopen("reseau.txt","r");
        if(file != NULL)
        {
            char ligne[100];
            int nbLigne=0;
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if (nbLigne==0) continue;
                else
                {
                    char ip[16],nom[20];
                    int i=0;
                    while(ligne[i]!=',')
                    {
                        ip[i]=ligne[i];
                        i++;
                    }
                    i=i+2;
                    while(ligne[i]!=',')
                    {
                        nom[i]=ligne[i];
                        i++;
                    }
                    if(!strcmp(ip,param) )
                    {
                        printf("Cet addresse IP est attribuee a %s\n",nom);
                        nbLigne=99;
                        break;
                    }
                    else if(!strcmp(nom,param))
                    {
                        printf("Cette machine est connectee avec l'adresse %s\n",ip);
                        nbLigne=99;
                        break;
                    }
                    nbLigne++;
                }
                //rewind(file);
            }
            if(nbLigne!= 99) printf("Machine pas connectee dans le reseau\n");
            fclose(file);
        }
    }
}