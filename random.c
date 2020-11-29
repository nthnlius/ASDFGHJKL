// C program for generating a 
// random number in a given range. 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
/*Source :
https://www.geeksforgeeks.org/generating-random-number-range-c/
*/
// Generates and prints 'count' random 
// numbers in range [lower, upper]. 
int Randoms(int lower, int upper,  
                             int count) 
{ 
    int i; 
    int num = (rand() % 
        (upper - lower + 1)) + lower; 
    return num;
} 
  
//Driver code 
int main() 
{ 
    int lower = 5, upper = 7, count = 1; 
  
    // Use current time as  
    // seed for random generator 
    srand(time(0)); 
    int A, B, C;
    A = 0;
    B = 4;
    // scanf("%d", &A);
    // scanf("%d", &B);
    int a = Randoms(A, B, 1);
    printf("hasil gacha : %d\n", a);
    return 0; 
} 

// int main() {
//      const char *str = "10";
//      const char *c = "27";
//      int x, y, z;
//      char t ;
//     char a ;
//     scanf ("%c", &t);
//     a = t;
//     int yee;
//     yee = atoi(&a);

//      y = atoi(str); // Using atoi()
//     printf("\nThe value of y : %d\n", y);
//     x = atoi(c);
//     printf("value c : %d\n", x);
//     return 0;
// }