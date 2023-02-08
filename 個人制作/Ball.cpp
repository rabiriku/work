#include "Ball.h"
#include <Novice.h>


void Ball::Initialize(int x, int y)
{
	pos_.x = x;
	pos_.y = y;
	radius_ = 10;
	speedX_ = 0;
	speedY_ = 5;
	enebub_ = Novice::LoadTexture("./resouces/images/ene.png");
}



void Ball::Update()
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


void Ball::Draw()
{
	Novice::DrawSprite(pos_.x - radius_, pos_.y - radius_, enebub_, 1, 1, 0, 0xFFFFFFFF);
}
