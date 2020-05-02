#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "donneesCommunes.c"


        void desinstallerClient(Machine *ordi, char* clientName)
        {
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
 