#ifndef __linear_queue_linkedlist_h__
#define __linear_queue_linkedlist_h__

#include "boolean.h"

/* Nilai untuk indeks yang tidak terdefinisi */
#define NilQLL NULL

/* Definisi tipe elemen dan indeks pada Queue */
typedef int infotypeQLL;

typedef struct tElmtQueueLL * addressQLL;
typedef struct tElmtQueueLL {
	infotypeQLL InfoQLL;
	addressQLL NextQLL;
} ElmtQueueLL;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	addressQLL HEADQLL;  /* alamat penghapusan */
	addressQLL TAILQLL;  /* alamat penambahan */
} QueueLL;

/*Selektor */
#define HeadQLL(Q) (Q).HEADQLL
#define TailQLL(Q) (Q).TAILQLL
#define InfoHeadQLL(Q) (Q).HEADQLL->InfoQLL
#define InfoTailQLL(Q) (Q).TAILQLL->InfoQLL
#define NextQLL(P) (P)->NextQLL
#define InfoQLL(P) (P)->InfoQLL
/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */

/* ********* Prototype ********* */
/* Prototype manajemen memori */
addressQLL AlokasiQLL (infotypeQLL X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiQLL (addressQLL  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsQueueLLEmpty (QueueLL Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtQLL(QueueLL Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateQLL(QueueLL * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
void EnqueueQLL (QueueLL * Q, infotypeQLL X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong*/
/* F.S. Jika Alokasi berhasil :
            X menjadi TAIL yang baru,
            TAIL "maju" dengan mekanisme circular buffer
            Jika Q kosong, HEAD dimulai dari 0 
        Jika Alokasi gagal : I.S. = F.S.*/
        

void DequeueQLL (QueueLL * Q, infotypeQLL * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */


infotypeQLL FrontQLL (QueueLL Q);
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

#endif