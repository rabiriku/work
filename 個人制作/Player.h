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
/// プレイヤー
/// </summary>
class Player {
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 左右移動
	/// </summary>
	/// <param name="keys"></param>
	void Update(char* keys);
	/// <summary>
	/// player当たり判定
	/// </summary>
	void VertexUpdate();

	/// <summary>
	/// パリィ
	/// </summary>
	/// <param name="keys"></param>
	void Parry(char* keys);
	/// <summary>
	/// 上下の壁に移動する
	/// </summary>
	/// <param name="keys"></param>
	void Jamp(char* keys);
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	//player詳細
	Vector2 GetPosition() { return pos_; }
	int Getradius() { return radius_; }
	int GetparryFlaf() { return parryFlag_; }

	//当たり判定取得
	Vertex GetSideVertex() { return sideVertex_; }
	Vertex GetHightVertex() { return hightVertex_; }

	//当たったら引き戻し
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


	// テクスチャ
	int playerright_;
	int playerleft_;
	
	//audio
	int parryaudio_;

};
