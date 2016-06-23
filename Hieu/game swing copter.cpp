#include <iostream>
#include <string.h>
#include <windows.h>
#include <ctime>
using namespace std;
//Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width,int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect (console,&r);
	MoveWindow(console,r.left,r.top,width,height,TRUE);
}
//Hàm tô màu chữ.
void textcolor(int x){
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//Hàm dịch chuyển con trỏ đến tọa độ x,y.
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
//Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
char Map[41][41];
void TaoDuongBay()
{
	for(int i=0;i<41;i++){	
		Map[i][0] = 'T'; 
		Map[i][40] = 'T';
	}
}
void TaoVatCan_1(int &x,int &y)
{
	Map[x][y+1]='=';
	Map[x][y+2]='=';
	Map[x][y+3]='=';
	Map[x][y+4]='=';
	Map[x][y+5]='=';
	Map[x][y+6]='=';
	Map[x][y+7]='=';
	Map[x][y+8]='=';
	Map[x][y+9]='=';
	Map[x][y+10]='=';
	Map[x][y+11]='=';
	Map[x][y+12]='|';
	Map[x][y+13]='|';
	Map[x+1][y+1]='=';
	Map[x+1][y+2]='=';
	Map[x+1][y+3]='=';
	Map[x+1][y+4]='=';
	Map[x+1][y+5]='=';
	Map[x+1][y+6]='=';
	Map[x+1][y+7]='=';
	Map[x+1][y+8]='=';
	Map[x+1][y+9]='=';
	Map[x+1][y+10]='=';
	Map[x+1][y+11]='=';
	Map[x+1][y+12]='|';
	Map[x+1][y+13]='|';

}
void TaoLucLac_1_1(int &x,int &y)//tạo lúc lăc bên trái màn hình ứng với vật cản 1.
{
	Map[x+2][y+13]='I';
	Map[x+3][y+13]='#';
	
}
void TaoLucLac_1_2(int &x,int &y)//tạo lúc lăc bên trái màn hình ứng với vật cản 1.
{
	
	Map[x+2][y+12]='/';
	Map[x+3][y+12]='#';
}
void XoaLucLac_1(int &x,int &y) //xóa lúc lắc vật cản 1.
{
	Map[x+2][y+13]=' ';
	Map[x+3][y+13]=' ';
	Map[x+2][y+12]=' ';
	Map[x+3][y+12]=' ';
}
void TaoVatCan_2(int &x,int &y)
{
	Map[x][y+1]='=';
	Map[x][y+2]='=';
	Map[x][y+3]='=';
	Map[x][y+4]='=';
	Map[x][y+5]='=';
	Map[x][y+6]='=';
	Map[x][y+7]='=';
	Map[x][y+8]='=';
	Map[x][y+9]='=';
	Map[x][y+10]='=';
	Map[x][y+11]='|';
	Map[x][y+12]='|';
	Map[x+1][y+1]='=';
	Map[x+1][y+2]='=';
	Map[x+1][y+3]='=';
	Map[x+1][y+4]='=';
	Map[x+1][y+5]='=';
	Map[x+1][y+6]='=';
	Map[x+1][y+7]='=';
	Map[x+1][y+8]='=';
	Map[x+1][y+9]='=';
	Map[x+1][y+10]='=';
	Map[x+1][y+11]='|';
	Map[x+1][y+12]='|';
}
void TaoLucLac_2_1(int &x,int &y)
{
	Map[x+2][y+11]='/';
	Map[x+3][y+11]='#';
}
void TaoLucLac_2_2(int &x,int &y)
{
	Map[x+2][y+12]='I';
	Map[x+3][y+12]='#';
}
void XoaLucLac_2(int &x,int &y)
{
	Map[x+2][y+11]=' ';
	Map[x+3][y+11]=' ';
	Map[x+2][y+12]=' ';
	Map[x+3][y+12]=' ';
}
void TaoVatCan_3(int &x,int &y)
{
	Map[x][y+1]='|';
	Map[x][y+2]='|';
	Map[x][y+3]='=';
	Map[x][y+4]='=';
	Map[x][y+5]='=';
	Map[x][y+6]='=';
	Map[x][y+7]='=';
	Map[x][y+8]='=';
	Map[x][y+9]='=';
	Map[x][y+10]='=';
	Map[x][y+11]='=';
	Map[x][y+12]='=';
	Map[x][y+13]='=';
	Map[x+1][y+1]='|';
	Map[x+1][y+2]='|';
	Map[x+1][y+3]='=';
	Map[x+1][y+4]='=';
	Map[x+1][y+5]='=';
	Map[x+1][y+6]='=';
	Map[x+1][y+7]='=';
	Map[x+1][y+8]='=';
	Map[x+1][y+9]='=';
	Map[x+1][y+10]='=';
	Map[x+1][y+11]='=';
	Map[x+1][y+12]='=';
	Map[x+1][y+13]='=';
}
void TaoLucLac_3_1(int &x,int &y)//tạo lúc lăc bên pải màn hình ứng với vật cản 3.
{
	Map[x+2][y+2]='I';
	Map[x+3][y+2]='#';

}
void TaoLucLac_3_2(int &x,int &y)//tạo lúc lăc bên pải màn hình ứng với vật cản 3.
{
	Map[x+2][y+1]='/';
	Map[x+3][y+1]='#';
}
void XoaLucLac_3(int &x,int &y)//xoa lúc lắc ở vật cản 3.
{
	Map[x+2][y+1]=' ';
	Map[x+3][y+1]=' ';
	Map[x+2][y+2]=' ';
	Map[x+3][y+2]=' ';
}
void TaoVatCan_4(int &x,int &y)
{
	Map[x][y+1]='|';
	Map[x][y+2]='|';
	Map[x][y+3]='=';
	Map[x][y+4]='=';
	Map[x][y+5]='=';
	Map[x][y+6]='=';
	Map[x][y+7]='=';
	Map[x][y+8]='=';
	Map[x][y+9]='=';
	Map[x][y+10]='=';
	Map[x][y+11]='=';
	Map[x][y+12]='=';
	Map[x+1][y+1]='|';
	Map[x+1][y+2]='|';
	Map[x+1][y+3]='=';
	Map[x+1][y+4]='=';
	Map[x+1][y+5]='=';
	Map[x+1][y+6]='=';
	Map[x+1][y+7]='=';
	Map[x+1][y+8]='=';
	Map[x+1][y+9]='=';
	Map[x+1][y+10]='=';
	Map[x+1][y+11]='=';
	Map[x+1][y+12]='=';
}
void TaoLucLac_4_1(int &x,int &y)
{
	Map[x+2][y+1]='/';
	Map[x+3][y+1]='#';
}
void TaoLucLac_4_2(int &x,int &y)
{
	Map[x+2][y+2]='I';
	Map[x+3][y+2]='#';
}
void Tao_Vat_Can_5(int &x, int &y, int &n)
{
	for(int i=2;i<n;i++){
	    Map[x][y+i-1]='=';
		Map[x+1][y+i-1]='=';
	}
	Map[x][n-2]='|'; 
	Map[x][n-1]='|';
	Map[x+1][n-2]='|';
	Map[x+1][n-1]='|';
}
void TaoLucLac_5_1(int &x,int &y, int &n)
{
	Map[x+2][n-2]='/';
	Map[x+3][n-2]='#';
}
void TaoLucLac_5_2(int &x,int &y, int &n)
{
	Map[x+2][n-1]='I';
	Map[x+3][n-1]='#';
}
void XoaLucLac_5(int &x,int &y, int	&n)
{
	Map[x+2][n-1]=' ';
	Map[x+3][n-1]=' ';
	Map[x+2][n-2]=' ';
	Map[x+3][n-2]=' ';
}
void Tao_Vat_Can_6(int &x, int &y, int &n)
{
	for(int i=2;i<n;i++){
	    Map[x][y-i+1]='=';
		Map[x+1][y-i+1]='=';
	}
	Map[x][y-n]='|'; 
	Map[x][y-n+1]='|';
	Map[x+1][y-n]='|';
	Map[x+1][y-n+1]='|';
}
void TaoLucLac_6_1(int &x,int &y, int &n)
{
	Map[x+2][y-n+1]='I';
	Map[x+3][y-n+1]='#';
}
void TaoLucLac_6_2(int &x,int &y, int &n)
{
	Map[x+2][y-n]='/';
	Map[x+3][y-n]='#';
}
void XoaLucLac_6(int &x,int &y, int	&n)
{
	Map[x+2][y-n+1]=' ';
	Map[x+3][y-n+1]=' ';
	Map[x+2][y-n]=' ';
	Map[x+3][y-n]=' ';
}
void XoaVatCan_6(int &x, int &y, int &n)
{
	for(int i=2;i<n;i++){
	    Map[x][y-i+1]=' ';
		Map[x+1][y-i+1]=' ';
	}
	Map[x][y-n]=' '; 
	Map[x][y-n+1]=' ';
	Map[x+1][y-n]=' ';
	Map[x+1][y-n+1]=' ';
}
void XoaVatCan_5(int &x, int &y, int &n)
{
	for(int i=2;i<n;i++){
	    Map[x][y+i-1]=' ';
		Map[x+1][y+i-1]=' ';
	}
	Map[x][n-2]=' ';
	Map[x][n-1]=' ';
	Map[x+1][n-2]=' ';
	Map[x+1][n-1]=' ';
}
void XoaLucLac_4(int &x,int &y)
{
	Map[x+2][y+1]=' ';
	Map[x+3][y+1]=' ';
	Map[x+2][y+2]=' ';
	Map[x+3][y+2]=' ';
}
void XoaVatCan_1(int &x,int &y)
{
	Map[x][y+1]=' ';
	Map[x][y+2]=' ';
	Map[x][y+3]=' ';
	Map[x][y+4]=' ';
	Map[x][y+5]=' ';
	Map[x][y+6]=' ';
	Map[x][y+7]=' ';
	Map[x][y+8]=' ';
	Map[x][y+9]=' ';
	Map[x][y+10]=' ';
	Map[x][y+11]=' ';
	Map[x][y+12]=' ';
	Map[x][y+13]=' ';
	Map[x+1][y+1]=' ';
	Map[x+1][y+2]=' ';
	Map[x+1][y+3]=' ';
	Map[x+1][y+4]=' ';
	Map[x+1][y+5]=' ';
	Map[x+1][y+6]=' ';
	Map[x+1][y+7]=' ';
	Map[x+1][y+8]=' ';
	Map[x+1][y+9]=' ';
	Map[x+1][y+10]=' ';
	Map[x+1][y+11]=' ';
	Map[x+1][y+12]=' ';
	Map[x+1][y+13]=' ';
}
void XoaVatCan_2(int &x,int &y)
{
	Map[x][y+1]=' ';
	Map[x][y+2]=' ';
	Map[x][y+3]=' ';
	Map[x][y+4]=' ';
	Map[x][y+5]=' ';
	Map[x][y+6]=' ';
	Map[x][y+7]=' ';
	Map[x][y+8]=' ';
	Map[x][y+9]=' ';
	Map[x][y+10]=' ';
	Map[x][y+11]=' ';
	Map[x][y+12]=' ';
	Map[x+1][y+1]=' ';
	Map[x+1][y+2]=' ';
	Map[x+1][y+3]=' ';
	Map[x+1][y+4]=' ';
	Map[x+1][y+5]=' ';
	Map[x+1][y+6]=' ';
	Map[x+1][y+7]=' ';
	Map[x+1][y+8]=' ';
	Map[x+1][y+9]=' ';
	Map[x+1][y+10]=' ';
	Map[x+1][y+11]=' ';
	Map[x+1][y+12]=' ';
}
void XoaVatCan_3(int &x,int &y)
{
	Map[x][y+1]=' ';
	Map[x][y+2]=' ';
	Map[x][y+3]=' ';
	Map[x][y+4]=' ';
	Map[x][y+5]=' ';
	Map[x][y+6]=' ';
	Map[x][y+7]=' ';
	Map[x][y+8]=' ';
	Map[x][y+9]=' ';
	Map[x][y+10]=' ';
	Map[x][y+11]=' ';
	Map[x][y+12]=' ';
	Map[x][y+13]=' ';
	Map[x+1][y+1]=' ';
	Map[x+1][y+2]=' ';
	Map[x+1][y+3]=' ';
	Map[x+1][y+4]=' ';
	Map[x+1][y+5]=' ';
	Map[x+1][y+6]=' ';
	Map[x+1][y+7]=' ';
	Map[x+1][y+8]=' ';
	Map[x+1][y+9]=' ';
	Map[x+1][y+10]=' ';
	Map[x+1][y+11]=' ';
	Map[x+1][y+12]=' ';
	Map[x+1][y+13]=' ';
}
void XoaVatCan_4(int &x,int &y)
{
	Map[x][y+1]=' ';
	Map[x][y+2]=' ';
	Map[x][y+3]=' ';
	Map[x][y+4]=' ';
	Map[x][y+5]=' ';
	Map[x][y+6]=' ';
	Map[x][y+7]=' ';
	Map[x][y+8]=' ';
	Map[x][y+9]=' ';
	Map[x][y+10]=' ';
	Map[x][y+11]=' ';
	Map[x][y+12]=' ';
	Map[x+1][y+1]=' ';
	Map[x+1][y+2]=' ';
	Map[x+1][y+3]=' ';
	Map[x+1][y+4]=' ';
	Map[x+1][y+5]=' ';
	Map[x+1][y+6]=' ';
	Map[x+1][y+7]=' ';
	Map[x+1][y+8]=' ';
	Map[x+1][y+9]=' ';
	Map[x+1][y+10]=' ';
	Map[x+1][y+11]=' ';
	Map[x+1][y+12]=' ';
}
void InDuongBay()//in đường bay, vật cản, máy bay...ra màn hình
{
	for(int i=0;i<25;i++){
		textcolor(85);//tạo lề cách khung 2 khoảng trống có màu tím ở bên trái .
		cout<<"      ";
		for(int j=0;j<41;j++){//In vạch ngăn cách 2 bên đường.
			if(j==0||j==40){
				textcolor(185);
				cout<<Map[i][j];
				textcolor(7);
			}else{
					//In máy bay.
					if(Map[i][j] =='^'){
						textcolor(15);
						cout<<Map[i][j];
						textcolor(7);
					}else{
						if(Map[i][j] =='@'){
							textcolor(47);
							cout<<Map[i][j];
							textcolor(7);
						}else{
							if(Map[i][j] =='-'||Map[i][j] ==':'){
								textcolor(15);
								cout<<Map[i][j];
								textcolor(7);
							}else{//in vật cản, lúc lắc.
								if(Map[i][j]=='='||Map[i][j]=='|'){
									textcolor(169);
									cout<<Map[i][j];
									textcolor(7);
								}else{
									if(Map[i][j]=='/'||Map[i][j]=='#'||Map[i][j]=='I'){
										textcolor(15);
										cout<<Map[i][j];
										textcolor(7);
								}else{
									cout<<Map[i][j];
								}
							}
						}
					}
				}
			}
		}
		cout<<endl;
	}
}
void TaoMayBay_1(int &x,int &y)
{
	Map[x][y] = '@';
	Map[x-1][y-1] = '-';
	Map[x-1][y+1] = '-';
	Map[x-1][y] = ':';
	Map[x+1][y-1] = '^';
	Map[x+1][y] = '^';

}
void TaoMayBay_2(int &x,int &y)
{
	Map[x][y] = '@';
	Map[x-1][y-2] = '-';
	Map[x-1][y+2] = '-';
	Map[x-1][y] = ':';
	Map[x+1][y+1] = '^';
	Map[x+1][y] = '^';

}
void XoaMayBay_1(int &x,int &y)
{
	Map[x][y] = ' ';
	Map[x-1][y-1] = ' ';
	Map[x-1][y+1] = ' ';
	Map[x-1][y] = ' ';
	Map[x+1][y-1] = ' ';
	Map[x+1][y] = ' ';

}
void XoaMayBay_2(int &x,int &y)
{
	Map[x][y] = ' ';
	Map[x-1][y-2] = ' ';
	Map[x-1][y+2] = ' ';
	Map[x-1][y] = ' ';
	Map[x+1][y+1] = ' ';
	Map[x+1][y] = ' ';

}
void Hinh_Nen()
{
	textcolor(95);
	gotoxy(0,0);
	cout<<" -----------Dai Hoc Thuy Loi------------ \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	cout<<"   -----Khoa Cong nghe thong tin--- \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	textcolor(94);
	cout<<"      -----------------------------------------                                    ";
	cout<<"  | @@@@@@@@@                               |                                  ";
	cout<<"  | @@@                    @@                |                                 ";
	cout<<"  | @@@                                       | =============================  ";
	cout<<"  | @@@@@@@@@ @@        @@ @@ @@@   @@ @@@@@@@@|                               ";
	cout<<"  |       @@@  @@       @@ @@ @@@@  @@ @@       |                              ";
	cout<<"  |       @@@   @@  @@ @@  @@ @@ @@ @@ @@  @@@@ |                              ";
	cout<<"   |@@@@@@@@@    @@@@ @@@  @@ @@  @@@@ @@    @@ |                               ";
	cout<<"   |@@@@@@@@     @@   @@  @@ @@   @@@ @@@@@@@@ |                                ";
	cout<<"   --------------------------------------------                                 ";
	cout<<"                                                                                ";
	cout<<"        -----------------------------------------                                 ";
	cout<<"     | @@@@@@@@                                |                               ";
	cout<<"     | @@                                       |                              ";
	cout<<"     | @@       @@@@@@ @@@@@@ @@@@@@ @@@@@ @@@@@ |                             ";
	cout<<"     | @@       @@  @@ @@  @@   @@   @@    @@  @@ |                            ";
	cout<<"     | @@       @@  @@ @@@@@@   @@   @@@@  @@@@@@ |                            ";
	cout<<"      |@@       @@  @@ @@       @@   @@    @@ @@  |                            ";
	cout<<"       |@@@@@@@ @@@@@@ @@       @@   @@@@@ @@  @@ |                            ";
	cout<<"         ------------------------------------------                                        ";
	gotoxy(1,25);
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	gotoxy(59,3);
	textcolor(27);
	cout<<"                \n"; 
	gotoxy(59,4);
	cout<<"      Menu      \n";
	gotoxy(59,5);
	cout<<"                \n";
	textcolor(27);
	gotoxy(51,10);
	cout<<" Enter: Bat dau (vao game).\n";
	gotoxy(51,15);
	cout<<" Space: Bat dau di chuyen. \n";
	gotoxy(51,20);
	cout<<" Esc: Thoat khoi game.     \n";
	gotoxy(51,25);
	cout<<" Tam dung: phim Tab.       \n";
	gotoxy(61,28);
	textcolor(91);
	cout<<"\3Verson: @ Hieu_koy ";
	textcolor(91);
	gotoxy(4,27);
	cout<<"     ======>I Love Programming Game<========\n\n";
	cout<<"\t\t\t\t\t\t\t     \n";
}
void Tao_Diem(int &c,int &x,int &y)
{
	c++;
	textcolor(27);
	if(Map[x-1][y-2]=='$'||Map[x-1][y+2]=='$'||Map[x-1][y+2]=='$'||Map[x-1][y-2]=='$'||Map[x-1][y-1]=='$'||Map[x-1][y+1]=='$'||Map[x-1][y]=='$'){
		c+=100;
		gotoxy(58,2);
		cout<<"+100";
	}
	if(Map[x-1][y+2]=='\3'||Map[x-1][y-2]=='\3'||Map[x-1][y-2]=='\3'||Map[x-1][y+2]=='\3'||Map[x-1][y-1]=='\3'||Map[x-1][y+1]=='\3'||Map[x-1][y]=='\3'){
		c+=200;
		gotoxy(58,2);
		cout<<"+200";
	}
	textcolor(91);
	gotoxy(49,2);
	cout<<"Diem: ";
	textcolor(95);
	cout<<c;//Tạo điểm.
	if(c%20==0){//xóa điểm + khi ăn tiền, tim
	gotoxy(58,2);
	textcolor(90);
	cout<<"    ";
	}
}
void Tao_Lever(int &L,int &c)
{
	if(c%15==0){
		L++;
	}
	textcolor(91);
	gotoxy(49,4);
	cout<<"Lever: ";
	textcolor(95);
	cout<<L;
	gotoxy(49,6);
	if(L<4){
		textcolor(91);
	    cout<<"Muc do:";
		textcolor(95);
		cout<<" De";
	}
	if(L>=4&&L<10){
		textcolor(91);
		cout<<"Muc do:";
		textcolor(95);
		cout<<" Trung binh";
	}
	if(L>=10){
		textcolor(91);
		cout<<"Muc do:";
	    textcolor(95);
		cout<<" Kho       ";
	}
}
void Tao_Luot_Choi()
{
	char A[]={'\3','\0'};
	gotoxy(68,7);
	textcolor(91);
	cout<<"Luot Choi: ";
	for(int i=0;i<1;i++){
		textcolor(92);
		cout<<A;
	}
}
void Ktra(int &x, int &y)
{
	if(x<=y+3){
		y-=2;
	}
}
void Tao_Tien(int &x, int &y,int &i)
{
	textcolor(79);
	Map[x][y]='$';
	Map[x+3][y+i]='\3';
}
void Xoa_Tien(int &x, int &y,int &i)
{
	Map[x][y]=' ';
	Map[x+3][y+i]=' ';
}
int main()
{
	char tl=' ';
	int k=0;
	resizeConsole(800,400);
	textcolor(92);
	gotoxy(1,1);
	Hinh_Nen();
	int a=0,b=0,c=0,d=0,L=0;
	int x1=11,y1=0,x2=1,y2=0,x3=11,y3=26,x4=1,y4=27,x5=1,y5=0,x6=1,y6=40,x7=11,y7=0,x8=11,y8=40,x9=0,y9=10,i=6;
	int n1=20,n2=8,n3=8,n4=20;
	TaoDuongBay();
	do
	{
		int y=20;
		char f=' ';
		while(a==0){
			if(GetAsyncKeyState(VK_RETURN)){
				a++;
				int x=20;
				while(true){
					Sleep(20);
					b++;
					if(7<a&&a<16){
					    y++;//cho may bay chạy sau khi bắt đầu.
					}
					if(b%2==0){//lấy số chia hết cho 2 và không chia hết cho 2 để tạo sự chuyển động lúc lăc,máy bay.
						TaoMayBay_1(x,y);
						if(L<4){
							Sleep(35);
							TaoLucLac_1_1(x1,y1);//tạo lúc lăc bên trái ứng với vật cản 1.
						    TaoLucLac_3_1(x3,y3);//tạo lúc lăc bên pải ứng với vật cản 3.
						}
						if(L>=4&&L<10){
							Sleep(12);
							TaoLucLac_1_1(x1,y1);//tạo lúc lăc bên trái ứng với vật cản 1.
						    TaoLucLac_3_1(x3,y3);//tạo lúc lăc bên pải ứng với vật cản 3.
							TaoLucLac_2_1(x2,y2);//tạo lúc lăc bên trái ứng với vật cản 2.
							TaoLucLac_4_1(x4,y4);//tạo lúc lăc bên pải ứng với vật cản 4.
						}
						if(L>=10){
							if(L==10){
								Sleep(20);
							}
							Sleep(10);
							TaoLucLac_5_1(x5,y5,n1);
							TaoLucLac_5_1(x7,y7,n4);
							TaoLucLac_6_1(x6,y6,n2);
							TaoLucLac_6_1(x8,y8,n3);
						}
					}else{
						TaoMayBay_2(x,y);
						if(L<4){
							Sleep(35);
							TaoLucLac_1_2(x1,y1);//tạo lúc lăc bên trái ứng với vật cản 1.
						    TaoLucLac_3_2(x3,y3);//tạo lúc lăc bên pải ứng với vật cản 3.
						}
						if(L>=4&&L<10){
							Sleep(12);
							TaoLucLac_1_2(x1,y1);//tạo lúc lăc bên trái ứng với vật cản 1.
						    TaoLucLac_3_2(x3,y3);//tạo lúc lăc bên pải ứng với vật cản 3.
							TaoLucLac_2_2(x2,y2);//tạo lúc lăc bên pải ứng với vật cản 2.
							TaoLucLac_4_2(x4,y4);//tạo lúc lăc bên trái ứng với vật cản 4.
						}
						if(L>=10){
							if(L==10){
								Sleep(20);
							}
							Sleep(10);
							TaoLucLac_5_2(x5,y5,n1);
							TaoLucLac_5_2(x7,y7,n4);
							TaoLucLac_6_2(x6,y6,n2);
							TaoLucLac_6_2(x8,y8,n3);
						}
					}
					Tao_Tien(x9,y9,i);
					if(L<4){//làm vật cản 2,4 xuất hiện sau.
						Sleep(35);
						TaoVatCan_1(x1,y1);//tạo vật cản bên trái (cặp 1-3)
						TaoVatCan_3(x3,y3);//tạo vật cản bên pải (cặp 1-3)
					}
					if(L>=4&&L<10){
						Sleep(12);
						TaoVatCan_1(x1,y1);//tạo vật cản bên trái (cặp 1-3)
						TaoVatCan_3(x3,y3);//tạo vật cản bên pải (cặp 1-3)
						TaoVatCan_2(x2,y2);//bên trái.
						TaoVatCan_4(x4,y4);
					}
					if(L>=10){
						if(L==10){
								Sleep(20);
							}
						Sleep(10);
						Tao_Vat_Can_6(x6,y6,n2);
						Tao_Vat_Can_5(x7,y7,n4);
						Tao_Vat_Can_6(x8,y8,n3);
						Tao_Vat_Can_5(x5,y5,n1);
					}
					InDuongBay();
					a++;
					if(tl==' '){
						Tao_Diem(c,x,y);
						Tao_Lever(L,c);
						Tao_Luot_Choi();
					}
					else{
						if(tl=='Y'||tl=='y'){
							Tao_Diem(c,x,y);
							Tao_Lever(L,c);
						}
					}
					XoaManHinh();
					if(Map[x-1][y-2]=='='||Map[x-1][y+2]=='|'||Map[x-1][y+2]=='='||Map[x-1][y-2]=='|'||Map[x-1][y-2]=='I'||Map[x-1][y+2]=='#'||Map[x-1][y+2]=='I'||Map[x-1][y-2]=='#'||Map[x-1][y-2]=='/'||Map[x-1][y+2]=='/'||Map[x-1][y-2]=='T'||Map[x-1][y+2]=='T'||Map[x-1][y-1]=='T'||Map[x-1][y+1]=='T'){
						cout<<"\a";//tạo tiếng beep.
						gotoxy(22,10);
						textcolor(15);
						cout<<"Game over.\n";
						gotoxy(10,12);
						textcolor(15);
						cout<<"  Ban co muon tiep tuc khong (Y/N) :";cin>>tl;
						cout<<"\n";
						cout<<"\n";
						cout<<"\n"; 
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						textcolor(15);//tô màu chữ Press any key to continue....
						cout<<"\n ";
						if(tl=='N'||tl=='n'){
							break;
						}
						if(tl=='Y'||tl=='y'){
							XoaMayBay_1(x,y);//xoa máy bay với giá trị của y cũ.
							XoaMayBay_2(x,y);//khởi tạo lại giá trị của y
							y=20;
						}
					}
					XoaLucLac_1(x1,y1);
					XoaLucLac_3(x3,y3);
					XoaLucLac_2(x2,y2);
					XoaLucLac_4(x4,y4);
					XoaLucLac_5(x5,y5,n1);
					XoaLucLac_6(x6,y6,n2);
					XoaLucLac_6(x8,y8,n3);
					XoaLucLac_5(x7,y7,n4);
					XoaVatCan_1(x1,y1);
					XoaVatCan_2(x2,y2);
					XoaVatCan_3(x3,y3);
					XoaVatCan_4(x4,y4);
					XoaVatCan_5(x5,y5,n1);
					XoaVatCan_6(x6,y6,n2);
					XoaVatCan_5(x7,y7,n4);
					XoaVatCan_6(x8,y8,n3);
					Xoa_Tien(x9,y9,i);
					XoaMayBay_1(x,y);
					XoaMayBay_2(x,y);
					x1++;
					x2++;
					x3++;
					x4++;
					x5++;
					x6++;
					x7++;
					x8++;
					x9++;

					srand(time(NULL));
					if(x1>24){
						x1=rand()%6;
					}
					if(x2==25){
						x2 =rand()%6;
						Ktra(x1,x2);
					}
					if(x3>24){
						x3 = x1;
					}
					if(x4==25){
						x4 = x2;
					}
					if(x5==25){
						x5 = rand()%6;
						n1=8 + rand()%9;
					}
					if(x6==25){
						x6 = x5;
						n2=n1 + 6;
						if(n1>10){
							n2-=6;
						}
					}
					if(x7>24){
						x7=rand()%6;
						Ktra(x5,x7);
					}
					if(x8>24){
						x8=x7;
						n4=18 + rand()%4;
					}
					if(x9>25){
						x9=0;
						y9=4+rand()%21;
						i=6+rand()%10;
					}
					switch(f){//tao di chuyen
					case '1':
						y--;
						Sleep(20);
						y--;
						k=21;
						break;
					case '2':
						y++;
						Sleep(20);
						y++;
						k=12;
						break;
					}
					if(GetAsyncKeyState(VK_SPACE)){//tạo chuyển động của máy bay
						f='1';
						if(k==21){
							f='2';
						}
					}					
					if(GetAsyncKeyState(VK_TAB)){
						gotoxy(20,10);
						textcolor(142);
						cout<<"Tam dung";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						cout<<"\n";
						textcolor(7);
						break;
					}
					if(GetAsyncKeyState(VK_ESCAPE)){
						gotoxy(17,10);
						textcolor(15);
						cout<<"  Good Bye !\n";
						gotoxy(14,11);
						cout<<"  See you again !!!";
						Sleep(2000);
						return 0;
					}
				}
			}
		}
	}while(tl=='Y'||tl=='y');
	system("pause");
	return 0;
}
