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
        if( CurrentlyBuilt != Nil ){ // udah startbuild jadi bisa addcomponent
            // harus nya dari sini loop sampe berhasil dipasang kalau mau nampilin semua inventory
            // tapi kalau satu2 per kategori harusnya gausa bikin loop
            printf("Komponen yang telah terpasang: ");
            // tampilin komponen yang terpasang
            // nampilin stack build (cek teststack.c)
            // hitung total stack ( S.TOP+1 ) kalo masih 0 ke motherboard dan seterusnya, kalo 1 ke 
            printf("Komponen motherboard yang tersedia: ");
            // tampilin inventory
            // TulisIsiTab(inventorymotherboard)
            // tampilin inventory yg >0, kalo barang yang bernilai = 0 gausa tampilin (how ya)
            for (int j = 0;j < 4;j++){
                printf("%d. %s \n", j+1, motherboard[j]);
            }
            printf("Komponen motherboard yang ingin dipasang: ");
            scanf("%d", &i);
            Push(&S, (*inventorymotherboard)[i-1] );
            jumlahmotherboard[i-1] = jumlahmotherboard[i-1] - 1;
            printf("Komponen motherboard berhasil dipasang!");
            // bikin command BACK buat keluar dari addcomponen ini
            
        }

        else{ 
            // belum startbuild 
            printf("Mulai startbuild terlebih dahulu!");
        }
    }
}
    
