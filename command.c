#include "command.h"

void printbatas(){
    printf("\n=================================================================================\n");
}
void PrintCommandBase(){
    printbatas();
    printf("1. MOVE\n");
    printf("2. STARTBUILD\n");
    printf("3. FINISHBUILD\n");
    printf("4. ADDCOMPONENT\n");
    printf("5. REMOVECOMPONENT\n");
    printf("6. STATUS\n");
    printf("7. CHECKORDER\n");
    printf("8. END_DAY\n");
    printf("9. EXIT\n");
}
void PrintCommandShop(){
    printbatas();
    printf("1. MOVE\n");
    printf("2. SHOP\n");
    printf("3. END_DAY\n");
    printf("4. EXIT\n");
}