#include "mesinkata.h"

//primitif-primitif mesin kata
void Ignore_Blank() {
/*	Mengabaikan satu atau beberapa BLANK
	I.S. : CC sembarang
	F.S. : CC != BLANK atau CC == MARK
*/
	//ALGORITMA
	while (!EOP() && (CC==blank)) {
		ADV();
	}
	if (EOP())
		EndKata=true;
}

void STARTKATA(char* filename) {
/*	I.S. : CC sembarang
	F.S  : Salah satu dari dua kondisi dibawah.
		1. EndKata = true dan CC == Mark
		2. EndKata = false, CKata adalah kata yang sudah diakuisisi, dan CC adalah satu karakter setelah karakter terakhir kata

		Keterangan: CC mengacu pada yang disebut pada mesinkarakter
*/
	//ALGORITMA
// 	START(filename);
// 	Ignore_Blank();
// 	if (!EOP()) {
// 		EndKata=false;
// 		SalinKata();
// 	}
// 	else {
// 		EndKata=true;
// 	}
// }
{
    START(filename);
    Ignore_Blank();
    if (CC == MARK){
        EndKata = true;
    } else {
        EndKata = false;
        ADVKATA();
    }
}
}

void ADVKATA() {
/*	I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
	dari kata yg sudah diakuisisi
	F.S. : Jika CC = MARK, maka EndKata = true
	atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
	CC karakter pertama sesudah karakter terakhir kata
*/
	//ALGORITMA
{
    Ignore_Blank();
    if (CC == MARK && !EndKata){
        EndKata = true;
    } else{
        SalinKata();
        Ignore_Blank();
    }
}}

void SalinKata() {
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S. : CC adalah karakter pertama dari kata
	F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
	NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
	karakter sesudah karakter terakhir yang diakuisisi
*/
	//KAMUS LOKAL
	int i;
	//ALGORITMA

	//reset CKata terlebih dahulu
	for (i=0; i<CKata.Length; i++)
		CKata.TabKata[i]='\0';
	CKata.Length=0;
	while (!EOP() && (CC!=blank)) {
		if (CKata.Length<NMax) {
			CKata.Length+=1;
			CKata.TabKata[CKata.Length-1] = CC;
		}
		ADV();
	}
	if (EOP())
		EndKata = true;
}

//operasi lain
boolean IsKataSama(Kata K1, Kata K2) {
/*	Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
	urutan karakter yang menyusun kata juga sama. Sensitif terhadap uppercase dan lowercase
*/
	//KAMUS LOKAL
	int i;
	//ALGORITMA
	if (K1.Length==K2.Length) {
		i=0;
		while ((i<K1.Length) && (K1.TabKata[i]==K2.TabKata[i])) {
			i++;
		}
		if (i==K1.Length) return true;
		else return false;
	}
	else return false;
}



// int main (){
//     Kata kata1 = {("Ayam", 9)};
//     Kata kata2 = {("Ayam", 7)};
    
//     STARTKATA;
//     IsKataSama(kata1, kata2);
// }