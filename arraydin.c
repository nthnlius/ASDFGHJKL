#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxeldin)
{
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
    TI(*T) = (ElType *)malloc((maxeldin + 1) * sizeof(ElType));
    Neff(*T) = 0;
    maxeldin(*T) = maxeldin;
}

void DealokasiAr(TabInt *T)
{
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(TI(*T));
    Neff(*T) = 0;
    maxeldin(*T) = 0;
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
    return maxeldin(T);
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
    return ((i >= IdxMin) && (i <= maxeldin(T)));
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
    return (Neff(T) == maxeldin(T) - IdxMin + 1);
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
        if (ElmtAD(T, i) == X)
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
            key = ElmtAD(*T, i);
            j = i - 1;
            //
            while ((j >= GetFirstIdx(*T)) && (ElmtAD(*T, j) > key))
            {
                ElmtAD(*T, j + 1) = ElmtAD(*T, j);
                j--;
            }
            //
            ElmtAD(*T, j + 1) = key;
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
                if (ElmtAD(*T, j) > ElmtAD(*T, iMax))
                {
                    iMax = j;
                }
            }
            //
            tmp = ElmtAD(*T, iMax);
            ElmtAD(*T, iMax) = ElmtAD(*T, i);
            ElmtAD(*T, i) = tmp;
        }
    }
}
