#ifndef __MAP_H__
#define __MAP_H__

#include "matriks.h"
#include "graph.h"

int ReadInt(char * A);
/* Fungsi ini berfungsi untuk mengubah string menjadi integer
I.S. A bernilai string sembarang
F.S. A berubah menjadi integer. */

MATRIKS ReadFileMap(char* filename);
/*Fungsi membaca file konfigurasi map dan graph
  menjadi matriks.
  I.S. pita of kata terdefinisi
  F.S. pita of kata dikonfigurasi sesuai dengan
       Spesifikasi Tugas Besar/ */

int bacajumlahbuilding(char* filename);
Graph CreateGraph(char* filename);
int PINDAH(Graph G, int Posisi);
#endif
