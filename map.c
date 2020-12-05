#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "graph.h"

int ReadInt(char * A){
    int x = atoi(A);
    return x;
}
int bacajumlahbuilding(char* filename){
    int jml;
    STARTKATAFILE(filename);
    ADVKATA();
    ADVKATA();
    jml = ReadInt(CKata.TabKata);
    return jml;
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
            ElmtM(yee, i, j) = ' ';
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
        ElmtM(yee, i, j) = NamaBuild[count-1];
        count++;
    }
    // printf("%c\n", NamaBuild[0]);
    //TulisMATRIKS(yee);
    return yee;
}

Graph CreatedGraph(char* filename){
    Graph G;
    CreateEmptyGraph(&G);
    STARTKATAFILE(filename); // 
    ADVKATA();
    ADVKATA();
    int i = 0;
    int j = 0;
    int jml = bacajumlahbuilding(filename);
    int Grf[jml][jml];
    for (i=1 ; i<= jml ; i++){
        ADVKATA();
        ADVKATA();
        ADVKATA();
    }
            ADVKATA();
    for (i = 0 ; i < jml; i++){
        for (j = 0; j < jml ; j++){
            Grf [i][j] = ReadInt(CKata.TabKata);
            //printf("CKATA.TabKata : %s \n", CKata.TabKata);
            ADVKATA();
        }
    }
    initGraph(&G, jml);
    for (i = 0 ; i < jml ; i++){
        for (j = 0 ; j < jml ; j++){
            if (Grf[i][j]==1){
                AddLink (&G, i+1, j+1);
            }
        }
    }
    return G;
    //PrintLink(G, 1);
}
// int main(){
//     MATRIKS map;
//     map = ReadFileMap("map.txt");
//     TulisMATRIKS(map);
// }
int main(){
    Graph G;
    CreateEmptyGraph(&G);
    G = CreatedGraph("map.txt");
    printf("1\n");
    int i=0;
    int j = 0;
    int Posisi = 2;
    int jml = bacajumlahbuilding("map.txt");
    for (i = 0 ; i < jml;i++){
        if (IsLinked(G, Posisi, i+1)){
            printf("%d. Bangunan %d\n", j+1, i+1);
            j++;
        }
    }
}