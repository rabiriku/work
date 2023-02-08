#pragma once

struct Vector2 {
	int x;
	int y;
};

struct Vertex {
	Vector2 leftTop;
	Vector2 leftBottom;
	Vector2 rightTop;
	Vector2 rightBottom;
};

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
	/// <summary>
	/// player�����蔻��
	/// </summary>
	void VertexUpdate();

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

	//player�ڍ�
	Vector2 GetPosition() { return pos_; }
	int Getradius() { return radius_; }
	int GetparryFlaf() { return parryFlag_; }

	//�����蔻��擾
	Vertex GetSideVertex() { return sideVertex_; }
	Vertex GetHightVertex() { return hightVertex_; }

	//��������������߂�
	void SetHightpos(int Blocksize);
	void SetUnderPos(int Blocksize);
	void SetLeftPos(int Blocksize);
	void SetRightPos(int Blocksize);
	void Fall();

	
private:


	Vector2 pos_;
	Vertex sideVertex_;
	Vertex hightVertex_;
	Vector2 speed_;


	int radius_;
	unsigned int color_;

	int speedtmp_;

	const int kJumpPower = 15;
	int jumpSpeed_;
	int isJump_;

	int playerdirection_;

	int parryFlag_;
	int invincibleTime_;

	int effectFlag_;
	int effectTime_;


	// �e�N�X�`��
	int playerright_;
	int playerleft_;
	
	//audio
	int parryaudio_;

};
