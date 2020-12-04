#ifndef __ORDERGAN_H__
#define __ORDERGAN_H__

#include "IsiIventory.h"

#define NilOrder NULL
// #define int maxkomp
#define maxkomp 4
typedef int infotype ;
typedef struct tElmtQueueOrder * addressOrder;
typedef struct tElmtQueueOrder {
    int *TIO;
    addressOrder NextOrder ;
}ElmtQueueOrder;

typedef struct {
    addressOrder HeadOrder;
}QueueOrder;

/*Selektor*/
#define HeadOrder(Q) (Q).HeadOrder
#define InfoPart(P, i) (P)->TIO[i]
#define NextOrder(P) (P)->NextOrder
#endif