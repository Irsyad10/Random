/************************************************
	* Project Title	: Mesin Gambar Sederhana
	* Date			: 20 Desember 2020
	* Author	: 3411201032 Irsyad Shofwan Fauzi
				  3411201034 Agung Prasetyo
				  3411201053 Hibatullah Muzaffar M A
*************************************************/

#include <stdio.h>	
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define NMAX 3248



#ifndef boolean.h
#define boolean.h
#define true 1
#define false 0
#define boolean unsigned char
#endif

//-------------------------------------------------
struct coor {
	int x;
	int y;
};

coor t;
coor saved[NMAX];
int jumKoorSaved;
int jumgambar = 0;

void gotoxy(int x, int y);
void frame();
	/*
		f.s : menampilkan frame 
	*/
void box(int x1, int x2, int y1, int y2);
	/*
		i.s : x1, x2, y1, y2 terdefinisi sembarang
		f.s : menampilkan frame box
	*/
void currentfile();
	/*
		f.s : menampilkan lembar gambar
	*/
void erasexy(int hapusx, int hapusy, int i);
	/*
		i.s : menerima nilai hapusx dan hapusy sembarang
		f.s : menghapus titik koordinasi pada array saved[]
	*/
void clear(coor clearsaved[], int *jumsaved);
boolean backtomenu();
	/*
		mengirim status kembali ke menu
	*/
void clearcommand();
	/*
		f.s : membersihkan command pane
	*/
void clearSideBar();
	/*
		f.s : membersihkan side pane		
	*/
boolean cekArray();
	/*
		i.s : meneruma cekx, ceky sembarang
		f.s : memberikan
	*/
int getJumGambar();
	/*
		mengirim jumlah file yang tersimpan
	*/

void drawxy();
	/*
		f.s : menggambar 
	*/
	
void testing(int i);

//--------------------------------------------------

int main() {			
	char temp;
	int i,o;
	
	system("MODE 170,39");
	frame();
	jumgambar = getJumGambar();
	
	
	//mainmenu
		menu :	
		while (true) {
			//Menghapus gambar ketika masuk ke menu
				for(i = 3; i <= 30; i++) {
					for(o = 9; o<=119; o++) {
						gotoxy(o,i);printf(" ");
					}
					printf("\n");
				}
			gotoxy(125,9);printf("------------------------------");
			gotoxy(125,10);printf("Main Menu");
			gotoxy(125,11);printf("------------------------------");			
			gotoxy(125,12);printf("1. Mulai Gambar");
			gotoxy(125,13);printf("2. Exit");
			gotoxy(125,14);printf("------------------------------");
		
		
			while (temp != '1' && temp != '2' ) {
				clearcommand();
				gotoxy(10,34);scanf("%c", &temp);
			}
			
			switch(temp) {
				case '1' :
					currentfile();
					temp = NULL;
					goto menu;
					break;
				case '2' :
					//exit(0);
					goto exit;
					break;
			}
		}
		exit : ;
}

//--------------------------------------------------

//frame
void frame() {

	int i,o;

	//frame luar
	//	box(5,160,1,37);
		
	//header
		gotoxy(124, 3);printf("--- Mesin Gambar Sederhana --- ");
		gotoxy(124, 4);printf("\t     Dibuat Oleh:");
		gotoxy(124, 5);printf("[3411201032] Irsyad Shofwan Fauzi");
		gotoxy(124, 6);printf("[3411201034] Agung Prasetyo");
		gotoxy(124, 7);printf("[3411201053] Hibatullah Muzaffar M A");		

	
	//frame workpaper
		box(8,120,2,31);
	
		
	//frame command
		box(8,120,32,36);
		gotoxy(10,33);printf("Masukkan perintah:");
	
	//frame  side-pane
		box(122,157,8,36);
}

//Currentfile
//menampilkan lembar gambar user
void currentfile() {
	/*
		f.s : 
	*/
	char temp;
	int i,o,p,q;
	boolean mode;
	boolean draw; 
	boolean erase;
	boolean ketemu;
	boolean keluar;
	
	//membersihkan side bar
	clearSideBar();
	
	//membersihkan lembar gambar user
		for(i = 3; i <= 30; i++) {
			for(o = 9; o<=119; o++) {
				gotoxy(o,i);printf(" ");
			}
		}
	//membersihkan command line
		clearcommand();
		
	//koordinat awal
		mode = true;
		draw = true; 
		erase = false;
		//Print indikator gambar default
		gotoxy(135,12);printf("[ON]");
		//Print indikator hapus default
		gotoxy(135,13);printf("[OFF]");
		
		gotoxy(68,17);
		t.x = 68;
		t.y = 17;
		jumKoorSaved = 1;
			
			
	//gotoxy(10,34);
	while(true) {
		
		//sidebar
		gotoxy(125,9);printf("------------------------------");
		gotoxy(125,10);printf("Daftar Tools:");
		gotoxy(125,11);printf("------------------------------");
		gotoxy(125,12);printf("[W] Gambar");
		gotoxy(125,13);printf("[E] Hapus");
		gotoxy(125,14);printf("[C] Hapus Semua");
		gotoxy(125,15);printf("[B] Kembali ke Menu");
		gotoxy(125,16);printf("------------------------------");
		gotoxy(125,17);printf("Daftar Control:");
		gotoxy(125,18);printf("------------------------------");
		gotoxy(125,19);printf("[I] untuk Atas");
		gotoxy(125,20);printf("[J] untuk Kiri");
		gotoxy(125,21);printf("[K] untuk Bawah");
		gotoxy(125,22);printf("[L] untuk Kanan");
		gotoxy(125,23);printf("------------------------------");
		gotoxy(t.x,t.y);
		temp = getch();
		
		switch(temp) {
			
				//Mode gambar
				gotoxy(135,12);
				if (draw == true) printf("[ON]");
				else printf("[OFF]");
				//Mode hapus
				gotoxy(135,13);
				if (erase == true) printf("[ON]");
				else printf("[OFF]");
				break;
			
			//atas
			case 'i' :
				if (t.y > 3) {
					t.y--;
					gotoxy(t.x, t.y);
					if (draw == true) {
						drawxy();
					}
					if (erase == true) {
						ketemu = cekArray();
						if (ketemu == true) {
							erasexy(t.x, t.y, jumKoorSaved);	
							jumKoorSaved--;
						}
					}
				}
				break;
			
			//bawah
			case 'k' :
				if (t.y < 30) {
					t.y++;
					gotoxy(t.x, t.y);
					if (draw == true) {
						drawxy();
					}
					if (erase == true) {
						ketemu = cekArray();
						if (ketemu == true) {
							erasexy(t.x,t.y, jumKoorSaved);	
							jumKoorSaved--;
						}
					}
				}
				break;
			
			//kiri
			case 'j' :
				if (t.x > 9) {
					t.x--;
					gotoxy(t.x, t.y);
					if (draw == true) {
						drawxy();
					}
					if (erase == true) {
						ketemu = cekArray();
						if (ketemu == true) {
							erasexy(t.x, t.y, jumKoorSaved);	
							jumKoorSaved--;
						}											
					}
				}
				break;
			
			//kanan
			case 'l' :
				if(t.x < 119) {
					t.x++;
					gotoxy(t.x, t.y);
					if (draw == true) {
						drawxy();
					}
					if (erase == true) {
						ketemu = cekArray();
						if (ketemu == true) {
							erasexy(t.x,t.y,jumKoorSaved);	
							jumKoorSaved--;
						}
					}
				}
				break;
				
			//serong kiri atas	
			case 'a' :
				if(t.x > 9 && t.y > 3 ) {
					t.x--;
					t.y--;
					gotoxy(t.x, t.y);
					if (draw == true){
						drawxy();
					}
					if (erase == true) {
						ketemu = cekArray();
						if (ketemu == true) {
							erasexy(t.x,t.y,jumKoorSaved);	
							jumKoorSaved--;
						}
					}
				}
				break;
			//indikator gambar [on/off]
			case 'w' :
				if (draw == true ) {
					draw = false;
					gotoxy(135,12);printf("[OFF]");
				}
				else {
					draw = true;
					erase = false;
					gotoxy(135,12);printf("[ON] ");
					gotoxy(135,13);printf("[OFF]");
				}
				break;
			
			//Indikator hapus [on/off]
			case 'e' :
				if (erase == true) {
					erase = false;
					gotoxy(135,13);printf("[OFF]");
				}
				else {
					erase = true;
					draw = false;
					gotoxy(135,13);printf("[ON] ");
					gotoxy(135,12);printf("[OFF]");
				}
				break;
				
			//mode hapus semua
			case 'c' :
				clear(saved, &jumKoorSaved);
				break;
			
			//Kembali ke menu
			case 'b' :
				keluar = backtomenu();
				if (keluar) {
					goto backmenu;
				}
				break;
		}		
	}

	backmenu: 
	gotoxy(10,34);
}

//Output gambar
void drawxy() {
	printf("*");
	saved[jumKoorSaved].x = t.x;
	saved[jumKoorSaved].y = t.y;
	jumKoorSaved++;
}


//periksa ada saved
boolean cekArray() {
	int o,p,q;
	boolean ketemu;
	
	ketemu = false;
	
	//periksa
	while(o <= jumKoorSaved && !ketemu) {
		if (t.x == saved[o].x && t.y == saved[o].y) {
			ketemu = true;
		}
		else {
			o++;	
		}
	}
	
	if (ketemu == true) {
		return true;
	}
	else {
		return false;
	}
}

//Mode hapus
void erasexy(int hapusx, int hapusy, int i) {
	
	int o,p,q;
	boolean ketemu;
	
	printf(" ");
	o = 0;	
	ketemu = false;
	while (o <= i && !ketemu) {
		//ketemu
		if (saved[o].x == hapusx && saved[o].y == hapusy) {
			saved[o].x = NULL;
			saved[o].y = NULL;
			
			ketemu = true;
			q = i; 
			//geser
			for (p = o; p <= i; p++) {
				saved[p].x = saved[p+1].x;
				saved[p].y = saved[p+1].y;
			}
			i--;
		}
		//belum ketemu
		else {
			o++;
		}
	} 
}

//mode hapus semua
void clear(coor clearsaved[], int *jumsaved) {
	/*
		i.e :
		f.s : membersihkan lembar kerja
	*/
	int i, o;
	
	//membersihkan lembar kerja
	for(i = 3; i <= 30; i++) {
		for(o = 9; o<=119; o++) {
			gotoxy(o,i);printf(" ");
		}
	}
	
	gotoxy(68,17);
	t.x = 68;
	t.y = 17;
	i = 1;
}

//back to menu
boolean backtomenu() {
	/*
		f.s : mengembalikan ke mainmenu setelah memberikan konfirmasi penyimpanan array
	*/
	int m,o,i,e;
	boolean keluar;
	
	gotoxy(125,24);printf("Kamu yakin ingin keluar?");
	gotoxy(125,25);printf("------------------------------");
	gotoxy(125,26);printf("1. Ya");
	gotoxy(125,27);printf("2. Tidak");
	gotoxy(125,28);printf("------------------------------");	
	
	gotoxy(10,34);scanf("%d", &m);
	
	switch(m) {
		case 1 :
			for(o = 0; o <= jumKoorSaved; o++) {
				saved[o].x = NULL;
				saved[o].y = NULL;
			}
			//membersihkan side pane
			clearSideBar();
			
			//membersihkan command
			clearcommand();
			keluar = true;
			break;
			
		case 2 : 
			//membersihkan side pane
			for (i = 24; i <= 28; i++) {
				for (o = 125; o < 157; o++) {
					gotoxy(o,i);printf(" ");
				}
			}
			
			//membersihkan command
			clearcommand();
			keluar = false;
			break;
	}
	
	return keluar;
}

//countjumgambar
int getJumGambar() {
	int jumgbr = 1;
	boolean akhir = false;
	char buffer[32];
	
	FILE *file;
	
	while (!akhir) {
		snprintf(buffer, sizeof(char) * 32, "gambar %i.txt", jumgbr);
		file = fopen(buffer,"r");
		if( file !=NULL) {
			 // file exists
	        jumgbr++;
	        fclose(file);
		}   
	    else {
	    	akhir = true;
		}
	}
	
	return jumgbr-1;
}

//clear command
void clearcommand() {
	/*
		f.s : membersihkan command bar
	*/
	int i;
	
	for (i = 10; i <=35; i++ ) {
		gotoxy(i,34);printf(" ");
	}
}

//clear side pane
void clearSideBar() {
	/*
		f.s : membersihkan command bar
	*/
	
	int i, o;
	
	for (i = 9; i < 36; i++) {
		for (o = 123; o < 157; o++) {
			gotoxy(o,i);printf(" ");
		}
	}
}


//testing-------------------------
void testing(int i) {
	int o;
	
	for(o = 1; o<i; o++) {
		gotoxy(saved[o].x, saved[o].y);
		printf("0");
	}
}

//box
void box(int x1, int x2, int y1, int y2){
	/*
		i.e : memasukan x1, x2,y1,y2 sembarang 
		f.s : membuat frame bujur sangkar 
	*/
	int i;
	
	for(i = x1; i <= x2; i++) {
		gotoxy(i, y1);printf("%c", 205);
		gotoxy(i, y2);printf("%c", 205);
	}
	
	for (i = y1; i <= y2; i++) {
		gotoxy(x1, i);printf("%c", 186);
		gotoxy(x2, i);printf("%c", 186);
	}

	//edges
		gotoxy(x1,y1);printf("%c",201);
		gotoxy(x1,y2);printf("%c",200);
		gotoxy(x2,y1);printf("%c",187);
		gotoxy(x2,y2);printf("%c",188);
}
	
//gotoxy
void gotoxy(int x, int y) {
	HANDLE handle;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}
