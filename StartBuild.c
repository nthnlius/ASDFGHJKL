#include "queuelinier.h"
#include "queuelinier.c"

void printbatas(){
    printf("\n=================================================================================\n");
}
void StartBuild(Queue Q, IdxType * CurrentlyBuilt){
    if (*CurrentlyBuilt == NIL){
        if (Q.HEAD != NIL){
            printbatas();
            printf("Item yang dibutuhkan oleh pesanan ini : \n");
            printf("%d", Q.Tab[Q.HEAD]);
            *CurrentlyBuilt = Q.HEAD;
            printbatas();
        }
        else {
            printbatas();
            printf("Selamat! Semua pesanan telah selesai dikerjakan");
            printbatas();
        }
    }
    else{
        printbatas();
        printf("tolong kerjakan pesanan yang sudah terdaftar terlebih dahulu!");
        printbatas();
    }
}
// int main(){
//     Queue Q;
//     int A, B, C, D, E;
//     int Qi = NIL;
//     int Qmax = 10;
//     A = 7;
//     B = 2;
//     C = 9;
//     D = 15;
//     E = 11;
//     Q=CreateQueue(Qmax);
//     StartBuild(Q, &Qi);
//     Push(&Q, A);
//     Push(&Q, B);
//     Push(&Q, C);
//     Push(&Q, D);
//     Push(&Q, E);
//     StartBuild(Q, &Qi);
//     A = Pop(&Q);
//     Qi = NIL;
//     StartBuild(Q, &Qi);
//     StartBuild(Q, &Qi);
// }