#include "map.h"
#include <Novice.h>

void Map::Initialize() {
	map1;
	mapCountX = sizeof(map1[0]) / sizeof(map1[0][0]);
	mapCountY = sizeof(map1) / sizeof(map1[0]);
	blockSize = 32;
	mapFlag_ = 0;
	bg = Novice::LoadTexture("./resouces/bg.png");
	bgbox = Novice::LoadTexture("./resouces/passbox.png");
}

void Map::ColBottom(const Vertex& vertex)
{
	leftBottomX_ = vertex.leftBottom.x;
	leftBottomY_ = vertex.leftBottom.y;
	rightBottomX_ = vertex.rightBottom.x;
	rightBottomY_ = vertex.rightBottom.y;
}

void Map::ColTop(const Vertex& vertex)
{
	leftTopX_ = vertex.leftTop.x;
	leftTopY_ = vertex.leftTop.y;
	rightTopX_ = vertex.rightTop.x;
	rightTopY_ = vertex.rightTop.y;
}
void Map::Colplayer(const Vector2& vevtor2, int radius) {
	posX_ = vevtor2.x;
	posY_ = vevtor2.y;
	radius_ = radius;
}

int Map::BlockTopCollision(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0) {
		return 0;
	}

	if (map1[vertex.leftTop.y][vertex.leftTop.x] == BLOCK ||
		map1[vertex.rightTop.y][vertex.rightTop.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockBottomCollison(Vertex vertex)
{
	if (vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}


	if (map1[vertex.leftBottom.y][vertex.leftBottom.x] == BLOCK ||
		map1[vertex.rightBottom.y][vertex.rightBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockLeftCollision(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0) {
		return 0;
	}


	if (map1[vertex.leftTop.y][vertex.leftTop.x] == BLOCK ||
		map1[vertex.leftBottom.y][vertex.leftBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockRightCollision(Vertex vertex)
{

	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}
	

	if (map1[vertex.rightTop.y][vertex.rightTop.x] == BLOCK ||
		map1[vertex.rightBottom.y][vertex.rightBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::GoalTopCollision(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0) {
		return 0;
	}

	if (map1[vertex.leftTop.y][vertex.leftTop.x] == GOAL ||
		map1[vertex.rightTop.y][vertex.rightTop.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalBottomCollision(Vertex vertex)
{
	if (vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map1[vertex.leftBottom.y][vertex.leftBottom.x] == GOAL ||
		map1[vertex.rightBottom.y][vertex.rightBottom.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalLeftCollision(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0) {
		return 0;
	}


	if (map1[vertex.leftTop.y][vertex.leftTop.x] == GOAL ||
		map1[vertex.leftBottom.y][vertex.leftBottom.x] == GOAL) {
		return 1;
	}

	return 0;
}

int Map::GoalRightCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map1[vertex.rightTop.y][vertex.rightTop.x] == GOAL ||
		map1[vertex.rightBottom.y][vertex.rightBottom.x] == GOAL) {
		return 1;
	}

	return 0;
}


void Map::Draw() {

	Novice::DrawSprite(0, 0, bg, 1, 1, 0, WHITE);
	Novice::DrawSprite(0, 0, bgbox, 1, 1, 0, 0xffffff20);
	Novice::ScreenPrintf(0, 240, "leftbottom%d", leftBottomX_);
	Novice::ScreenPrintf(0, 300, "%d", mapFlag_);
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			if (map1[y][x] == BLOCK) {
				Novice::DrawBox(x * blockSize, y * blockSize, blockSize, blockSize, 0.0f, BLACK, kFillModeSolid);
			}
			if (map1[y][x] == GOAL) {
				Novice::DrawBox(x * blockSize, y * blockSize, blockSize, blockSize, 0, WHITE, kFillModeWireFrame);
			}
		}
	}
}



