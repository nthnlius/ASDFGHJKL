#ifndef ___STARTBUILD_H___
#define ___STARTBUILD_H___


#include "queuelinkedlist.h"
void printbatas();
/* print batas antar command
   dengan character "=" sebanyak
   ntah berapa kali */

void StartBuild(QueueLL Q, int CurrentlyBuilt);
/*memulai Build.
  Jika CurrentlyBuilt == Nil atau sedang tidak menjalankan
  build manapun, maka startbuild sukses dengan membaca
  Head(Q) sebagai currentlybuilt.
  Jika CurrentlyBuilt != Nil, maka mengirimkan pesan error
  I.S. CurrentlyBuilt sembarang
  F.S. CurrentlyBuilt terdefinisi sebagai Head(Q) jika 
       Head(Q) != Nil. */

void FinishBuild(QueueLL * Q, int *X);
/*  menyelesaikan built.
    Jika Stack sesuai dengan Head(Q), maka
    membebaskan memori Head(Q), me-nil-kan X.
    I.S. : X sembarang, Stack sembarang.
    F.S. : Me-nil-kan X dan membebaskan memori HEAD(Q), serta
           Head "bergeser".*/

#endif