#include<stdio.h>
#include<stdlib.h>
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
// La fonction prend en paramètre une machine et le nom du logiciel client qu'on doit y installer
void installer(Machine *machine, char* nomClient) {
	// Ce pointeur va nous permettre d'itérer au cas où y'aurait plus d'un logiciel client dans la liste
	//des logiciels clients de la machine
	listeClients * curseur;
	// Ici on crée un nouveau logiciel client
	listeClients * nouveauClient = (listeClients*)malloc(sizeof(listeClients));
	// On vérifie si la machine compte déja des logiciels clients. Si tel est le cas on va itérer jusqu'au dernier
	// logiciel client pour pouvoir ajouter le nouveau. Sinon on ajoute directement le nouveau logiciel client
	if (machine.liste_clients != NULL) {
		curseur = machine.liste_clients;
		while(curseur->next != NULL)
			curseur = curseur->next;	
	}
	// En C l'affectation d'une chaine de caractères à une autre se fait par copie. Donc on utilise la fonction strcpy
	// pour donner comme nom, au nouveau client, le nom du logiciel client passé en paramètre
	strcpy(nouveauClient->nom_client, nomClient);
	// Le nouveau client étant le dernier, son champ next pointe vers NULL
	nouveauClient->next = NULL;
}
return 0;
}
