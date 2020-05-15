#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
//#include "ajouter.c"
#include "donneesCommunes.c"
#define DEFAULT_STRING_SIZE 30

//creer reseau
Reseau *creerReseau(){
    Reseau *reseau = malloc(sizeof(Reseau));
    if (reseau == NULL){
        return NULL;
    }
    char* adresse;
    char* masque;
    listeMachine *l1 = malloc(sizeof(listeMachine));
    if (l1 == NULL){
        return NULL;
    }
    listeMachine ajouter_machine(listeMachine *listemachine);
    printf("Entrez l'adresse du reseau\n");
    scanf("%s", adresse);
    printf("Entrez le masque du reseau\n");
    scanf("%s", masque);
    ajouter_machine(l1);
    reseau->liste_machines = l1;

    return reseau;
}
//afficher reseau
void afficherReseau()
{
    FILE *file=fopen("reseau.txt","r");
            if(file != NULL)
            {
                char ligne[1000];
                char reseau[100];
                int nbLigne=0;

                while(fgets(ligne, sizeof(ligne), file)!= NULL)
                {
                        if(nbLigne==0)
                        {
                            int i=0;
                            while(ligne[i]!='\n')
                            {
                                reseau[i]=ligne[i];
                                i++;
                            }
                            printf("----------reseau: %s -----------\n",reseau);
                            nbLigne++;
                        }
                    else
                    {
                        char ip[20]="",nom[20]="",mac[20]="";
                       //recuperation d'une ligne contenant les donnees d'une machine...
                        int i=0,j=0,k=0;
                        //extraction de l'id
                        while(ligne[i]!=',')
                        {
                            ip[i]=ligne[i];
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
                        printf("Nom: %s - ip: %s - mac: %s\n",nom,ip,mac);
                        nbLigne++;
                    }
                }
            }
    
}


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
                        for(int k=0;k<10;k++) 
                        {
                            printf("Reply from %s\n",ip);
                            sleep(1);
                        }
                        printf("%s ==> %s\n",ip,nom);
                        nbLigne=99;
                        break;
                    }
                    else
                    {
                        if(!strcmp(nom,param))
                        {
                            for(int k=0;k<10;k++) 
                            {       
                                printf("Reply from %s\n",ip);
                                sleep(1);
                            }
                            printf("%s ==> %s\n",nom,ip);
                            nbLigne=99;
                            break;
                        }
                    }
                    
                }
              
            }
            if(nbLigne!= 99) 
            {
                for(int k=0;k<5;k++) 
                {
                    printf("Request timed out.\n");
                    sleep(1);
                }
                printf("Inconnu dans le reseau\n");
            }
            fclose(file);
        }
    }

        //*********** Recuperer toutes les machines**************************
        void afficherParc()
        {
            FILE *file=fopen("fic.txt","r");
            if(file != NULL)
            {
                char ligne[1000];
                while(fgets(ligne, sizeof(ligne), file)!= NULL)
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
                        printf("nom: %s - @mac: %s - @ip: %s - clients: %s - serveurs: %s\n",nom,mac,ip,clients,serveurs);
            }
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
    /*************************************************************************************/
    Machine machine(char* nomMachine)
    {
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
    // **************** initialiserReseau *****************************
    listeMachine *initialiserReseau()
    {
        listeMachine *myList;
        FILE *file=fopen("reseau.txt","r");
            if(file != NULL)
            {
                char ligne[1000];
                listeMachine *dernier=malloc(sizeof(listeMachine));
                listeMachine *n=malloc(sizeof(listeMachine));
                listeMachine *(*MachineList);
                int nbLigne=0;
                while(fgets(ligne, sizeof(ligne), file)!= NULL)
                {
                        if(nbLigne==0)
                        {
                            
                            nbLigne++;
                        }
                    else
                    {
                        char ip[20]="",nom[20]="",mac[20]="";
                       //recuperation d'une ligne contenant les donnees d'une machine...
                        int i=0,j=0,k=0;
                        //extraction de l'id
                        while(ligne[i]!=',')
                        {
                            ip[i]=ligne[i];
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
                        Machine pc=machine(nom);
                        *MachineList=myList;
                        if (n!= NULL)
                        {
                            n->machine=&pc;
                            n->next=NULL;
                            if(*MachineList==NULL)
                            {
                                *MachineList=n;              
                            }
                            else
                            {
                                    //Parcourt jusqu'au dernier element de la liste
                                dernier=*MachineList;
                                while(dernier->next != NULL)
                                {
                                    dernier=dernier->next;
                                }
                            //Ajouter le nouvel element a la fin
                                dernier->next=n;
                            }
                        }
                        
                        nbLigne++;
                    }
                }
                fclose(file);
            }
        return myList;
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
        printf("Serveur(s) installe(s)\n");
    }
        //***********Desintallation d'un serveur**************************
        void desinstallerServeur(Machine *ordi )
        {
            char* serverName=malloc(30);
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
                    updateFile(ordi);
                    test=1;
                    break;
                }
                
                else
                {
                    precedent=courant;
                }
            }
            test==0 ? printf("Ce serveur n'est pas installe dans la machine\n"):printf("Serveur desinstalle avec succes!\n");
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
        printf("Client(s) installe(s)\n");
    }
        //***********Desinstallation de Clients**************************
    void desinstallerClient(Machine *ordi)
        {
            char* clientName=malloc(25);
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
                    updateFile(ordi);

                    test=1;
                    break;
                }
                
                else
                {
                    precedent=courant;
                }
        
            }
            test==0 ? printf("Ce client n'est pas installe dans la machine\n"):printf("Client desinstalle avec succes!\n");
        }
        //******************* Ajouter une Machine au reseau***************//
        void ajouterMachineReseau(Machine *pc)
        {
            FILE *fic=fopen("reseau.txt","r");
            if(fic!=NULL)
            {
                char ligne[100];
                while(fgets(ligne, sizeof(ligne), fic)!= NULL)
                {
                    if((strstr(ligne,pc->nom)))
                    {
                        printf("Cette machine est deja connectee!!\n");
                        fclose(fic);
                        return ;;
                    }
                }

            }
            FILE *file=fopen("reseau.txt","a+");
            if(file != NULL)
            {
            //attributs dans l'ordre
                fprintf(file,"%s,%s,%s\n",pc->adresseIp,pc->nom,pc->adresseMac);       
            }
            fclose(file);
            printf("Machine bien ajoutee!\n");
        }
        //*******************Retirer une Machine du reseau***************//
    void retirerMachineReseau(Machine *ordi)
    {

        FILE *file=fopen("reseau.txt","r");
        if(file != NULL)
        {
            char ligne[100];
            int trouve=0;
            FILE *fic=fopen("tmp.txt","w");
            while(fgets(ligne, sizeof(ligne), file)!= NULL)
            {
                if(!(strstr(ligne,ordi->nom)))
                {
                    fputs(ligne,fic);
                }
                else trouve=1;
                //rewind(file);
            }
            fclose(file);
            fclose(fic);
            remove("reseau.txt");
            rename("tmp.txt","reseau.txt");
            trouve==0? printf("Cette machine n'existe pas dans le reseau\n"):printf("Machine retiree du reseau avec succes!\n");
        }
    
}

void supprimerMachine(listeMachine *machines, Machine *m1){
        for (listeMachine *tmp = machines; tmp != NULL; tmp = tmp->next ){
            if (tmp->machine->nom = m1->nom){
                free(tmp);
            }
        }
        printf("La machime %s a été supprimée\n", m1->nom);
    }


    //DHCP
    Reseau *DHCP (Reseau *reseau, Machine *m1){
    srand(time(NULL));
    int number = 0, unique = 0;
    char* ip = "";
    char* lastDigits = "";
    printf("Tentative de connection...\n");
    listeMachine *positionMachine  (listeMachine *listemachine);

    listeMachine *positionFinale = positionMachine (reseau->liste_machines);
    strcpy (ip, reseau->addrese);
    ip[strlen(ip)-1] = 0; //suprime le dernier charactere de l'adresse donc le 0
    do{
        number = rand()%255;
        sprintf(lastDigits, "%d", number); //conversion de int a char
        strcat(ip ,lastDigits);
        listeMachine *m=malloc(sizeof(listeMachine));
        if(m!= NULL)
        {
            m->machine=m1;
            m->next=NULL;
        }
        for (listeMachine *tmp = reseau->liste_machines; tmp != NULL; tmp = tmp->next){
            if (!strcmp(tmp->machine->adresseIp, ip)){
                unique = unique++;
            }
        }
        if (unique = 0){
            positionFinale->next = m;
        }
    }while(unique != 0);
    printf("Connexion réussit.\n");
    return reseau;
}


Machine *creer_machine(){
        char* variable;
        int nb, i;
        void installerClient(Machine *ordi);
        void installerServeur(Machine *ordi);
        Machine *computer = malloc(sizeof(computer));
        if (computer != NULL){
            computer->nom = malloc(100);
            printf("Entrez le nom de la machine: \n");
            scanf("%s", computer->nom);

            installerClient(computer);

            installerServeur(computer);

            computer->adresseMac = malloc(100);
            printf("Entrez l'adresse MAC\n");
            scanf("%s", computer->adresseMac);

            computer->adresseIp = malloc(100);
            computer->adresseIp = "NA";
            computer->etat = NON;
        printf("Machine %s créée.\n", computer->nom);
        }

        return computer;
    }

    ecrireFichier(Machine *m1){
        char* etatConn=malloc(30);
        FILE *file=fopen("fic.txt","r+");
        if (file != NULL){

            if(m1->etat==0) etatConn="NON";
            else etatConn="OUI";
            fprintf(file, "%s,%s,%s,%s,", m1->nom, m1->adresseMac, m1->adresseIp, etatConn);
            fputc('[',file);
            for (listeClients *tmp = m1->liste_clients; tmp!=NULL; tmp = tmp->next){
                fprintf(file, "%s,", m1->liste_clients);
            }
            fputc(']',file);
            fputc('[',file);
            for (listeServeurs *tmp = m1->liste_serveurs; tmp!=NULL; tmp = tmp->next){
                fprintf(file, "%s,", m1->liste_serveurs);
            }
            fputc(']',file);

        }
        fclose(file);
    }

    listeMachine ajouter_machine(listeMachine *listemachine){
        int i =  malloc(sizeof(int)), n =  malloc(sizeof(int));
        printf("Combien de machines a ajouter?\n");
        scanf("%d", &n);
        Machine *creer_machine();
        listeMachine *positionMachine  (listeMachine *listemachine);
        listeMachine *listeFinale = positionMachine (listemachine);
        
        for(i = 0; i < n; i++){

            Machine *creationMachine = malloc(sizeof(Machine));
            if (creationMachine != NULL){
                creationMachine = creer_machine();
                listeMachine *computerList = malloc(sizeof(listeMachine));
                if (computerList != NULL){
                    computerList->machine = creationMachine;
                    computerList->next = NULL;
                    if (listemachine == NULL){
                        listemachine = computerList;
                        listeFinale = listemachine;
                    }else{
                        listeFinale->next = computerList;
                        listeFinale = listeFinale->next;
                    }
                }   
            }


        }
        return *listemachine;

    }

    listeMachine *positionMachine( listeMachine *listemachine){
        listeMachine *positionMachine = malloc (sizeof(listeMachine));
        if (positionMachine != NULL){
            positionMachine = listemachine;
            while (positionMachine->next != NULL){
                positionMachine = positionMachine->next;
            }
        }
        return positionMachine;
    }