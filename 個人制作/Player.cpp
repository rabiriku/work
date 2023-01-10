#include "player.h"
#include"map.h"
#include<Novice.h>

void Player::Initialize()
{
	posX_ = 32;
	posY_ = 35;
	radius_ = 10;
	speedX_ = 5;
	speedY_ = -5;
	color_ = WHITE;
	jampflag_ = 0;
	speedtmp_ = 5;
	effectflag = 0;
}

void Player::Plly(char* keys) {
	if (keys[DIK_E]) {

	}



}

void Player::Jamp(char* keys) {
	if (keys[DIK_SPACE] && posY_ - radius_ <= 40) {
		jampflag_ = 1;
	}
	if (keys[DIK_SPACE]&& posY_ + radius_ >= 750) {
		jampflag_ = 2;
	}
	if (jampflag_ == 1) {
		jampspeed_ = 7;

		posY_ += jampspeed_;
		rightTopY = (posX_ - speedtmp_ - radius_) / 32;
		leftTopY = (posY_ -speedtmp_- radius_) / 32;
		
	}
	if (jampflag_ == 2) {
		jampspeed_ = 7;
		jampspeed_ *= -1;
		posY_ += jampspeed_;
		rightTopY = (posX_ - speedtmp_ - radius_) / 32;
		leftTopY = (posY_ - speedtmp_ - radius_) / 32;

	}
	if (posY_ + radius_ >= 768) {
		jampspeed_ = 0;
		jampflag_ = 0;
	}
	if (posY_ - radius_ <= 32) {
		jampflag_ = 0;
		jampspeed_ = 0;
	}
}

void Player::Update(char* keys)
{
	if (keys[DIK_W]) {
		posY_ += speedY_;
	}
	if (keys[DIK_S]) {
		posY_ -= speedY_;
	}
	if (keys[DIK_A]) {
		posX_ -= speedX_;
	}
	if (keys[DIK_D]) {
		posX_ += speedX_;
	}

	rightTopY = (posX_ - radius_) / 32;
	rightTopX = (posX_ + radius_ - 1) / 32;
	rightBottomX = (posX_ + radius_ - 1) / 32;
	rightBottomY = (posY_ + radius_ - 1) / 32;
	leftTopY = (posY_ - radius_) / 32;
	leftTopX = (posX_ - radius_) / 32;
	leftBottomX = (posX_ - radius_) / 32;
	leftBottomY = (posY_ + radius_ - 1) / 32;

}


void Player::Draw()
{
	//Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, color_, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "%d", jampflag_);
	Novice::ScreenPrintf(0, 20, "%d", posX_);
	if (posY_ - radius_ <= 35){
		Novice::DrawSprite(posX_-radius_, posY_-radius_, playerright, 1, 1, 0, WHITE);
	}
	if (posY_ + radius_ >= 760) {
		Novice::DrawSprite(posX_ - 3*radius_, posY_ - 3*radius_, playerdownright, 1, 1, 0, WHITE);
	}

	if (jampflag_ == 1) {
		Novice::DrawSprite(posX_ - radius_, posY_ - radius_, playerjamp2, 1, 1, 0, WHITE);
	}
	if (jampflag_ == 2) {
		Novice::DrawSprite(posX_ - radius_, posY_ - radius_, playerjamp1, 1, 1, 0, WHITE);
	}
}

void Player::Oncollision() 
{
	Novice::DrawBox(0, 0, 1280, 800, 0, 0x11111159, kFillModeSolid);

}
