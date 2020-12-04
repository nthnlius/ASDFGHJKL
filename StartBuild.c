#include "queuelinkedlist.h"
#include "command.h"
#include "boolean.h"
#include "stack.h"


void StartBuild(QueueLL Q, int *CurrentlyBuilt, Stack *S){
    if (*CurrentlyBuilt == 0){
        if (HeadQLL(Q) != NilQLL){
            //printbatas();
            CreateEmptyStack(S);
            printf("Item yang dibutuhkan oleh pesanan ini : \n");
            printf("%d", InfoHeadQLL(Q));
            *CurrentlyBuilt = 1;
            //printbatas();
        }
        else {
            //printbatas();
            printf("Selamat! Semua pesanan telah selesai dikerjakan");
            //printbatas();
        }
    }
    else{
        printbatas();
        printf("tolong kerjakan pesanan yang sudah terdaftar terlebih dahulu!");
        printbatas();
    }
}
void FinishBuild(QueueLL * Q, int *X){
    *X = 0;
    infotypeQLL A; //variabel dummy
    DequeueQLL(Q, &A);
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