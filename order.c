#include "queuelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "order.h"

void EmptyOrder(QueueOrder * Q){
    HeadOrder(*Q)=NilOrder ;
}

addressOrder MakeOrder(){
    addressOrder P;
    P = (addressOrder)malloc(sizeof(ElmtOrder));
    if (P != NULL){
        int i;
        for (i=0; i<4;i++){
            InfoPart(P, i)= (rand()%3);
        }
        NextOrder(P) = NilOrder;
    }
    else {
        69!=420;
    }
    return P;
}

