#include "map.h"
#include<Novice.h>

Map map_;
void Player::Initialize()
{
	pos_.x = 64;
	pos_.y = 800 - 32 -16;
	radius_ = 16;
	speed_.x = 5;
	speed_.y = 5;
	VertexUpdate();

	color_ = WHITE;
	isJump_ = 0;
	jumpSpeed_ = kJumpPower;
	speedtmp_ = 5;
	effectFlag_ = 0;
	effectTime_ = 10;
	playerHp_ = 5;
	parryFlag_ = 0;
	invincibleTime_ = 180;


	playerright = Novice::LoadTexture("./player2.png");
	playerdownright = Novice::LoadTexture("./player.png");
	playerjamp1 = Novice::LoadTexture("./player4.png");
	playerjamp2 = Novice::LoadTexture("./player5.png");

}

void Player::Parry(char* keys) {
	if (keys[DIK_E]) {
		effectFlag_ = 1;
		parryFlag_ = 1;
		isJump_ = 0;
		Sleep(160);
	}
}


void Player::VertexUpdate()
{
	sideVertex_.rightTop.x = (pos_.x + radius_ - 1) / 32;
	sideVertex_.rightTop.y = (pos_.y - radius_ + 1) / 32;
	sideVertex_.rightBottom.x = (pos_.x + radius_ - 1) / 32;
	sideVertex_.rightBottom.y = (pos_.y + radius_ - 3) / 32;

	sideVertex_.leftTop.x = (pos_.x - radius_) / 32;
	sideVertex_.leftTop.y = (pos_.y - radius_ + 1) / 32;
	sideVertex_.leftBottom.x = (pos_.x - radius_) / 32;
	sideVertex_.leftBottom.y = (pos_.y + radius_ - 3) / 32;

	hightVertex_.rightTop.x = (pos_.x + radius_ - 6) / 32;
	hightVertex_.rightTop.y = (pos_.y - radius_) / 32;
	hightVertex_.rightBottom.x = (pos_.x + radius_ - 6) / 32;
	hightVertex_.rightBottom.y = (pos_.y + radius_) / 32;

	hightVertex_.leftTop.x = (pos_.x - radius_ + 5) / 32;
	hightVertex_.leftTop.y = (pos_.y - radius_) / 32;
	hightVertex_.leftBottom.x = (pos_.x - radius_ + 5) / 32;
	hightVertex_.leftBottom.y = (pos_.y + radius_) / 32;
}

void Player::Jamp(char* keys) {
	if (keys[DIK_SPACE] && !isJump_) {
		isJump_ = 1;
		jumpSpeed_ = kJumpPower;
	}

	if (isJump_) {
		pos_.y -= jumpSpeed_;
		jumpSpeed_ -= 1;
	}
}

void Player::Update(char* keys)
{

	if (keys[DIK_A] && pos_.x - radius_ > 32) {
		pos_.x -= speed_.x;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_.x;
	}
	Jamp(keys);
	VertexUpdate();
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

	if (isJump_ == 1) {
		Novice::DrawSprite(pos_.x - radius_, pos_.y - radius_, playerjamp2, 1, 1, 0, WHITE);
	}
	if (isJump_ == 2) {
		Novice::DrawSprite(pos_.x - radius_, pos_.y - radius_, playerjamp1, 1, 1, 0, WHITE);
	}

	if (effectFlag_ == 1) {
		Novice::DrawBox(0, 0, 1280, 800, 0, 0xFFFFFF64, kFillModeSolid);
	}
#ifdef _DEBUG
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	//Novice::DrawSprite(pos_.x - radius_ * 2, pos_.y- radius_ * 2, playerdownright, 1, 1, 0, WHITE);
	Novice::ScreenPrintf(0, 0, "jumoFlag : %d", radius_);
	Novice::ScreenPrintf(0, 20, "pos : [%d,%d]", pos_.x, pos_.y);
	Novice::ScreenPrintf(0, 40, "SideLeftTop : [%d,%d]", sideVertex_.leftTop.x, sideVertex_.leftTop.y);
	Novice::ScreenPrintf(0, 60, "SideLeftBotoom : [%d,%d]", sideVertex_.leftBottom.x, sideVertex_.leftBottom.y);
	Novice::ScreenPrintf(0, 80, "SideRightTop : [%d,%d]", sideVertex_.rightTop.x, sideVertex_.rightTop.y);
	Novice::ScreenPrintf(0, 100, "SideLeftBottom : [%d,%d]", sideVertex_.rightBottom.x, sideVertex_.rightBottom.y);

	/*Novice::DrawEllipse(sideVertex_.leftTop.x, sideVertex_.leftTop.y, 2, 2, 0.0f, RED, kFillModeSolid);
	Novice::DrawEllipse(sideVertex_.leftBottom.x, sideVertex_.leftBottom.y, 2, 2, 0.0f, RED, kFillModeSolid);
	Novice::DrawEllipse(sideVertex_.rightBottom.x, sideVertex_.rightBottom.y, 2, 2, 0.0f, RED, kFillModeSolid);
	Novice::DrawEllipse(sideVertex_.rightTop.x, sideVertex_.rightTop.y, 2, 2, 0.0f, RED, kFillModeSolid);*/


#endif
}

void Player::Col(int x)
{
	//mapflag_ = x;
}

void Player::SetHightpos(int Blocksize)
{
	pos_.y = hightVertex_.leftTop.y * Blocksize + Blocksize + radius_;
	jumpSpeed_ = 0;	// —Ž‰º‚³‚¹‚é
	VertexUpdate();
}

void Player::SetUnderPos(int BlockSize)
{
	pos_.y = hightVertex_.leftBottom.y * BlockSize - radius_;
	isJump_ = false;
	VertexUpdate();
}

void Player::SetLeftPos(int Blocksize)
{
	pos_.x = sideVertex_.leftBottom.x * Blocksize + Blocksize + radius_;
	VertexUpdate();
}

void Player::SetRightPos(int Blocksize)
{
	pos_.x = sideVertex_.rightBottom.x * Blocksize - radius_;
	VertexUpdate();
}

void Player::Fall()
{
	if (!isJump_) {
		isJump_ = true;
		jumpSpeed_ = 0;
	}
}



void Player::Oncollision(char* keys)
{
	if (parryFlag_ == 0) {
		playerHp_ -= 1;
	}
}