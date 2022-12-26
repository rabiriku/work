#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize()
{
	posX_ = 200;
	posY_ = 200;
	radius_ = 10;
	speedX_ = 5;
	speedY_ = -5;
	color_ = WHITE;
}

void Enemy::Initialize(int x, int y)
{
	posX_ = x;
	posY_ = y;
	radius_ = 10;
	speedX_ = 5;
	speedY_ = 5;
	color_ = WHITE;
}



void Enemy::Update()
{
	posX_ += speedX_;
	posY_ += speedY_;
	if (posX_ - radius_ == 0 || posX_ + radius_ == 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ == 0 || posY_ + radius_ == 720) {
		speedY_ *= -1;
	}
}

//void Enemy::Update(char* keys)
//{
//	if (keys[DIK_W]) {
//		posY_ += speedY_;
//	}
//	if (keys[DIK_S]) {
//		posY_ -= speedY_;
//	}
//	if (keys[DIK_A]) {
//		posX_ -= speedX_;
//	}
//	if (keys[DIK_D]) {
//		posX_ += speedX_;
//	}
//	if (keys[DIK_SPACE]) {
//
//	}
//}
void Enemy::Draw()
{
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, color_, kFillModeSolid);
}

void Enemy::Oncollision()
{
	speedX_ *= -1;
	//color_ = BLACK;
}

void Enemy::Nocollision()
{
	color_ = WHITE;
}
