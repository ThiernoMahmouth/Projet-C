#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "donneesCommunes.c"


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

    Machine *creer_machine(){
        char* variable;
        int nb, i;
        listeClients ajouter_client(int n, listeClients *listeClient);
        listeServeurs ajouter_serveur(int n, listeServeurs * listeServeur);
        Machine *computer = malloc(sizeof(computer));
        if (computer != NULL){
            printf("Entrez le nom de la machine: \n");
            scanf("%s", variable);
            strcpy(computer->nom,variable);
            printf("la machine est-elle connectée?\n");
            scanf("%s", variable);
            if (variable == "oui"){
                computer->etat = OUI;
                printf("Entrez l'adresse IP\n");
                scanf("%s", variable);
                strcpy(computer->adresseIp, variable);
            }
            else{
                computer->etat = NON;
            }
            printf("Entrez l'adresse MAC\n");
                scanf("%s", variable);
                strcpy(computer->adresseMac, variable);

            printf("Quel est le nombre de client?\n");
            scanf("%d", &nb);
            ajouter_client(nb, computer->liste_clients);

            printf("Quel est le nombre de serveur?\n");
            scanf("%d", &nb);
            ajouter_serveur(nb, computer->liste_serveurs);
        }

        return computer;
    }

    listeMachine ajouter_machine(int n, listeMachine *listemachine){
        int i;
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
      
    }

    

// int main(void){
//     Machine *m1 = malloc(sizeof(Machine));
//     FILE *fichier;
//     if (m1 != NULL){
//         m1->id = 1;
//         m1->nom = "machine1";
//         m1->esConnecte = OUI;
//         m1->adresseIp = "192.168.10.23";
//         m1->adresseMac = "05.AD.P5.0C";
//         listeClients *l1 = malloc(sizeof(listeClients));
//         if (l1 != NULL){
//             l1->nom_client = "mysqlClient";
//             l1->next = NULL;
//             m1->liste_clients = l1;
//         }
       
//        listeServeurs *s1 = malloc(sizeof(listeServeurs));
//        if (s1 != NULL){
//            s1->nom_serveur = "mysqlServer";
//            s1->next = NULL;
//            m1->liste_serveurs = s1;
//        }

//         fichier = fopen("file1", "a+");
//         if (fichier != NULL){
//             fwrite(m1, sizeof(Machine), 1, fichier);
//             fwrite("\n", sizeof(char), 1, fichier);
//             fclose(fichier);
//             printf("Ecriture reussie!\n");
//         }else{
//             printf("erreur de creation du fichier\n");
//         }
//     }else{
//         printf("Erreur de création de la machine!\n");
//     }
    
// }