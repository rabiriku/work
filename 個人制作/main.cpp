#include <Novice.h>
#include "Enemy.h"
#include"player.h"
const char kWindowTitle[] = "GC1A_03_ウエダリクト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };



	Enemy enemy;
	Enemy enemy2;
	Player player;
	//enemy.Initialize();
	player.Initialize();
	enemy2.Initialize(200, 200);

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
		//enemy.Update(keys);
		player.Update(keys);
		enemy2.Update();

		//float dx = enemy2.GetposX() - enemy.GetposX();
		//float dy = enemy2.GetposY() - enemy.GetposY();
		//
		//float d = dx * dx + dy * dy;
		//if (d < enemy.Getradius() + enemy2.Getradius()) {
		//	enemy.Oncollision();
		//	enemy2.Oncollision();
		//}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		//enemy.Draw();
		enemy2.Draw();
		player.Draw();
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
