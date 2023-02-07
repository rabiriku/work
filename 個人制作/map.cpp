#include "map.h"
#include <Novice.h>

void Map::Initialize() {
	mapCountX = sizeof(map1[0]) / sizeof(map1[0][0]);
	mapCountY = sizeof(map1) / sizeof(map1[0]);
	blockSize = 32;
	bg = Novice::LoadTexture("./resouces/images/bg.png");
	bgbox = Novice::LoadTexture("./resouces/images/passbox.png");
	block_= Novice::LoadTexture("./resouces/images/block.png");
	lock_= Novice::LoadTexture("./resouces/images/lock.png");
	key_= Novice::LoadTexture("./resouces/images/key.png");
	explanation_ = Novice::LoadTexture("./resouces/images/explanation.png");
	goal_= Novice::LoadTexture("./resouces/images/goal.png");
	ball_= Novice::LoadTexture("./resouces/images/ball.png");
	goalaudio_= Novice::LoadAudio("./resouces/audio/goal.mp3");
	keyaudio_= Novice::LoadAudio("./resouces/audio/key.mp3");
	keyFlag_ = 0;
	dropflag_ = 1;
	efectflag_ = 1;
	speed_ = -10;

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
//BLOCK
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


int Map::BlockTopCollision2(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0) {
		return 0;
	}

	if (map2[vertex.leftTop.y][vertex.leftTop.x] == BLOCK ||
		map2[vertex.rightTop.y][vertex.rightTop.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockBottomCollison2(Vertex vertex)
{
	if (vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}


	if (map2[vertex.leftBottom.y][vertex.leftBottom.x] == BLOCK ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockLeftCollision2(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0) {
		return 0;
	}


	if (map2[vertex.leftTop.y][vertex.leftTop.x] == BLOCK ||
		map2[vertex.leftBottom.y][vertex.leftBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockRightCollision2(Vertex vertex)
{

	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}


	if (map2[vertex.rightTop.y][vertex.rightTop.x] == BLOCK ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockTopCollision3(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == BLOCK ||
		map3[vertex.rightTop.y][vertex.rightTop.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockBottomCollison3(Vertex vertex) {

	if (vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}
		if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == BLOCK ||
			map3[vertex.rightBottom.y][vertex.rightBottom.x] == BLOCK) {
			return 1;
		}
		return 0;
}

int Map::BlockLeftCollision3(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0) {
		return 0;
	}


	if (map3[vertex.leftTop.y][vertex.leftTop.x] == BLOCK ||
		map3[vertex.leftBottom.y][vertex.leftBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}

int Map::BlockRightCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}


	if (map3[vertex.rightTop.y][vertex.rightTop.x] == BLOCK ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == BLOCK) {
		return 1;
	}
	return 0;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//GOAL
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


int Map::GoalTopCollision2(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0) {
		return 0;
	}

	if (map2[vertex.leftTop.y][vertex.leftTop.x] == GOAL ||
		map2[vertex.rightTop.y][vertex.rightTop.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalBottomCollision2(Vertex vertex)
{
	if (vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.leftBottom.y][vertex.leftBottom.x] == GOAL ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalLeftCollision2(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0) {
		return 0;
	}


	if (map2[vertex.leftTop.y][vertex.leftTop.x] == GOAL ||
		map2[vertex.leftBottom.y][vertex.leftBottom.x] == GOAL) {
		return 1;
	}

	return 0;
}

int Map::GoalRightCollision2(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.rightTop.y][vertex.rightTop.x] == GOAL ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == GOAL) {
		return 1;
	}

	return 0;
}

int Map::GoalTopCollision3(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == GOAL ||
		map3[vertex.rightTop.y][vertex.rightTop.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalBottomCollision3(Vertex vertex)
{
	if (vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == GOAL ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalLeftCollision3(Vertex vertex)
{
	if (vertex.leftTop.x >= mapCountX || vertex.leftTop.x < 0 ||
		vertex.leftTop.y >= mapCountY || vertex.leftTop.y < 0 ||
		vertex.leftBottom.x >= mapCountX || vertex.leftBottom.x < 0 ||
		vertex.leftBottom.y >= mapCountY || vertex.leftBottom.y < 0) {
		return 0;
	}


	if (map3[vertex.leftTop.y][vertex.leftTop.x] == GOAL ||
		map3[vertex.leftBottom.y][vertex.leftBottom.x] == GOAL) {
		return 1;
	}
	return 0;
}

int Map::GoalRightCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.rightTop.y][vertex.rightTop.x] == GOAL ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == GOAL) {
		return 1;
	}

	return 0;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//KEY
int Map::KeyTopCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.leftTop.y][vertex.leftTop.x] == KEY ||
		map2[vertex.rightTop.y][vertex.rightTop.x] == KEY) {
		return 1;
	}
	return 0;
}

int Map::KeyBottomCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.leftBottom.y][vertex.leftBottom.x] == KEY ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == KEY) {
		return 1;
	}
	return 0;
}

int Map::KeyLeftCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.leftTop.y][vertex.leftTop.x] == KEY ||
		map2[vertex.leftBottom.y][vertex.leftBottom.x] == KEY) {
		return 1;
	}
	return 0;
}

int Map::KeyRightCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.rightTop.y][vertex.rightTop.x] == KEY ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == KEY) {
		return 1;
	}

	return 0;
}
int Map::KeyTopCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == KEY ||
		map3[vertex.rightTop.y][vertex.rightTop.x] == KEY) {
		return 1;
	}
	return 0;
}
int Map::KeyBottomCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == KEY ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == KEY) {
		return 1;
	}
	return 0;
}
int Map::KeyLeftCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == KEY ||
		map3[vertex.leftBottom.y][vertex.leftBottom.x] == KEY) {
		return 1;
	}
	return 0;
}
int Map::KeyRightCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.rightTop.y][vertex.rightTop.x] == KEY ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == KEY) {
		return 1;
	}
	return 0;
}
int Map::KeyTopCollision5(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == KEY2 ||
		map3[vertex.rightTop.y][vertex.rightTop.x] == KEY2) {
		return 1;
	}
	return 0;
}
int Map::KeyBottomCollision5(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == KEY2 ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == KEY2) {
		return 1;
	}
	return 0;
}
int Map::KeyLeftCollision5(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == KEY2 ||
		map3[vertex.leftBottom.y][vertex.leftBottom.x] == KEY2) {
		return 1;
	}
	return 0;
}
int Map::KeyRightCollision5(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.rightTop.y][vertex.rightTop.x] == KEY2 ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == KEY2) {
		return 1;
	}
	return 0;
}
int Map::KeyTopCollision6(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == KEY3 ||
		map3[vertex.rightTop.y][vertex.rightTop.x] == KEY3) {
		return 1;
	}
	return 0;
}
int Map::KeyBottomCollision6(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == KEY3 ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == KEY3) {
		return 1;
	}
	return 0;
}
int Map::KeyLeftCollision6(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == KEY3 ||
		map3[vertex.leftBottom.y][vertex.leftBottom.x] == KEY3) {
		return 1;
	}
	return 0;
}
int Map::KeyRightCollision6(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.rightTop.y][vertex.rightTop.x] == KEY3 ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == KEY3) {
		return 1;
	}
	return 0;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//LOCK
int Map::LockTopCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.rightTop.y][vertex.rightTop.x] == LOCK ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == LOCK) {
		return 1;
	}

	return 0;
}

int Map::LockBottomCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.leftBottom.y][vertex.leftBottom.x] == LOCK ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}

int Map::LockLeftCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.leftTop.y][vertex.leftTop.x] == LOCK ||
		map2[vertex.leftBottom.y][vertex.leftBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}

int Map::LockRightCollision(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map2[vertex.rightTop.y][vertex.rightTop.x] == LOCK ||
		map2[vertex.rightBottom.y][vertex.rightBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}
int Map::LockTopCollisio3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == LOCK ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}
int Map::LockBottomCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftBottom.y][vertex.leftBottom.x] == LOCK ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}
int Map::LockLeftCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.leftTop.y][vertex.leftTop.x] == LOCK ||
		map3[vertex.leftBottom.y][vertex.leftBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}
int Map::LockRightCollision3(Vertex vertex)
{
	if (vertex.rightTop.x >= mapCountX || vertex.rightTop.x < 0 ||
		vertex.rightTop.y >= mapCountY || vertex.rightTop.y < 0 ||
		vertex.rightBottom.x >= mapCountX || vertex.rightBottom.x < 0 ||
		vertex.rightBottom.y >= mapCountY || vertex.rightBottom.y < 0) {
		return 0;
	}

	if (map3[vertex.rightTop.y][vertex.rightTop.x] == LOCK ||
		map3[vertex.rightBottom.y][vertex.rightBottom.x] == LOCK) {
		return 1;
	}
	return 0;
}
//<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>
void Map::KeyChange(int x, int y, int v, int z)
{
	map2[x][y] = NONE;
	map2[v][z] = NONE;
	Novice::PlayAudio(keyaudio_, 0, 1);

}

void Map::KeyCange2(int y, int x,int v ,int z,int a,int b) {
	map3[y][x] = NONE;
	map3[v][z] = NONE;
	map3[a][b] = NONE;
	Novice::PlayAudio(keyaudio_, 0, 1);
}

void Map::KeyReturn(int x, int y, int v, int z)
{
	map2[x][y] = LOCK;
	map2[v][z] = KEY;
}

void Map::KeyReturn2(int y, int x, int v, int z, int a, int b)
{
	map3[y][x] = LOCK;
	map3[v][z] = LOCK;
	map3[a][b] = KEY;
}

void Map::KeyCangeEfect(float x, float y)
{
	if (dropflag_ == 1) {
		speed_ = -10;
		BulletposX[0] = x;
		BulletposX[1]=x;
		BulletposX[2]=x;
		BulletposX[3]=x;

		BulletposY[0] = y;
		BulletposY[1]=y;
		BulletposY[2]=y;
		BulletposY[3]=y;
		dropflag_ = 0;
		efectflag_ = 1;
	}
	speed_ += 0.6;
	
	BulletposY[0] += speed_;
	BulletposY[1] += speed_;
	BulletposY[2] += speed_;
	BulletposY[3] += speed_;
	BulletposX[0] += 0.9;
	BulletposX[1] += 0.3;
	BulletposX[2] -= 0.9;
	BulletposX[3] -= 0.3;

	if (BulletposY[0] > 850) {
		dropflag_ = 1;
		efectflag_ = 0;
	}
}

void Map::GoalAudio()
{
	Novice::PlayAudio(goalaudio_, 0, 1);
}

void Map::Draw() {

	Novice::DrawSprite(0, 0, bg, 1, 1, 0, WHITE);
	Novice::DrawSprite(0, 0, bgbox, 1, 1, 0, 0xffffff20);
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			if (map1[y][x] == BLOCK) {
				Novice::DrawSprite(x * blockSize, y * blockSize, block_, 1, 1, 0.0f, WHITE);
			}
			if (map1[y][x] == GOAL) {
				Novice::DrawSprite(x * blockSize, y * blockSize, goal_, 1, 1, 0.0f, WHITE);
			}
		}
	}
	Novice::DrawSprite(0, 0, explanation_, 1, 1, 0.0f, WHITE);
}

void Map::Draw2()
{
	Novice::DrawSprite(0, 0, bg, 1, 1, 0, WHITE);
	Novice::DrawSprite(0, 0, bgbox, 1, 1, 0, 0xffffff20);
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			if (map2[y][x] == BLOCK) {
				Novice::DrawSprite(x * blockSize, y * blockSize, block_, 1, 1, 0.0f, WHITE);
			}
			if (map2[y][x] == GOAL) {
				Novice::DrawSprite(x * blockSize, y * blockSize, goal_, 1, 1, 0.0f, WHITE);
			}
			if (map2[y][x] == KEY) {
				Novice::DrawSprite(x * blockSize, y * blockSize, key_, 1, 1, 0.0f, WHITE);
			}
			if (map2[y][x] == LOCK) {
				Novice::DrawSprite(x * blockSize, y * blockSize, lock_, 1, 1, 0.0f, WHITE);
			}

		}
	}

	Novice::DrawSprite(BulletposX[0] - 8, BulletposY[0] - 8, ball_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(BulletposX[1] - 8, BulletposY[1] - 8, ball_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(BulletposX[2] - 8, BulletposY[2] - 8, ball_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(BulletposX[3] - 8, BulletposY[3] - 8, ball_, 1, 1, 0.0f, WHITE);
}

void Map::Draw3()
{
	Novice::DrawSprite(0, 0, bg, 1, 1, 0, WHITE);
	Novice::DrawSprite(0, 0, bgbox, 1, 1, 0, 0xffffff20);
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			if (map3[y][x] == BLOCK) {
				Novice::DrawSprite(x * blockSize, y * blockSize, block_, 1, 1, 0.0f, WHITE);
			}
			if (map3[y][x] == GOAL) {
				Novice::DrawSprite(x * blockSize, y * blockSize, goal_, 1, 1, 0.0f, WHITE);
			}
			if (map3[y][x] == KEY) {
				Novice::DrawSprite(x * blockSize, y * blockSize, key_, 1, 1, 0.0f, WHITE);
			}
			if (map3[y][x] == LOCK) {
				Novice::DrawSprite(x * blockSize, y * blockSize, lock_, 1, 1, 0.0f, WHITE);
			}
			if (map3[y][x] == KEY2) {
				Novice::DrawSprite(x * blockSize, y * blockSize, key_, 1, 1, 0.0f, WHITE);
			}
			if (map3[y][x] == KEY3) {
				Novice::DrawSprite(x * blockSize, y * blockSize, key_, 1, 1, 0.0f, WHITE);
			}
		}
	}
	Novice::DrawSprite(BulletposX[0] - 8, BulletposY[0] - 8, ball_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(BulletposX[1] - 8, BulletposY[1] - 8, ball_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(BulletposX[2] - 8, BulletposY[2] - 8, ball_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(BulletposX[3] - 8, BulletposY[3] - 8, ball_, 1, 1, 0.0f, WHITE);
}


