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

#include <string.h>

int main(){
    boolean start = true;
    int Posisi = 0;
    int duit = 0;
    /*  0= base
        1 = shop
        2 = customer
        4 = ....
    */
    boolean DayENDED = false;
    int CountDay=0;
    MATRIKS Map = ReadFileMap("map.txt");
    QueueLL Pesanan;
    CreateQLL(&Pesanan);
    int CurrentlyBuilt = 0;
    TabInt Inventory;
    //printf("Selamat Datang di Santo Tycoon\n");
    Inventory = masukinisi();
    
    Stack Komponen;
    CreateEmptyStack(&Komponen);
    while (start){
        CountDay++;
        Posisi =0;
        printf("Day - %d\n", CountDay);
        DayENDED=false;
        while (!DayENDED){
            while (Posisi == 0){
                PrintCommandBase();
                printf("Masukkan Command : ");
                STARTKATAINPUT();
                if (strcmp(CKata.TabKata, "MOVE")==0){
                    //MOVE movean
                    //Posisi berubah
                    printf("harusnya Move\n");
                }
                else if (strcmp(CKata.TabKata, "STARTBUILD")==0){
                    StartBuild(Pesanan, CurrentlyBuilt);
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
                    FinishBuild(&Pesanan , &CurrentlyBuilt);
                }
                else if (strcmp(CKata.TabKata, "STATUS")==0){
                    //Check Status
                    printf("Nampilin Status\n");
                }
                else if (strcmp(CKata.TabKata, "CHECKORDER")==0){
                    //PrintQueueLL(Komponen);
                    printf("Nampilin order\n");
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
                if (strcmp(CKata.TabKata, "SHOP")==0){
                    shop(&Inventory, &duit);
                }
                else if (strcmp(CKata.TabKata, "EXIT")==0){
                    start = false;
                }
                else if (strcmp(CKata.TabKata, "END_DAY")==0){
                    DayENDED=true;
                }
                else if(strcmp(CKata.TabKata, "MOVE")==0){
                    //Move;
                    printf("Harusnya Move\n");
                }
            }
        }
    }
    printf("Terima kasih. \n");
    return 0;
}