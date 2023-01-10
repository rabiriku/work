#pragma once
//#include"bullet.h"
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

	int shaketime_;
	int reshaketime;
	int randX_ = 0;
	int randY_ = 0;
	int shakeflag_;
	int atacckposX_;
	int atacckposY_;
};