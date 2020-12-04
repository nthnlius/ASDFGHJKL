
#include "command.h"
#include "boolean.h"
#include "stack.h"
#include "StartBuild.h"
#include "queuelinkedlist.h"

void StartBuild(QueueOrder * Q, int *CurrentlyBuilt, Stack *S, int *nb){
// void StartBuild(QueueLL Q, int *CurrentlyBuilt){
    if (*CurrentlyBuilt == 0){
        if (HeadOrder(*Q) != NilOrder){
            CreateEmptyStack(S);
            PrintKomponen(HeadOrder(*Q));
            *CurrentlyBuilt = 1;
            *nb ++;
        }
        else {
            printf("Selamat! Semua pesanan telah selesai dikerjakan");
        }
    }
    else{
        printbatas();
        printf("tolong kerjakan pesanan yang sudah terdaftar terlebih dahulu!");
        printbatas();
    }
}
void FinishBuild(QueueOrder * Q, int *X){
    *X = 0;
    addressOrder A; //variabel dummy
    DequeueOrder(Q, &A);
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