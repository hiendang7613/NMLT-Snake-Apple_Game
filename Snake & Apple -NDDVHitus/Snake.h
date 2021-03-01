#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Ball.h"
#include "Pos.h"
#include "graphics.h"
#include "Map.h"
#include "Control.h"
#include "Define.h"
class Snake {
	pos Pos[mlen];
	int dir,len,color,speed;
public:
	int Getlen();
	pos *Getpos();
	void Set();
	void SetColor(int color);
	void Move(Ball *ball,Map *map);
	void Draw(int color);
	void Die();
	bool isDieWall(Map *map);
	bool isSuicide();
	bool isEat(Ball *ball);
	Snake(int lenght, int c, int speeds);
	void inspeed(int speed);
	int Getspeed();
	int GetColor();
	void PrintLen();
	void Levelup();
	void PrintSpeed();
};

