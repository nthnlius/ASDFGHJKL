// #include "build.h"
#include "arraydin.h"
#include "boolean.h"
#include "build.h"
#include "inventory.h"
#include "map.h"
#include "matriks.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "point.h"
#include "queuelinkedlist.h"
#include "random.h"
#include "stack.h"
#include "StartBuild.h"
#include "command.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    boolean start = true;
    int Posisi = 0;
    unsigned long duit = 0;
    /*  0= base
        1 = shop
        2 = customer
        4 = ....
    */
    boolean DayENDED = false;
    addressOrder P;
    int CountDay=0;
    MATRIKS Map = ReadFileMap("map.txt");
    int Jumbuild = bacajumlahbuilding("map.txt");
    int CurrentlyBuilt = 0;
    TabInt Inventory;
    //printf("Selamat Datang di Santo Tycoon\n");
            //printf("1\n");
    MakeEmpty(&Inventory, 100);  
    Inventory = masukinisi();
    int antri = 0;
    int hargajob = 50000;
    int nomororder =0;
    int jmlorder=0;
    int i;
    Stack Komponen;
    Komponen = CreateEmptyStack();
    int noplg=-999;
    
    QueueOrder Pesanan;
    EmptyOrder(&Pesanan);
    //printf("aaaa : %d\n", HeadOrder(Pesanan)==NilOrder);
    while (start){
        CountDay++;
        Posisi =0;
        printf("Day - %d\n", CountDay);
        DayENDED=false;
        jmlorder = rand() % (3)+2;
        for (i=0;i<=jmlorder;i++){
            P = MakeOrder();
            EnqueueOrder (&Pesanan, P);
        }
        while (!DayENDED){
            while (Posisi == 0){
                PrintCommandBase();
                printf("Masukkan Command : ");
                STARTKATAINPUT();
                if (strcmp(CKata.TabKata, "MOVE")==0){
                    //MOVE movean
                    //Posisi berubah
                    Posisi = rand() % (Jumbuild);
                    printf("Kamu sekarang ada di building ke - %d", Posisi);
                }
                else if (strcmp(CKata.TabKata, "STARTBUILD")==0){
                    StartBuild(&Pesanan, &CurrentlyBuilt, &Komponen, &nomororder, &hargajob, Inventory, &noplg);
                }
                else if (strcmp(CKata.TabKata, "ADDCOMPONENT")==0){
                    AddComponent (&Komponen, &Inventory, CurrentlyBuilt);
                }
                else if (strcmp(CKata.TabKata, "REMOVECOMPONENT")==0){
                    RemoveComponent(&Komponen, &Inventory, CurrentlyBuilt);
                }
                else if (strcmp(CKata.TabKata, "EXIT")==0){
                    start = false;
                    Posisi = 999;
                    DayENDED = true;
                }
                else if (strcmp(CKata.TabKata, "END_DAY")==0){
                    DayENDED=true;
                    Posisi =999;
                }
                else if (strcmp(CKata.TabKata, "FINISHBUILD")==0){
                    FinishBuild(&Pesanan , &CurrentlyBuilt, &Komponen, &Inventory);
                }
                else if (strcmp(CKata.TabKata, "STATUS")==0){
                    //Check Status
                    Status(duit , CurrentlyBuilt, Posisi, nomororder,noplg,  Inventory);
                }
                else if (strcmp(CKata.TabKata, "CHECKORDER")==0){
                    //PrintQueueLL(Komponen);
                    CheckOrderGopud (jmlorder, CurrentlyBuilt, Pesanan);
                }
                else if (strcmp(CKata.TabKata, "SHOP")==0){
                    Posisi = 1;
                }
                // else if (strcmp(CKata.TabKata, "CUSTOMER")==0){
                //     Posisi = rand() % (10);
                // }
                else if (strcmp(CKata.TabKata, "MAP")==0){
                    TulisMATRIKS (Map);
                    printf("\n");
                }
                else {
                    printf("Command salah!\n");
                }
                // strcompare :
                /*if command = Move {
                    print command move
                    Posisi ganti
                }
                else command command command
                if command = Exit ;
                start = false.*/
            }
            while (Posisi == 1){
                PrintCommandShop();
                /*1=Move
                  2=BuyItem*/
                printf("Masukkan Command : ");
                STARTKATAINPUT();
                if (strcmp(CKata.TabKata, "SHOP")==0){
                    shop(&Inventory, &duit);
                    CKata.TabKata[1] = 'X';
                }
                else if (strcmp(CKata.TabKata, "EXIT")==0){
                    start = false;
                    Posisi = 999;
                    DayENDED = true;
                }
                else if (strcmp(CKata.TabKata, "END_DAY")==0){
                    DayENDED=true;
                    Posisi =999;
                }
                else if(strcmp(CKata.TabKata, "MOVE")==0){
                    //Move;
                    Posisi = rand() % (Jumbuild);
                    printf("Kamu sekarang ada di building ke - %d", Posisi);
                }
                else if (strcmp(CKata.TabKata, "STATUS")==0){
                    //Check Status
                    Status(duit , CurrentlyBuilt, Posisi, nomororder,noplg,  Inventory);
                }
                else {
                    printf("Command salah!\n");
                }
            }
            while (Posisi >=2 && Posisi <=10){
                PrintCommandCustomer();
                /*1=Move
                  2=BuyItem*/
                printf("Masukkan Command : ");
                STARTKATAINPUT();
                if (strcmp(CKata.TabKata, "DELIVER")==0){
                    PuntenGopud(&Inventory, &noplg, Posisi, &duit, &hargajob);
                }
                else if (strcmp(CKata.TabKata, "EXIT")==0){
                    start = false;
                    Posisi = 999;
                    DayENDED = true;
                }
                else if (strcmp(CKata.TabKata, "END_DAY")==0){
                    DayENDED=true;
                    Posisi =999;
                }
                else if(strcmp(CKata.TabKata, "MOVE")==0){
                    //Move;
                    Posisi = rand() % (Jumbuild);
                    printf("Kamu sekarang ada di building ke - %d", Posisi);
                }
                else if (strcmp(CKata.TabKata, "STATUS")==0){
                    //Check Status
                    Status(duit , CurrentlyBuilt, Posisi, nomororder,noplg, Inventory);
                }
                else {
                    printf("Command salah!\n");
                }
            }
        }
    }
    printf("Terima kasih sudah bermain bersama Santo Tycoon. \n");
    return 0;
}