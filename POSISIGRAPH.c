#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "point.c"
#include "graph.c"

int main(){
    Graph G;
    infotypeList X;
    X = 2;
    boolean found;
    found = false;
    int posisi;
    int posisiA = 0;
    int kemana;
    int a, b, c, d;
    a = 2;
    b = 3;
    c = 4;
    d = 5;
    CreateEmptyGraph(&G);
    initGraph(&G, 4);
    AddLink(&G, 1, 3);      // Posisi 1.B(1,1) ke 3.C(6,9) = 1->3
    AddLink(&G, 1, 4);      // Posisi 1.B(1,1) ke 4.C(4,2) = 1->4
    AddLink(&G, 2, 4);      // Posisi 2.S(5,4) ke 4.C(4,2) = 2->4          
    
    printf("Masukkan posisi: ");
    scanf("%d", &kemana);

while (posisiA == 0){   
    while(kemana == 1){
        found = true;
        printf("Kamu berada pada base.\n");
        printf("Daftar lokasi yang dapat dicapai: \n");
        if (IsLinked(G, 1, 3)){
            PrintLink(G, 1);
        }
        printf("Mau kemana lagi? \n");
        scanf("%d", &kemana);
        if (kemana == 1){
            kemana = 3;
        }
        else
        {
            kemana = 4;
        }
        
    }

    while (kemana == 2){
        found = true;
        printf("Kamu berada pada posisi 2.\n");
        printf("Daftar lokasi yang dapat dicapai: \n");
        if (IsLinked(G, 2, 4)){
            PrintLink(G, 2);
            
        }
        printf("Mau kemana lagi? \n");
        scanf("%d", &kemana);
        if (kemana == 1){
            kemana = 4;
        }
    }

    while ((kemana == 3)){
        found = true;
        printf("Kamu berada pada posisi 3.\n");
        printf("Daftar lokasi yang dapat dicapai: \n");
        if (IsLinked(G, 3, 1)){
            PrintLink(G, 3);
        }
        printf("Mau kemana lagi? \n");
        scanf("%d", &kemana);
        if (kemana == 1){
            kemana = 1;
        }
    }
    
    while ((kemana == 4)){
        found = true;
        printf("Kamu berada pada posisi 4.\n");
        printf("Daftar lokasi yang dapat dicapai: \n");
        if (IsLinked(G, 4, 1)){
            PrintLink(G, 4);
        }
        printf("Mau kemana lagi? \n");
        scanf("%d", &kemana);
        if (kemana == 1){
            kemana = 1;
        }
        else if (kemana == 2){
            kemana = 2;
        }
    }

}

}