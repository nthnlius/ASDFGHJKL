#include <stdio.h>
#include "stack.h"
/* *** Konstruktor/Kreator *** */
Stack CreateEmptyStack()
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Stack S;
    S.TOP= NilS;
    int i;
   for (i=0 ; i<MaxEl ; i++){
       S.T[i]="\0";
   }
    return S;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsStackEmpty(Stack S)
{
    return S.TOP == NilS ;
}
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsStackFull(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return (S.TOP == MaxEl);
}

bool IsStackOneElmt(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return (S.TOP == 0);
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotypeS X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    if (IsStackEmpty(*S) != false){
        //printf("eee : %d\n", (*S).TOP);
        //printf("ddd : %s\n", (*S).T[(*S).TOP]);
        (*S).TOP = (*S).TOP + 1;
        (*S).T[(*S).TOP]=X;
    }
    else{
        //printf("eee : %d\n", (*S).TOP);
        //printf("ddd : %s\n", (*S).T[(*S).TOP]);
        if (!IsStackFull(*S)){
            (*S).TOP = (*S).TOP + 1;
            (*S).T[(*S).TOP]=X;
        }
    }
    
        //printf("eee : %d\n", (*S).TOP);
        //printf("ddd : %s\n", (*S).T[(*S).TOP]);
}
void Pop(Stack *S, infotypeS *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    if ((*S).TOP == 0){
        //printf("Athena\n");
        *X = (*S).T[(*S).TOP];
        //printf("Demeter\n");
        (*S).TOP = NilS;
        //printf("Hades\n");
        //printf("%d \n", (*S).TOP);
    }
    else{
        //printf("Zeus\n");
        *X=(*S).T[(*S).TOP];
        //printf("Poseidon\n");
        (*S).TOP -- ;
        //printf("Ares\n");
    }
}

/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotypeS X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
{
    if (IsStackFull(*S)){
        int i;
        for (i=0;i<MaxEl;i++){
            (*S).T[i]=(*S).T[i+1];
        }
        (*S).T[((*S).TOP)-1] = X;
    }
    else {
        Push(S, X);
    }
}

void CopyStack(Stack * S, Stack * Sout)
/*Men-copy Stack S ke Stack Sout.
I.S. S tidak mungkin kosong
FS . Tercipta Stack Sout dengan elemen sama persis dengan Stack S */
{
    Stack Stemp;
    infotypeS X;
    Stemp = CreateEmptyStack();
    *Sout = CreateEmptyStack();
    int i=0;
    while (!IsStackEmpty(*S)){
    // printf("aaa : %d\n", Stemp.TOP);
    // printf("bbb : %s\n", (*S).T[(*S).TOP]);
    // printf("ccc : %d\n", (*S).TOP);
        Push(&Stemp, (*S).T[(*S).TOP]);
        Pop(S, &X);
    }
    //printf("mabar\n");
    while (!IsStackEmpty(Stemp)){
        Push (S, Stemp.T[Stemp.TOP]);
        //printf("anjay mabar = %s \n", Stemp.T[Stemp.TOP]);
        Push (Sout, Stemp.T[Stemp.TOP]);
        //i++;
        //printf("%d\n",i);
        Pop(&Stemp, &X);
    }
}

void InversStack(Stack S, Stack * Sout){
    Stack Stemp;
    infotypeS X;
    Stemp = CreateEmptyStack();
    *Sout = CreateEmptyStack();
    CopyStack(&S, &Stemp);
    while (!IsStackEmpty(Stemp)){
        Push(Sout, Stemp.T[Stemp.TOP]);
        Pop(&Stemp, &X);
    }
}

void PrintStack(Stack * S){
    Stack Stemp;
    infotypeS X; //variabel dummy untuk memenuhi parameter Pop
    Stemp = CreateEmptyStack();
    InversStack(*S, &Stemp);
    printf("[");
    //printf("aaaa : %d", Stemp.TOP);
    if (!IsStackEmpty(Stemp)){
        while (!IsStackOneElmt(Stemp)){
            printf("%s, ", Stemp.T[Stemp.TOP]);
            Pop(&Stemp, &X);
            
        }
        printf("%s", Stemp.T[Stemp.TOP]);
    }
    printf("]\n");
}

// int main(void){
//     Stack S, S1;
//     infotypeS A, B, C, D, E, F, G, H, I;
//     printf("Masukkan Kata : ");
//     STARTKATAINPUT();
//     S=CreateEmptyStack();
//     //printf("aaa : %d\n", S.TOP);
//     int i;
//     // for (i=0; i <MaxEl; i++){
//     //     printf("bbbb : %s,", S.T[i]);
//     // }
//     Push (&S, CKata.TabKata);
//     S1 = CreateEmptyStack();
//     // CopyStack(&S, &S1);
//     InversStack(S, &S1);
//     //PrintStack(S); 
//     //Push(&S, A);
//     // printf("%c\n", A);
//     // printf("%c\n", B);
//     // printf("%c\n", C);
//     // printf("%c\n", D);
//     // printf("%c\n", E);
//     // printf("%c\n", F);
//     // printf("%c\n", G);
//     // printf("%c\n", H);
//     // printf("%c\n", I);
//     // Top(S)=A;
//     // printf("%c\n", Top(S));
//     // Push(&S, B);
//     // Push(&S, C);
//     // Push(&S, D);
//     // Push(&S, E);
//     // Push(&S, F);
//     // Push(&S, G);
//     // Push(&S, H);
//     // Push(&S, I);
//     //printf("1\n");
//     PrintStack(&S);
// }
