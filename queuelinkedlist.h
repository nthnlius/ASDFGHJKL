#ifndef __linear_queue_linkedlist_h__
#define __linear_queue_linkedlist_h__

#include "boolean.h"

/* Nilai untuk indeks yang tidak terdefinisi */
#define Nil NULL

/* Definisi tipe elemen dan indeks pada Queue */
typedef int infotype;

typedef struct tElmtQueue * address;
typedef struct tElmtQueue {
	infotype Info;
	address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	address HEAD;  /* alamat penghapusan */
	address TAIL;  /* alamat penambahan */
} QueueLL;

/*Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */

/* ********* Prototype ********* */
/* Prototype manajemen memori */
address AlokasiQLL (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiQLL (address  P);
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
void EnqueueQLL (QueueLL * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong*/
/* F.S. Jika Alokasi berhasil :
            X menjadi TAIL yang baru,
            TAIL "maju" dengan mekanisme circular buffer
            Jika Q kosong, HEAD dimulai dari 0 
        Jika Alokasi gagal : I.S. = F.S.*/
        

void DequeueQLL (QueueLL * Q, infotype * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */


infotype FrontQLL (QueueLL Q);
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

#endif