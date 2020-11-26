#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "queuelinier.c"
#include "komponen.c"


void build(){
    Stack S;
    CreateEmptyStack(*S);
    IdxType CurrentlyBuilt;

    if( CurrentlyBuilt != Nil ){
        // udah startbuild jadi bisa addcomponent
        for (int j = 0;j < 4;j++){
            printf("%d. %s, \n", j+1, motherboard[j]);
        }
        printf("Komponen Motherboard yang keberapa ");
        scanf("%d", &i);
        Push(&S, (*inventorymotherboard)[i-1] );
        jumlahmotherboard[i-1] = jumlahmotherboard[i-1] - 1;
        
        for (int j = 0;j < 4;j++){
            printf("%d. %s, \n", j+1, cpu[j]);
        }
        printf("Komponen CPU yang keberapa ");
        scanf("%d", &i);
        Push(&S, (*inventorycpu)[i-1] );
        jumlahcpu[i-1] = jumlahcpu[i-1] - 1;
    }

    else{ 
        // belum startbuild 
        printf("Mulai startbuild terlebih dahulu!");
    }
}
    