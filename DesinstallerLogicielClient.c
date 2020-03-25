#include <stdio.h>
#include <stdlib.h>
typedef  struct listeClients
    {
        char * nom_client;
        struct listeClients * next;
    } listeClients
typedef  struct listeServeurs
    {
        char * nom_serveur;
        struct listeServeurs * suivant;
    } listeServeurs
typedef  Struct Machine
    {
        int id;
        char * nom;
        enum estConnecte {NON, OUI};
        char * adresseMac;
        char * adresseIp;
        listeClients * liste_clients;
        listeServeurs * liste_serveurs;
    } Machine
typedef  struct listeMachine
    {
        Machine machine;
        struct listeMachine * suivant;
    } listeMachine
typedef  struct parc
    {
        char * nom_parc;
        listeMachine * liste_machines;
    }
int main(int argc, char const *argv[])
{
	void deinstaller(Machine *machine, char* nomClient)
	{
     listeClients *precedent,*curseur; 
     //On test pour voir si la liste n'est pas vide
      while (machine.liste_clients != NULL)	
     	{
     		// Si le logiciel a supprimé correspond au premier element 
     		//de la liste
     		if (machine.liste_clients.nom_client==nomClient)
     		 	{   //L'adresse du premier element est stocké dans une 
     		 		//variable curseur et le nouveau premier element devient le suivant
     		 		// du precedent premier 
     		 		curseur=machine.liste_clients;
     		 		machine.liste_clients=machine.liste_clients.next;
     		 		//l'adresse sctokée dans le curseur est déallouée
     		 		free(curseur);
     		 	} 	
     		else{
	     			// Si le logiciel a suprimé n'est pas le premiere element de la liste
	     			// On affecte à la variable "precedent", le premier element de la liste
	     			//Et l'element courant à regarder est le suivant du premier, tous les elements
	     			// de la liste vont ainsi être regardés et à chaque fois, le precedent est stocké
	     			precedent=machine.liste_clients;
	     			curseur=machine.liste_clients.next;
	     			while(curseur!=NULL)
	     			{	
	     				//Pendant le parcours de chaque element de la liste, on vérifie si le nom du logiciel 
	     				// a supprimé est trouvé, si c'est le cas, on crée le lien entre le précedent et le suivant et on
	     				// efface l'element, puis on provoque la fin de la boucle avec break
	     				if (curseur->nom_client==nomClient)
	     				{
	     					precedent->next=curseur->next;
	     					free(curseur);
	     					break;
	     				}
	     			} 
	     			precedent=curseur;
	     			curseur=curseur->next;	

     			}
		}
		return 0;
	}
}
