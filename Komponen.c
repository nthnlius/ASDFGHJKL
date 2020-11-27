#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"

#define rowNum 100
    //DAFTAR KOMPONEN
    //1
    const char *motherboard[] = {"Asus Prime 27", "AsusROG Crosshair", "GigaByte B365M", "GigaByte B450M"}; 
    const int hmotherboard[] = {3650000, 3030000, 2886900, 3418200};
    //2     
    const char *cpu[] = {"Intel core I3 7020", "AMD Ryzen 3", "Intel Core I5 9070", "AMD Ryzen 7"};   
    const int hcpu[] = {5250000, 5930000, 5886000, 6358000};
    //3            
    const char *memory[] = {"Samsung KKN 4GB", "Asus DSA 4GB", "Intel DI 4GB", "Asus PNR 4GB"};  
    const int hmemory[] = {500000, 552000, 578000, 625000};
    //4            
    const char *cpucooler[] = {"Asus Cooler Fan", "Samsung Ultra Fan", "Eyota Fan", "Alseye H120D"}; 
    const int hcpucooler[] = {567000, 532000, 613000, 645000};
    //5     
    const char *cases[] = {"Asus ROG Case Limited", "IBox Case Ori", "Samsung Case UX", "Asus EXP Case"}; 
    const int hcases[] = {1650000, 1530000, 1786000, 1530000};
    //6      
    const char *gpu[] = {"NVIDIA 1080 GTX", "Celeron 2030 X", "Intel 620 UHD", "NVIDA Geforce 2080 TI"}; 
    const int hgpu[] = {5650000, 5530000, 5786000, 6458000};
    //7              
    const char *storage[] = {"Samsung 1 TB SATA", "ASUS STRG 500 GB", "Dell SSD 250 GB", "Samsung SSD 500 GB"};
    const int hstorage[] = {1350000, 1330000, 1700000, 1450000};
     //8       
    const char *psu[] = {"ATX 450 Watt", "ANS 500 Watt", "AVU Power 500 Watt", "Hein Power Supply 450 Watt"};
    const int hpsu[] = {120000, 135000, 140000, 210000};   

    //SIZE OF ARRAY
    const int randomI[] = {1, 2, 3, 4};
    int indexIsembarang = sizeof(randomI)/sizeof(randomI[0]);
    
    int jumlahuang = 20000000;

    char *inventorymotherboard[] = {"Asus Prime 27", "AsusROG Crosshair", "GigaByte B365M", "GigaByte B450M"};
    char *inventorycpu[] = {"Intel core I3 7020", "AMD Ryzen 3", "Intel Core I5 9070", "AMD Ryzen 7"};
    char *inventorymemory[] = {"Samsung KKN 4GB", "Asus DSA 4GB", "Intel DI 4GB", "Asus PNR 4GB"};
    char *inventorycpucooler[] = {"Asus Cooler Fan", "Samsung Ultra Fan", "Eyota Fan", "Alseye H120D"};
    char *inventorycases[] = {"Asus ROG Case Limited", "IBox Case Ori", "Samsung Case UX", "Asus EXP Case"};
    char *inventorygpu[] = {"NVIDIA 1080 GTX", "Celeron 2030 X", "Intel 620 UHD", "NVIDA Geforce 2080 TI"};
    char *inventorystorage[] = {"Samsung 1 TB SATA", "ASUS STRG 500 GB", "Dell SSD 250 GB", "Samsung SSD 500 GB"};
    char *inventorypsu[] = {"ATX 450 Watt", "ANS 500 Watt", "AVU Power 500 Watt", "Hein Power Supply 450 Watt"};

    int jumlahmotherboard[] = {9, 8, 6, 7};
    int jumlahcpu[] = {6, 5, 7, 6};
    int jumlahmemory[] = {7, 6, 8, 5};
    int jumlahmcpucooler[] = {9, 6, 7, 8};
    int jumlahcases[] = {8, 6, 9, 8};
    int jumlahgpu[] = {8, 6, 7, 8};
    int jumlahstorage[] = {9, 8, 9, 7};
    int jumlahpsu[] = {9, 7, 8, 9};

