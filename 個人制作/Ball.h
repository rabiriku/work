#pragma once
#include"Player.h"

/// <summary>
/// �G
/// </summary>
class Ball {
public:

	void Initialize(int x, int y);

	void Update();

	void Draw();

	void Nocollision();

	//�A�N�Z�b�T
	Vector2 GetPosition() { return pos_; }
	int Getradius() { return radius_; }

	
private:
	
	Vector2 pos_;


	int radius_;
	unsigned int color_;
	int speedX_;
	int speedY_;

	int enebub_;
};