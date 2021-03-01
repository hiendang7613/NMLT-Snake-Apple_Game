#include "Snake.h"
int Snake::Getlen() { return len; }
pos *Snake::Getpos() { return &Pos[0]; }
void Snake::Set() {
	for (int i = 0; i < len; i++) { Pos[i].x = len+1 - i; Pos[i].y = 2; }
	dir = 1;
}
void Snake::SetColor(int color) { this->color = color; };
void Snake::Move(Ball *ball, Map *map) {
	if (kbhit()) {
		int temp = input();
		if (temp + dir != 4 && temp + dir != 6) { dir = temp; }
	}
	delay(150-20*(speed-1));
	setfillstyle(1, 0);
	bar(Pos[len-1].x*Coef, Pos[len - 1].y*Coef, Pos[len - 1].x*Coef + Coef - 1, Pos[len - 1].y*Coef + Coef - 1);
	for (int i = len - 1; i > 0; i--) { Pos[i].x = Pos[i - 1].x; Pos[i].y = Pos[i - 1].y; }
	switch (dir) {
	case 1:Pos[0].x++;  break;
	case 2:Pos[0].y--;  break;
	case 3:Pos[0].x--;  break;
	case 4:Pos[0].y++;  break;
	case 5:Die();
	}
	setfillstyle(1, color);
	Draw(color);
	if (isDieWall(map) || isSuicide()) { Die(); }
	else if (isEat(ball)) { 
		len++; 
		ball->Set(map, this->Getpos(), this->len); ball->Draw(); 
		setfillstyle(1, 0);
		bar(460, 10, 590, 180);
		PrintLen(); 
		PrintSpeed();
		if (!(len % 4)) { Levelup(); }
		Move(ball, map); 
	}
	else { Move(ball, map); }
}
void Snake::Die() {
	for (int i = 0; i < 3; i++) {
		 Draw(14); delay(200);
		 Draw(0); delay(200);
	}
	setcolor(14);
	settextstyle(0, 0, 16);
	outtextxy(90, 150, (char*)"GAME OVER");
	delay(1000);

}
void Snake::Draw(int color) {
	setfillstyle(1, color);
	for (int i = 0; i < len; i++) { bar(Pos[i].x*Coef, Pos[i].y*Coef, Pos[i].x*Coef + Coef - 1, Pos[i].y*Coef + Coef - 1); }
}

bool Snake::isDieWall(Map *map) {
	for (int i = 0; i < len; i++) { if (map->GetWall(Pos[i].x, Pos[i].y)) { return true; } }
	return false;
}
bool Snake::isSuicide() {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) { if (Pos[i].x == Pos[j].x&&Pos[i].y == Pos[j].y) { return true; } }
	}
	return false;
}
bool Snake::isEat(Ball *ball) {
	if (Pos[0].x == ball->Getpos().x&&Pos[0].y == ball->Getpos().y) { return true; }
	return false;
}
Snake::Snake(int lenght, int c, int speeds) : len(lenght), color(c), speed(speeds) {};
void Snake::inspeed(int speed) { this->speed = speed; }
int Snake::Getspeed() { return speed; }
int Snake::GetColor() { return color; }
void Snake::PrintLen() {
	char a[3];
	sprintf(a,"%d", len);
	setcolor(14);
	settextstyle(1, 0, 23);
	outtextxy(440, 100, (char*)"SnakeLength");
	settextstyle(1, 0, 24);
	outtextxy(500, 150, a);
}
void Snake::Levelup() {
	settextstyle(1, 0, 23);
	for (int i = 0; i < 3; i++) {
		setcolor(14);
		outtextxy(450, 200, (char*)"Level up");
		outtextxy(440, 220, (char*)"-> Speed++");
		delay(250);
		setcolor(0);
		outtextxy(450, 200, (char*)"Level up");
		outtextxy(440, 220, (char*)"-> Speed++");
		delay(250);
	}
	speed++;
	PrintSpeed();
}
void Snake::PrintSpeed() {
	char a[3];
	sprintf(a, "%d", speed);
	setcolor(14);
	settextstyle(1, 0, 23);
	outtextxy(440, 300, (char*)"Snake Speed");
	settextstyle(1, 0, 24);
	outtextxy(500, 350, a);
}