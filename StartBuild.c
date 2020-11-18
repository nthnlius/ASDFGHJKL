#include "queuelinier.h"
#include "queuelinier.c"

void StartBuild(Queue Q, IdxType * CurrentlyBuilt){
    if (*CurrentlyBuilt == NIL){
        printf("=================================================================================\n");
        printf("Item yang dibutuhkan oleh pesanan ini : \n");
        printf("%d\n", Q.Tab[Q.HEAD]);
        *CurrentlyBuilt = Q.HEAD;
        printf("=================================================================================\n");
    }
    else{
        printf("=================================================================================\n\n\n");
        printf("tolong kerjakan pesanan yang sudah terdaftar terlebih dahulu!\n\n\n");
        printf("=================================================================================\n");
    }
}
