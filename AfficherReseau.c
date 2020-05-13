#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donneesCommunes.c"
#define DEFAULT_STRING_SIZE 30

void AfficherReseau()
{
    int id_machine = 0;
    char *nom_machine, *adresse_mac, *adresse_ip, *est_connecte;
    char *s_liste_clients, *s_liste_serveurs;
    char enregistrement[DEFAULT_STRING_SIZE * 300];
    char* token = NULL;
    FILE* f_enregistrements = fopen("fic.txt", "r");
    int nombre_machine = 7;

    if (!f_enregistrements) {
        perror("Erreur lors de l'ouverture du fichier contenant les enregistrements");
        return ;;
    }

    fscanf(f_enregistrements, "%d", &nombre_machine);

    for (int i = 0; (i < nombre_machine) && (!feof(f_enregistrements)); i++)
    {
        fscanf(f_enregistrements, "%s", enregistrement);
        id_machine = atoi(strtok(enregistrement, ","));
        nom_machine = strtok(NULL, ",");
        adresse_mac = strtok(NULL, ",");
        est_connecte = strtok(NULL, ",");
        adresse_ip = strtok(NULL, ",");
        s_liste_clients = strtok(NULL, ",");
        s_liste_serveurs = strtok(NULL, ",");
        printf("%d, %s, %s, %s, %s, %s, %s\n", id_machine, nom_machine, adresse_mac, est_connecte, adresse_ip, s_liste_clients, s_liste_serveurs);
    }
    
    
}
int main()
    {
        void AfficherReseau();
        AfficherReseau();
    }