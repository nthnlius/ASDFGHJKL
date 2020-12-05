
#include "command.h"
#include "boolean.h"
#include "stack.h"
#include "StartBuild.h"
#include "queuelinkedlist.h"
#include "inventory.h"
#include <string.h>

void StartBuild(QueueOrder * Q, int *CurrentlyBuilt, Stack *S, int *nb, int *honor, TabInt T, int* noplg){
// void StartBuild(QueueLL Q, int *CurrentlyBuilt){
    if (*CurrentlyBuilt == 0){
        if (HeadOrder(*Q) != NilOrder){
            if (strcmp(T.A[T.Neff], "Pesanan")!=0){
                *S = CreateEmptyStack();
                PrintKomponen(HeadOrder(*Q));
                *CurrentlyBuilt = 1;
                *nb ++;
                *honor = HitungHonor(HeadOrder(*Q));
                *noplg = InfoPart(HeadOrder(*Q), 0);
            }
            else{
                printf("Deliver dulu gan \n");
            }
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
void FinishBuild(QueueOrder * Q, int *X, Stack *S, TabInt *T){
    int i = 1;
    boolean sama;
    if (*X == 0){
        printf("blom ngbuild bang\n");
    }
    else {
        if (checkstack (*S, *Q)!= false)
        {
            if ((*T).Neff < (*T).maxeldin){
                *X = 0;
                addressOrder A; //variabel dummy
                A=HeadOrder(*Q);
                DequeueOrder(Q, &A);
                printf("PESANAN SUDAH JADI BWANG \n");
                (*T).TI[(*T).Neff] = 1;
                (*T).A[(*T).Neff] = "Pesanan";
            }
        }
        else{
            printf("Buildnya belum sesuai gan \n");
        }
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