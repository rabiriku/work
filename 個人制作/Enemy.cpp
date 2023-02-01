#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize()
{
	pos_.x = 180;
	pos_.y = 200;
	radius_ = 10;
	speedX_ = 5;
	speedY_ = 5;
	color_ = WHITE;
	shakeFlag_ = 0;
	shakeTime_ = 60;
	reshakeTime = 500;
	atacckPosX_ = 1300;
	atacckPosY_ = 300;

}

void Enemy::Initialize(int x, int y)
{
	pos_.x = x;
	pos_.y = y;
	radius_ = 10;
	speedX_ = 0;
	speedY_ = 5;
	color_ = WHITE;
}



void Enemy::Update()
{
	
	pos_.x += speedX_;
	pos_.y += speedY_;
	if (pos_.x- radius_ == 0 || pos_.x + radius_ >= 1248) {
		speedX_ *= -1;
	}
	if (pos_.y - radius_ <= 32 || pos_.y + radius_ >= 768){
		speedY_ *= -1;
	}
}

void Enemy::Update2()
{
	if (shakeFlag_ == 0) {
		if (shakeTime_ > 0) {
			shakeTime_ -= 1;
		}
		if (shakeTime_ > 40) {
			randX_ = rand() % 16 - 8;
			randY_ = rand() % 16 - 8;
		}
		if (shakeTime_ < 40 && shakeTime_ > 20) {
			randX_ = rand() % 11 - 5;
			randY_ = rand() % 11 - 5;
		}
		if ( shakeTime_ < 20 && shakeTime_ > 0) {
			randX_ = rand() % 7 - 3;
			randY_ = rand() % 7 - 3;
		}
		if (shakeTime_ == 0) {
			shakeFlag_ = rand() % 3;
			shakeTime_ = 60;
			
		}

	}
	if (shakeFlag_ == 1) {
		pos_.x += speedX_;
		pos_.y += speedY_;
		reshakeTime -= 1;
		if (pos_.x - radius_ == 0 || pos_.y+ radius_ >= 1248) {
			speedX_ *= -1;
		}
		if (pos_.y - radius_ <= 32 || pos_.y + radius_ >= 768) {
			speedY_ *= -1;
			if (reshakeTime < 0) {
				shakeFlag_ = 0;
				reshakeTime = 500;
		}

		}
	}

	if (shakeFlag_ == 2) {
		atacckPosX_ -= speedX_;
		if (atacckPosX_ < -1280) {
			shakeFlag_ = 0;
			atacckPosX_ = 1300;
		}
	}

	//const int kEmitterMax = 300;


	//struct Vector2 {
	//	int X;
	//	int Y;
	//};
	//
	//struct Circle {
	//	Vector2 Pos[kEmitterMax];
	//	Vector2 Speed[kEmitterMax];
	//	int flag[kEmitterMax];
	//};
	//
	//struct Mouse {
	//	Vector2 Pos;
	//};
	//
	//struct Scale {
	//	Vector2 Pos;
	//	Vector2 Max;
	//	Vector2 Min;
	//};
	//
	//Circle ball = { 0 };
	//for (int i = 0; i < kEmitterMax; i++) {
	//	ball.Pos[i].X = 0;
	//	ball.Pos[i].Y = 0;
	//	ball.Speed[i].Y = 0;
	//	ball.flag[i] = 0;
	//}
	//
	//Scale scale = { 0 };
	//scale.Pos.X = 100;
	//scale.Pos.Y = 100;
	//scale.Max.X = 50;
	//scale.Max.Y = 20;
	//scale.Min.X = 25;
	//scale.Min.Y = 10;

	//if (shakeflag_ == 3) {
	//
	//
	//	for (int i = 0; i < kEmitterMax; i++) {
	//		if (ball.flag[i] == 0) {
	//			ball.flag[i] = 1;
	//			ball.Pos[i].X = scale.Pos.X + scale.Max.X / 2;
	//			ball.Pos[i].Y = scale.Pos.Y;
	//			ball.Pos[i].X += rand() % scale.Max.X - scale.Min.X;
	//			ball.Pos[i].Y += rand() % scale.Max.Y;
	//			ball.Speed[i].Y = 0;
	//			break;
	//		}
	//	}
	//
	//	for (int i = 0; i < kEmitterMax; i++) {
	//		if (ball.flag[i] == 1) {
	//
	//			
	//			
	//			
	//			
	//			ball.Pos[i].Y += ball.Speed[i].Y;
	//			ball.Speed[i].Y++;
	//		}
	//		if (ball.Pos[i].Y >= 720) {
	//			ball.flag[i] = 0;
	//		}
	//	}
	//	for (int i = 0; i < kEmitterMax; i++) {
	//		if (ball.flag[i]) {
	//			Novice::DrawEllipse(ball.Pos[i].X, ball.Pos[i].Y, 10, 10, 0.0f, BLACK, //kFillModeSolid);
	//		}
	//	}
	//}
	//
	//if (shakeflag_ == 4) {
	//
	//}
}

//void Enemy::Parry(char*keys) {
//	if (keys[DIK_E]) {
//		
//	}
//
//}

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
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}

void Enemy::Draw2() {
	Novice::DrawEllipse(pos_.x + randX_, pos_.y + randY_, radius_, radius_, 0, WHITE,kFillModeSolid);
	Novice::DrawBox(atacckPosX_, atacckPosY_, 1280, 150, 0, RED, kFillModeSolid);

	//Novice::ScreenPrintf(0, 60, "%d", shakeFlag_);
}
void Enemy::Oncollision()
{
		color_ = BLACK;
}

void Enemy::Nocollision()
{
	color_ = WHITE;
}
