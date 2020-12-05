#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "graph.h"
#include "point.h"

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
    MakeMATRIKS(Baris, Kolom, &yee);
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
    int num='1';
    count = 1;
    while (count <= JmlBuilding){
        i = koorxBuild[count-1];
        j = kooryBuild[count-1];
        if (count  >= 3){
            ElmtM(yee, i, j) = (char)(num);
            num++;
        }
        else{
            ElmtM(yee, i, j) = NamaBuild[count-1];
        }
        count++;
    }
    // printf("%c\n", NamaBuild[0]);
    //TulisMATRIKS(yee);
    return yee;
}

Graph CreateGraph(char* filename){
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
int PINDAH(Graph G, int Posisi){
    // Graph G;
    // CreateEmptyGraph(&G);
    // G = CreatedGraph("map.txt");
    //printf("1\n");
    int i=0;
    int j = 0;
    int Pos = 2;
    int jml = bacajumlahbuilding("map.txt");
    int tujuan [jml];
    int piltu;
    for (i = 0 ; i < jml;i++){
        if (IsLinked(G, Posisi, i+1)){
            if (i == 0){
                printf("%d. Base \n", j+1);
                tujuan [j] = i;
                j++;
            }
            else if (i == 1 ){
                printf("%d. Shop \n", j+1);
                tujuan [j] = i;
                j++;
            }
            else{
                printf("%d. Pelanggan %d\n", j+1, i-1);
                tujuan [j] = i;
                j++;
            }
        }
    }
    printf("Masukkan Tujuan : ");
    scanf("%d", &piltu);
    if (piltu <= j){
        Pos = tujuan [piltu-1];
        if (Pos == 0){
            printf("Posisi anda di Base.\n");
        }
        else if (Pos == 1){
            printf("Posisi anda di Shop.\n");
        }
        else{
            printf("Posisi anda di Pelanggan %d\n", Pos-1);
        }
    }
    return Pos;
}