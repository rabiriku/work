#include "Map.h"
#include <Novice.h>

void Map::Initialize() {
	map1;
	mapCountX;
	mapCountY;
	blockSize = 32;
}

void Map::Draw() {
	Novice::DrawSprite(0,0, bg, 1, 1, 0, WHITE);

	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			if (map1[y][x] == BLOCK) {
				Novice::DrawBox(x * blockSize, y * blockSize, blockSize, blockSize, 0.0f, BLACK,kFillModeSolid);
			}
		}
	}
}

