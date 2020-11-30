#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
// #include "StartBuild.c"

int AddComponent(){
    // di startbuild createstack harusnya
    Stack S;
    CreateEmptyStack(&S);
    int i,j,z,w;
    j = 0;
    z = 0;
    w = 0;

    //ini masih pake inventory asal

//     char *X[12] = {"Ac", "B", "C", "D",
//                   "E", "F", "G", "H",
//                   "I", "J", "K","L"}; 

//     int invetoryX[] = {9, 8, 6, 0,
//                        9, 8, 6, 7, 
//                        9, 8, 6, 7};

    char ac[20];
    int CurrentlyBuilt = 1;
//     printf("ENTER COMMAND: ");
//     scanf("%s", ac);

    if( (strcmp(ac, "ADDCOMPONENT")==0) && ( CurrentlyBuilt != Nil )){
        while(strcmp(ac, "ADDCOMPONENT")==0){
            printf("Komponen yang telah terpasang: \n");
            // PrintStack(S);
            printf("Komponen yang tersedia: \n");
            // PrintStack(S);
            while(j<12){
                printf("%d. %s stock: %d \n", j+1, X[j], invetoryX[j]);
                j++;
            }
            printf("Komponen yang stocknya 0 tidak dapat dipasang! \n");
            printf("Komponen X yang ingin dipasang: ");
            scanf("%d", &i);

            if( invetoryX[i-1] == 0){
                printf("Komponen %s tidak tersedia! \n", X[i-1]);
            }
            else{
                // Push(&S, (X)[i-1]);
                printf("%s\n", X[i-1]);
                printf("%d\n",invetoryX[i-1]);
                printf("Komponen berhasil dipasang!\n");
            }
            printf("ENTER COMMAND: ");
            scanf("%s", ac);
            j = 0;
        }
    }
    else{
        printf("silahkan 'startbuild' terlebih dahulu\n");
    }
}

int RemoveComponent(){
    // di startbuild createstack harusnya
    int i,j,z,w;
    j = 0;
    z = 0;
    w = 0;
    i = 0;

    //ini masih pake inventory asal

//     char *X[12] = {"Ac", "B", "C", "D",
//                   "E", "F", "G", "H",
//                   "I", "J", "K","L"}; 

//     int invetoryX[] = {9, 8, 6, 0,
//                        9, 8, 6, 7, 
//                        9, 8, 6, 7};

    char ac[20];
    int CurrentlyBuilt = 1;
//     printf("ENTER COMMAND: ");
//     scanf("%s", ac);

    if( (strcmp(ac, "REMOVECOMPONENT")==0) && ( CurrentlyBuilt != Nil )){
        while(strcmp(ac, "REMOVECOMPONENT")==0){
            // Pop(&S,(&X)[i-1]);
            printf("Komponen berhasil dicopot! \n");
            printf("ENTER COMMAND: ");
            scanf("%s", ac);
        }
    }
    else{
        printf("silahkan 'startbuild' terlebih dahulu\n");
    }
}
