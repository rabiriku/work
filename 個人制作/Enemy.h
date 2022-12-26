#pragma once
//#include"bullet.h"
class Enemy {
public:
	void Initialize();

	void Initialize(int x, int y);

	void Update();

	void Update(char* keys);

	void Draw();

	void Oncollision();

	void Nocollision();
	//アクセッサ
	int GetposX() { return posX_; }
	int GetposY() { return posY_; }
	int Getradius() { return radius_; }


private:
	int posX_;
	int posY_;

	int radius_;
	unsigned int color_;
	int speedX_;
	int speedY_;


};