#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "queuelinkedlist.h"
#include "arraydin.h"
// #include "StartBuild.c"
// #include "inventory.c"

// skr versi inventory arrydin tapi blom dicoba karena bingung :<
void AddComponent(Stack* S, TabInt *T, int CB){
    // di startbuild createstack harusnya
    // CreateEmptyStack(&S);
    int i,j,z,w;
    j = 0;
    z = 0;
    w = 0;

    //ini masih pake inventory asal

    // char *X[12] = {"Ac", "B", "C", "D",
    //               "E", "F", "G", "H",
    //               "I", "J", "K","L"}; 

    // int invetoryX[] = {9, 8, 6, 0,
    //                    9, 8, 6, 7, 
    //                    9, 8, 6, 7};

    //int CurrentlyBuilt = 1;
    // printf("ENTER COMMAND: ");
    // scanf("%s", ac);

    if (( CB != 0 )){
        //while(strcmp(ac, "ADDCOMPONENT")==0){
            printf("Komponen yang telah terpasang: \n");
            PrintStack(S);
            printf("Komponen yang tersedia: \n");
            while(j<32){ // NGEPRINT LIST KOMPONEN 
                printf("%d. %s stock: %d\n", j+1, (*T).A[j], (*T).TI[j]);
                j++;
            }
            printf("Komponen yang stocknya 0 tidak dapat dipasang! \n");
            printf("Komponen yang ingin dipasang: ");
            scanf("%d", &i); //nanti input (i) ini dikurang 1 untuk menyesuaikan index

            if( (*T).TI[i-1]== 0){ //kalau user milih komponen yang stocknya 0
                printf("Komponen %s tidak tersedia! \n", (*T).A[i-1]);
            }
            else{ //kalo user milih komponennya bener
                Push(S, (*T).A[i-1]); //nge push komponen pilihan ke stack (stack yg udh di create di startbuild)
                printf("Komponen %s sedang dipasang\n", (*T).A[i-1]); //memperlihatkan komponen apa yg ke push
                (*T).TI[i-1] = (*T).TI[i-1] -1; //ngurangin 1 stock dr komponen yg dipilih
                printf("Stock sekarang: %d\n",(*T).TI[i-1]); //ngeliatin stock 
                printf("Komponen berhasil dipasang!\n");
            }
            //printf("ENTER COMMAND: "); //kalo mau addcomponent lagi
            //scanf("%s", ac);
            j = 0;
        //}
    }
    else{ // ini kalo blom startbuild alias startbuild == Nil
        printf("silahkan 'startbuild' terlebih dahulu\n"); 
    }
}

void RemoveComponent(Stack* S, TabInt *T, int CB){
    // di startbuild createstack harusnya
    int i,j,z,w;
    j = 0;
    z = 0;
    w = 0;
    i = 0;
    infotypeS X; //variabel dummy untuk memenuhi parameter Pop

    //ini masih pake inventory asal

    // char *X[12] = {"Ac", "B", "C", "D",
    //               "E", "F", "G", "H",
    //               "I", "J", "K","L"}; 

    // int invetoryX[] = {9, 8, 6, 0,
    //                    9, 8, 6, 7, 
    //                    9, 8, 6, 7};

    //int CurrentlyBuilt = 1;
    // printf("ENTER COMMAND: ");
    // scanf("%s", ac);

    if(( CB != 0 )){
        //while(strcmp(ac, "REMOVECOMPONENT")==0){
            if (!IsStackEmpty(*S)){
                Pop(S, &X);
                printf("Komponen %s berhasil dicopot! \n", X); //ini %c ngikutin dari stack.c nya printstack
                // printf("ENTER COMMAND: ");
                // scanf("%s", ac);
            }
            else {
                printf("Tidak ada komponen yang bisa di remove\n");
            }
        //}
    }
    else{//CurrentBuilt == Nil atau blom startbuild
        printf("silahkan 'startbuild' terlebih dahulu\n");
    }
}
