#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"

/************* PING par passage de l'adresse IP ***********************/
    void ping()
    {
        char* param=malloc(30);
        printf("Le parametre de ping doit etre soit le nom soit l'adresse ip d'une machine donnee\n ");
        printf("ping   ");
        scanf("%s",param);
        FILE *file=fopen("reseau.txt","r");
        if(file != NULL)
        {
            char ligne[100];
            int nbLigne=0;
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if(strstr(ligne,param))
                {
                    char ip[20],nom[20];
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
                    if(!strcmp(ip,param))
                    {
                        printf("%s ==> %s\n",ip,nom);
                        nbLigne=99;
                        break;
                    }
                    else
                    {
                        if(!strcmp(nom,param))
                        {
                            printf("%s ==> %s\n",nom,ip);
                            nbLigne=99;
                            break;
                        }
                    }
                    
                }
              
            }
            if(nbLigne!= 99) printf("Inconnu dans le reseau\n");
            fclose(file);
        }
    }

        //*********** Recuperer une machine**************************
    Machine getMachine()
    {
    
        char* nomMachine=malloc(30);
        printf("Donner le nom de la machine : ");
        scanf("%s",nomMachine);
       // printf("Vous avez saisi %s\n",nomMachine);
        Machine machine;
        FILE *file=fopen("fic.txt","r");
        if(file != NULL)
        {
            char ligne[1000];
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if(strstr(ligne,nomMachine))
                {
                //recuperation d'une ligne contenant les donnees d'une machine...
                    char id[3],ip[16],nom[20],mac[20],etat[3];
                    char serveurs[200]="";
                    char clients[200]="";
                    int i=0,j=0,k=0,l=0,m=0,n=0,o=0;
                    //extraction de l'id
                    while(ligne[i]!=',')
                    {
                        id[i]=ligne[i];
                        i++;
                    }   
                    i++;
                    //extraction du nom
                    while(ligne[i]!=',')
                    {
                        nom[j]=ligne[i];
                        i++;
                        j++;
                    }
                    i++;
                    //extraction de l'adresse mac
                    while(ligne[i]!=',')
                    {
                        mac[k]=ligne[i];
                        i++;
                        k++;
                    }
                    i++;
                    //extraction de l'etat de la machine
                    while(ligne[i]!=',')
                    {
                        etat[l]=ligne[i];
                        i++;
                        l++;
                    }
                    i++;
                    //extraction de l'adresse ip
                    while(ligne[i]!=',')
                    {
                        ip[m]=ligne[i];
                        i++;
                        m++;
                    }
                    i++;
                    //extraction de la liste des clients
                    while(ligne[i]!=']')
                    {
                        clients[n]=ligne[i];
                        i++;
                        n++;
                    }
                    clients[n]=']';
                    i+=2;
                    //extraction de la liste des serveurs
                    while(ligne[i]!=']')
                    {
                        serveurs[o]=ligne[i];
                        i++;
                        o++;
                    }
                    serveurs[o]=']';
                    //stocke les donnees extraites dans la machine resultat
                        machine.id=atoi(id);
                        machine.nom=nom;
                        machine.adresseIp=ip;
                        machine.adresseMac=mac;
                        if(!strcmp(etat,"OUI"))
                        {
                            machine.etat=1;
                        }
                        else machine.etat=0;
            
                        machine.liste_serveurs=NULL;
                        machine.liste_clients=NULL;
                        //ajout de la liste des clients de la machine  
                    listeClients *(*clientList)=&(machine.liste_clients);
                    listeClients *dernierClient=malloc(sizeof(listeClients));  
                                
                    char*  separateurs="[,]";
                    char* clientNames=strtok(clients,separateurs);
                    while(clientNames!=NULL)
                    {
                        listeClients *m=malloc(sizeof(listeClients));
                        if(m!= NULL)
                        {
                                m->nom_client=clientNames;
                                m->next=NULL;
                                //Parcourt jusqu'au dernier element de la liste
                                if(*clientList==NULL)
                                {
                                    *clientList=m;
                                }
                                else 
                                {

                                    dernierClient=*clientList;
                                    while(dernierClient->next != NULL)
                                    {
                                        dernierClient=dernierClient->next;
                                    }
                                }
                                
                                //Ajouter le nouvel element a la fin
                                dernierClient->next=m;
                        }
                        clientNames=strtok(NULL,separateurs);

                    }
                        //ajout de la liste des serveurs de la machine  
                    listeServeurs *(*serverList)=&(machine.liste_serveurs);
                    listeServeurs *dernier=malloc(sizeof(listeServeurs));  
                                
                    char* serverNames=strtok(serveurs,separateurs);
                    while(serverNames!=NULL)
                    {
                        listeServeurs *m=malloc(sizeof(listeServeurs));
                        if(m!= NULL)
                        {
                                m->nom_serveur=serverNames;
                                m->next=NULL;
                                //Parcourt jusqu'au dernier element de la liste
                                if(*serverList==NULL)
                                {
                                    *serverList=m;
                                }
                                else 
                                {

                                    dernier=*serverList;
                                    while(dernier->next != NULL)
                                    {
                                        dernier=dernier->next;
                                    }
                                }
                                
                                //Ajouter le nouvel element a la fin
                                dernier->next=m;
                        }
                        serverNames=strtok(NULL,separateurs);

                    }
                    fclose(file);
                    return machine;

                }
            }
        
            fclose(file);
            printf("Cette Machine n'existe pas dans le parc\n");
            machine.id=-99999;
            return machine;
        }
    }
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
            int i=0,test=0;

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
                    test=1;
                    break;
                }
                
                else
                {
                    precedent=courant;
                }
            }
            test==0 ? printf("Ce serveur n'est pas installe dans la machine\n"):printf("Serveur desinstalle avec succes!");
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
            int i=0,test=0;
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
                    test=1;
                    break;
                }
                
                else
                {
                    precedent=courant;
                }
        
            }
            test==0 ? printf("Ce client n'est pas installe dans la machine\n"):printf("Client desinstalle avec succes!");
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
        int i=0,test=0;
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
                test=1;
                break;
            }
            else
            {
                precedent=courant;
            }
        }
        test==0? printf("Cette machine n'existe pas dans le reseau\n"):printf("Machine retiree du reseau avec succes!\n");
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