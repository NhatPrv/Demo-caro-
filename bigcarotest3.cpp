#include <winbgim.h> 
#include <iostream>
#include <string.h>

using namespace std;

void banco()  {
	for (int i=0;i<=3;i++)  {
		setcolor(0);
		rectangle(97+i,97+i,603-i,603-i);
	}
	for (int i=100;i<=580;i=i+20) {
		for (int j=100;j<=580;j=j+20) {
			rectangle(j,i,j+20,i+20);
		}
	}
}

void dauX(int x,int y, int color) {
	setcolor(color);
	
	x=20*(x/20)+3;
	y=20*(y/20)+3;
	
	line(x+1,y,x+14,y+13);
	line(x,y,x+14,y+14);
	line(x,y+1,x+13,y+14);	
	
	line (x+13,y,x,y+13);
	line (x+14,y,x,y+14);
	line (x+14,y+1,x+1,y+14);
}

void dauO(int x, int y, int color )  {

	setcolor(color);

	x=20*(x/20)+10;
	y=20*(y/20)+10;
	
	circle(x,y,6);
	circle(x,y,5);
	circle(x,y,7);
}

void play()  {
	int count_trung = 0;
	int f_x_win;
	int f_y_win;
	int Atd[25][25];
	for (int a=0;a<25;a++)  {
		for (int b=0;b<25;b++)
		{
			Atd[a][b]=0;
		}
	}
	cout << "  MOI   ";
	int x,y;
	int count_click = 0;
	bool is_win = false;
	while (1)  {   delay(0.0001);
		if (is_win==false) {
			if (ismouseclick(WM_LBUTTONUP)){   
			   	getmouseclick(WM_LBUTTONUP,x, y);			
				cout << x << ":" << y << "\t";
	   			if(x<=100  ||  x>=600  ||  y<=100  ||  x>=600  || x%20==0  || y%20==0)
	   			{
				}
				else {
					if (Atd[x/20-5][y/20-5]==0) {// xac dinh coi o do da duoc danh hay chua
						if(count_click < 625) {    
							if(count_click %2==0)  {
								Atd[x/20-5][y/20-5]=2;
								dauX(x,y,1);
							}
							else {
								Atd[x/20-5][y/20-5]=1;
								dauO(x,y,4); 
							}
							count_click++;
							int f_x_win;
							int f_y_win;
							int tdx = x/20-5;
							int tdy = y/20-5;
							int check_number = (count_click %2==0) ? 2 : 1;
							// kiem tra doc
							count_trung = 0;
							for (int i=0;i<20;i++) {
								count_trung = 0;
								int i_check=i;
								for (int j=i_check;j<i_check+5;j++)
								{
									if(Atd[tdx][j]==check_number) {
										if (count_trung==1)
										{
											int f_x_win=tdx;
											int f_y_win=j;
										}
										count_trung ++;
										cout << count_trung;
										delay(1);
									}
								}
								if (count_trung==5) {
									break;
								}
							}
							
							cout << count_trung;
							
							if(count_trung == 5 ) {
								is_win = true;
								for (int i=f_y_win;i<3;i++) {
									if (check_number==2) {
										dauX((tdx+5)*20+1,(i+5)*20+1,15);
										cout << "Dau moi 2  ";
									}
									else{
										dauO((tdx+5)*20+1,(i+5)*20+1,15);
										cout << "Dau moi 3   ";
									}
								}
							}
							
						}
						else {
							cout << "Game over ! Noone win...";
						}
					}
				}
			}
		}
	}
}

											

int main(int argc, char *argv[]){
	// now, you can run project

	initwindow(700,700);			// init window graphics
	setbkcolor(7);					// set background
	cleardevice();
   	
	banco();
	play();
	
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}







/*
 
	while (1) { // Luu ý câu while này nhé ! tuc la chuong trinh cua chu dang lap di lap lai 1 vong lap => nhung bien nao duoc khai bao trong vong while nay se bi khai bao lai. dan den viec khong the luu tru bien duoc
		delay(0.0001);
		
							
							// kiem tra tu diem x,y co ton tai 1 truong hop win nao khong
							// kiem tra cheo trai
							for (i=0;i<3;i++) {
								if(Atd[i][i]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
							}
							// kiem tra cheo phai
							count_trung = 0;
							for (i=0;i<3;i++) {
								if(Atd[2-i][i]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
							}		
							// kiem tra ngang
							count_trung = 0;
							for (i=0;i<3;i++) {
								if(Atd[tdy][i]==check_number) {
									count_trung ++;
								}
							}
							if(count_trung == 3 ) {
								is_win = true;
							}
							
							count_click ++;
							
							
							if(is_win == true) {
								obj_win = check_number == 2 ? 'X' : 'O';
								string msg="Chuc mung " + obj_win + " da chien thang ! ";
								char p[msg.length()];
								for (i=0;i<msg.length();i++) {
									p[i]=msg[i];
								}
								
								cout << p;
								
								setcolor(0);
								int w=8*msg.length();
								outtextxy(250-w/2,425,p);
							}
						} else {
						cout <<"Con o nua dau ma danh";
						if (kbhit){
							break;
						}
						}	
					}
				}
			}
		}	
	//}
	}
	
    system("pause");
    closegraph();
} 

*/ 

