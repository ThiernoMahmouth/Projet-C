#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"


void ajouterMachine(Reseau *rsx,Machine pc)
{
    listeMachine *(*MachineList)=&(rsx->liste_machines);
    listeMachine *dernier=malloc(sizeof(listeMachine));
    if(*MachineList==NULL)
    {
        listeMachine *n=malloc(sizeof(listeMachine));
        if (n!= NULL)
        {
            n->Machine=pc;
            n->next=NULL;
            *MachineList=n;                
        } 
    }
    else
    {
        listeMachine *m=malloc(sizeof(listeMachine));
        if(m!= NULL)
        {
            m->Machine=pc;
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
void retirerMachine(Reseau *rsx, Machine ordi)
{
    listeMachine *(*machineList)=&(rsx->liste_machines);
    listeMachine *precedent= NULL;
    int i=0;
    for(listeMachine *courant=*machineList; courant!= NULL; courant=courant->next)
    {
        listeMachine *suivant=courant->next;
        if (!strcmp(courant->machine->nom,ordi->nom))
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
}