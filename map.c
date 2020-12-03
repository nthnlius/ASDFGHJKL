#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

int ReadInt(char * A){
    int x = atoi(A);
    return x;
}
MATRIKS ReadFileMap(char* filename){
    MATRIKS yee;
    int Baris, Kolom;
    STARTKATAFILE(filename);
    Baris = ReadInt(CKata.TabKata);
    //printf("%s ", CKata.TabKata);
    //printf("\nCurrent Char : %d\n", Baris);
    ADVKATA();
    Kolom = ReadInt (CKata.TabKata);
    MakeMATRIKS(Kolom, Baris, &yee);
    int i;
    int j;
    for (i = 0 ; i<NBrsEff(yee); i++){
        for (j = 0 ; j<NKolEff(yee);j++){
            Elmt(yee, i, j) = ' ';
        }
    }
    // TulisMATRIKS (yee);
    // while (!EOP()){
    //     // Baris = CKata.TabKata;
    //     ADVKATA();
    //     //printf("%s ", CKata.TabKata);
    //     Baris = ReadInt(CKata.TabKata);
    //     printf("\nCurrent Char : %d\n", Baris);
    // }
    int JmlBuilding ;
    ADVKATA();
    JmlBuilding=ReadInt(CKata.TabKata);
    //printf("%d\n", JmlBuilding);
    char NamaBuild [JmlBuilding];
    int koorxBuild [JmlBuilding];
    int kooryBuild [JmlBuilding];
    for (i = 0; i< JmlBuilding;i++){
        ADVKATA();
        NamaBuild[i]=(CKata.TabKata[2]);
        ADVKATA();
        koorxBuild[i] = ReadInt (CKata.TabKata);
        ADVKATA();
        kooryBuild[i]=ReadInt (CKata.TabKata);
    }
    int count;
    count =1;
    while (count <= JmlBuilding){
        i = kooryBuild[count-1];
        j = koorxBuild[count-1];
        Elmt(yee, i, j) = NamaBuild[count-1];
        count++;
    }
    // printf("%c\n", NamaBuild[0]);
    //TulisMATRIKS(yee);
    return yee;
}
int main(){
    MATRIKS map;
    map = ReadFileMap("map.txt");
    TulisMATRIKS(map);
}
