#include <stdio.h>
#include "queuelinier.h"
#include <stdlib.h>

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Q.HEAD == NILQLin && Q.TAIL ==NILQLin);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Q.TAIL == Q.MaxEl-1);
}
int Length (Queue Q)
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
{
    return(Q.TAIL - Q.HEAD +1 );
}
int MaxLength (Queue Q)
/* Mengirimkan kapasitas jumlah elemen Q */
{
    return (Q.MaxEl - Length(Q));
}

/* *** Kreator *** */
Queue CreateQueue (Queue *Q, int Max)
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */
{
    
    (*Q).Tab = (int *)malloc(sizeof(ElType)*Max);
    if ((*Q).Tab != NULL){
        (*Q).HEAD=NILQLin;
        (*Q).TAIL = NILQLin;
        (*Q).MaxEl=Max;
    }
    return (*Q);
}

/* *** Destruktor *** */
void DeleteQueue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */
{
    (*Q).MaxEl=0;
    free((*Q).Tab);
}

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
{
    if (IsEmpty((*Q))){
        (*Q).HEAD = 0;
        (*Q).TAIL = 0;
        (*Q).Tab[(*Q).TAIL]=X;
    }
    else if(!(IsFull(*Q))) {
        int maks ;
        maks = (*Q).MaxEl;
        (*Q).TAIL = (*Q).TAIL + 1 ;
        (*Q).Tab[(*Q).TAIL] = X;
    }
    else{
        1==1;
    }
}
ElType Pop (Queue * Q)
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    ElType X;
    X=(*Q).Tab[(*Q).HEAD];
    int i;
    i=(*Q).HEAD;
    for (i ; i<(*Q).TAIL; i++){
        (*Q).Tab[i]=(*Q).Tab[i+1];
    }
    (*Q).TAIL -=1;
    return X;
}
ElType Front (Queue Q)
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
{
    return (Q.Tab[Q.HEAD]);
}
/* *** Utilitas *** */
// Queue CopyQueue (Queue Q)
// /* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
// /* I.S. Q pernah dialokasi */
// /* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
//         HEAD pada Queue baru dimulai dari 0 */
// {
//     Queue Q1;
//     IdxType i;
//     Q1=CreateQueue(Q.MaxEl);
//     Q1.HEAD = 0;
//     Q1.TAIL = Length(Q)-1;
//     for (i=0 ; i<= Q1.TAIL; i++){
//         Q1.Tab[i]=Q.Tab[i];
//     }
//     return Q1;
// }
void PrintInfo(Queue Q){
    printf("[");
    IdxType i;
    i=Q.HEAD;
    while(i != Q.TAIL){
        printf("%d,", Q.Tab[i]);
        i++;
    }
    printf("%d]\n", Q.Tab[Q.TAIL]);
}
