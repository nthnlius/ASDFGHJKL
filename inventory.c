#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "arraydin.h"
#include "inventory.h"
#include "IsiIventory.h"
#include "map.h"
#include <string.h>


    // UNTUK KEPERLUAN MEMBELI KOMPONEN
    // const char *motherboard[] = {"Asus Prime 27", "AsusROG Crosshair", "GigaByte B365M", "GigaByte B450M"}; 
    // const int hmotherboard[] = {3650000, 3030000, 2886900, 3418200};
    // //2     
    // const char *cpu[] = {"Intel core I3 7020", "AMD Ryzen 3", "Intel Core I5 9070", "AMD Ryzen 7"};   
    // const int hcpu[] = {5250000, 5930000, 5886000, 6358000};
    // //3            
    // const char *memory[] = {"Samsung KKN 4GB", "Asus DSA 4GB", "Intel DI 4GB", "Asus PNR 4GB"};  
    // const int hmemory[] = {500000, 552000, 578000, 625000};
    // //4            
    // const char *cpucooler[] = {"Asus Cooler Fan", "Samsung Ultra Fan", "Eyota Fan", "Alseye H120D"}; 
    // const int hcpucooler[] = {567000, 532000, 613000, 645000};
    // //5     
    // const char *cases[] = {"Asus ROG Case Limited", "IBox Case Ori", "Samsung Case UX", "Asus EXP Case"}; 
    // const int hcases[] = {1650000, 1530000, 1786000, 1530000};
    // //6      
    // const char *gpu[] = {"NVIDIA 1080 GTX", "Celeron 2030 X", "Intel 620 UHD", "NVIDA Geforce 2080 TI"}; 
    // const int hgpu[] = {5650000, 5530000, 5786000, 6458000};
    // //7              
    // const char *storage[] = {"Samsung 1 TB SATA", "ASUS STRG 500 GB", "Dell SSD 250 GB", "Samsung SSD 500 GB"};
    // const int hstorage[] = {1350000, 1330000, 1700000, 1450000};
    //  //8       
    // const char *psu[] = {"ATX 450 Watt", "ANS 500 Watt", "AVU Power 500 Watt", "Hein Power Supply 450 Watt"};
    // const int hpsu[] = {120000, 135000, 140000, 210000};    
    
    
    // int duit = 20000000;



void shop(TabInt* T, long *jumlahuang){
        
    int beli;
    int beliberapa;

    printf("Komponen yang tersedia: \n");
        for (int i = 0;i < 4;i++){
            printf("%d. %s, harga Rp.%d\n", i+1, motherboard[i], hmotherboard[i]);
        }
        
        for (int i = 0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+5, cpu[i], hcpu[i]);
        }
        
        for (int i =0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+9, memory[i], hmemory[i]);
        }
        
        for (int i = 0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+13, cpucooler[i], hcpucooler[i]);
        }
        
        for (int i = 0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+17, cases[i], hcases[i]);
        }
        
        for (int i = 0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+21, gpu[i], hgpu[i]);
        }
        
        for (int i = 0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+25, storage[i], hstorage[i]);
        }
       
        for (int i = 0; i<4; i++){
            printf("%d. %s, harga Rp.%d\n", i+29, psu[i], hpsu[i]);
        }
        printf("\n");


    printf("Komponen yang ingin dibeli : ");
    scanf("%d", &beli);
    printf("Masukkan jumlah yang ingin dibeli : ");
    scanf("%d", &beliberapa);


    if (beliberapa >=0){
    if (beli == 1){
        if (*jumlahuang >= beliberapa*hmotherboard[0]){
            *jumlahuang = *jumlahuang - beliberapa*hmotherboard[0];
            (*T).TI[1] = (*T).TI[1] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 2){
        if (*jumlahuang >= beliberapa*hmotherboard[1]){
            *jumlahuang = *jumlahuang - beliberapa*hmotherboard[1];
            (*T).TI[2] = (*T).TI[2] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 3){
        if (*jumlahuang >= beliberapa*hmotherboard[2]){
            *jumlahuang = *jumlahuang - beliberapa*hmotherboard[2];
            (*T).TI[3] = (*T).TI[3] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 4){
        if (*jumlahuang >= beliberapa*hmotherboard[3]){
            *jumlahuang = *jumlahuang - beliberapa*hmotherboard[3];
            (*T).TI[4] = (*T).TI[4] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 5){
        if (*jumlahuang >= beliberapa*hcpu[0]){
            *jumlahuang = *jumlahuang - beliberapa*hcpu[0];
            (*T).TI[5] = (*T).TI[5] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

     else if (beli == 6){
        if (*jumlahuang >= beliberapa*hcpu[1]){
            *jumlahuang = *jumlahuang - beliberapa*hcpu[1];
            (*T).TI[6] = (*T).TI[6] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

     else if (beli == 7){
        if (*jumlahuang >= beliberapa*hcpu[2]){
            *jumlahuang = *jumlahuang - beliberapa*hcpu[2];
            (*T).TI[7] = (*T).TI[7] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

     else if (beli == 8){
        if (*jumlahuang >= beliberapa*hcpu[3]){
            *jumlahuang = *jumlahuang - beliberapa*hcpu[3];
            (*T).TI[8] = (*T).TI[8] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

     else if (beli == 9){
        if (*jumlahuang >= beliberapa*hmemory[0]){
            *jumlahuang = *jumlahuang - beliberapa*hmemory[0];
            (*T).TI[9] = (*T).TI[9] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 10){
        if (*jumlahuang >= beliberapa*hmemory[1]){
            *jumlahuang = *jumlahuang - beliberapa*hmemory[1];
            (*T).TI[10] = (*T).TI[10] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 11){
        if (*jumlahuang >= beliberapa*hmemory[2]){
            *jumlahuang = *jumlahuang - beliberapa*hmemory[2];
            (*T).TI[11] = (*T).TI[11] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 12){
        if (*jumlahuang >= beliberapa*hmemory[3]){
            *jumlahuang = *jumlahuang - beliberapa*hmemory[3];
            (*T).TI[12] = (*T).TI[12] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }
    
    else if (beli == 13){
        if (*jumlahuang >= beliberapa*hcpucooler[0]){
            *jumlahuang = *jumlahuang - beliberapa*hcpucooler[0];
            (*T).TI[13] = (*T).TI[13] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 14){
        if (*jumlahuang >= beliberapa*hcpucooler[1]){
            *jumlahuang = *jumlahuang - beliberapa*hcpucooler[1];
            (*T).TI[14] = (*T).TI[14] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 15){
        if (*jumlahuang >= beliberapa*hcpucooler[2]){
            *jumlahuang = *jumlahuang - beliberapa*hcpucooler[2];
            (*T).TI[15] = (*T).TI[15] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }
    
    else if (beli == 16){
        if (*jumlahuang >= beliberapa*hcpucooler[3]){
            *jumlahuang = *jumlahuang - beliberapa*hcpucooler[3];
            (*T).TI[16] = (*T).TI[16] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }
    
    else if (beli == 17){
        if (*jumlahuang >= beliberapa*hcases[0]){
            *jumlahuang = *jumlahuang - beliberapa*hcases[0];
            (*T).TI[17] = (*T).TI[17] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 18){
        if (*jumlahuang >= beliberapa*hcases[1]){
            *jumlahuang = *jumlahuang - beliberapa*hcases[1];
            (*T).TI[18] = (*T).TI[18] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 19){
        if (*jumlahuang >= beliberapa*hcases[2]){
            *jumlahuang = *jumlahuang - beliberapa*hcases[2];
            (*T).TI[19] = (*T).TI[19] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 20){
        if (*jumlahuang >= beliberapa*hcases[3]){
            *jumlahuang = *jumlahuang - beliberapa*hcases[3];
            (*T).TI[20] = (*T).TI[20] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 21){
        if (*jumlahuang >= beliberapa*hgpu[0]){
            *jumlahuang = *jumlahuang - beliberapa*hgpu[0];
            (*T).TI[21] = (*T).TI[21] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 22){
        if (*jumlahuang >= beliberapa*hgpu[1]){
            *jumlahuang = *jumlahuang - beliberapa*hgpu[1];
            (*T).TI[22] = (*T).TI[22] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 23){
        if (*jumlahuang >= beliberapa*hgpu[2]){
            *jumlahuang = *jumlahuang - beliberapa*hgpu[2];
            (*T).TI[23] = (*T).TI[23] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 24){
        if (*jumlahuang >= beliberapa*hgpu[3]){
            *jumlahuang = *jumlahuang - beliberapa*hgpu[3];
            (*T).TI[24] = (*T).TI[24] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 25){
        if (*jumlahuang >= beliberapa*hstorage[0]){
            *jumlahuang = *jumlahuang - beliberapa*hstorage[0];
            (*T).TI[25] = (*T).TI[25] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 26){
        if (*jumlahuang >= beliberapa*hstorage[1]){
            *jumlahuang = *jumlahuang - beliberapa*hstorage[1];
            (*T).TI[26] = (*T).TI[26] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 27){
        if (*jumlahuang >= beliberapa*hstorage[2]){
            *jumlahuang = *jumlahuang - beliberapa*hstorage[2];
            (*T).TI[27] = (*T).TI[27] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 28){
        if (*jumlahuang >= beliberapa*hstorage[3]){
            *jumlahuang = *jumlahuang - beliberapa*hstorage[3];
            (*T).TI[28] = (*T).TI[28] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 29){
        if (*jumlahuang >= beliberapa*hpsu[0]){
            *jumlahuang = *jumlahuang - beliberapa*hpsu[0];
            (*T).TI[29] = (*T).TI[29] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 30){
        if (*jumlahuang >= beliberapa*hpsu[1]){
            *jumlahuang = *jumlahuang - beliberapa*hpsu[1];
            (*T).TI[30] = (*T).TI[30] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 31){
        if (*jumlahuang >= beliberapa*hpsu[2]){
            *jumlahuang = *jumlahuang - beliberapa*hpsu[2];
            (*T).TI[31] = (*T).TI[31] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }

    else if (beli == 32){
        if (*jumlahuang >= beliberapa*hpsu[3]){
            *jumlahuang = *jumlahuang - beliberapa*hpsu[3];
            (*T).TI[32] = (*T).TI[32] + beliberapa;
            printf("Komponen berhasil dibeli!\n");
        }
        else{
        printf("Uang anda tidak cukup!\n");
    }

    }
    }
    else{
        printf("Cie mau ngebug... \n");
    }
    // CUMA BUAT TEST
    // printf("%d\n", jumlahuang);
    // for (int i=1; i<=32; i++){
    //     printf("%s dengan jumlah %d\n", (*T).A[i], (*T).TI[i]);
    // }
    

}
 

 TabInt masukinisi(){
    //TabInt T;
    TabInt *T;
    // MakeEmpty(T, 33);     // Membuat empty array dengan 32 elemen kosong. Asumsi semua komponen mendapat tempat satu


    // (*T).A[i] melambangkan nama barang, dan (*T).TI[i] adalah jumlah inventory
    (*T).A[1] = "Asus Prime 27";                   (*T).A[17] = "Asus ROG Case Limited";
    (*T).TI[1] = 1;                                (*T).TI[17] = 1;
    (*T).A[2] = "AsusROG Crosshair";               (*T).A[18] = "IBox Case Ori";
    (*T).TI[2] = 1;                                (*T).TI[18] = 1;
    (*T).A[3] = "GigaByte B365M";                  (*T).A[19] = "Samsung Case UX";
    (*T).TI[3] = 1;                                (*T).TI[19] = 1;    
    (*T).A[4] = "GigaByte B450M";                  (*T).A[20] = "Asus EXP Case";
    (*T).TI[4] = 1;                                (*T).TI[20] = 1;
    (*T).A[5] = "Intel core I3 7020";              (*T).A[21] = "NVIDIA 1080 GTX"; 
    (*T).TI[5] = 1;                                (*T).TI[21] = 1;
    (*T).A[6] = "AMD Ryzen 3";                     (*T).A[22] = "Celeron 2030 X";
    (*T).TI[6] = 1;                                (*T).TI[22] = 1;
    (*T).A[7] =  "Intel Core I5 9070";             (*T).A[23] = "Intel 620 UHD";
    (*T).TI[7] = 1;                                (*T).TI[23] = 1;
    (*T).A[8] = "AMD Ryzen 7";                     (*T).A[24] = "NVIDA Geforce 2080 TI";
    (*T).TI[8] = 1;                                (*T).TI[24] = 1;
    (*T).A[9] = "Samsung KKN 4GB";                 (*T).A[25] = "Samsung 1 TB SATA"; 
    (*T).TI[9] = 1;                                (*T).TI[25] = 1; 
    (*T).A[10] = "Asus DSA 4GB";                   (*T).A[26] = "ASUS STRG 500 GB";    
    (*T).TI[10] = 1;                               (*T).TI[26] = 1;
    (*T).A[11] = "Intel DI 4GB";                   (*T).A[27] = "Dell SSD 250 GB";
    (*T).TI[11] = 1;                               (*T).TI[27] = 1;
    (*T).A[12] = "Asus PNR 4GB";                   (*T).A[28] = "Samsung SSD 500 GB";
    (*T).TI[12] = 1;                               (*T).TI[28] = 1;
    (*T).A[13] = "Asus Cooler Fan";                (*T).A[29] = "ATX 450 Watt"; 
    (*T).TI[13] = 1;                               (*T).TI[29] = 1;
    (*T).A[14] = "Samsung Ultra Fan";              (*T).A[30] = "ANS 500 Watt";
    (*T).TI[14] = 1;                               (*T).TI[30] = 1;
    (*T).A[15] = "Eyota Fan";                      (*T).A[31] = "AVU Power 500 Watt";
    (*T).TI[15] = 1;                               (*T).TI[31] = 1; 
    (*T).A[16] = "Alseye H120D";                   (*T).A[32] = "Hein Power Supply 450 Watt";
    (*T).TI[16] = 1;                               (*T).TI[32] = 1;

    (*T).Neff = 32;
    
     //shop(T);
    // printf("%s berjumlah %d", (*T).A[1], (*T).TI[1]);  CUMA NGETEST
    return (*T);
 }
void PrintInventory(TabInt T){
    int i;
    //printf("Uang anda : %d \n Inventory anda : \n", jumlahuang);
    for (i=1;i<T.Neff;i++){
        printf("%s berjumlah %d\n", T.A[i], T.TI[i]);
    }
}
void EmptyOrder(QueueOrder * Q){
    HeadOrder(*Q)=NilOrder ;
}

addressOrder MakeOrder(void){
    int Hermes;
    Hermes = bacajumlahbuilding("map.txt");
    addressOrder P;
    P = (addressOrder)malloc(sizeof(ElmtOrder));
    if (P != NULL){
        int i;
        InfoPart(P, 0) = (rand()% (Hermes-2))+1;
        for (i=1; i<9;i++){
            InfoPart(P, i)= (rand()%4);
        }
        NextOrder(P) = NilOrder;
    }
    else {
        69!=420;
    }
    return P;
}
/*i = 0 : indeks Nomor Komponen
      1 : indeks Motherboard (TI[1]=3 maksudnya Motherboardnya harus GigaByteB450M)
      2 : indeks CPU
      3 : indeks Memory
      4 : indeks CPU Cooler
      5 : indeks Case
      6 : GPU
      7 : Storage
      8 : PSU */
void DealokasiOrder (addressOrder P){
    free(P);
}

void EnqueueOrder (QueueOrder * Q, addressOrder P){
    if (HeadOrder(*Q)==NilOrder){//order udah kosong
        HeadOrder(*Q)=P;
    }
    else{
        addressOrder P1;
        P1 = HeadOrder(*Q);
        while (NextOrder(P1)!=NilOrder){
            P1 = NextOrder(P1);
        }//P1 udah last
        NextOrder(P1)=P;
    }
}
void DequeueOrder(QueueOrder * Q, addressOrder * P){
    *P = HeadOrder(*Q);
    HeadOrder(*Q)=NextOrder(HeadOrder(*Q));
    DealokasiOrder(*P);
    
}
int HitungHonor(addressOrder P){
    int honor;
    honor = hmotherboard[InfoPart(P, 1)];
    honor += hcpu[InfoPart(P, 2)];
    honor += hmemory[InfoPart(P, 3)];
    honor += hcpucooler[InfoPart(P, 4)];
    honor += hcases[InfoPart(P, 5)];
    honor += hgpu[InfoPart(P, 6)];
    honor += hstorage[InfoPart(P, 7)];
    honor += hpsu[InfoPart(P,8)];
    honor = honor + (honor *0.2);
    return honor;
}
void PrintOrder(QueueOrder Q){
    if (HeadOrder(Q)!=NilOrder){
        addressOrder P;
        P = HeadOrder(Q);
        while (NextOrder(P) != NilOrder){
            printf("Pesanan untuk Customer %d     ", InfoPart(P, 0));
            printf("Invoice : %d \n", HitungHonor(P));
            P = NextOrder(P);
        }
        printf("Pesanan untuk Customer %d     ", InfoPart(P, 0));
        printf("Invoice : %d \n", HitungHonor(P));
    }
}
void PrintQueue(QueueOrder Q){
    printf("[");
    if (HeadOrder(Q)!=NilOrder){
        addressOrder P;
        P = HeadOrder(Q);
        while (NextOrder(P)!= NilOrder){
            printf("%d, ", InfoPart(P, 0));
            P=NextOrder(P);
        }
        printf("%d", InfoPart(P, 0));
    }
    printf("]\n");
}
void PrintKomponen(addressOrder P){
    //int i;
    printf("Komponen: \n");
    printf("1. %s \n", motherboard[InfoPart(P,1)]);
    printf("2. %s \n", cpu[InfoPart(P,2)]);
    printf("3. %s \n", memory[InfoPart(P,3)]);
    printf("4. %s \n", cpucooler[InfoPart(P,4)]);
    printf("5. %s \n", cases[InfoPart(P,5)]);
    printf("6. %s \n", gpu[InfoPart(P,6)]);
    printf("7. %s \n", storage[InfoPart(P,7)]);
    printf("8. %s \n", psu[InfoPart(P,8)]);
}
boolean checkstack(Stack S, QueueOrder Q){
    addressOrder P;
    P = HeadOrder(Q);
    boolean checkmotherboard, checkcpu, checkmemory, checkcooler, checkcases, checkgpu, checkstorage, checkpsu;
    checkmotherboard = (S.T[0]==motherboard[InfoPart(P, 1)]);
    checkcpu = (S.T[1]==cpu[(InfoPart(P,2))]);
    checkmemory = (S.T[2]==memory[InfoPart(P,3)]);
    checkcooler = (S.T[3]==cpucooler[InfoPart(P,4)]);
    checkcases= (S.T[4]== cases[InfoPart(P,5)]);
    checkgpu = (S.T[5]==gpu[InfoPart(P,6)]);
    checkstorage =(S.T[6]==storage[InfoPart(P,7)]);
    checkpsu = (S.T[7]==psu[InfoPart(P,8)]);
    boolean checkall;
    checkall = (checkmotherboard && checkcpu && checkmemory && checkcooler && checkcases && checkgpu && checkstorage && checkpsu);
    return (checkall);
}
void PuntenGopud(TabInt *T, int *noplg, int Posisi, unsigned long *duit, int *honor, int noorder){
    if (((*noplg)+2) != Posisi){
        printf("Salah tempat, Mas.\n");
    }
    else {
        if (strcmp((*T).A[(*T).Neff], "Pesanan")==0){
            (*T).Neff --;
            *duit += *honor;
            *honor =0;
            *noplg = -999;
            printf("Pesanan #%d telah dikirim. \n", noorder);
        }
        else {
            printf("Pelanggan ngambek dikarenakan pesanan tidak sesuai aplikasi \n");
        }
    }

}
void CheckOrderGopud (int noorder, int Curr, QueueOrder Q){
    if (Curr == 0){
        printf("Anda nganggur. Cari kerja sono jangan jadi beban ortu.\n");
    }
    else {
        addressOrder P;
        P = HeadOrder(Q);
        printf("Nomor Order : %d\n", noorder);
        printf("Pesanan untuk Customer %d \n", InfoPart(P, 0)+1);
        printf("Invoice : %d \n", HitungHonor(P));
        PrintKomponen(P);
    }
}
//  int main(){
//      TabInt T;
//     T = masukinisi();
//     printf("%s berjumlah %d", (*T).A[1], (*T).TI[1]);
//  }