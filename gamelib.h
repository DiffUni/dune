#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void crea_cunicoli();
void gioca();
void fine_gioco();

enum melassa {nessuna=0, poca=1, molta=3};
enum imprevisto {NessunImprevisto=0, Crollo=1, Baco=2};
enum stato {Normale=0, Speciale=1, Accidentata=2, Uscita=3};


struct Caverna{
  struct Caverna *avanti;
  struct Caverna *destra;
  struct Caverna *sinistra;
  enum melassa q_Melassa;
  enum imprevisto t_imprevisto;
  enum stato t_stato;
};

struct scavatrice{
  struct Caverna *posizione;
  int serbatoio;      //ricorda il serbatoio tiene 4
  int riserva;        //ricorda raccolta tiene 10;
};
