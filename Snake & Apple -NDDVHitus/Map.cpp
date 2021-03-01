#include "Map.h"
bool Map::GetWall(int x, int y) { return Wall[x][y]; }
void Map::draw() {
	for (int i = 0; i < mmap; i++) {
		for (int j = 0; j < mmap; j++) {if (Wall[i][j]) { setfillstyle(1,color); bar(i*Coef, j*Coef, i*Coef + Coef - 1, j*Coef + Coef - 1); }}
	}
}
void Map::Setcolor(int color) { this->color = color; }
void Map::map1() {
	for (int i = 0; i < mmap - 1; i++) { Wall[i][0] = Wall[mmap - 2][i] = Wall[mmap - 2 - i][mmap - 2] = Wall[0][mmap - 2 - i] = 1; }
}
void Map::set(int map) {
	switch (map) {
	case 1:map1(); break;
	}
}
Map::Map(int c) :color(c) {};
