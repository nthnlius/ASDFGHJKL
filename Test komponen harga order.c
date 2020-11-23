#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "queue.c"


#define rowNum 500000

int main(){
    //DAFTAR KOMPONEN
    //1
    const char *motherboard[] = {"Asus Prime 27", "AsusROG Crosshair", "GigaByte B365M", "GigaByte B450M"}; 
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
    //2     
    const char *cpu[] = {"Intel core I3 7020", "AMD Ryzen 3", "Intel Core I5 9070", "AMD Ryzen 7"};   
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
    //3            
    const char *memory[] = {"Samsung KKN 4GB", "Asus DSA 4GB", "Intel DI 4GB", "Asus PNR 4GB"};  
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
    //4            
    const char *cpucooler[] = {"Asus Cooler Fan", "Samsung Ultra Fan", "Eyota Fan", "Alseye H120D"}; 
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
    //5     
    const char *cases[] = {"Asus ROG Case Limited", "IBox Case Ori", "Samsung Case UX", "Asus EXP Case"}; 
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
    //6      
    const char *gpu[] = {"NVIDIA 1080 GTX", "Celeron 2030 X", "Intel 620 UHD", "NVIDA Geforce 2080 TI"}; 
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
    //7              
    const char *storage[] = {"Samsung 1 TB SATA", "ASUS STRG 500 GB", "Dell SSD 250 GB", "Samsung SSD 500 GB"};
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};
     //8       
    const char *psu[] = {"ATX 450 Watt", "ANS 500 Watt", "AVU Power 500 Watt", "Hein Power Supply 450 Watt"};  
    const int harga[] = {5650000, 5530000, 5786900, 6458200, 4987200, 5200900, 6290000, 7100000};                          
    ///////////////////////////////////////////////////////////

    //SIZE OF ARRAY
    int mb_count = sizeof(motherboard)/sizeof(motherboard[0]);
    int cpu_count = sizeof(cpu)/sizeof(cpu[0]);
    int mem_count = sizeof(memory)/sizeof(memory[0]);
    int cool_count = sizeof(cpucooler)/sizeof(cpucooler[0]);
    int case_count = sizeof(cases)/sizeof(cases[0]);
    int gpu_count = sizeof(gpu)/sizeof(gpu[0]);
    int stor_count = sizeof(storage)/sizeof(storage[0]);
    int psu_count = sizeof(psu)/sizeof(psu[0]);
    int harga_count = sizeof(harga)/sizeof(harga[0]);
    ////////////////////////////////////////////////////////////

    //CONST CHAR FOR RANDOMIZE
    int time();
    srand(time(NULL));
    const char *randommoth;
    const char *randomcpu;
    const char *randommem;
    const char *randomcooler;
    const char *randomcase;
    const char *randomgpu;
    const char *randomstor;
    const char *randompsu;
    const int *randomharga;
    ///////////////////////////////////////////////////////////

    /* RANDOMIZE STRING */
    randommoth = motherboard[rand()%mb_count];
    randomcpu = cpu[rand()%cpu_count];
    randommem = memory[rand()%mem_count];
    randomcooler = cpucooler[rand()%cool_count];
    randomcase = cases[rand()%case_count];
    randomgpu = gpu[rand()%gpu_count];
    randomstor = storage[rand()%stor_count];
    randompsu = psu[rand()%psu_count];
    randomharga = harga[rand()%harga_count];
    ////////////////////////////////////////////////////

    printf("Total yang harus dibayar %d", randomharga);
}   

    /////////////////////MAIN FUNCTION//////////////////

// int main(){
//     Queue Q;
//     infotype X = 15;
//     CreateEmpty(&Q, 10);
//     Add(&Q, X);
//     Add(&Q, 20);
//     if (IsEmpty(Q)){
//         printf("Queue Kosong\n");
//     }
//     else{
//         PrintQ(Q);
//     }
// }







