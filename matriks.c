/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include <stdio.h>

#include "matriks.h"
#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
// #define BrsMin 0
// #define BrsMax 99
// #define KolMin 0
// #define KolMax 99

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
  (*M).NBrsEff = NB+2;
  (*M).NKolEff = NK+2;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define ElmtM(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxBrs (MATRIKS M){
  return BrsMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
  return KolMin;
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxBrs (MATRIKS M){
  return M.NBrsEff-1;
}
/* Mengirimkan indeks kolom terbesar M */
indeks GetLastIdxKol (MATRIKS M){
  return M.NKolEff-1;
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* Mengirimkan elemen M(i,i) */


/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
  int i, j;

  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      if ((i == 0 || i == M.NBrsEff-1)||(j ==0 || j==M.NKolEff-1)){
          printf("# ");
      }
      else {
        printf("%c", Elmt(M, i, j)); if(j < GetLastIdxKol(M)) printf(" ");
      }
    }
    if(i != GetLastIdxBrs(M)) printf("\n");
  }
}

