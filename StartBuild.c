#include "queuelinier.h"
#include "queuelinier.c"

void StartBuild(Queue Q){
    printf("=================================================================================\n");
    printf("Item yang dibutuhkan oleh pesanan ini : \n");
    printf("%d\n", Q.Tab[Q.HEAD]);
    printf("=================================================================================\n");
}
int main(){
    Queue Q;
    int A = 7;
    Q = CreateQueue(7);
    Push(&Q, A);
    StartBuild(Q);
    return 0;
}