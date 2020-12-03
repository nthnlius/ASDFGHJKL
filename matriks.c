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
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
boolean IsIdxValid (int i, int j){
  return (BrsMin <= i && i <= BrsMax) && (KolMin <= j && j <= KolMax);
}

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
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
  return (BrsMin <= i && i <= M.NBrsEff-1) && (KolMin <= j && j <= M.NKolEff-1);
}
/* Mengirimkan elemen M(i,i) */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
  return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
  int i, j;

  MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
  for(i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
    for(j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
      Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
    }
  }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
  int i, j;

  MakeMATRIKS(NB, NK, M);
  for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
    for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
      scanf("%c", &(Elmt(*M, i, j)));
    }
  }
}
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

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
  MATRIKS M;
  int i, j;

  MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      Elmt(M, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
    }
  }
  return M;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
  MATRIKS M;
  int i, j;

  MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i ++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      Elmt(M, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
    }
  }
  return M;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
  int i, j, k;
  MATRIKS M;

  MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      Elmt(M, i, j) = 0;
      for(k = GetFirstIdxBrs(M2); k <= GetLastIdxBrs(M2); k++){
        Elmt(M, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
      }
    }
  }
  return M;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
MATRIKS KaliKons (MATRIKS M, ElType X){
  MATRIKS Mh;
  int i, j;

  MakeMATRIKS(NBrsEff(M), NKolEff(M), &Mh);
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      Elmt(Mh, i, j) = Elmt(M, i, j) * X;
    }
  }
  return Mh;
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
void PKaliKons (MATRIKS * M, ElType K){
  int i, j;

  for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
    for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
      Elmt(*M, i, j) *= K;
    }
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean EQ (MATRIKS M1, MATRIKS M2){
  boolean sama;
  int i, j;

  sama = (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)) && (GetFirstIdxBrs(M1) == GetFirstIdxBrs(M2)) && (GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetFirstIdxKol(M1) == GetFirstIdxKol(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2));
  for(i = GetFirstIdxKol(M1); i <= GetLastIdxKol(M1) && sama; i++){
    for(j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1) && sama; j++){
      sama &= Elmt(M1, i, j) == Elmt(M2, i, j);
    }
  }

  return sama;
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean NEQ (MATRIKS M1, MATRIKS M2){
  return !EQ(M1, M2);
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
boolean EQSize (MATRIKS M1, MATRIKS M2){
  return (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
/* Mengirimkan banyaknya elemen M */
int NBElmt (MATRIKS M){
  return NBrsEff(M) * NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsBujurSangkar (MATRIKS M){
  return NBrsEff(M) == NKolEff(M);
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSimetri (MATRIKS M){
  boolean simetri;
  int i, j;

  simetri = true;
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M) && simetri; i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M) && simetri; j++){
      simetri &= Elmt(M, i, j) == Elmt(M, j, i);
    }
  }
  return simetri;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSatuan (MATRIKS M){
  boolean satuan;
  int i, j;

  satuan = true;
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M) && satuan; i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M) && satuan; j++){
      satuan &= (Elmt(M, i,j) == 1 && i == j) || (Elmt(M, i, j) == 0 && i != j);
    }
  }
  return satuan;
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
boolean IsSparse (MATRIKS M){
  int i, j, count;

  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      count += Elmt(M, i, j) != 0 ? 1 : 0;
    }
  }
  return (count*100/NBElmt(M)) < 5;
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
MATRIKS Inverse1 (MATRIKS M){
  int i, j;
  MATRIKS Mout;

  MakeMATRIKS(NBrsEff(M), NKolEff(M), &Mout);
  for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
      Elmt(Mout, i, j) = Elmt(M, i, j) * -1;
    }
  }
  return Mout;
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
float Determinan (MATRIKS M){
  int i, j, k;
  MATRIKS cofac;
  float det;

  if(NBElmt(M) == 1) return Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));

  MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &cofac);

  det = 0;
  /* Ekspansi Kofaktor */
  for(i = GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++){
    /* Loop sebaris matriks asli */
    for(j = GetFirstIdxBrs(M)+1; j <= GetLastIdxBrs(M); j++){
      for(k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++){
        /* Buat Matriks Kofaktor */
        if(i != k) Elmt(cofac, j-1, k > i ? k-1 : k) = Elmt(M, j, k);
      }
    }
    det += Elmt(M, 0, i) * Determinan(cofac) * ((i%2 == 0) ? 1 : -1);
  }
  return det;
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void PInverse1 (MATRIKS * M){
  int i, j;
  for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
    for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
      Elmt(*M, i, j) *= -1;
    }
  }
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
void Transpose (MATRIKS * M){
  int i, j;
  ElType temp;

  for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
    for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M) && i > j; j++){
      temp = Elmt(*M, i, j);
      Elmt(*M, i, j) = Elmt(*M, j, i);
      Elmt(*M, j, i) = temp;
    }
  }
}
