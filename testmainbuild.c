#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "build.c"


// INI MASI ERROR PAS DARI SALAH SATU WHILE GABISA KE WHILE YG LAIN BISANYA KE BACK

int main(){
    char ac[15];
    int CurrentlyBuilt = 1;
    
    printf("ENTER COMMAND: ");
    scanf("%s", ac);
    
    while( (strcmp(ac, "ADDCOMPONENT")==0) && (CurrentlyBuilt != 0)){
        AddComponent(ac);
        printf("ceritanya udah masuk ke main menu\n");
        printf("ENTER COMMAND: ");
        scanf("%s", ac);
        // return ac;
        CurrentlyBuilt = 1;
    }

    while( (strcmp(ac, "REMOVECOMPONENT")==0) ){
        RemoveComponent(ac);
        printf("ceritanya udah masuk ke main menu\n");
        printf("ENTER COMMAND: ");
        scanf("%s", ac);
        // return ac;
        CurrentlyBuilt = 1;
    }

    if( (strcmp(ac, "BACK")==0) && (CurrentlyBuilt != 0)){
        printf("ceritanya balik ke MAIN menu lagi");
    }
}
