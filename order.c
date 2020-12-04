#include "queuelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "order.h"
#include "map.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "matriks.h"
void EmptyOrder(QueueOrder * Q){
    HeadOrder(*Q)=NilOrder ;
}

addressOrder MakeOrder(void){
    int Hermes;
    Hermes = bacajumlahbuilding("map.txt");
    addressOrder P;
    P = (addressOrder)malloc(sizeof(ElmtOrder));
    if (P != NULL){
        int i;
        InfoPart(P, 0) = (rand()% (Hermes-2))+1;
        for (i=1; i<9;i++){
            InfoPart(P, i)= (rand()%4);
        }
        NextOrder(P) = NilOrder;
    }
    else {
        69!=420;
    }
    return P;
}
/*i = 0 : indeks Nomor Komponen
      1 : indeks Motherboard (TI[1]=3 maksudnya Motherboardnya harus GigaByteB450M)
      2 : indeks CPU
      3 : indeks Memory
      4 : indeks CPU Cooler
      5 : indeks Case
      6 : GPU
      7 : Storage
      8 : PSU */
void DealokasiOrder (addressOrder P){
    free(P);
}

void EnqueueOrder (QueueOrder * Q, addressOrder P){
    if (HeadOrder(*Q)==NilOrder){//order udah kosong
        HeadOrder(*Q)=P;
    }
    else{
        addressOrder P1;
        P1 = HeadOrder(*Q);
        while (NextOrder(P1)!=NilOrder){
            P1 = NextOrder(P1);
        }//P1 udah last
        NextOrder(P1)=P;
    }
}
void DequeueOrder(QueueOrder * Q, addressOrder * P){
    *P = HeadOrder(*Q);
    HeadOrder(*Q)=NextOrder(HeadOrder(*Q));
    DealokasiOrder(*P);
    
}
int HitungHonor(addressOrder P){
    int honor;
    honor = hmotherboard[InfoPart(P, 1)];
    honor += hcpu[InfoPart(P, 2)];
    honor += hmemory[InfoPart(P, 3)];
    honor += hcpucooler[InfoPart(P, 4)];
    honor += hcases[InfoPart(P, 5)];
    honor += hgpu[InfoPart(P, 6)];
    honor += hstorage[InfoPart(P, 7)];
    honor += hpsu[InfoPart(P,8)];
    honor = honor + (honor *0.2);
    return honor;
}
void PrintOrder(QueueOrder Q){
    if (HeadOrder(Q)!=NilOrder){
        addressOrder P;
        P = HeadOrder(Q);
        while (NextOrder(P) != NilOrder){
            printf("Pesanan untuk Customer %d     ", InfoPart(P, 0));
            printf("Invoice : %d \n", HitungHonor(P));
            P = NextOrder(P);
        }
        printf("Pesanan untuk Customer %d     ", InfoPart(P, 0));
        printf("Invoice : %d \n", HitungHonor(P));
    }
}
void PrintQueue(QueueOrder Q){
    printf("[");
    if (HeadOrder(Q)!=NilOrder){
        addressOrder P;
        P = HeadOrder(Q);
        while (NextOrder(P)!= NilOrder){
            printf("%d, ", InfoPart(P, 0));
            P=NextOrder(P);
        }
        printf("%d", InfoPart(P, 0));
    }
    printf("]\n");
}
void PrintKomponen(addressOrder P){
    int i;
    printf("Komponen: \n");
    printf("1. %s \n", motherboard[InfoPart(P,1)]);
    printf("2. %s \n", cpu[InfoPart(P,2)]);
    printf("3. %s \n", memory[InfoPart(P,3)]);
    printf("4. %s \n", cpucooler[InfoPart(P,4)]);
    printf("5. %s \n", cases[InfoPart(P,5)]);
    printf("6. %s \n", gpu[InfoPart(P,6)]);
    printf("7. %s \n", storage[InfoPart(P,7)]);
    printf("8. %s \n", psu[InfoPart(P,8)]);
}

int main(){
    QueueOrder Q;
    EmptyOrder(&Q);
    printf("1\n");
    PrintOrder(Q);
    printf("%d\n", HeadOrder(Q)==NilOrder);
    // addressOrder P;
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // P = MakeOrder();
    // EnqueueOrder(&Q, P);
    // PrintKomponen(HeadOrder(Q));
    // addressOrder P1;
    // DequeueOrder(&Q, &P1);
    
    // PrintKomponen(HeadOrder(Q));
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintQueue(Q);
    // printf("\n");
    // addressOrder P1;
    // DequeueOrder(&Q, &P1);
    // printf("P1 = %d", InfoPart(P1, 0));
    // PrintQueue(Q);
    // DequeueOrder(&Q, &P1);
    // printf("P1 = %d", InfoPart(P1, 0));
    // PrintQueue(Q);
    // DequeueOrder(&Q, &P1);
    // printf("P1 = %d", InfoPart(P1, 0));
    // PrintQueue(Q);
    // DequeueOrder(&Q, &P1);
    // printf("P1 = %d", InfoPart(P1, 0));
    // PrintQueue(Q);
    // int i;
    // for (i = 1; i<9;i++);{
    //     printf("%d\n", InfoPart(P, i));
    //     printf("%d", i);
    // }
    // PrintKomponen (HeadOrder(Q));
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
    // P = MakeOrder();
    // printf("P = %d\n", InfoPart(P, 0));
    // EnqueueOrder(&Q, P);
    // PrintOrder(Q);
    // printf("\n");
}
