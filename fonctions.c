#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"

/************* PING par passage de l'adresse IP ***********************/
    void ping()
    {
        char* param;
        printf("Parametre de ping: ");
        scanf("%s",param);
        FILE *file=fopen("reseau.txt","r");
        if(file != NULL)
        {
            char ligne[100];
            int nbLigne=0;
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if (nbLigne!=0) 
                {
                    char ip[16],nom[20];
                    int i=0,j=0;
                    while(ligne[i]!=',')
                    {
                        ip[i]=ligne[i];
                        i++;
                    }   
                    i++;
                    while(ligne[i]!=',')
                    {
                        nom[j]=ligne[i];
                        i++;
                        j++;
                    }
                    printf("ip= %s ; nom= %s ; param= %s\n",ip,nom,param);
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
                }
                nbLigne++;
                //rewind(file);
            }
            if(nbLigne!= 99) printf("Inconnu dans le reseau\n");
            fclose(file);
        }
    }

        //*********** Recuperer une machine**************************
    void getMachine()
    {
        char* nomMachine;
        printf("Donner le nom de la machine : ");
        scanf("%s",nomMachine);
        Machine machine;
        FILE *file=fopen("fic.txt","r");
        if(file != NULL)
        {
            char ligne[1000];
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                    char id[3],ip[16],nom[20],mac[20],serveurs[200],clients[200],etat[3];
                    int i=0,j=0,k=0,l=0,m=0,n=0,o=0;
                    while(ligne[i]!=',')
                    {
                        id[i]=ligne[i];
                        i++;
                    }   
                    i++;
                    while(ligne[i]!=',')
                    {
                        nom[j]=ligne[i];
                        i++;
                        j++;
                    }
                    i++;
                    while(ligne[i]!=',')
                    {
                        mac[k]=ligne[i];
                        i++;
                        k++;
                    }
                    i++;
                    while(ligne[i]!=',')
                    {
                        etat[l]=ligne[i];
                        i++;
                        l++;
                    }
                    i++;
                    while(ligne[i]!=',')
                    {
                        ip[m]=ligne[i];
                        i++;
                        m++;
                    }
                    i++;
                    while(ligne[i]!=']')
                    {
                        clients[n]=ligne[i];
                        i++;
                        n++;
                    }
                    //clients[n]=']';
                    i+=2;
                    while(ligne[i]!=']')
                    {
                        serveurs[o]=ligne[i];
                        i++;
                        o++;
                    }
                    serveurs[o]=']';
                    if(!strcmp("pc2",nom) )
                    {
                        machine.id=atoi(id);
                        machine.nom=nom;
                        machine.adresseIp=ip;
                        machine.adresseMac=mac;
                       // machine.etat=etat;
                        machine.liste_serveurs=NULL;
                        machine.liste_clients=NULL;
                        printf("%s\n",serveurs);
                        //liste serveurs de la machine                        
                        int h=1,z;
                        char nomServeur[25];
                        listeServeurs *(*serverList)=&(machine.liste_serveurs);
                        listeServeurs *dernier=malloc(sizeof(listeServeurs));
                        do
                        {
                            z=0;
                            while(serveurs[h]!=',' || serveurs[h]!=']')
                            {
                                nomServeur[z]=serveurs[h];
                                h++;
                                z++;
                            }
                            printf("%s\n",nomServeur);
                            listeServeurs *m=malloc(sizeof(listeServeurs));
                            if(m!= NULL)
                            {
                                m->nom_serveur=nomServeur;
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
                            
                        }while(serveurs[h]!=']');
                        //liste clients de la machine
                        h=1; 
                        z=0;
                        char nomClient[25];
                        listeClients *(*clientList)=&(machine.liste_clients);
                        listeClients *dernierC=malloc(sizeof(listeClients));
                        do
                        {
                            z=0;
                            while(clients[h]!=',' || clients[h]!=']')
                            {
                                nomClient[z]=clients[h];
                                h++;
                                z++;
                            }
                            printf("%s\n",nomClient);
                            listeClients *mC=malloc(sizeof(listeClients));
                            if(mC!= NULL)
                            {
                                mC->nom_client=nomClient;
                                mC->next=NULL;
                                //Parcourt jusqu'au dernier element de la liste
                                dernierC=*clientList;
                                while(dernierC->next != NULL)
                                {
                                    dernierC=dernierC->next;
                                }
                                //Ajouter le nouvel element a la fin
                                dernierC->next=mC;
                            }
                            
                        }while(clients[h]!=']');

                        //afficherServeurs(&machine);*/
                        //printf("id= %s ; nom= %s ; mac= %s ; etat=%s ; ip=%s ; clients=%s ; serveurs=%s\n",id,nom,mac,etat,ip,clients,serveurs);
                        break;
                    }  
                //rewind(file);
            }
            /*if(nbLigne!= 99) printf("Inconnu dans le reseau\n");
            }*/
            fclose(file);
            return machine;
        }
    }
        //***********Intallation de serveurs**************************
    void installerServeur(Machine *ordi)
    {
        /*
            char* nomMachine;
            printf("Donner le nom de la machine : ");
            scanf("%s",nomMachine);

        */
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
    
}