#include "player.h"
#include<Novice.h>

void Player::Initialize()
{
	posX_ = 200;
	posY_ = 200;
	radius_ = 10;
	speedX_ = 5;
	speedY_ = -5;
	color_ = WHITE;

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
}

void Player::Draw()
{
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, color_, kFillModeSolid);
}
