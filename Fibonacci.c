#include <stdio.h>
#include <math.h>

int main(){
	int low,high = 1;
	int hasil,N,i;
	//Beri masukkan bilangan bulat
	printf("Masukkan Urut yang diinginkan : ");
	scanf("%d",&N);
	//Kondisi jika di masukkan nilai 1&2 akan menghasilkan 1, selain itu maka nilai low+high
	if (N==1 || N==2){
		hasil = 1;
	}else{
		//Perulangan untuk menghitung Fibonacci
		for(i=1;i<N;i++){
			hasil = low+high;
			low = high;
			high = hasil;
		}
	}
	//Menampilkan hasil perhitungan Fibonacci
	printf("Urutan tersebut bernilai : %d",hasil);
}
