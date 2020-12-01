#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
{
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
    TI(*T) = (ElType *)malloc((maxel + 1) * sizeof(ElType));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}

void Dealokasi(TabInt *T)
{
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(TI(*T));
    Neff(*T) = 0;
    MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
{
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    /* *** Daya tampung container *** */
    return Neff(T);
}
int MaxElement(TabInt T)
{
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    /* *** Selektor INDEKS *** */
    return MaxEl(T);
}
IdxType GetFirstIdx(TabInt T)
{
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxType GetLastIdx(TabInt T)
{
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    return NbElmt(T) - GetFirstIdx(T) + 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMin) && (i <= MaxEl(T)));
}
boolean IsIdxEff(TabInt T, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
{
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
{
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (Neff(T) == MaxEl(T) - IdxMin + 1);
}


boolean SearchB(TabInt T, ElType X)
{
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    boolean Found = false;
    IdxType i = GetFirstIdx(T);
    //
    while ((!Found) && (i <= GetLastIdx(T)))
    {
        if (Elmt(T, i) == X)
        {
            Found = true;
        }
        else
        {
            i++;
        }
    }
    //
    return Found;
}


/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
{
    /* I.S. T boleh kosong */
    /* F.S. Jika asc = true, T terurut membesar */
    /*      Jika asc = false, T terurut mengecil */
    /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
    if (asc)
    {
        ElType key;
        IdxType j;
        for (IdxType i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++)
        {
            key = Elmt(*T, i);
            j = i - 1;
            //
            while ((j >= GetFirstIdx(*T)) && (Elmt(*T, j) > key))
            {
                Elmt(*T, j + 1) = Elmt(*T, j);
                j--;
            }
            //
            Elmt(*T, j + 1) = key;
        }
    }
    else
    {
        IdxType iMax;
        ElType tmp;
        for (IdxType i = GetFirstIdx(*T); i < GetLastIdx(*T); i++)
        {
            iMax = i;
            //
            for (IdxType j = i + 1; j <= GetLastIdx(*T); j++)
            {
                if (Elmt(*T, j) > Elmt(*T, iMax))
                {
                    iMax = j;
                }
            }
            //
            tmp = Elmt(*T, iMax);
            Elmt(*T, iMax) = Elmt(*T, i);
            Elmt(*T, i) = tmp;
        }
    }
}



