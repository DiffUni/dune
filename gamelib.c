#include "gamelib.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

static struct Caverna* primo_cunicolo_arvais=NULL;                //puntatori alle prime caverne delle due casate.
static struct Caverna* primo_cunicolo_artornerns=NULL;
static struct Caverna* ultimo_cunicolo_arvais=NULL;
static struct Caverna* ultimo_cunicolo_artornern=NULL;
static int c_caverna_art=0;
static int c_caverna_arv=0;
static struct scavatrice Scavatrice_arvais;
static struct scavatrice Scavatrice_artornern;
static int contat_turno_arv=0;
static int contat_turno_art=0;


/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

int generatore_numeri_casuali(){
  //genero un valore casuale copreso tra 0 e 99
  int sol=0;
  sol=(rand()%100);
  return sol;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
static void ins_caverna(int casata){
  int percentuali=0;
  if(casata==1){
      struct Caverna* cNuova=(struct Caverna*) malloc(sizeof (struct Caverna));         //qui ho creato lo pazio nell'heap
      int prendiTipo=0;
      do {      //prende da tastiera il tipo della caverna attraverso una variabile, poi viene controllata e attribuendo alla caverna il valore corrispondente o messaggio di errore
        printf("scegli che tipo di caverna vuoi\n");
        printf("0. Normale\n");
        printf("1. Speciale\n");
        printf("2. Accidentata\n");
        scanf("%d", &prendiTipo);
        if (prendiTipo==0) {
          cNuova->t_stato=Normale;
        } else if (prendiTipo==1) {
            cNuova->t_stato=Speciale;
          } else if(prendiTipo==2){
              cNuova->t_stato=Accidentata;
        }
      } while((prendiTipo!=0 && prendiTipo!=1) && prendiTipo!=2);       //questo while controlla che il valore immesso da tastiera sia un tipo di caverna.
      printf("tipo di caverna scelto\n");
      //ora impongo la quantità di MELASSA per cunicolo.
      percentuali=generatore_numeri_casuali();
      if(percentuali>=80){  //ora in base alla percentuale che ho ricevuto dalla funzione generatore_numeri_casuali(), attribuisco gli enum al cunicolo nel campo corrispondente alla melassa.
        cNuova->q_Melassa=molta;
      }else if(percentuali>=50){
        cNuova->q_Melassa=poca;
      }else{
        cNuova->q_Melassa=nessuna;
      }
      percentuali=0;
      printf("quantita' melassa generata\n");   //utilizzo lo stesso metodo del calcolo della quantità di melassa per cunicolo, ma ora per gli imprevisti, con le rispettive probabilità
      percentuali=generatore_numeri_casuali();
      if(percentuali>=85){
        cNuova->t_imprevisto=Baco;
      }else if(percentuali>=50){
        cNuova->t_imprevisto=Crollo;
      }else{
        cNuova->t_imprevisto=NessunImprevisto;
      }
      percentuali=0;
      printf("imprevisto generato\n");
      //ora pongo intanto uguali a null i vettori direzione delle struct caverna.
      cNuova->sinistra=NULL;
      cNuova->destra=NULL;
      cNuova->avanti=NULL;
      //insersione della caverna nel percorso
      if(primo_cunicolo_arvais==NULL){
        primo_cunicolo_arvais=cNuova;
        ultimo_cunicolo_arvais=cNuova;

      }else{
        int direzione;
        do{

        printf("dove vuoi che vada questo cunicolo rispetto a quello precedente?\n");
        printf("1. sinistra\n");
        printf("2. avanti\n");
        printf("3. destra\n");
        scanf("%d", &direzione);

      }while ((direzione!=1 && direzione!=2) && direzione!=3);

        if(direzione==1){
          //controllo se l'utente ha scelto la direzione sinistra, in questo modo pongo il vettore sinistra dell'ultimo elemento uguale a cNuova e poi pongo ultimo_cunicolo_arvais uguale a cNuova.
          ultimo_cunicolo_arvais->sinistra=cNuova;

          ultimo_cunicolo_arvais=cNuova;
        }
        if(direzione==2){
          ultimo_cunicolo_arvais->avanti=cNuova;

          ultimo_cunicolo_arvais=cNuova;
        }
        if(direzione==3){
          ultimo_cunicolo_arvais->destra=cNuova;

          ultimo_cunicolo_arvais=cNuova;
        }
      }
    } else {

      //qui inizia la creazione per gli Artornen.
      struct Caverna* cNuova=(struct Caverna*) malloc(sizeof (struct Caverna));         //qui ho creato lo pazio nell'heap
      int prendiTipo=0;
      do {      //prende da tastiera il tipo della caverna attraverso una variabile, poi viene controllata e attribuendo alla caverna il valore corrispondente o messaggio di errore
        printf("scegli che tipo di caverna vuoi\n");
        printf("0. Normale\n");
        printf("1. Speciale\n");
        printf("2. Accidentata\n");
        scanf("%d", &prendiTipo);
        if (prendiTipo==0) {
          cNuova->t_stato=Normale;
        } else if (prendiTipo==1) {
            cNuova->t_stato=Speciale;
          } else if(prendiTipo==2){
              cNuova->t_stato=Accidentata;
        }
      } while((prendiTipo!=0 && prendiTipo!=1) && prendiTipo!=2);       //questo while controlla che il valore immesso da tastiera sia un tipo di caverna.
      printf("tipo di caverna scelto\n");
      //ora impongo la quantità di MELASSA per cunicolo.
      percentuali=generatore_numeri_casuali();
      if(percentuali>=80){  //ora in base alla percentuale che ho ricevuto dalla funzione generatore_numeri_casuali(), attribuisco gli enum al cunicolo nel campo corrispondente alla melassa.
        cNuova->q_Melassa=molta;
      }else if(percentuali>=50){
        cNuova->q_Melassa=poca;
      }else{
        cNuova->q_Melassa=nessuna;
      }
      percentuali=0;
      printf("quantita' melassa generata\n");   //utilizzo lo stesso metodo del calcolo della quantità di melassa per cunicolo, ma ora per gli imprevisti, con le rispettive probabilità
      percentuali=generatore_numeri_casuali();
      if(percentuali>=85){
        cNuova->t_imprevisto=Baco;
      }else if(percentuali>=50){
        cNuova->t_imprevisto=Crollo;
      }else{
        cNuova->t_imprevisto=NessunImprevisto;
      }
      percentuali=0;
      printf("imprevisto generato\n");
      //ora pongo intanto uguali a null i vettori direzione delle struct caverna.
      cNuova->sinistra=NULL;
      cNuova->destra=NULL;
      cNuova->avanti=NULL;
      //insersione della caverna nel percorso
      if(primo_cunicolo_artornerns==NULL){
        primo_cunicolo_artornerns=cNuova;
        ultimo_cunicolo_artornern=cNuova;

      }else{
        int direzione;
        do{

        printf("dove vuoi che vada questo cunicolo?\n");
        printf("1. sinistra\n");
        printf("2. avanti\n");
        printf("3. destra\n");
        scanf("%d", &direzione);

      }while ((direzione!=1 && direzione!=2) && direzione!=3);

        if(direzione==1){
          //controllo se l'utente ha scelto la direzione sinistra, in questo modo pongo il vettore sinistra dell'ultimo elemento uguale a cNuova e poi pongo ultimo_cunicolo_artornern uguale a cNuova.
          ultimo_cunicolo_artornern->sinistra=cNuova;

          ultimo_cunicolo_artornern=cNuova;
        }
        if(direzione==2){
          ultimo_cunicolo_artornern->avanti=cNuova;

          ultimo_cunicolo_artornern=cNuova;
        }
        if(direzione==3){
          ultimo_cunicolo_artornern->destra=cNuova;

          ultimo_cunicolo_artornern=cNuova;
        }
      }
    }
    return;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

static void canc_caverna(int casata){
  if (casata==1){       //controllo di quale casata si tratta.
    if (primo_cunicolo_arvais==NULL) {                          //controllo se ci sono caverne
      printf("non sono stati ancora aperti cunicoli.\n");
    }
    else if (primo_cunicolo_arvais==ultimo_cunicolo_arvais) {   //controllo se ci sia solo una Caverna
      free(primo_cunicolo_arvais);
      primo_cunicolo_arvais=NULL;
      ultimo_cunicolo_arvais=NULL;
      printf("cancellato l'unico cunicolo creato\n");
    } else {                                                    //caso generico con più caverne
      struct Caverna *scanner=primo_cunicolo_arvais;
      struct Caverna *scanner_piccolo=NULL;                     //scanner piccolo mantiene in memoria l'elemento precedente della lista

      do {
        if ((scanner->sinistra)!=NULL) {
          scanner_piccolo=scanner;
          scanner=(scanner->sinistra);
        } else if ((scanner->avanti)!=NULL) {
          scanner_piccolo=scanner;
          scanner=(scanner->avanti);
        }else if ((scanner->destra)!=NULL) {
          scanner_piccolo=scanner;
          scanner=(scanner->destra);
        }
      } while(scanner==ultimo_cunicolo_arvais);
      free(scanner);
      scanner_piccolo->sinistra=NULL;
      scanner_piccolo->avanti=NULL;
      scanner_piccolo->destra=NULL;
      ultimo_cunicolo_arvais=scanner_piccolo;
    }
  } else {
    if (primo_cunicolo_artornerns==NULL) {                          //controllo se ci sono caverne
      printf("non sono stati ancora aperti cunicoli.\n");
    }
    else if (primo_cunicolo_artornerns==ultimo_cunicolo_artornern) {   //controllo se ci sia solo una Caverna
      free(primo_cunicolo_artornerns);
      primo_cunicolo_arvais=NULL;
      ultimo_cunicolo_arvais=NULL;
      printf("cancellato l'unico cunicolo creato\n");
    } else {                                                    //caso generico con più caverne
      struct Caverna *scanner=primo_cunicolo_artornerns;
      struct Caverna *scanner_piccolo=NULL;                     //scanner piccolo mantiene in memoria l'elemento precedente della lista

      do {                                                      //questo do while mi permette di scorrere la lista fino al penultimo e al ultimo elemento, cosi mettendo in evidenza il nuovo ultimo e quello da cancellare
        if ((scanner->sinistra)!=NULL) {
          scanner_piccolo=scanner;
          scanner=(scanner->sinistra);
        } else if ((scanner->avanti)!=NULL) {
          scanner_piccolo=scanner;
          scanner=(scanner->avanti);
        }else if ((scanner->destra)!=NULL) {
          scanner_piccolo=scanner;
          scanner=(scanner->destra);
        }
      } while(scanner==ultimo_cunicolo_artornern);
      free(scanner);                                            //cancello e sostituisco le posizioni.
      scanner_piccolo->sinistra=NULL;
      scanner_piccolo->avanti=NULL;
      scanner_piccolo->destra=NULL;
      ultimo_cunicolo_artornern=scanner_piccolo;
    }
  }
  return;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

static void stampa_cunicoli(int casata){
  struct Caverna *scansione=NULL;
  int indice_caverna=0;
  if(casata==1){
    indice_caverna=1;
    do {
      if(scansione==NULL){
        scansione=primo_cunicolo_arvais;
      } else {
        if((scansione->destra)!=NULL){
          scansione=(scansione->destra);
        } else if((scansione->avanti)!=NULL){
          scansione=(scansione->avanti);
        } else if((scansione->sinistra)!=NULL){
          scansione=(scansione->sinistra);
        }
      }
      printf("questa è la caverna %d\n", indice_caverna);
      indice_caverna++;
      //con questi if controllo che tipo ha la caverna di riferimento.
      if((scansione->t_stato)==Normale){
        printf("la caverna è Normale\n");
      }
      if ((scansione->t_stato)==Speciale) {
        printf("la caverna è Speciale\n");
      }
      if ((scansione->t_stato)==Accidentata) {
        printf("la caverna è di tipo Accidentata\n");
      }
      // con questi if controllo la quantita di MELASSA nella caverna
      if ((scansione->q_Melassa)==nessuna) {
        printf("nella caverna non c'e' MELASSA\n");
      }
      if ((scansione->q_Melassa)==poca) {
        printf("nella caverna c'e' poca MELASSA\n");
      }
      if ((scansione->q_Melassa)==molta) {
        printf("nella caverna c'e' molta MELASSA\n");
      }
      //con questi if controllo la presenza di imprevisti
      if((scansione->t_imprevisto)==NessunImprevisto){
        printf("la caverna non ha imprevisti\n");
      }
      if ((scansione->t_imprevisto)==Crollo) {
        printf("la caverna ha un crollo\n");
      }
      if ((scansione->t_imprevisto)==Baco) {
        printf("la caverna è abitata da un Baco\n");
      }
      // con uìquesti if controllo dove si trova la prossima Caverna
      if ((scansione->sinistra)!=NULL){
        printf("la prossima caverna e' sulla sinistra\n");
      }
      if ((scansione->destra)!=NULL){
        printf("la prossima Caverna e' sulla destra\n");
      }
      if ((scansione->avanti)!=NULL) {
        printf("la prossima caverna e' davanti\n");
      }
    } while(scansione!=ultimo_cunicolo_arvais);
  } else {
    do {
      if(scansione==NULL){
        scansione=primo_cunicolo_artornerns;
      } else {
        if((scansione->destra)!=NULL){
          scansione=(scansione->destra);
        } else if((scansione->avanti)!=NULL){
          scansione=(scansione->avanti);
        } else if((scansione->sinistra)!=NULL){
          scansione=(scansione->sinistra);
        }
      }
      printf("questa è la caverna %d\n", indice_caverna);
      indice_caverna++;
      //con questi if controllo che tipo ha la caverna di riferimento.
      if((scansione->t_stato)==Normale){
        printf("la caverna è Normale\n");
      }
      if ((scansione->t_stato)==Speciale) {
        printf("la caverna è Speciale\n");
      }
      if ((scansione->t_stato)==Accidentata) {
        printf("la caverna è di tipo Accidentata\n");
      }
      // con questi if controllo la quantita di MELASSA nella caverna
      if ((scansione->q_Melassa)==nessuna) {
        printf("nella caverna non c'e' MELASSA\n");
      }
      if ((scansione->q_Melassa)==poca) {
        printf("nella caverna c'e' poca MELASSA\n");
      }
      if ((scansione->q_Melassa)==molta) {
        printf("nella caverna c'e' molta MELASSA\n");
      }
      //con questi if controllo la presenza di imprevisti
      if((scansione->t_imprevisto)==NessunImprevisto){
        printf("la caverna non ha imprevisti\n");
      }
      if ((scansione->t_imprevisto)==Crollo) {
        printf("la caverna ha un crollo\n");
      }
      if ((scansione->t_imprevisto)==Baco) {
        printf("la caverna è abitata da un Baco\n");
      }
      // con uìquesti if controllo dove si trova la prossima Caverna
      if ((scansione->sinistra)!=NULL){
        printf("la prossima caverna e' sulla sinistra\n");
      }
      if ((scansione->destra)!=NULL){
        printf("la prossima Caverna e' sulla destra\n");
      }
      if ((scansione->avanti)!=NULL) {
        printf("la prossima caverna e' davanti\n");
      }
    } while(scansione!=ultimo_cunicolo_artornern);
  }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void crea_cunicoli(){
  int scelta=0, famiglia=0;
  //mettere il quadrato con dentro la scritta crea cunicoli
  printf("ti trovi nel menu di creazione scegli una delle seguenti opzione:\n");
do {
  do {
      printf("dimmi la famiglia della quale si vogliono creare caverne:\n");
      printf("1. Arvais\n");
      printf("2. Artornen\n");
      scanf("%d", &famiglia);

      if (famiglia!=1 && famiglia!=2) {
        printf("la scelta fornita non è valida \n");
      }

  } while(famiglia!=1 && famiglia!=2);
                                      //creo un loop che si conclude quando l'utente sceglie di tornare al menu principale
    printf("1. inserisci caverna.\n");
    printf("2. cancella caverna.\n");
    printf("3. stampa cunicolo.\n");
    printf("4. chiudi conicoli.\n");
    printf("5. ritorna al menu principale\n");

    scanf("%d", &scelta);                 //prende il valore scelto dall'utentescavatrice_arvais

    switch (scelta) {
      case 1:   printf("e' stato scelto: inserisci caverna.\n");

                if (famiglia==1) {                  //controllo quale è stata la scelta dell'utente per incrementare il valoe giusto di caverne per famiglia.
                  c_caverna_arv++;      //se il cunicolo è stato creato per gli arvais aumento il contatore dei cunicoli arvais
                } else {
                  c_caverna_art++;      //se il cunicolo è stato creato per gli Artornen aumento il contatore dei cunicoli Artornen
                }
                ins_caverna(famiglia);
                break;
      case 2:   printf("e' stato scelto: cancella caverna.\n");

                if (famiglia==1) {                  //controllo quale è stata la scelta dell'utente per incrementare il valoe giusto di caverne per famiglia.
                  c_caverna_arv--;                  //se il cunicolo è stato dostruttp per gli arvais diminuisco il contatore dei cunicoli arvais
                } else {
                  c_caverna_art--;                  //se il cunicolo è stato dostruttp per gli Artornen diminuisco il contatore dei cunicoli Artornen
                }
                canc_caverna(famiglia);
                break;
      case 3:   printf("e' stato scelto: stampa cunicolo.\n");
                stampa_cunicoli(famiglia);
                break;
      case 4:   printf("e' stato scelto: chiudi cunicoli.\n");
                //chiudi_cuicoli(famiglia);
                break;
      case 5:   printf("e' stato scelto: ritorna al menu principale.\n");
                if (c_caverna_arv<9 || c_caverna_art<9){
                  if (c_caverna_arv>9) {
                    printf("ATTENZIONE la quantita' di caverne del cunicolo della famiglia Arvais non è sufficiente per uscire dalla creazione mappa.\n");
                    } else {
                    printf("ATTENZIONE la quantita' di caverne del cunicolo della famiglia Artornen non è sufficiente per uscire della creazione mappa\n");
                    }
                  } else {
                    printf("La quantita' di caverne per ogni famiglia è almeno 10, quindi è possibile uscire dalla costruzione della mappa\n");
                  }
                break;
      default:  printf("ATTENZIONE L'OPZIONE SCELTA NON E' STATA RICONOSIUTA, PERFAVORE SI FORNISCA UN VALORE TRA QUELLI ELENCATI\n");
                break;
    }
  } while ((scelta!=5 && c_caverna_arv>=9) && c_caverna_art>=9);         //ristampo e chiedo il valore del menu fin quando quando scelta è diversa da 5(uscita dal MENU)
return;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

static void avanza(struct scavatrice *v_scavatrice){
  //dobbiamo vedere quale delle direzioni è accessibile (avanti destra o sinistra)
  int scelta=0;
  int caso_crollo=0;
  struct Caverna *vecchia=NULL;
  if ((v_scavatrice->posizione)->sinistra!=NULL) {

    do{
    printf("vuoi andare a sinistra?\n");
    printf("1. si\n");
    printf("2. no\n");
    scanf("%d", &scelta);

    if(scelta!=1 && scelta!=2){
      printf("la scelta effettuata non e' stata riconosciuta, PERFAVORE riinserisca il valore\n");
      }

    }while(scelta!=1 && scelta!=2);

      if(scelta==1){
        vecchia=v_scavatrice->posizione;
        v_scavatrice->posizione=v_scavatrice->posizione->sinistra;
        free(vecchia);            //cancello la caverna precedente
        //controlliamo lo stato della Caverna
        if ((v_scavatrice->posizione)->t_stato==Normale){
          printf("la caverna e' normale.\n");
        } else if ((v_scavatrice->posizione)->t_stato==Speciale) {
          printf("la caverna e' Speciale.\n");
          if(v_scavatrice->serbatoio<4){
            v_scavatrice->serbatoio++;
            printf("il tuo serbatoio è stato rifornito di un unita'.\n");
          }
        } else if ((v_scavatrice->posizione)->t_stato==Accidentata) {
          printf("la caverna è Accidentata.\n");
          printf("perdi un unita' di melassa dal serbatoio, se possibile.\n");
          if (v_scavatrice->serbatoio>0) {
            printf("perdi un unita' di carburante dal serbatoio.\n");
            v_scavatrice->serbatoio--;
          } else {
            printf("il tuo serbatoio e' vuoto, cio' implica che molte azioni nei turni successivi non potranno essere eseguite.\n");
            if (v_scavatrice->riserva!=0) {
              printf("e' possibile spostare un unita' di MELASSA dalla riserva al serbatoio, ma facendo ciò si perdera' un unita' in piu' sempre dalla riserva a causa del crollo.\n");
              scelta=0;
              do {
                printf("vuoi effettuare lo scambio?\n");
                printf("1. si.\n");
                printf("2. no.\n");
                scanf("%d", &scelta);
              } while(scelta!=1 && scelta!=2);
              if (scelta==1) {
                printf("scambio acettato.\n");
                v_scavatrice->riserva=v_scavatrice->riserva-2;
                v_scavatrice->serbatoio++;
              } else {
                printf("il percorso e' troppo impervio, i motori faticano troppo per poter muoversi libearmente e gli scanner danno solo segnale di errore\n");
                printf("il turno si conclude qui.\n");
                return;
              }
            } else {
              printf("il percorso e' troppo impervio, i motori faticano troppo per poter muoversi libearmente e gli scanner danno solo segnale di errore\n");
              printf("il turno si conclude qui.\n");
              return;
            }
          }
        } else {
          printf("si vede della luce nella caverna.\n");
        }
        //controlliamo eventuali imprevisti nella caverna.
        caso_crollo=generatore_numeri_casuali();              //caso del 25% di possibilità di crollo della Caverna.
        if (caso_crollo>=75) {
          printf("appena si entra nella Caverna avviene un Crollo\n");
          (v_scavatrice->posizione)->t_imprevisto=Crollo;
        }
        if((v_scavatrice->posizione)->t_imprevisto==NessunImprevisto){
          printf("non ci sono imprevisti nella Caverna.\n");
        } else if ((v_scavatrice->posizione)->t_imprevisto==Crollo) {
          printf("c'e' un crollo nella Caverna, perdi un unità di energia\n");
          v_scavatrice->serbatoio--;
        } else if ((v_scavatrice->posizione)->t_imprevisto==Baco) {
          printf("all'interno della Caverna incontri un Baco che attacca la scavatrice prosciugandola dalla MELASSA\n");
          v_scavatrice->serbatoio=0;
          v_scavatrice->riserva=0;
        }
        //controllo melassa nella Caverna
        if((v_scavatrice->posizione)->t_imprevisto!=Crollo){      //controllo se c'è un crollo nella Caverna, in caso affermativo il giocatore non può prendere la melassa al suo intenro.
        if ((v_scavatrice->posizione)->q_Melassa==nessuna) {
          printf("nella caverna non c'e' traccia di MELASSA\n");
        } else if ((v_scavatrice->posizione)->q_Melassa==poca) {
          printf("nella Caverna c'e' poca (1) MELASSA\n");
          do {
            printf("dove la vuoi mettere?\n");
            printf("1. nel serbatoio\n");
            printf("2. nella riserva\n");
            scanf("%d", &scelta);
          } while(scelta!=1 && scelta!=2);
          if (scelta==1) {
            if(v_scavatrice->serbatoio<4){
              v_scavatrice->serbatoio++;
              printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
            } else {
              printf("il serbatoio è gia' pieno, si tenta di porre la MELASSA nella riserva\n");
              if (v_scavatrice->riserva<10) {
                v_scavatrice->riserva++;
                printf("la riserva ha %d unita' di MELASSA\n", v_scavatrice->riserva);
              } else {
                printf("entrambi i serbatoi sono pieni, non si puo' fare nulla\n");
              }
            }
          } else {
            if (v_scavatrice->riserva<10) {
              v_scavatrice->riserva++;
              printf("la riserva ha %d unita' di MELASSA\n", v_scavatrice->riserva);
            } else {
              printf("la riserva e' piena, si tenta di porre la MELASSA nel serbatoio\n");
              if(v_scavatrice->serbatoio<4){
                v_scavatrice->serbatoio++;
                printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
              } else {
                printf("non c'e' spazio in nessun serbatoio\n");
              }
            }
          }
        }else if ((v_scavatrice->posizione)->q_Melassa==molta) {
          printf("nella Caverna c'e' molta (3) MELASSA\n");
          do {
            printf("dove la vuoi mettere?\n");
            printf("1. nel serbatoio\n");
            printf("2. nella riserva\n");
            scanf("%d", &scelta);
          } while(scelta!=1 && scelta!=2);
          if (scelta==1) {
            if (v_scavatrice->serbatoio==0) {
              v_scavatrice->serbatoio=3;
              printf("il serbatoio ha 3 unita' di MELASSA\n");
            } else if (v_scavatrice->serbatoio>0 && v_scavatrice->serbatoio<4) {
              v_scavatrice->serbatoio=4;                //faccio in modo che va a riempimento, cioè basta che ci sia spazio nel serbatoio e se lo spazio è > o = 3 allora lo riempe automaticamente (la quantità in più va persa)
              printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
            }else if (v_scavatrice->serbatoio>3) {
              printf("il serbatoio ha raggiunto la sua capacita' massima e non puo' essere riempito.\n");
              printf("si prova a porre la MELASSA all'interno della riserva\n");
              if (v_scavatrice->riserva<8) {
                v_scavatrice->riserva= v_scavatrice->riserva + 3;
                printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
              } else if (v_scavatrice->riserva>7 && v_scavatrice->riserva<10) {
                v_scavatrice->riserva=10;
                printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
              } else if (v_scavatrice->riserva==10) {
                printf("entrambi i serbatoi sono pieni\n");
              }
            }
          } else {
            if (v_scavatrice->riserva<8) {
              v_scavatrice->riserva= v_scavatrice->riserva + 3;
              printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
            } else if (v_scavatrice->riserva>7 && v_scavatrice->riserva<10) {
              v_scavatrice->riserva=10;
              printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
            } else if (v_scavatrice->riserva==10){
                printf("la riserva e' piena, si tenta di porre la MELASSA nel serbatoio\n");
                if (v_scavatrice->serbatoio==0) {
                  v_scavatrice->serbatoio=3;
                  printf("il serbatoio contiene %d unita'.\n", v_scavatrice->serbatoio);
                } else if (v_scavatrice->serbatoio>0 && v_scavatrice->serbatoio<4) {
                  v_scavatrice->serbatoio=4;
                  printf("il serbatoio contiene %d unita'.\n", v_scavatrice->serbatoio);
                } else if (v_scavatrice->serbatoio==4) {
                  printf("entrambi i serbatoi sono pieni.\n");
                }
              }
            }
          }
        }
        }
      } else if ((v_scavatrice->posizione)->avanti!=NULL) {

            do{
            printf("vuoi andare avanti?\n");
            printf("1. si\n");
            printf("2. no\n");
            scanf("%d", &scelta);

            if(scelta!=1 && scelta!=2){
              printf("la scelta effettuata non e' stata riconosciuta, PERFAVORE riinserisca il valore\n");
              }

            }while(scelta!=1 && scelta!=2);

              if(scelta==1){
                vecchia=v_scavatrice->posizione;
                v_scavatrice->posizione=(v_scavatrice->posizione)->avanti;
                free(vecchia);
                //controlliamo lo stato della Caverna
                if ((v_scavatrice->posizione)->t_stato==Normale){
                  printf("la caverna e' normale.\n");
                } else if ((v_scavatrice->posizione)->t_stato==Speciale) {
                  printf("la caverna e' Speciale.\n");
                  if(v_scavatrice->serbatoio<4){
                    v_scavatrice->serbatoio++;
                    printf("il tuo serbatoio è stato rifornito di un unita'.\n");
                  }
                } else if ((v_scavatrice->posizione)->t_stato==Accidentata) {
                  printf("la caverna è Accidentata.\n");
                  printf("perdi un unita' di melassa dal serbatoio\n");
                  v_scavatrice->serbatoio--;
                } else {
                  printf("si vede della luce nella caverna.\n");
                }
                //controlliamo eventuali imprevisti nella caverna.
                caso_crollo=generatore_numeri_casuali();              //caso del 25% di possibilità di crollo della Caverna.
                if (caso_crollo>=75) {
                  printf("appena si entra nella Caverna avviene un Crollo\n");
                  (v_scavatrice->posizione)->t_imprevisto=Crollo;
                }
                if((v_scavatrice->posizione)->t_imprevisto==NessunImprevisto){
                  printf("non ci sono imprevisti nella Caverna.\n");
                } else if ((v_scavatrice->posizione)->t_imprevisto==Crollo) {
                  printf("c'e' un crollo nella Caverna, perdi un unità di energia, se ne hai.\n");
                  v_scavatrice->serbatoio--;
                } else if ((v_scavatrice->posizione)->t_imprevisto==Baco) {
                  printf("all'interno della Caverna incontri un Baco che attacca la scavatrice prosciugandola dalla MELASSA\n");
                  v_scavatrice->serbatoio=0;
                  v_scavatrice->riserva=0;
                }
                //controllo melassa nella Caverna
                if((v_scavatrice->posizione)->t_imprevisto!=Crollo){      //controllo se c'è un crollo nella Caverna, in caso affermativo il giocatore non può prendere la melassa al suo intenro.
                if ((v_scavatrice->posizione)->q_Melassa==nessuna) {
                  printf("nella caverna non c'e' traccia di MELASSA\n");
                } else if ((v_scavatrice->posizione)->q_Melassa==poca) {
                  printf("nella Caverna c'e' poca (1) MELASSA\n");
                  do {
                    printf("dove la vuoi mettere?\n");
                    printf("1. nel serbatoio\n");
                    printf("2. nella riserva\n");
                    scanf("%d", &scelta);
                  } while(scelta!=1 && scelta!=2);
                  if (scelta==1) {
                    if(v_scavatrice->serbatoio<4){
                      v_scavatrice->serbatoio++;
                      printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
                    } else {
                      printf("il serbatoio è gia' pieno, si tenta di porre la MELASSA nella riserva\n");
                      if (v_scavatrice->riserva<10) {
                        v_scavatrice->riserva++;
                        printf("la riserva ha %d unita' di MELASSA\n", v_scavatrice->riserva);
                      } else {
                        printf("entrambi i serbatoi sono pieni, non si puo' fare nulla\n");
                      }
                    }
                  } else {
                    if (v_scavatrice->riserva<10) {
                      v_scavatrice->riserva++;
                      printf("la riserva ha %d unita' di MELASSA\n", v_scavatrice->riserva);
                    } else {
                      printf("la riserva e' piena, si tenta di porre la MELASSA nel serbatoio\n");
                      if(v_scavatrice->serbatoio<4){
                        v_scavatrice->serbatoio++;
                        printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
                      } else {
                        printf("non c'e' spazio in nessun serbatoio\n");
                      }
                    }
                  }
                }else if ((v_scavatrice->posizione)->q_Melassa==molta) {
                  printf("nella Caverna c'e' molta (3) MELASSA\n");
                  do {
                    printf("dove la vuoi mettere?\n");
                    printf("1. nel serbatoio\n");
                    printf("2. nella riserva\n");
                    scanf("%d", &scelta);
                  } while(scelta!=1 && scelta!=2);
                  if (scelta==1) {
                    if (v_scavatrice->serbatoio==0) {
                      v_scavatrice->serbatoio=3;
                      printf("il serbatoio ha 3 unita' di MELASSA\n");
                    } else if (v_scavatrice->serbatoio>0 && v_scavatrice->serbatoio<4) {
                      v_scavatrice->serbatoio=4;                //faccio in modo che va a riempimento, cioè basta che ci sia spazio nel serbatoio e se lo spazio è > o = 3 allora lo riempe automaticamente (la quantità in più va persa)
                      printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
                    }else if (v_scavatrice->serbatoio>3) {
                      printf("il serbatoio ha raggiunto la sua capacita' massima e non puo' essere riempito.\n");
                      printf("si prova a porre la MELASSA all'interno della riserva\n");
                      if (v_scavatrice->riserva<8) {
                        v_scavatrice->riserva= v_scavatrice->riserva + 3;
                        printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                      } else if (v_scavatrice->riserva>7 && v_scavatrice->riserva<10) {
                        v_scavatrice->riserva=10;
                        printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                      } else if (v_scavatrice->riserva==10) {
                        printf("entrambi i serbatoi sono pieni\n");
                      }
                    }
                  } else {
                    if (v_scavatrice->riserva<8) {
                      v_scavatrice->riserva= v_scavatrice->riserva + 3;
                      printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                    } else if (v_scavatrice->riserva>7 && v_scavatrice->riserva<10) {
                      v_scavatrice->riserva=10;
                      printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                    } else if (v_scavatrice->riserva==10){
                        printf("la riserva e' piena, si tenta di porre la MELASSA nel serbatoio\n");
                        if (v_scavatrice->serbatoio==0) {
                          v_scavatrice->serbatoio=3;
                          printf("il serbatoio contiene %d unita'.\n", v_scavatrice->serbatoio);
                        } else if (v_scavatrice->serbatoio>0 && v_scavatrice->serbatoio<4) {
                          v_scavatrice->serbatoio=4;
                          printf("il serbatoio contiene %d unita'.\n", v_scavatrice->serbatoio);
                        } else if (v_scavatrice->serbatoio==4) {
                          printf("entrambi i serbatoi sono pieni.\n");
                        }
                      }
                    }
                  }
                }
                }
  } else if ((v_scavatrice->posizione)->destra!=NULL) {

        do{
        printf("vuoi andare a destra?\n");
        printf("1. si\n");
        printf("2. no\n");
        scanf("%d", &scelta);

        if(scelta!=1 && scelta!=2){
          printf("la scelta effettuata non e' stata riconosciuta, PERFAVORE riinserisca il valore\n");
          }

        }while(scelta!=1 && scelta!=2);

          if(scelta==1){
            vecchia=v_scavatrice->posizione;
            v_scavatrice->posizione=v_scavatrice->posizione->destra;
            free(vecchia);
            //controlliamo lo stato della Caverna
            if ((v_scavatrice->posizione)->t_stato==Normale){
              printf("la caverna e' normale.\n");
            } else if ((v_scavatrice->posizione)->t_stato==Speciale) {
              printf("la caverna e' Speciale.\n");
              if(v_scavatrice->serbatoio<4){
                v_scavatrice->serbatoio++;
                printf("il tuo serbatoio è stato rifornito di un unita'.\n");
              }
            } else if ((v_scavatrice->posizione)->t_stato==Accidentata) {
              printf("la caverna è Accidentata.\n");
              printf("perdi un unita' di melassa dal serbatoio\n");
              v_scavatrice->serbatoio--;
            } else {
              printf("si vede della luce nella caverna.\n");
            }
            //controlliamo eventuali imprevisti nella caverna.
            caso_crollo=generatore_numeri_casuali();              //caso del 25% di possibilità di crollo della Caverna.
            if (caso_crollo>=75) {
              printf("appena si entra nella Caverna avviene un Crollo\n");
              (v_scavatrice->posizione)->t_imprevisto=Crollo;
            }
            if((v_scavatrice->posizione)->t_imprevisto==NessunImprevisto){
              printf("non ci sono imprevisti nella Caverna.\n");
            } else if ((v_scavatrice->posizione)->t_imprevisto==Crollo) {
              printf("c'e' un crollo nella Caverna, perdi un unità di energia\n");
              v_scavatrice->serbatoio--;
            } else if ((v_scavatrice->posizione)->t_imprevisto==Baco) {
              printf("all'interno della Caverna incontri un Baco che attacca la scavatrice prosciugandola dalla MELASSA\n");
              v_scavatrice->serbatoio=0;
              v_scavatrice->riserva=0;
            }
            //controllo melassa nella Caverna
            if((v_scavatrice->posizione)->t_imprevisto!=Crollo){      //controllo se c'è un crollo nella Caverna, in caso affermativo il giocatore non può prendere la melassa al suo intenro.
            if ((v_scavatrice->posizione)->q_Melassa==nessuna) {
              printf("nella caverna non c'e' traccia di MELASSA\n");
            } else if ((v_scavatrice->posizione)->q_Melassa==poca) {
              printf("nella Caverna c'e' poca (1) MELASSA\n");
              do {
                printf("dove la vuoi mettere?\n");
                printf("1. nel serbatoio\n");
                printf("2. nella riserva\n");
                scanf("%d", &scelta);
              } while(scelta!=1 && scelta!=2);
              if (scelta==1) {
                if(v_scavatrice->serbatoio<4){
                  v_scavatrice->serbatoio++;
                  printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
                } else {
                  printf("il serbatoio è gia' pieno, si tenta di porre la MELASSA nella riserva\n");
                  if (v_scavatrice->riserva<10) {
                    v_scavatrice->riserva++;
                    printf("la riserva ha %d unita' di MELASSA\n", v_scavatrice->riserva);
                  } else {
                    printf("entrambi i serbatoi sono pieni, non si puo' fare nulla\n");
                  }
                }
              } else {
                if (v_scavatrice->riserva<10) {
                  v_scavatrice->riserva++;
                  printf("la riserva ha %d unita' di MELASSA\n", v_scavatrice->riserva);
                } else {
                  printf("la riserva e' piena, si tenta di porre la MELASSA nel serbatoio\n");
                  if(v_scavatrice->serbatoio<4){
                    v_scavatrice->serbatoio++;
                    printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
                  } else {
                    printf("non c'e' spazio in nessun serbatoio\n");
                  }
                }
              }
            }else if ((v_scavatrice->posizione)->q_Melassa==molta) {
              printf("nella Caverna c'e' molta (3) MELASSA\n");
              do {
                printf("dove la vuoi mettere?\n");
                printf("1. nel serbatoio\n");
                printf("2. nella riserva\n");
                scanf("%d", &scelta);
              } while(scelta!=1 && scelta!=2);
              if (scelta==1) {
                if (v_scavatrice->serbatoio==0) {
                  v_scavatrice->serbatoio=3;
                  printf("il serbatoio ha 3 unita' di MELASSA\n");
                } else if (v_scavatrice->serbatoio>0 && v_scavatrice->serbatoio<4) {
                  v_scavatrice->serbatoio=4;                //faccio in modo che va a riempimento, cioè basta che ci sia spazio nel serbatoio e se lo spazio è > o = 3 allora lo riempe automaticamente (la quantità in più va persa)
                  printf("il serbatoio ha %d unita' di MELASSA\n", v_scavatrice->serbatoio);
                }else if (v_scavatrice->serbatoio>3) {
                  printf("il serbatoio ha raggiunto la sua capacita' massima e non puo' essere riempito.\n");
                  printf("si prova a porre la MELASSA all'interno della riserva\n");
                  if (v_scavatrice->riserva<8) {
                    v_scavatrice->riserva= v_scavatrice->riserva + 3;
                    printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                  } else if (v_scavatrice->riserva>7 && v_scavatrice->riserva<10) {
                    v_scavatrice->riserva=10;
                    printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                  } else if (v_scavatrice->riserva==10) {
                    printf("entrambi i serbatoi sono pieni\n");
                  }
                }
              } else {
                if (v_scavatrice->riserva<8) {
                  v_scavatrice->riserva= v_scavatrice->riserva + 3;
                  printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                } else if (v_scavatrice->riserva>7 && v_scavatrice->riserva<10) {
                  v_scavatrice->riserva=10;
                  printf("la riserva contiene %d unita'.\n", v_scavatrice->riserva);
                } else if (v_scavatrice->riserva==10){
                    printf("la riserva e' piena, si tenta di porre la MELASSA nel serbatoio\n");
                    if (v_scavatrice->serbatoio==0) {
                      v_scavatrice->serbatoio=3;
                      printf("il serbatoio contiene %d unita'.\n", v_scavatrice->serbatoio);
                    } else if (v_scavatrice->serbatoio>0 && v_scavatrice->serbatoio<4) {
                      v_scavatrice->serbatoio=4;
                      printf("il serbatoio contiene %d unita'.\n", v_scavatrice->serbatoio);
                    } else if (v_scavatrice->serbatoio==4) {
                      printf("entrambi i serbatoi sono pieni.\n");
                    }
                  }
                }
              }
            }
            }
  }
  printf("si conclude il turno.\n");
  return;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

static void aggira(struct scavatrice *v_scavatrice){
  int scelta=0;
  int moneta=0;
  struct Caverna *vecchia=NULL;
  struct Caverna *appoggio=NULL;
  if (v_scavatrice->serbatoio==0) {
    if(v_scavatrice->riserva!=0){
      printf("ATTENZIONE non hai abbastanza melassa per eseguire quest'azione.\n");
      do {
        printf("vuoi mettere un unita' di MELASSA dalla riserva al serbatoio?\n");
        printf("1. si\n");
        printf("2. no\n");
        scanf("%d", &scelta);
      } while(scelta!=1 && scelta!=2);
      if(scelta==1){
        printf("spostamento di MELASSA in corso.\n");
        v_scavatrice->riserva--;
        v_scavatrice->serbatoio++;
      } else {
        printf("si conclude il turno.\n");
        return;
      }
    } else{
      printf("non hai melassa per continuare, si conclude il turno\n");
      return;
    }
  }
  if ((v_scavatrice->posizione)->t_imprevisto==Crollo) {
    if((v_scavatrice->posizione)->sinistra!=NULL){
      vecchia=v_scavatrice->posizione;
      v_scavatrice->posizione=v_scavatrice->posizione->sinistra;
      free(vecchia);
      printf("hai consumato un' unita' di MELASSA dal serbatoio\n");
      v_scavatrice->serbatoio--;
      if ((v_scavatrice->posizione)->q_Melassa!=nessuna) {
        printf("trovi un unta' di melassa e la metti nel serbatoio\n");
        v_scavatrice->serbatoio++;
      }
    }else if ((v_scavatrice->posizione)->avanti!=NULL) {
        vecchia=v_scavatrice->posizione;
        v_scavatrice->posizione=v_scavatrice->posizione->avanti;
        free(vecchia);
        printf("hai consumato un' unita' di MELASSA dal serbatoio\n");
        v_scavatrice->serbatoio--;
        if ((v_scavatrice->posizione)->q_Melassa!=nessuna) {
          printf("trovi un unta' di melassa e la metti nel serbatoio\n");
          v_scavatrice->serbatoio++;
        }
    } else  if ((v_scavatrice->posizione)->destra!=NULL) {
      vecchia=v_scavatrice->posizione;
      v_scavatrice->posizione=v_scavatrice->posizione->destra;
      free(vecchia);
      printf("hai consumato un' unita' di MELASSA dal serbatoio\n");
      v_scavatrice->serbatoio--;
      if ((v_scavatrice->posizione)->q_Melassa!=nessuna) {
        printf("trovi un unta' di melassa e la metti nel serbatoio\n");
        v_scavatrice->serbatoio++;
        }
      }else {
      appoggio=(struct Caverna*) malloc(sizeof(struct Caverna));
      appoggio->sinistra=NULL;                                    //non completo completamente le caratteristiche della Caverna, ma anzi ne creo una standard che ne migliore dei casi rifornisce la quantità di MELASSA utilizzata per arrivarci e nel peggiore non succede nulla.
      appoggio->avanti=NULL;
      appoggio->destra=NULL;
      appoggio->t_imprevisto=NessunImprevisto;
      appoggio->t_stato=Normale;
      moneta=(generatore_numeri_casuali())%2;
      if (moneta==0) {
        appoggio->q_Melassa=poca;
      } else {
        appoggio->q_Melassa=nessuna;
      }
      vecchia=v_scavatrice->posizione;
      v_scavatrice->posizione=appoggio;
      free(vecchia);
      if((v_scavatrice->posizione)->q_Melassa==poca){
        printf("hai trovato un unita' di melassa che metti nel serbatoio\n");
        v_scavatrice->serbatoio++;
      }
    }
  } else  {
    printf("la caverna in cui ti trovi non è crollata, quindi non c'e' nulla da aggirare.\n");
  }
  printf("si conclude il turno.\n");
  return;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

static void abbatti(struct scavatrice* g_scavatrice, struct scavatrice* a_scavatrice, int contat_turno) {
  int scelta=0;
  int uscita_v=0;
  int fato=0;
  int incontro=0;
  if((g_scavatrice->posizione)->t_imprevisto==Crollo){      //controllo se la caverna in cui si trova il giocatore sia crollata.
    printf("attenzione ti trovi in una caverna crollata, non e' possibile muoversi liberamente, se vuoi proseguire e' meglio AGGIRARE il problema.\n");
    do {
      printf("vuoi avviare il protocollo AGGIRA della scavatrice? (se non esegui il protocollo, il turno si conlcudera'.)\n");
      printf("1. si.\n");
      printf("2. no.\n");
      scanf("%d", &scelta);
    } while(scelta!=1 && scelta!=2);
    if (scelta==1) {
      printf("codice riconosciuto.\n");
      printf("preparazione del protocollo AGGIRA.\n");
      aggira(g_scavatrice);
    } else {
      printf("protocollo aggira rifiutato.\n");
    }
  } else {
    if ((g_scavatrice->posizione)->sinistra==NULL) {
      do {
        printf("a sinistra hai trovato un muro, puo' essere abbattuto e rivelare nuove caverne, procedere?\n");
        printf("1. si.\n");
        printf("2. no.\n");
        scanf("%d", &scelta);
      } while(scelta!=1 && scelta!=2);
      if (scelta==1) {
        printf("si abbatte il muro e appena si abbassa il fumo si intravede una nuova caverna e si consuma un'unita' di MELASSA.\n");
        g_scavatrice->serbatoio--;
        fato=generatore_numeri_casuali();         //prendo un valore dal generatore per vedere se nello sfondare la parete si è incappati nell'avversario.
        incontro=99-(3*contat_turno);
        if (fato>=incontro) {
          printf("Oh no, non sei l'unico ad interessarsi a quella caverna, infatti si intravede un'altra scavatrice.\n");
          fato=generatore_numeri_casuali();
          if (fato>=80) {
            printf("l'altra scavatrice tenta di attaccarti, ma riesci a bloccarla facendo cadere dal soffitto un enorme pezzo di pietra, facendo perdere all'avversario un unita' di carburante\n");
            if (a_scavatrice->serbatoio!=0) {
              a_scavatrice->serbatoio--;
            } else {
              printf("se non fosse che e' gia a secco.\n");
            }
          } else if (fato>=40) {
            printf("riesci a nasconderti, lui non vedendoti continua sulla sua strada. nessun malus ne bonus per nessuno.\n");
          } else {
            printf("l'altra scsvatrice vede che ci sei tu dietro al crollo, per restituirti il favore fa crollare un enorme pezzo di pietra dal soffitto colpendoti, successivamente scappa e continua la sua ricerca.\n");
            printf("hai perso un'unita' di MELASSA \n");
            if (g_scavatrice->serbatoio==0) {
              if (g_scavatrice->riserva==0) {
                printf("se non fosse che non possiedi nessun'unita' di MELASSA.\n");
              } else {
                printf("ATTENZIONE dato che il tuo serbatoio e' vuoto, l'unita' di melassa persa viene dalla riserva.\n");
                g_scavatrice->riserva--;
              }
            } else {
              g_scavatrice->serbatoio--;
            }
          }
        }
        //inizio la creazione della grotta.
        (g_scavatrice->posizione)->sinistra=(struct Caverna*) malloc(sizeof(struct Caverna));
        //controllo se è l'Uscita (e stati).
        fato=generatore_numeri_casuali();
        uscita_v=99-(5*contat_turno);
        if (fato>=uscita_v) {
          ((g_scavatrice->posizione)->sinistra)->t_stato=Uscita;
        }
        //qui controllo gli stati, controllando prima di tutto se la caverna sia effettivamente un Uscita.
        if (((g_scavatrice->posizione)->sinistra)->t_stato!=Uscita) {
          fato=generatore_numeri_casuali();
          if (fato>=80) {
            //Accidentata
            ((g_scavatrice->posizione)->sinistra)->t_stato=Accidentata;
          } else if (fato>=40) {
            //Speciale
            ((g_scavatrice->posizione)->sinistra)->t_stato=Speciale;
          } else {
            //Normale
            ((g_scavatrice->posizione)->sinistra)->t_stato=Normale;
          }
        }
        //inizio il controllo della MELASSA
        fato=generatore_numeri_casuali();
        if (fato>=80) {
          //molta MELASSA
          ((g_scavatrice->posizione)->sinistra)->q_Melassa=molta;
        } else if (fato>=40) {
          //poca MELASSA
          ((g_scavatrice->posizione)->sinistra)->q_Melassa=poca;
        } else {
          //no MELASSA
          ((g_scavatrice->posizione)->sinistra)->q_Melassa=nessuna;
        }
        //inizio controllo imprevisti
        fato=generatore_numeri_casuali();
        if (fato>=80) {
          ((g_scavatrice->posizione)->sinistra)->t_imprevisto=Baco;
        } else if (fato>=40) {
          ((g_scavatrice->posizione)->sinistra)->t_imprevisto=Crollo;
        } else {
          ((g_scavatrice->posizione)->sinistra)->t_imprevisto=NessunImprevisto;
        }
      }
    } else if ((g_scavatrice->posizione)->avanti==NULL) {
      do {
        printf("avanti hai trovato un muro, puo' essere abbattuto e rivelare nuove caverne, procedere?\n");
        printf("1. si.\n");
        printf("2. no.\n");
        scanf("%d", &scelta);
      } while(scelta!=1 && scelta!=2);
      if (scelta==1) {
        printf("si abbatte il muro e appena si abbassa il fumo si intravede una nuova caverna e si consuma un'unita' di MELASSA.\n");
        g_scavatrice->serbatoio--;
        fato=generatore_numeri_casuali();         //prendo un valore dal generatore per vedere se nello sfondare la parete si è incappati nell'avversario.
        incontro=99-(3*contat_turno);
        if (fato>=incontro) {
          printf("Oh no, non sei l'unico ad interessarsi a quella caverna, infatti si intravede un'altra scavatrice.\n");
          fato=generatore_numeri_casuali();
          if (fato>=80) {
            printf("l'altra scavatrice tenta di attaccarti, ma riesci a bloccarla facendo cadere dal soffitto un enorme pezzo di pietra, facendo perdere all'avversario un unita' di carburante\n");
            if (a_scavatrice->serbatoio!=0) {
              a_scavatrice->serbatoio--;
            } else {
              printf("se non fosse che e' gia a secco.\n");
            }
          } else if (fato>=40) {
            printf("riesci a nasconderti, lui non vedendoti continua sulla sua strada. nessun malus ne bonus per nessuno.\n");
          } else {
            printf("l'altra scsvatrice vede che ci sei tu dietro al crollo, per restituirti il favore fa crollare un enorme pezzo di pietra dal soffitto colpendoti, successivamente scappa e continua la sua ricerca.\n");
            printf("hai perso un'unita' di MELASSA \n");
            if (g_scavatrice->serbatoio==0) {
              if (g_scavatrice->riserva==0) {
                printf("se non fosse che non possiedi nessun'unita' di MELASSA.\n");
              } else {
                printf("ATTENZIONE dato che il tuo serbatoio e' vuoto, l'unita' di melassa persa viene dalla riserva.\n");
                g_scavatrice->riserva--;
              }
            } else {
              g_scavatrice->serbatoio--;
            }
          }
        }
        //inizio la creazione della grotta.
        (g_scavatrice->posizione)->avanti=(struct Caverna*) malloc(sizeof(struct Caverna));
        //controllo se è l'Uscita (e stati).
        fato=generatore_numeri_casuali();
        uscita_v=99-(5*contat_turno);
        if (fato>=uscita_v) {
          ((g_scavatrice->posizione)->avanti)->t_stato=Uscita;
        }
        //qui controllo gli stati, controllando prima di tutto se la caverna sia effettivamente un Uscita.
        if (((g_scavatrice->posizione)->avanti)->t_stato!=Uscita) {
          fato=generatore_numeri_casuali();
          if (fato>=80) {
            //Accidentata
            ((g_scavatrice->posizione)->avanti)->t_stato=Accidentata;
          } else if (fato>=40) {
            //Speciale
            ((g_scavatrice->posizione)->avanti)->t_stato=Speciale;
          } else {
            //Normale
            ((g_scavatrice->posizione)->avanti)->t_stato=Normale;
          }
        }
        //inizio il controllo della MELASSA
        fato=generatore_numeri_casuali();
        if (fato>=80) {
          //molta MELASSA
          ((g_scavatrice->posizione)->avanti)->q_Melassa=molta;
        } else if (fato>=40) {
          //poca MELASSA
          ((g_scavatrice->posizione)->avanti)->q_Melassa=poca;
        } else {
          //no MELASSA
          ((g_scavatrice->posizione)->avanti)->q_Melassa=nessuna;
        }
        //inizio controllo imprevisti
        fato=generatore_numeri_casuali();
        if (fato>=80) {
          ((g_scavatrice->posizione)->avanti)->t_imprevisto=Baco;
        } else if (fato>=40) {
          ((g_scavatrice->posizione)->avanti)->t_imprevisto=Crollo;
        } else {
          ((g_scavatrice->posizione)->avanti)->t_imprevisto=NessunImprevisto;
        }
      }
    } else if ((g_scavatrice->posizione)->destra==NULL) {
      do {
        printf("a destra hai trovato un muro, puo' essere abbattuto e rivelare nuove caverne, procedere?\n");
        printf("1. si.\n");
        printf("2. no.\n");
        scanf("%d", &scelta);
      } while(scelta!=1 && scelta!=2);
      if (scelta==1) {
        printf("si abbatte il muro e appena si abbassa il fumo si intravede una nuova caverna e si consuma un'unita' di MELASSA.\n");
        g_scavatrice->serbatoio--;
        fato=generatore_numeri_casuali();         //prendo un valore dal generatore per vedere se nello sfondare la parete si è incappati nell'avversario.
        incontro=99-(3*contat_turno);
        if (fato>=incontro) {
          printf("Oh no, non sei l'unico ad interessarsi a quella caverna, infatti si intravede un'altra scavatrice.\n");
          fato=generatore_numeri_casuali();
          if (fato>=80) {
            printf("l'altra scavatrice tenta di attaccarti, ma riesci a bloccarla facendo cadere dal soffitto un enorme pezzo di pietra, facendo perdere all'avversario un unita' di carburante\n");
            if (a_scavatrice->serbatoio!=0) {
              a_scavatrice->serbatoio--;
            } else {
              printf("se non fosse che e' gia a secco.\n");
            }
          } else if (fato>=40) {
            printf("riesci a nasconderti, lui non vedendoti continua sulla sua strada. nessun malus ne bonus per nessuno.\n");
          } else {
            printf("l'altra scsvatrice vede che ci sei tu dietro al crollo, per restituirti il favore fa crollare un enorme pezzo di pietra dal soffitto colpendoti, successivamente scappa e continua la sua ricerca.\n");
            printf("hai perso un'unita' di MELASSA \n");
            if (g_scavatrice->serbatoio==0) {
              if (g_scavatrice->riserva==0) {
                printf("se non fosse che non possiedi nessun'unita' di MELASSA.\n");
              } else {
                printf("ATTENZIONE dato che il tuo serbatoio e' vuoto, l'unita' di melassa persa viene dalla riserva.\n");
                g_scavatrice->riserva--;
              }
            } else {
              g_scavatrice->serbatoio--;
            }
          }
        }
        //inizio la creazione della grotta.
        (g_scavatrice->posizione)->destra=(struct Caverna*) malloc(sizeof(struct Caverna));
        //controllo se è l'Uscita (e stati).
        fato=generatore_numeri_casuali();
        uscita_v=99-(5*contat_turno);
        if (fato>=uscita_v) {
          ((g_scavatrice->posizione)->destra)->t_stato=Uscita;
        }
        //qui controllo gli stati, controllando prima di tutto se la caverna sia effettivamente un Uscita.
        if (((g_scavatrice->posizione)->destra)->t_stato!=Uscita) {
          fato=generatore_numeri_casuali();
          if (fato>=80) {
            //Accidentata
            ((g_scavatrice->posizione)->destra)->t_stato=Accidentata;
          } else if (fato>=40) {
            //Speciale
            ((g_scavatrice->posizione)->destra)->t_stato=Speciale;
          } else {
            //Normale
            ((g_scavatrice->posizione)->destra)->t_stato=Normale;
          }
        }
        //inizio il controllo della MELASSA
        fato=generatore_numeri_casuali();
        if (fato>=80) {
          //molta MELASSA
          ((g_scavatrice->posizione)->destra)->q_Melassa=molta;
        } else if (fato>=40) {
          //poca MELASSA
          ((g_scavatrice->posizione)->destra)->q_Melassa=poca;
        } else {
          //no MELASSA
          ((g_scavatrice->posizione)->destra)->q_Melassa=nessuna;
        }
        //inizio controllo imprevisti
        fato=generatore_numeri_casuali();
        if (fato>=80) {
          ((g_scavatrice->posizione)->destra)->t_imprevisto=Baco;
        } else if (fato>=40) {
          ((g_scavatrice->posizione)->destra)->t_imprevisto=Crollo;
        } else {
          ((g_scavatrice->posizione)->destra)->t_imprevisto=NessunImprevisto;
        }
      }
    }
  }
  printf("si conclude il turno.\n");
  return;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

static void uscita(struct scavatrice* v_scavatrice) {
  int scelta=0;
  if ((v_scavatrice->posizione)->t_stato==Uscita) {
    printf("ti trovi di fronte all'Uscita.\n");
    printf("uscendo cocludi la partita, acquisendo anche il bonus USCITA.\n");
    do {
      printf("vuoi uscire?\n");
      printf("1. si.\n");
      printf("2. no.\n");
      scanf("%d", &scelta);
    } while(scelta!=1 && scelta!=2);
    if (scelta==1) {
      printf("ti avvii finalmente all'uscita, il sole entra dalle crepe nella pietra come lame, i tuoi occhi si devono ancora abituare alla luce ma gia' senti il calore sulla pelle; finalmente puoi tirare un sospiro di sollievo e riposarti.\n");
      //distruggo l'ultima Caverna.
      free(v_scavatrice->posizione);
      v_scavatrice->posizione=NULL;
    }
  } else {
    printf("la caverna in cui ti trovi non e' presente nessun'uscita.\n");
  }
  printf("si conclude il turno.\n");
  return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void gioca(){
  int moneta=0;     //questa variabile stabilirà chi comincia
  int azione_arv=0;
  int azione_art=0;
  //questo if controlla se sono state creati cunicoli con crea_cunicoli(), se risulta flaso, si gioca normalemnte, se l'if ritorna 1 (vero) allora manda direttamente su crea_cunicoli().
  if(c_caverna_art<9 || c_caverna_arv<9){
    printf("ATTENZIONE non e' stata creata una mappa dalla creazione nel MENU.\n");
    printf("verrai reindirizzato sull'editor per la creazione.\n");
    crea_cunicoli();
  } else {
    //inizializzo le scavatrici
    //Arvais
    Scavatrice_arvais.posizione=primo_cunicolo_arvais;
    Scavatrice_arvais.serbatoio=4;
    Scavatrice_arvais.riserva=0;

    //Artornen
    Scavatrice_artornern.posizione=primo_cunicolo_artornerns;
    Scavatrice_artornern.serbatoio=4;
    Scavatrice_artornern.riserva=0;

    //vettori alle scavatrici.
    struct scavatrice *v_scavatrice_arv= &Scavatrice_arvais;
    struct scavatrice *v_scavatrice_art= &Scavatrice_artornern;
    moneta=(generatore_numeri_casuali())%2;           //cosi il risultato sarà o 0 o 1
    do {
      if (moneta==0) {
        //Arvais
        contat_turno_arv++;
        printf("e' il turno degli Arvais\n");
        printf("scegli un'azione da poter compiere: (le scelte devono essere inserite come valore numerico corrispondente alla opzione che si intende compiere)\n");
        printf("\n");
        printf("1. avanza. ti permette di verificare in quali direzioni è possibile avanzare e sceglierne una. (per ogni direzione viene chiesto se si vuole andare la' oppure no, non e' possibile cambiare la scelta.)\n");
        printf("2. aggira. ti permette di aggirare una cavrena consumando 1 da serbatoio (attenzione non puoi eseguire aggira se non ti trovi in una caverna crollata.)\n");
        printf("3. abbatti. ti permette di abbattere una parete della caverna in cui ti trovi, rendedo accessibile la direzione in cui hai abbattuto la parete.\n");
        printf("4. uscita. questa azione puo essere eseguita solamente se nella caverna in cui ti trovi hai intravisto una luce, altrimenti non potrai uscire, e il turno si concludera' molto prima di quanto immagini.\n");
        do {
          scanf("%d", &azione_arv);
          if ((azione_arv!=1 && azione_arv!=2) && (azione_arv!=3 && azione_arv!=4)) {
            printf("la scelta inserita non e' stata riconosciuta, perfavore inserisca una scelta consona\n");
          }
        } while((azione_arv!=1 && azione_arv!=2) && (azione_arv!=3 && azione_arv!=4));
        switch (azione_arv) {
          case 1:printf("e' stato scelto avanza.\n");
                 avanza(v_scavatrice_arv);

                 break;
          case 2:printf("e' stato scleto aggira.\n");
                 aggira(v_scavatrice_arv);

                 break;
          case 3:printf("e' stato scelto abbatti\n");

                 abbatti(v_scavatrice_arv, v_scavatrice_art, contat_turno_arv);
                 break;
          case 4:printf("e' stato scelto uscita\n");

                 uscita(v_scavatrice_arv);
                 break;
          default: printf("ehm davvero qui credo che la situazione sia imbarazzante...\n");
        }
          //Artornen
          contat_turno_art++;
          printf("e' il turno degli Artornen\n");
          printf("scegli un'azione da poter compiere: (le scelte devono essere inserite come valore numerico corrispondente alla opzione che si intende compiere)\n");
          printf("\n");
          printf("1. avanza. ti permette di verificare in quali direzioni è possibile avanzare e sceglierne una. (per ogni direzione viene chiesto se si vuole andare la' oppure no, non e' possibile cambiare la scelta.)\n");
          printf("2. aggira. ti permette di aggirare una cavrena consumando 1 da serbatoio (attenzione non puoi eseguire aggira se non ti trovi in una caverna crollata.)\n");
          printf("3. abbatti. ti permette di abbattere una parete della caverna in cui ti trovi, rendedo accessibile la direzione in cui hai abbattuto la parete.\n");
          printf("4. uscita. questa azione puo essere eseguita solamente se nella caverna in cui ti trovi hai intravisto una luce, altrimenti non potrai uscire, e il turno si concludera' molto prima di quanto immagini.\n");
          do {
            scanf("%d", &azione_art);
            if ((azione_art!=1 && azione_art!=2) && (azione_art!=3 && azione_art!=4)) {
              printf("la scelta inserita non e' stata riconosciuta, perfavore inserisca una scelta consona\n");
            }
          } while((azione_art!=1 && azione_art!=2) && (azione_art!=3 && azione_art!=4));
          switch (azione_art) {
            case 1:printf("e' stato scelto avanza.\n");
                   avanza(v_scavatrice_art);

                   break;
            case 2:printf("e' stato scleto aggira.\n");
                   aggira(v_scavatrice_art);

                   break;
            case 3:printf("e' stato scelto abbatti\n");

                   abbatti(v_scavatrice_art, v_scavatrice_arv, contat_turno_art);
                   break;
            case 4:printf("e' stato scelto uscita\n");

                   uscita(v_scavatrice_art);
                   break;
            default: printf("ehm davvero qui credo che la situazione sia imbarazzante...\n");
        }
      } else {
        //Artornen
        contat_turno_art++;
        printf("e' il turno degli Artornen\n");
        printf("scegli un'azione da poter compiere: (le scelte devono essere inserite come valore numerico corrispondente alla opzione che si intende compiere)\n");
        printf("\n");
        printf("1. avanza. ti permette di verificare in quali direzioni è possibile avanzare e sceglierne una. (per ogni direzione viene chiesto se si vuole andare la' oppure no, non e' possibile cambiare la scelta.)\n");
        printf("2. aggira. ti permette di aggirare una cavrena consumando 1 da serbatoio (attenzione non puoi eseguire aggira se non ti trovi in una caverna crollata.)\n");
        printf("3. abbatti. ti permette di abbattere una parete della caverna in cui ti trovi, rendedo accessibile la direzione in cui hai abbattuto la parete.\n");
        printf("4. uscita. questa azione puo essere eseguita solamente se nella caverna in cui ti trovi hai intravisto una luce, altrimenti non potrai uscire, e il turno si concludera' molto prima di quanto immagini.\n");
        do {
          scanf("%d", &azione_art);
          if ((azione_art!=1 && azione_art!=2) && (azione_art!=3 && azione_art!=4)) {
            printf("la scelta inserita non e' stata riconosciuta, perfavore inserisca una scelta consona\n");
          }
        } while((azione_art!=1 && azione_art!=2) && (azione_art!=3 && azione_art!=4));
        switch (azione_art) {
          case 1:printf("e' stato scelto avanza.\n");
                 avanza(v_scavatrice_art);

                 break;
          case 2:printf("e' stato scleto aggira.\n");
                 aggira(v_scavatrice_art);

                 break;
          case 3:printf("e' stato scelto abbatti\n");

                 abbatti(v_scavatrice_art, v_scavatrice_arv, contat_turno_art);
                 break;
          case 4:printf("e' stato scelto uscita\n");

                 uscita(v_scavatrice_art);
                 break;
          default: printf("ehm davvero qui credo che la situazione sia imbarazzante...\n");
       }
       //Arvais
       contat_turno_arv++;
       printf("e' il turno degli Arvais\n");
       printf("scegli un'azione da poter compiere: (le scelte devono essere inserite come valore numerico corrispondente alla opzione che si intende compiere)\n");
       printf("\n");
       printf("1. avanza. ti permette di verificare in quali direzioni è possibile avanzare e sceglierne una. (per ogni direzione viene chiesto se si vuole andare la' oppure no, non e' possibile cambiare la scelta.)\n");
       printf("2. aggira. ti permette di aggirare una cavrena consumando 1 da serbatoio (attenzione non puoi eseguire aggira se non ti trovi in una caverna crollata.)\n");
       printf("3. abbatti. ti permette di abbattere una parete della caverna in cui ti trovi, rendedo accessibile la direzione in cui hai abbattuto la parete.\n");
       printf("4. uscita. questa azione puo essere eseguita solamente se nella caverna in cui ti trovi hai intravisto una luce, altrimenti non potrai uscire, e il turno si concludera' molto prima di quanto immagini.\n");
       do {
         scanf("%d", &azione_arv);
         if ((azione_arv!=1 && azione_arv!=2) && (azione_arv!=3 && azione_arv!=4)) {
           printf("la scelta inserita non e' stata riconosciuta, perfavore inserisca una scelta consona\n");
         }
       } while((azione_arv!=1 && azione_arv!=2) && (azione_arv!=3 && azione_arv!=4));
       switch (azione_arv) {
         case 1:printf("e' stato scelto avanza.\n");
                avanza(v_scavatrice_arv);

                break;
         case 2:printf("e' stato scleto aggira.\n");
                aggira(v_scavatrice_arv);

                break;
         case 3:printf("e' stato scelto abbatti\n");

                abbatti(v_scavatrice_arv, v_scavatrice_art, contat_turno_arv);
                break;
         case 4:printf("e' stato scelto uscita\n");

                uscita(v_scavatrice_arv);
                break;
         default: printf("ehm davvero qui credo che la situazione sia imbarazzante...\n");
       }
      }
    }while(((Scavatrice_arvais.posizione!=NULL && azione_arv!=4) || (Scavatrice_artornern.posizione!=NULL && azione_art!=4)) || (((Scavatrice_arvais.serbatoio!=0) && (Scavatrice_arvais.riserva!=0)) || ((Scavatrice_artornern.serbatoio!=0) && (Scavatrice_artornern.riserva!=0))));
  }
  return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void fine_gioco() {
  printf("attribuzione di eventuali bonus, per favore attendere...\n");
  if (Scavatrice_arvais.posizione==NULL) {
    //bonus USCITA.
    Scavatrice_arvais.riserva++;
    free(Scavatrice_artornern.posizione);         //distruggo l'ultima Caverna
  }
  if (Scavatrice_artornern.posizione==NULL) {
    Scavatrice_artornern.riserva++;
    free(Scavatrice_arvais.posizione);
  }
  if (Scavatrice_arvais.riserva>Scavatrice_artornern.riserva) {
    printf("la famiglia vincitrice e' la famiglia Arvais, CONGRATULAZIONI.\n");
    printf("MELASSA collezionata dalla famiglia Arvais: %d\n", Scavatrice_arvais.riserva);
    printf("MELASSA collezionata dalla famiglia Artornen: %d\n", Scavatrice_artornern.riserva);
  } else if (Scavatrice_arvais.riserva==Scavatrice_artornern.riserva) {
    if (Scavatrice_arvais.posizione==NULL) {
      printf("la famiglia vincitrice e' la famiglia Arvais, CONGRATULAZIONI.\n");
      printf("MELASSA collezionata dalla famiglia Arvais (ha trovato l'Uscita): %d\n", Scavatrice_arvais.riserva);
      printf("MELASSA collezionata dalla famiglia Artornen: %d\n", Scavatrice_artornern.riserva);
    } else if (Scavatrice_artornern.posizione==NULL) {
      printf("la famiglia vincitrice e' la famiglia Artornen, CONGRATULAZIONI.\n");
      printf("MELASSA collezionata dalla famiglia Arvais: %d\n", Scavatrice_arvais.riserva);
      printf("MELASSA collezionata dalla famiglia Artornen (ha trovato l'Uscita): %d\n", Scavatrice_artornern.riserva);
    }
  } else if (Scavatrice_artornern.riserva> Scavatrice_arvais.riserva) {
    printf("la famiglia vincitrice e' la famiglia Artornen, CONGRATULAZIONI.\n");
    printf("MELASSA collezionata dalla famiglia Arvais: %d\n", Scavatrice_arvais.riserva);
    printf("MELASSA collezionata dalla famiglia Artornen: %d\n", Scavatrice_artornern.riserva);
  }
  printf("crediti:\n");
  printf("ispirato dal libro DUNE di FRANK HERBERT\n");
  printf("da un idea di FRANCESCO SANTINI\n");
  printf("e realizzato da CARLO MARIA 'Diff_Uni' CASINI.\n");
}
