#ifndef stack_H
#define stack_H
#include <stdio.h>

/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
dan ukuran sama
TOP adalah alamat elemen puncak*/

#define false 0
#define true 1
#define NilS -1
#define MaxEl 50

typedef int bool;
typedef char* infotypeS;
typedef int addressS;

typedef struct
{
    infotypeS T[MaxEl];
    addressS TOP;
} Stack;

/* Definisi stack S kosong : S.TOP = NilS */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
Stack CreateEmptyStack();
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsStackFull(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
bool IsStackOneElmt(Stack S);
/* Mengirim true jika Stack sisa 1 elemen
/* Ciri Stack satu Elemen : S.TOP = 0*/
/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotypeS X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop(Stack *S, infotypeS *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotypeS X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
void CopyStack(Stack * S, Stack * Sout);
void InversStack(Stack S, Stack * Sout);
void PrintStack(Stack *S);
#endif
