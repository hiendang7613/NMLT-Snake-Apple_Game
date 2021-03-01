#include <iostream>
#include "graphics.h"
#include "Control.h"
#include "Ball.h"
#include "Map.h"
#include "Snake.h"
#include "Windows.h"
using namespace std;
Ball ball(14);
Map map(8);
Snake snake(3, 14, 1);
Snake *psnake = &snake;
int Thanhmau();
int getint() {
	char c=getch();
	return c + 48;
}
int Menu();
void New();
void Speed();
int Load();
int Customize();
void Mapf();
void SnakeColor();
void MapColor();
int Thanhspeed();
int main() {
	FreeConsole();
	initwindow(mmap*Coef+150, mmap*Coef, "Snake & Apple -NDDVH");
	while (1) {
		switch (Menu()) {
		case -1:return 0;
		case 1:New(); break;
		case 2:Load(); break;
		case 3:	switch (Customize()) {
			case -1:break;
			case 1:Speed(); break;
			case 2:Mapf(); break;
			case 3:SnakeColor(); break;
			case 4:MapColor(); break;
			}break;
		}
	}
	return 0;
}
int Load() {
	cleardevice();
	setfillstyle(1, 15);
	outtextxy(75, 45, (char *)"Coming soon");
	delay(2000);
	return -1;
}
void New() {
	cleardevice();
	ball.Set(&map, psnake->Getpos(), snake.Getlen());
	map.set(1);
	snake.Set();
	map.draw();
	snake.Draw(snake.GetColor());
	ball.Draw();
	snake.PrintLen();
	snake.PrintSpeed();
	snake.Move(&ball, &map);
}
int Customize() {
	int choice = 1;
	cleardevice();
	setcolor(14);
	settextstyle(0, 0, 15);
	outtextxy(75, 45, (char *)"Speed");
	setcolor(15);
	settextstyle(0, 0, 15);
	outtextxy(75, 90, (char*)"Map");
	outtextxy(75, 135, (char*)"SnakeColor");
	outtextxy(75, 180, (char*)"MapColor");
	while (1) {
		if (kbhit()) {
			switch (choice) {
			case 1:setcolor(15); outtextxy(75, 45, (char*)"Speed"); break;
			case 2:setcolor(15); outtextxy(75, 90, (char*)"Map"); break;
			case 3:setcolor(15); outtextxy(75, 135, (char*)"SnakeColor"); break;
			case 4:setcolor(15); outtextxy(75, 180, (char*)"MapColor"); break;
			}
			switch (input()) {
			case 2:choice--; break;
			case 4:choice++; break;
			case 5:return -1; break;
			case 0:return choice;
			}
		}
		if (choice == 5) { choice = 1; }
		else if (choice == 0) { choice = 3; }
		switch (choice) {
		case 1:setcolor(14); outtextxy(75, 45, (char*)"Speed"); break;
		case 2:setcolor(14); outtextxy(75, 90, (char*)"Map"); break;
		case 3:setcolor(14); outtextxy(75, 135, (char*)"SnakeColor"); break;
		case 4:setcolor(14); outtextxy(75, 180, (char*)"MapColor"); break;
		}
	}
}
int Menu() {
	int choice = 1;
	cleardevice();
	setcolor(14);
	settextstyle(0, 0, 17);
	outtextxy(60, 10, (char*)"Snake & Apple");
	setcolor(15);
	settextstyle(0, 0, 15);
	outtextxy(75, 150, (char*)"Load");
	outtextxy(75, 200, (char*)"Customize");
	settextstyle(0, 0, 2);
	outtextxy(420, 400, (char*)"by NDDVHitus");
	outtextxy(10, 380, (char*)"Use arrow to control snake");
	outtextxy(10, 400, (char*)"Esc to escape");
	outtextxy(10, 420, (char*)"Enter to entering");
	settextstyle(0, 0, 15);
	while (1) {
		if (kbhit()) {
			switch (choice) {
			case 1:setcolor(15); outtextxy(75, 100, (char*)"New"); break;
			case 2:setcolor(15); outtextxy(75, 150, (char*)"Load"); break;
			case 3:setcolor(15); outtextxy(75, 200, (char*)"Customize"); break;
			}
			switch (input()) {
			case 2:choice--; break;
			case 4:choice++; break;
			case 5:return -1; break;
			case 0:return choice;
			}
		}
		if (choice == 4) { choice = 1; }
		else if (choice == 0) { choice = 3; }
		switch (choice) {
		case 1:setcolor(1); outtextxy(75, 100, (char*)"New"); break;
		case 2:setcolor(1); outtextxy(75, 150, (char*)"Load"); break;
		case 3:setcolor(1); outtextxy(75, 200, (char*)"Customize"); break;
		}
	}
}
void Mapf() {
	cleardevice();
	setcolor(11);
	outtextxy(20, 45, (char*)"Chua co ban do moi");
	//outtextxy(75, 45, "Nhap SHMap ");
	//outtextxy(75, 90, "(0<speed<2)");
	//map.set(getint());
	//while (1) { if (input() == 5) { return; } };
	delay(1500);
}
void SnakeColor() {
	cleardevice();
	setcolor(15);
	outtextxy(75, 45, (char*)"Chon mau ran");
	int temp = Thanhmau();
	if (temp == -1) { return; }
	snake.SetColor(temp);
}
void MapColor() {
	cleardevice();
	setcolor(15);
	outtextxy(75, 45, (char*)"Chon mau ban do ");
	int temp = Thanhmau();
	if (temp == -1) { return; }
	map.Setcolor(temp);
}
void Speed() {
	cleardevice();
	setcolor(15);
	outtextxy(75, 45, (char*)" Speed ");
	int temp = Thanhspeed();
	if (temp == -1) { return; };
	snake.inspeed(temp);
}
int Thanhmau() {
	int a[6] = { 0,330,30,330,15,345 },choice=1;
	for (int i = 0; i < 15; i++) { setfillstyle(1, i + 1); bar(i * 40, 350, i * 40 + 29, 450); }
	while (1) {
		if (kbhit()) {
			setfillstyle(1, 15); fillpoly(3, a);
			switch (input()) {
			case 3:choice--; break;
			case 1:choice++; break;
			case 5:return -1; break;
			case 0:return choice;
			}
		}
		if (choice == 16) { choice = 1; }
		else if (choice == 0) { choice = 14; }
		a[0] = (choice-1)*40; a[2] = (choice - 1)*40+29; a[4] = (choice - 1)*40+20;
		setfillstyle(1, 14); fillpoly(3, a);
	}
}
int Thanhspeed() {
	int choice = 1;
	setfillstyle(1, 14);
	rectangle(97, 297, 503, 343);
	bar(100,300,179,340);
	while (1) {
			if (kbhit()) {
				switch (input()) {
				case 3:choice--; if (!choice) { choice++; break; } 
					   else {setfillstyle(1, 0);bar(100+80*(choice), 300, 179+80* (choice), 340);}; break;
				case 1:choice++; if (choice==6) { choice--; break; }
					   else { setfillstyle(1, 14); bar(100 + 80 * (choice-1), 300, 179 + 80 * (choice-1), 340); }; break;
				case 5:return -1; break;
				case 0:return choice;
				}
			}
		}
}