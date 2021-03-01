#pragma once
#include "graphics.h"
#include "Define.h"
class Map {
	bool Wall[mmap][mmap];
	int color;
public:
	bool GetWall(int x,int y);
	void set(int map);
	void Setcolor(int color);
	void draw();
	void map1();
	Map(int c);
};
