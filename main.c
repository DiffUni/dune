#include <stdio.h>
#include <stdlib.h>
#include "gamelib.h"
int main(void) {
  time_t t;
  srand((unsigned) time(&t));     //inizializzo un generatore di numeri casuali utilizzando il tempo attuale
  int scelta_menu;

    printf("____________________________\n");
    printf("|                          |\n");
    printf("|    beneath the dune      |\n");
    printf("|            by            |\n");
    printf("|    Casini Carlo Maria    |\n");
    printf("|__________________________|\n");
    printf("Ci troviamo nel 4798, la Terra non e' più la 'Blue Marble' che ci ricordiamo, ma e' l'ennesimo pianeta ormai inabitabile del sistema solare.\n");
    printf("Nel 3076, quando le condizioni della terra erano ormai critiche si opto' per l'opzione 'seed' in cui la poca popolazione rimasta fu messa sotto Crio-sonno nelle navi New-Hope.\n");
    printf("Queste navi erano gestite da IA con scopo quello di mantenere in vita i passeggeri e di identificare pianeti capaci di sostenere la vita umana.\n");
    printf("Fu' cosi' che si scopri' il pianeta Sabbie, o almeno cosi' da noi rinominato a causa della sua aridità. Esso nascondeva sotto la sua crosta arida e desolata uno dei tesori dell'universo:\n");
    printf("LA MELASSA.\n");
    printf("Quseta sostanza incuriosi' non una, ma ben 2 delle IA al comando delle New-Hope, portando all'incotro tra i due equipaggi, che pero' ha portato allo scontro per il monopolio della MELASSA da parte degli equipaggi, ora detti famiglie:\n");
    printf("Gli Arvais e Gli Artornen\n");
    printf("Ora e' il tuo compito aggiudicarti il monopolio della MELASSA\n");
    do{
        printf(" _______________\n");
        printf("|               |\n");
        printf("|     MENU'     |\n");
        printf("|_______________|\n");
        printf("ecco la lista di codici che puoi utilizzare\n");
        printf("1 -> costruisci i cunicoli: costruisci una mappa di azione per trovare la MELASSA\n");
        printf("2 -> gioca:  fatti strada attraverso l'arida roccia per cercare la MELASSA, ma ricordati non sei l'unico qui sotto\n");
        printf("3 -> fine gioco: ormai hai conquistato tutta la MELASSA, non ti resta che ritirarti e goderti la meritata vittoria, oppure la situzione e' stata troppo ardua e quindi per evitare altre perdite e' meglio ritirasi e riprovare una prossima volta\n");

        scanf("%d", &scelta_menu);
        switch (scelta_menu) {
          case 1: printf("hai scelto il codice 1: costruisci cunicoli\n");
                  crea_cunicoli();
                  break;
          case 2: printf("hai scelto il codice 2: gioca\n");
                  gioca();
                  break;
          case 3: printf("hai scelto il codice 3: fine gioco (e anche il risultato)\n");
                  fine_gioco();
                  break;
        default:  printf("hai fatto casino\n");
        }
    } while(scelta_menu!=3);
    printf("sei uscito dallo switch\n");
  return 0;
}
