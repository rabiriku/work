#include <Novice.h>
#include "Enemy.h"
#include"Player.h"
#include"map.h"
const char kWindowTitle[] = "GC1A_03_ウエダリクト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 800);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };



	Enemy enemy;
	Enemy enemy2;
	Player player;
	Map map;
	enemy.Initialize();
	player.Initialize();
	enemy2.Initialize(160, 200);
	map.Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		//player.Col(map.GetmapFlag());
		
		//enemy.Update2();
		player.Update(keys);

		//player.Update();
		enemy2.Update();

		//map.Colplayer(player.GetPosition(), player.Getradius());
		//map.ColBottom(player.GetVertex());
		//map.ColTop(player.GetVertex());
		

		// 当たっていたら1 当たってなかったら0
		if (map.BlockBottomCollison(player.GetHightVertex())) {
			player.SetUnderPos(map.GetBlockSize());
		}
		else {
			player.Fall();
		}
		
		if (map.BlockLeftCollision(player.GetSideVertex())) {
			player.SetLeftPos(map.GetBlockSize());
		}

		if (map.BlockRightCollision(player.GetSideVertex())) {
			player.SetRightPos(map.GetBlockSize());
		}
		if (map.BlockTopCollision(player.GetHightVertex())) {
			player.SetHightpos(map.GetBlockSize());
		}

		if (map.GoalBottomCollision(player.GetHightVertex())) {
			player.Col();
		}

		if (map.GoalLeftCollision(player.GetSideVertex())) {
			player.Col();
		}

		if (map.GoalRightCollision(player.GetSideVertex())) {
			player.Col();
		}
		
		if (map.GoalTopCollision(player.GetHightVertex())) {
			player.Col();
		}

		float dx = enemy2.GetPosition().x - player.GetPosition().x;
		float dy = enemy2.GetPosition().y - player.GetPosition().y;
		
		float d = dx * dx + dy * dy;
		float dis = player.Getradius() + enemy2.Getradius();
		if (d <= dis*dis) {
			player.Oncollision();
			enemy2.Oncollision();
		}
		if (d <= (dis * dis) + 400) {
			player.Parry(keys);
			
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		//enemy.Draw();
		map.Draw();
		//enemy.Draw2();
		enemy2.Draw();
		player.Draw();
	
		//Novice::ScreenPrintf(0, 40, "%f", dis*dis);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
