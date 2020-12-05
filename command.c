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
    printf("8. MAP\n");
    printf("9. END_DAY\n");
    printf("10. EXIT\n");
    printbatas();
}
void PrintCommandShop(){
    printbatas();
    printf("1. MOVE\n");
    printf("2. SHOP\n");
    printf("3. STATUS\n");
    printf("4. MAP\n");
    printf("5. END_DAY\n");
    printf("6. EXIT\n");
    printbatas();
}
void PrintCommandCustomer(){
    printbatas();
    printf("1. MOVE\n");
    printf("2. DELIVER\n");
    printf("3. STATUS\n");
    printf("4. MAP\n");
    printf("5. END_DAY\n");
    printf("6. EXIT\n");
    printbatas();
}