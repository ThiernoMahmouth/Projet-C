#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fonctions.c"

int main()
{
        Parc parc, *p;
        p=&parc;
        Machine pc1,computer;
        char *serveur;
        computer.id=5;
        computer.nom="Toshiba";
        computer.adresseMac="adresse mac";
        computer.adresseIp="adresse ip";
        computer.etat=NON;
        computer.liste_serveurs=NULL;
        computer.liste_clients=NULL;
        //int nbServerIns,nbClientIns;
       /* pc1.id=3;
        pc1.nom="HP";
        pc1.adresseMac="adresse mac";
        pc1.adresseIp="adresse ip";
        pc1.etat=NON;
        pc1.liste_serveurs=NULL;
        pc1.liste_clients=NULL;*/
        ///////////////
        ajouterMachine(p->reseau,computer);
        afficherReseau(p->reseau);
        // *****************Serveur********************//

        installerServeur(&computer);
        afficherServeurs(&computer);
        printf("Nom du serveur a desinstaller: ");
        scanf("%s",serveur);
        desinstallerServeur(&computer,serveur);
        afficherServeurs(&computer);

        // *******************Client*****************///////
/*      
        installerClient(&pc);
        afficherClients(&pc);
        tab[1]=(char *) malloc(25);
        printf("Nom du client a desinstaller: ");
        scanf("%s",tab[1]);
        desinstallerClient(&pc,tab[1]);
        afficherClients(&pc);
*/
        // **************** Reseau ******************* //
        /*parc.nom_parc="my Parc";
        computer.nom="HP";
        pc2.nom="Mac";
        pc3.nom="Dell";*/
        ajouterMachine(p->reseau,computer);
        afficherReseau(p->reseau);
        /*
        retirerMachine(p->reseau,computer);
        afficherReseau(p->reseau);
        */
        /*ajouterMachine(&parc,computer);
        afficherReseau(&parc);*/
        /*ajouterMachine(&monParc,pc2);
        afficherReseau(&monParc);
        ajouterMachine(&monParc,pc3);
        afficherReseau(&monParc);*/
}

