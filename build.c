#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "queuelinier.c"
#include "komponen.c"
#include "arraydin.c"


void addcomponent(){
    char ac[15];
    Stack S;
    CreateEmptyStack(*S);
    IdxType CurrentlyBuilt;

    printf("ENTER COMMAND: ");
    scanf("%s", ac);
    if (strcmp(ac, "ADDCOMPONENT")==0){
        if( CurrentlyBuilt != Nil ){// udah startbuild jadi bisa addcomponent
            printf("Komponen yang telah terpasang: ");
            // tampilin komponen yang terpasang
            printf("Komponen yang tersedia: ");
            // tampilin inventory
            // TulisIsiTab(inventorymotherboard)
            for (int j = 0;j < 4;j++){
                printf("%d. %s, \n", j+1, motherboard[j]);
            }
            printf("Komponen motherboard yang ingin dipasang: ");
            scanf("%d", &i);
            Push(&S, (*inventorymotherboard)[i-1] );
            jumlahmotherboard[i-1] = jumlahmotherboard[i-1] - 1;
            printf("Komponen motherboard berhasil dipasang!");

        }

        else{ 
            // belum startbuild 
            printf("Mulai startbuild terlebih dahulu!");
        }
    }
}
    
