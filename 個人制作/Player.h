#pragma once
#include"map.h"
#include<Novice.h>
class Player {
public:
	void Initialize();

	void Update(char* keys);

	void Plly(char* keys);

	void Jamp(char* keys);

	void Draw();

	int GetposX() { return posX_; }
	int GetposY() { return posY_; }
	int Getradius() { return radius_; }

	void Oncollision();
	Map map_;
	
private:
	int posX_;
	int posY_;
	int rightTopX;
	int rightTopY;
	int rightBottomX;
	int rightBottomY;
	int leftTopY;
	int leftTopX;
	int leftBottomX;
	int leftBottomY;

	int radius_;
	unsigned int color_;
	int speedX_;
	int speedY_;
	int speedtmp_;

	int jampspeed_;
	int jampflag_;

	int effectflag;

	int playerright=Novice::LoadTexture("./player2.png");
	int playerdownright = Novice::LoadTexture("./player.png");
	int  playerjamp1 = Novice::LoadTexture("./player4.png");
	int  playerjamp2 = Novice::LoadTexture("./player5.png");



};
