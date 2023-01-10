#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize()
{
	posX_ = 200;
	posY_ = 200;
	radius_ = 10;
	speedX_ = 5;
	speedY_ = 5;
	color_ = WHITE;
	shakeflag_ = 0;
	shaketime_ = 60;
	reshaketime = 500;
	atacckposX_ = 1300;
	atacckposY_ = 300;
}

void Enemy::Initialize(int x, int y)
{
	posX_ = x;
	posY_ = y;
	radius_ = 10;
	speedX_ = 0;
	speedY_ = 5;
	color_ = WHITE;
}



void Enemy::Update()
{
	posX_ += speedX_;
	posY_ += speedY_;
	if (posX_ - radius_ == 0 || posX_ + radius_ >= 1248) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 32 || posY_ + radius_ >= 768){
		speedY_ *= -1;
	}
}

void Enemy::Update2()
{
	if (shakeflag_ == 0) {
		if (shaketime_ > 0) {
			shaketime_ -= 1;
		}
		if (shaketime_ > 40) {
			randX_ = rand() % 16 - 8;
			randY_ = rand() % 16 - 8;
		}
		if (shaketime_ < 40 && shaketime_ > 20) {
			randX_ = rand() % 11 - 5;
			randY_ = rand() % 11 - 5;
		}
		if ( shaketime_ < 20 && shaketime_ > 0) {
			randX_ = rand() % 7 - 3;
			randY_ = rand() % 7 - 3;
		}
		if (shaketime_ == 0) {
			shakeflag_ = rand()%3;
			shaketime_ = 60;
			
		}

	}
	if (shakeflag_ == 1) {
		posX_ += speedX_;
		posY_ += speedY_;
		reshaketime -= 1;
		if (posX_ - radius_ == 0 || posX_ + radius_ >= 1248) {
			speedX_ *= -1;
		}
		if (posY_ - radius_ <= 32 || posY_ + radius_ >= 768) {
			speedY_ *= -1;
			if (reshaketime < 0) {
				shakeflag_ = 0;
				reshaketime = 500;
		}

		}
	}

	if (shakeflag_ == 2) {
		atacckposX_ -= speedX_;
		if (atacckposX_ < -1280) {
			shakeflag_ = 0;
			atacckposX_ = 1300;
		}
	}

	if (shakeflag_ == 3) {

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

void Enemy::Draw2() {
	Novice::DrawEllipse(posX_ + randX_, posY_ + randY_, radius_, radius_, 0, WHITE,kFillModeSolid);
	Novice::DrawBox(atacckposX_, atacckposY_, 1280, 150, 0, RED, kFillModeSolid);
	Novice::ScreenPrintf(0, 60, "%d", shakeflag_);
}
void Enemy::Oncollision()
{
	speedX_ *= -1;
	color_ = BLACK;
}

void Enemy::Nocollision()
{
	color_ = WHITE;
}
