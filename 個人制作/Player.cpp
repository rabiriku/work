#include "map.h"
#include<Novice.h>

Map map_;
void Player::Initialize()
{
	posX_ = 32;
	posY_ = 700;
	radius_ = 16;
	speedX_ = 5;
	speedY_ = 5;
	color_ = WHITE;
	jampFlag_ = 0;
	jampSpeed_ = 15;
	speedtmp_ = 5;
	effectFlag_ = 0;
	effectTime_ = 10;
	playerHp_ = 5;
	parryFlag_ = 0;
	invincibleTime_ = 180;
	rightTopY_ = (posX_ - radius_) / 32;
	rightTopX_ = (posX_ + radius_ - 1) / 32;
	rightBottomX_ = (posX_ + radius_ - 1) / 32;
	rightBottomY_ = (posY_ + radius_ - 1) / 32;
	leftTopY_ = (posY_ - radius_) / 32;
	leftTopX_ = (posX_ - radius_) / 32;
	leftBottomX_ = (posX_ - radius_) / 32;
	leftBottomY_ = (posY_ + radius_ - 1) / 32;
	

	playerright = Novice::LoadTexture("./player2.png");
	playerdownright = Novice::LoadTexture("./player.png");
	playerjamp1 = Novice::LoadTexture("./player4.png");
	playerjamp2 = Novice::LoadTexture("./player5.png");

}

void Player::Parry(char* keys) {
	if (keys[DIK_E]) {
			effectFlag_ = 1;
			parryFlag_ = 1;
			jampFlag_ = 0;
			Sleep(200);
	}
}

void Player::Update() {
	rightTopY_ = (posY_ - radius_) / 32;
	rightTopX_ = (posX_ + radius_ - 1) / 32;
	rightBottomX_ = (posX_ + radius_ - 1) / 32;
	//rightBottomY_ = (posY_ + radius_ - 1) / 32;
	leftTopY_ = (posY_ - radius_) / 32;
	leftTopX_ = (posX_ - radius_) / 32;
	leftBottomX_ = (posX_ - radius_) / 32;
	//leftBottomY_ = (posY_ + radius_ - 1) / 32;
	leftBottomY_ = (posY_ -jampSpeed_+radius_ -1) / 32;
	rightBottomY_ = (posY_ -jampSpeed_+ radius_-1) / 32;
}

void Player::Jamp(char* keys) {
	if (keys[DIK_SPACE]) {
		jampFlag_ = 1;
	}
	//if (keys[DIK_SPACE]) {
	//	jampFlag_ = 1;
	//}
	//if (keys[DIK_SPACE]&& posY_ + radius_ >= 720) {
	//	jampFlag_ = 2;
	//}
	//
	//if (mapflag_ == 1) {
	//	jampFlag_ = 0;
	//	jampSpeed_ = 0;
	//}
	//
	if (jampFlag_ == 1) {
		posY_ -= jampSpeed_;
		jampSpeed_ -= 1;

	}
	if (mapflag_==1) {
		jampFlag_ = 0;
		jampSpeed_ = 15;
	}
	if (jampFlag_ == 0) {
		jampSpeed_ = 15;
	}
	////if (jampFlag_ == 2) {
	////	jampSpeed_ = 10;
	////	jampSpeed_ *= -1;
	////	posY_ += jampSpeed_;
	////
	////}
	//
	////if (posY_ + radius_ >= 768) {
	////	jampSpeed_ = 0;
	////	jampFlag_ = 0;
	////}
	//if (posY_ - radius_ <= 32) {
	//	jampFlag_ = 0;
	//	jampSpeed_ = 0;
	//}
	
}

void Player::Update(char* keys)
{
	//if (mapflag_ == 1) {
	//	speedY_ = 0;
	//}
	//if (mapflag_ == 0) {
	//	speedY_ = 5;
	//}
	if (keys[DIK_A]) {
		posX_ -= speedX_;
	}
	if (keys[DIK_D]) {
		posX_ += speedX_;
	}
	if (keys[DIK_W]) {
		posY_ -= speedY_;
	}
	if (keys[DIK_S]) {
		
		posY_ += speedY_;
	}
	if (effectFlag_ == 1) {
		effectTime_ -= 1;
		if (effectTime_ < 0) {
			effectFlag_ = 0;
			effectTime_ = 10;
		}
	}
	if (parryFlag_ == 1) {
		invincibleTime_ -= 1;
		if (invincibleTime_ < 0) {
			parryFlag_ = 0;
			invincibleTime_ = 60;
		}
	}

}



void Player::Draw()
{
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, color_, kFillModeSolid);
	Novice::DrawSprite(posX_-radius_*2, posY_-radius_*2, playerdownright, 1, 1, 0, WHITE);
	Novice::ScreenPrintf(0, 0, "%d", jampFlag_);
	Novice::ScreenPrintf(0, 20, "%d", jampSpeed_);
	Novice::ScreenPrintf(0, 100, "%d", effectTime_);
	Novice::ScreenPrintf(0, 120, "%d", effectFlag_);
	Novice::ScreenPrintf(0, 140, "%d", playerHp_);
	Novice::ScreenPrintf(50, 160, "rightbottom%d %d", rightBottomY_,rightBottomX_);
	Novice::ScreenPrintf(50, 200, "righttop%d,%d", rightTopY_,rightTopX_);
	Novice::ScreenPrintf(50, 180, "leftbottom%d %d", leftBottomY_,leftBottomX_);
	Novice::ScreenPrintf(50, 220, "ledttop%d %d", leftTopY_,leftTopX_);
	//Novice::ScreenPrintf(0, 180, "%d", map_.GetmapFlag());

	if (posY_ - radius_ <= 35){
		Novice::DrawSprite(posX_-radius_, posY_-radius_, playerright, 1, 1, 0, WHITE);
	}
	if (posY_ + radius_ >= 768) {
		Novice::DrawSprite(posX_ - 3*radius_, posY_ - 3*radius_, playerdownright, 1, 1, 0, WHITE);
	}

	if (jampFlag_ == 1) {
		Novice::DrawSprite(posX_ - radius_, posY_ - radius_, playerjamp2, 1, 1, 0, WHITE);
	}
	if (jampFlag_ == 2) {
		Novice::DrawSprite(posX_ - radius_, posY_ - radius_, playerjamp1, 1, 1, 0, WHITE);
	}
	
	if (effectFlag_ == 1) {
		Novice::DrawBox(0, 0, 1280, 800, 0, 0xFFFFFF64, kFillModeSolid);
	}
}

void Player::Col(int x)
{
	mapflag_ = x;
	
}

void Player::Oncollision(char*keys) 
{
	if (parryFlag_ == 0) {
		playerHp_ -= 1;
	}
}
