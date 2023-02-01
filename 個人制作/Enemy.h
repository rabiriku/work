#pragma once
#include"Player.h"

/// <summary>
/// �G
/// </summary>
class Enemy {
public:
	void Initialize();

	void Initialize(int x, int y);

	void Update();

	void Update2();

	void Update(char* keys);

	void Draw();

	void Draw2();

	void Oncollision();

	void Nocollision();

	void Parry(char*keys);
	//�A�N�Z�b�T
	Vector2 GetPosition() { return pos_; }
	int Getradius() { return radius_; }

	
private:
	
	Vector2 pos_;


	int radius_;
	unsigned int color_;
	int speedX_;
	int speedY_;

	int shakeTime_;
	int reshakeTime;
	int randX_ = 0;
	int randY_ = 0;
	int shakeFlag_;
	int atacckPosX_;
	int atacckPosY_;

	
};