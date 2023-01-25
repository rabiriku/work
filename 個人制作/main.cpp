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
	enemy2.Initialize(200, 200);
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
		map.ColBottom(player.GetleftBottomX(), player.GetleftBottomY(), player.GetrightBottomX(), player.GetrightBottomY());
		map.ColTop(player.GetleftTopX(), player.GetleftTopY(), player.GetrightTopX(), player.GetrightTopY());
		player.Col(map.GetmapFlag());
		map.Updete();
		enemy.Update2();
		player.Update(keys);
		player.Jamp(keys);
		player.Update();
		enemy2.Update();

		
		

		float dx = enemy2.GetposX() - player.GetposX();
		float dy = enemy2.GetposY() - player.GetposY();
		
		float d = dx * dx + dy * dy;
		float dis = player.Getradius() + enemy2.Getradius();
		if (d <= dis*dis) {
			player.Oncollision(keys);
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
		enemy.Draw2();
		enemy2.Draw();
		player.Draw();
	
		Novice::ScreenPrintf(0, 40, "%f", dis*dis);
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
