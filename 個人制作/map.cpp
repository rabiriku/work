#include "map.h"
#include <Novice.h>

void Map::Initialize() {
	map1;
	mapCountX;
	mapCountY;
	blockSize = 32;
	mapFlag_ = 0;
	bg = Novice::LoadTexture("./haikei.png");
} 

void Map::ColBottom(int LbottomX, int LbottomY, int RbottomX, int RbottomY)
{
	leftBottomX_ = LbottomX;
	leftBottomY_ = LbottomY;
	rightBottomX_ = RbottomX;
	rightBottomY_ = RbottomY;
}

void Map::ColTop(int LtopX, int LtopY, int RtopX, int RtopY)
{
	leftTopX_ = LtopX;
	leftTopY_ = LtopY;
	rightTopX_ = RtopX;
	rightTopY_ = RtopY;
}

void Map::Updete() {
	if (map1[leftBottomY_][leftBottomX_] == BLOCK&&map1[rightBottomY_][rightBottomX_] == BLOCK) {
			mapFlag_ = 1;
		}
if (map1[leftBottomY_][leftBottomX_] == NONE&& map1[rightBottomY_][rightBottomX_] == NONE) {
		mapFlag_ = 0;
}

}



void Map::Draw() {
	
	Novice::DrawSprite(0,0, bg, 1, 1, 0, WHITE);
	Novice::ScreenPrintf(0, 240, "leftbottom%d", leftBottomX_);
	Novice::ScreenPrintf(0, 300, "%d",mapFlag_);
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			if (map1[y][x] == BLOCK) {
				Novice::DrawBox(x * blockSize, y * blockSize, blockSize, blockSize, 0.0f, BLACK,kFillModeSolid);
			}
			if (map1[y][x] == GOAL) {
				Novice::DrawBox(x * blockSize, y * blockSize, blockSize, blockSize, 0, WHITE, kFillModeWireFrame);
			}
		}
	}
}



