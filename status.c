#include <stdio.h>
#include "boolean.h"
#include "startbuild.h"
#include "point.h"
#include "arraydin.h"
#include "inventory.h"

// int main(){
//   int jumlahuang = 2000;
//   boolean mulaipermainan = true
//   while (mulaipermainan){
// // jika enter command = status
//     printf("Uang Tersisa: "); printf("$ %d", uang);
//   // uang = uang + Q.nilai
//   // butuh command deliver
//   }
//   return 0;
// }
void Status(unsigned long jumlahuang, int StartBuild, int point, int antrian, int noplg,  TabInt T){
  printf("Uang Tersisa: "); printf("$ %lu\n", jumlahuang); //uang lihat di command deliver, variabelnya apa
  printf("Build yang sedang dikerjakan: ");
  if (StartBuild == 1){
    printf("Pesanan %d untuk pelanggan %d.\n", antrian, noplg+2);
  }else{
    printf("Sedang tidak ada yang dikerjakan. \n");
  }
  printf("Lokasi: ");
  if(point== 0){
    printf("Pemain sedang berada pada Base. \n");
  }else if(point == 1){
    printf("Pemain sedang berada pada Shop. \n");
  }else if(point == 2){
    printf("Pemain sedang berada pada Pelanggan 2. \n");
  }else if(point == 3){
    printf("Pemain sedang berada pada Pelanggan 3. \n");
  }else if(point == 4){
    printf("Pemain sedang berada pada Pelanggan 4. \n");
  }else if(point == 5){
    printf("Pemain sedang berada pada Pelanggan 5. \n");
  }else if(point == 6){
    printf("Pemain sedang berada pada Pelanggan 6. \n");
  }else if(point == 7){
    printf("Pemain sedang berada pada Pelanggan 7. \n");
  }else if(point == 8){
    printf("Pemain sedang berada pada Pelanggan 8. \n");
  }else if(point == 9){
    printf("Pemain sedang berada pada Pelanggan 9. \n");
  }
  printf("Inventory anda: \n");
  PrintInventory(T);
}
//   printf("\n\n Build yang sedang dikerjakan: \n\n"); printf("Pesanan %bla untuk pelanggan %bla", pesanan, pelanggan);
//   printf("\n\n Lokasi: \n\n"); printf("Pemain sedang berada dalam base")
//   printf("\n\n Inventory anda: \n\n")
// }
