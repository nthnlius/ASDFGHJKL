#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "build.c"


    // INI MASI ERROR PAS DARI SALAH SATU WHILE GABISA KE WHILE YG LAIN BISANYA KE BACK
int main(){
    char ac[20];
    int CurrentlyBuilt = 1;
    
    printf("ENTER COMMAND: ");
    scanf("%s", ac);
    
    if( (strcmp(ac, "ADDCOMPONENT")==0) && ( CurrentlyBuilt != Nil )){
        while( (strcmp(ac, "ADDCOMPONENT")==0)){
            AddComponent(ac);
            printf("ceritanya udah masuk ke main menu\n");
            printf("ENTER COMMAND: ");
            scanf("%s", ac);
            CurrentlyBuilt = 1;
        }
    }

    else if( (strcmp(ac, "REMOVECOMPONENT")==0) && ( CurrentlyBuilt != Nil )){
        while( (strcmp(ac, "REMOVECOMPONENT")==0) ){
            RemoveComponent(ac);
            printf("ceritanya udah masuk ke main menu\n");
            printf("ENTER COMMAND: ");
            scanf("%s", ac);
            // return ac;
            CurrentlyBuilt = 1;
        }
    }

    else if( (strcmp(ac, "BACK")==0) && (CurrentlyBuilt != Nil)){
        printf("ceritanya balik ke MAIN menu lagi");
    }
    
}
