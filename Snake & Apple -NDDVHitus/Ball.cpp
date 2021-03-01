#include "Ball.h"
void Ball::SetColor(int color) { this->color = color; }
void Ball::Draw() { setfillstyle(1, color); bar(ball.x*Coef, ball.y*Coef, ball.x*Coef + Coef - 1, ball.y*Coef + Coef - 1); }
void Ball::Set(Map *map, pos *possnake,int lensnake) {
	srand((unsigned)time(NULL));
	ball.x = rand() % 27 + 1;
	ball.y = rand() % 27 + 1;
	if (map->GetWall(ball.x, ball.y)) { Set(map, possnake,lensnake); }
	for (int i = 0; i < lensnake; i++) {
		if (ball.x == (possnake+i)->x&&ball.y == (possnake+i)->y) { Set(map, possnake, lensnake); }
	}
}
Ball::Ball(int c) :color(c) {};
pos Ball::Getpos() { return ball; }
