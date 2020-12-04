#ifndef _Inventory_H_
#define _Inventory_H_

#include "arraydin.h"
// #include "IsiIventory.h"

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

void shop(TabInt* T, long *jumlahuang);
TabInt masukinisi();
void PrintInventory(TabInt T);
#define NilOrder NULL
typedef int infotype ;
typedef struct tElmtQueueOrder * addressOrder;
typedef struct tElmtQueueOrder {
    int TIO[9];
    addressOrder NextOrder ;
}ElmtOrder;

typedef struct {
    addressOrder HeadOrder;
}QueueOrder;

/*Selektor*/
#define HeadOrder(Q) (Q).HeadOrder
#define InfoPart(P, i) (P)->TIO[i]
#define NextOrder(P) (P)->NextOrder

/*Creator*/
void EmptyOrder(QueueOrder * Q);
addressOrder MakeOrder(void);
void DealokasiOrder (addressOrder P);
void EnqueueOrder (QueueOrder * Q, addressOrder P);
void DequeueOrder(QueueOrder * Q, addressOrder * P);
void PrintOrder(QueueOrder Q);
void PrintQueue(QueueOrder Q);
void PrintKomponen(addressOrder P);
int HitungHonor(addressOrder P);
#endif