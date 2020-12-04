#ifndef __ORDERGAN_H__
#define __ORDERGAN_H__

#include "IsiIventory.h"

#define NilOrder NULL
// #define int maxkomp
#define maxkomp 4
typedef int infotype ;
typedef struct tElmtQueueOrder * addressOrder;
typedef struct tElmtQueueOrder {
    int TIO[9];
    addressOrder NextOrder ;
}ElmtOrder;

typedef struct {
    addressOrder HeadOrder;
}QueueOrder;

/*Selektor*/
#define HeadOrder(Q) (Q).HeadOrder
#define InfoPart(P, i) (P)->TIO[i]
#define NextOrder(P) (P)->NextOrder

/*Creator*/
void EmptyOrder(QueueOrder * Q);
addressOrder MakeOrder(void);
void DealokasiOrder (addressOrder P);
void EnqueueOrder (QueueOrder * Q, addressOrder P);
void DequeueOrder(QueueOrder * Q, addressOrder * P);
void PrintOrder(QueueOrder Q);
void PrintQueue(QueueOrder Q);
void PrintKomponen(addressOrder P);
int HitungHonor(addressOrder P);
#endif