#pragma once
#include"Player.h"

/// <summary>
/// �{�[��
/// </summary>
class Ball {
public:

	void Initialize(int x, int y);

	void Update();

	void Draw();

	//�A�N�Z�b�T
	Vector2 GetPosition() { return pos_; }
	int Getradius() { return radius_; }

	
private:
	
	Vector2 pos_;


	int radius_;
	int speedX_;
	int speedY_;

	int enebub_;
};