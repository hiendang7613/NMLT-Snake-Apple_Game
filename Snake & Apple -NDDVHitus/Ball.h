#pragma once
#include "graphics.h"
#include "Map.h"
#include "Control.h"
#include "Pos.h"
#include "stdlib.h"
#include "time.h"
class Ball {
	pos ball;
	int color;
public:
	void Draw();
	void SetColor(int color);
	void Set(Map *map,pos *possnake,int lensnake);
	pos Getpos();
	Ball(int c);
};
