#pragma once
class Player {
public:
	void Initialize();

	void Update(char* keys);

	void Draw();

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
