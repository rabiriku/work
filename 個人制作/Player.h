#pragma once

/// <summary>
/// �v���C���[
/// </summary>
class Player {
public:
	
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();
	/// <summary>
	/// ���E�ړ�
	/// </summary>
	/// <param name="keys"></param>
	void Update(char* keys);
	void Update();
	/// <summary>
	/// �p���B
	/// </summary>
	/// <param name="keys"></param>
	void Parry(char* keys);
	/// <summary>
	/// �㉺�̕ǂɈړ�����
	/// </summary>
	/// <param name="keys"></param>
	void Jamp(char* keys);
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	/// <summary>
	/// map�����󂯎��
	/// </summary>
	/// <param name="mapflag"></param>
	void Col(int x);
	
	int GetposX() { return posX_; }
	int GetposY() { return posY_; }
	int Getradius() { return radius_; }
	int GetparryFlaf() { return parryFlag_; }

	int GetrightTopX() { return rightTopX_; }
	int GetrightTopY() { return rightTopY_; }
	int GetrightBottomX() { return rightBottomX_; }
	int GetrightBottomY() { return rightBottomY_; }
	int GetleftTopX() { return leftTopX_; }
	int GetleftTopY() { return leftTopY_; }
	int GetleftBottomX() { return leftBottomX_; }
	int GetleftBottomY() { return leftBottomY_; }
	int GetsppedX() { return speedX_; }

	void Oncollision(char*keys);
	private:	
	int posX_;
	int posY_;
	int rightTopX_;
	int rightTopY_;
	int rightBottomX_;
	int rightBottomY_;
	int leftTopY_;
	int leftTopX_;
	int leftBottomX_;
	int leftBottomY_;

	int radius_;
	unsigned int color_;
	int speedX_;
	int speedY_;
	int speedtmp_;

	int jampSpeed_;
	int jampFlag_;

	int parryFlag_;
	int invincibleTime_;

	int effectFlag_;
	int effectTime_;

	int playerHp_;


	int playerright;
	int playerdownright;
	int  playerjamp1;
	int  playerjamp2;

	int mapflag_;
	int map1_;
};
