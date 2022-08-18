#include <stdio.h>
#include <math.h>

int main (){
	int i,N;
	int hasil = 1;
	//Beri masukkan bilangan bulat
	printf("Masukkan Faktorial : ");
	scanf("%d",&N);
	//Kondisi jika N=0 dan N>0
	if (N==0){
		hasil = 1;
		}else{
		//Perulangan untuk menghitung faktorial (contoh 3! = 3x2x1)
		/*for (i=N; i>=1; i--){
			hasil = hasil * i;
		}*/
		//Perulangan untuk menghitung faktorial (contoh 3! = 1x2x3)
		for (i=1; i<=N; i++){
			hasil = hasil * i;
		}
	}
	//Menampilkan hasil pemfaktoran
	printf("Hasil faktorial : %d",hasil);
}
