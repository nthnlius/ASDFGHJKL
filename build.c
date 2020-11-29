#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
// #include "StartBuild.c"
#include "Komponen.c"

//BLOM KELAR MASI ALUR MIKIR DAN BAHKAN ALURNYA KEKNYA BELOM KELAR
//BENER BENER BARU PRINT PRINT DOANG

int AddComponent(char a[15]){
    // char ac[15];

    Stack S;
    CreateEmptyStack(&S);

    // QueueLL Q;
    // int Qi = Nil;
    // int Qmax = 10;
    // Q = CreateQLL(Qmax);
    int CurrentlyBuilt = 1;

    // char *X[12] = {"A", "B", "C", "D",
    //               "D", "E", "F", "G",
    //               "H", "I", "J", "K"}; 

    // int invetoryX[] = {9, 8, 6, 7,
    //                    9, 8, 6, 7, 
    //                    9, 8, 6, 7};

    // printf("ENTER COMMAND: ");
    // scanf("%s", ac);
    // StartBuild(Q,&Qi);
    while( (strcmp(a, "ADDCOMPONENT")==0) && (CurrentlyBuilt != 0)){
        printf("Komponen yang telah terpasang: \n");
        // tampilin komponen yang terpasang
        // nampilin stack build (cek teststack.c)
        // printf("%d. %s \n", 1, S);
        printf("Komponen yang tersedia: \n");
        // nampilin inventory
        while(j<12){
            if( invetoryX[j] != 0 ){
                printf("%d. %s \n", z+1, X[j]);
                z++;
            }
            j++;
        }
        
        printf("Komponen yang ingin dipasang: ");
        scanf("%d", &i);
        printf("%s\n", X[i-1]);
        // disini push ke S dari X[i-1]
        // invetoryX[i-1] = invetoryX[i-1] - 1;
        printf("Komponen berhasil dipasang!\n");

        printf("ENTER COMMAND: ");
        scanf("%s", a);
        z = 0;
        j = 0;
        // return(a);
        CurrentlyBuilt = 1;
    }
    if(CurrentlyBuilt == 0){
        printf("silahkan 'startbuild' terlebih dahulu\n");
    }

}

int RemoveComponent(char a[15]){
    // char ac[15];
    int CurrentlyBuilt = 1;
    
    // printf("ENTER COMMAND: ");
    // scanf("%s", ac);

    while( (strcmp(a, "REMOVECOMPONENT")==0) && (CurrentlyBuilt != 0)){
            printf("Komponen %s berhasil dicopot! \n", X[i-1] );
            printf("ENTER COMMAND: ");
            scanf("%s", a);
    }

    if(CurrentlyBuilt == 0){
        printf("silahkan 'startbuild' terlebih dahulu!!!\n");
    }
}
