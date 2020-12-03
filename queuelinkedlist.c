#include <stdio.h>
#include <stdlib.h>
#include "queuelinkedlist.h"

addressQLL AlokasiQLL (infotypeQLL X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NILQLL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan NILQLL */
{
    addressQLL P;
    P = (addressQLL)malloc(sizeof(ElmtQueueLL));
    if (P!= NULL){
        InfoQLL(P)=X;
        NextQLL(P)=P;
        return (P);
    }
    else{
        return(NilQLL);
    }
    return P;
}
void DealokasiQLL (addressQLL  P)
/* I.S. P adalah hasil alokasi, P != NILQLL */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}
boolean IsQueueLLEmpty (QueueLL Q)
/* Mengirim true jika Q kosong: HEAD(Q)=NILQLL and TAIL(Q)=NILQLL */
{
    return (HeadQLL(Q) == NilQLL && TailQLL(Q)==NilQLL) ;
}


int NbElmtQLL(QueueLL Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int count = 0;
    addressQLL P;
    if (IsQueueLLEmpty(Q)){
        1==1;
    }
    else{
        P= HeadQLL(Q);
        count = 1;
        while (P!=TailQLL(Q)){
            P= NextQLL(P);
            count -=- 1;
        }
    }
    return count;
}
/*** Kreator ***/
void CreateQLL(QueueLL * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = NILQLL dan Tail(Q) = NILQLL) */
/*** Primitif Add/Delete ***/
{
    HeadQLL(*Q)=NilQLL;
    TailQLL(*Q)=NilQLL;
}
void EnqueueQLL (QueueLL * Q, infotypeQLL X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong*/
/* F.S. Jika Alokasi berhasil :
            X menjadi TAIL yang baru,
            TAIL "maju" dengan mekanisme circular buffer
            Jika Q kosong, HEAD dimulai dari 0 
        Jika Alokasi gagal : I.S. = F.S.*/
{
    addressQLL P1, P2;
    P1 = AlokasiQLL(X);
    if (IsQueueLLEmpty(*Q)){
        HeadQLL(*Q)=P1;
        TailQLL(*Q)=P1;
    }
    else{
        P2 = TailQLL(*Q);
        NextQLL(P2)=P1;
        TailQLL(*Q)=P1;
    }
}
void DequeueQLL (QueueLL * Q, infotypeQLL * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NILai elemen HEAD pd I.S., HEAD "mundur" */
{
    addressQLL P;
    (*X)=InfoQLL(HeadQLL(*Q));
    if (HeadQLL(*Q)==TailQLL(*Q)){// Queue 1 element
        DealokasiQLL(HeadQLL(*Q));
        HeadQLL(*Q)=NilQLL;
        TailQLL(*Q)=NilQLL;
    }
    else{
        P = HeadQLL(*Q);
        HeadQLL(*Q) = NextQLL(HeadQLL(*Q));
        DealokasiQLL(P);
    }
}


infotypeQLL FrontQLL (QueueLL Q)
/* Proses: Mengembalikan NILai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan NILai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
{
    return(InfoQLL(HeadQLL(Q)));
}


