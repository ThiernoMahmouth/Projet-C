#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"
#define DEFAULT_STRING_SIZE 30


void ajouterMachine(Reseau *rsx,Machine pc)
{
    listeMachine *(*MachineList)=&(rsx->liste_machines);
    listeMachine *dernier=malloc(sizeof(listeMachine));
    if(*MachineList==NULL)
    {
        listeMachine *n=malloc(sizeof(listeMachine));
        if (n!= NULL)
        {
            n->machine=pc;
            n->next=NULL;
            *MachineList=n;                
        } 
    }
    else
    {
        listeMachine *m=malloc(sizeof(listeMachine));
        if(m!= NULL)
        {
            m->machine=pc;
            m->next=NULL;
            //Parcourt jusqu'au dernier element de la liste
            dernier=*MachineList;
            while(dernier->next != NULL)
            {
                dernier=dernier->next;
            }
            //Ajouter le nouvel element a la fin
            dernier->next=m;
        }
    }
}
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

void getMachine()
{
    int id_machine = 0;
    char *nom_machine, *adresse_mac, *adresse_ip, *est_connecte, *listeClients;
    wchar_t *s_liste_clients, *s_liste_serveurs;
    char enregistrement[DEFAULT_STRING_SIZE * 500];
    char* token = NULL;
    FILE* file = fopen("fic.txt", "r");
    //int nombre_machine = 7;

    if (!file) {
        perror("Erreur lors de l'ouverture du fichier contenant les enregistrements");
        return ;;
    }

    //fscanf(f_enregistrements, "%d", &nombre_machine);

   // for (int i = 0; (i < nombre_machine) && (!feof(f_enregistrements)); i++)
    while(fgets(enregistrement, sizeof(enregistrement), file)!= NULL)
    {
        fscanf(file, "%s", enregistrement);
        id_machine = atoi(strtok(enregistrement, ","));
        nom_machine = strtok(NULL, ",");
        adresse_mac = strtok(NULL, ",");
        est_connecte = strtok(NULL, ",");
        adresse_ip = strtok(NULL, ",");
        liste_clients = strtok(NULL, ",");
        for(int i=0; i<)
        s_liste_serveurs = strtok(NULL, ",");
        printf("%d, %s, %s, %s, %s, %ls, %lls\n", id_machine, nom_machine, adresse_mac, est_connecte, adresse_ip, s_liste_clients, s_liste_serveurs);
    }
    
    
}
int main()
{
    void getMachine();
    getMachine();
}
