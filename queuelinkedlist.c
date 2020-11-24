#include <stdio.h>
#include <stdlib.h>
#include "queuelinkedlist.h"

address AlokasiQLL (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address)malloc(sizeof(ElmtQueue));
    if (P!= NULL){
        Info(P)=X;
        Next(P)=P;
        return (P);
    }
    else{
        return(Nil);
    }
    return P;
}
void DealokasiQLL (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}
boolean IsQueueLLEmpty (QueueLL Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return (Head(Q) == Nil && Tail(Q)==Nil) ;
}


int NbElmtQLL(QueueLL Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int count = 0;
    address P;
    if (IsQueueLLEmpty(Q)){
        1==1;
    }
    else{
        P= Head(Q);
        count = 1;
        while (P!=Tail(Q)){
            P= Next(P);
            count -=- 1;
        }
    }
    return count;
}
/*** Kreator ***/
void CreateQLL(QueueLL * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
{
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
void EnqueueQLL (QueueLL * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong*/
/* F.S. Jika Alokasi berhasil :
            X menjadi TAIL yang baru,
            TAIL "maju" dengan mekanisme circular buffer
            Jika Q kosong, HEAD dimulai dari 0 
        Jika Alokasi gagal : I.S. = F.S.*/
{
    address P1, P2;
    P1 = AlokasiQLL(X);
    if (IsQueueLLEmpty(*Q)){
        Head(*Q)=P1;
        Tail(*Q)=P1;
    }
    else{
        P2 = Tail(*Q);
        Next(P2)=P1;
        Tail(*Q)=P1;
    }
}
void DequeueQLL (QueueLL * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address P;
    (*X)=Info(Head(*Q));
    if (Head(*Q)==Tail(*Q)){// Queue 1 element
        DealokasiQLL(Head(*Q));
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    }
    else{
        P = Head(*Q);
        Head(*Q) = Next(Head(*Q));
        DealokasiQLL(P);
    }
}


infotype FrontQLL (QueueLL Q)
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
{
    return(Info(Head(Q)));
}


