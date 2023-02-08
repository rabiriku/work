#include <Novice.h>
#include "Ball.h"
#include"Player.h"
#include"map.h"
const char kWindowTitle[] = "Let's goal the way";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 800);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	float dx;
	float dy;
	float d;
	float dis;
	float dx2;
	float dy2;
	float d2;
	float dis2;

	int diffusionflag = 0;
	int No=0;
	int color = 0x00000000;
	int colorFlag = 0;
	int title = Novice::LoadTexture("./resouces/images/title.png ");
	int comprete= Novice::LoadTexture("./resouces/images/comprete.png ");
	int bgm= Novice::LoadAudio("./resouces/audio/bgm.mp3");
	enum scene {
		TITLE,
		GAME,
		GAME2,
		GAME3,
		COMPLETE,
	};
	Ball ball;
	Ball ball2;
	Player player;
	Map map;
	player.Initialize();
	ball.Initialize(600,200);
	ball2.Initialize(160, 400);
	map.Initialize();
	Novice::PlayAudio(bgm, 1, 0.02);
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
		switch (No)
		{
		case TITLE:
			player.Initialize();
			ball.Initialize(600, 200);
			ball2.Initialize(160, 400);
			map.Initialize();
			if (keys[DIK_SPACE]) {
				colorFlag = 1;
			}
			if (colorFlag == 1) {
				color += 0x00000003;
			}
			if (color > 0x000000fd) {
				No = GAME;
				color = 0x00000001;
				colorFlag = 0;
			}
			Novice::DrawSprite(0, 0, title, 1, 1, 0, WHITE);
			Novice::DrawBox(0, 0, 1280, 800, 0, color, kFillModeSolid);
			
			break;

		case GAME:
			player.Update(keys);

			ball.Update();
			ball2.Update();



			// 当たっていたら1 当たってなかったら0
			//当たり判定
			if (map.BlockBottomCollison(player.GetHightVertex())) {
				player.SetUnderPos(map.GetBlockSize());
			}
			else {
				player.Fall();
			}

			if (map.BlockTopCollision(player.GetHightVertex())) {
				player.SetHightpos(map.GetBlockSize());
			}

			if (map.BlockLeftCollision(player.GetSideVertex())) {
				player.SetLeftPos(map.GetBlockSize());
			}

			if (map.BlockRightCollision(player.GetSideVertex())) {
				player.SetRightPos(map.GetBlockSize());
			}
			

			if (map.GoalBottomCollision(player.GetHightVertex())) {
				No = GAME2;
				player.Initialize();
				ball.Initialize(270, 200);
				ball2.Initialize(170, 200);
				map.Initialize();
				map.GoalAudio();
			}

			if (map.GoalLeftCollision(player.GetSideVertex())) {
				No = GAME2;
				player.Initialize();
				ball.Initialize(220, 200);
				ball2.Initialize(150, 200);
				map.Initialize();
				map.GoalAudio();
			}

			if (map.GoalRightCollision(player.GetSideVertex())) {
				No = GAME2;
				player.Initialize();
				ball.Initialize(220, 200);
				ball2.Initialize(150, 200);
				map.Initialize();
				map.GoalAudio();
			}

			if (map.GoalTopCollision(player.GetHightVertex())) {
				No = GAME2;
				player.Initialize();
				ball.Initialize(220, 200);
				ball2.Initialize(150, 200);
				map.Initialize();
				map.GoalAudio();
			}

			 dx = ball2.GetPosition().x - player.GetPosition().x;
			 dy = ball2.GetPosition().y - player.GetPosition().y;

			 d = dx * dx + dy * dy;
			 dis = player.Getradius() + ball2.Getradius();
			if (d <= (dis * dis) + 400) {
				player.Parry(keys);

			}

			 dx2 = ball.GetPosition().x - player.GetPosition().x;
			 dy2 = ball.GetPosition().y - player.GetPosition().y;

			 d2 = dx2 * dx2 + dy2 * dy2;
			 dis2 = player.Getradius() + ball2.Getradius();
			if (d2 <= (dis2 * dis2) + 400) {
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
			ball.Draw();
			ball2.Draw();
			player.Draw();

			//Novice::ScreenPrintf(0, 40, "%f", dis*dis);
			///
			/// ↑描画処理ここまで
			///
			break;

		case GAME2:
			///
			/// ↓更新処理ここから
			///
			player.Update(keys);
			ball.Update();
			ball2.Update();

			// 当たっていたら1 当たってなかったら0
			//当たり判定
			if (map.BlockBottomCollison2(player.GetHightVertex()) || map.LockBottomCollision(player.GetHightVertex())) {
				player.SetUnderPos(map.GetBlockSize());
			}
			else {
				player.Fall();
			}

			if (map.BlockTopCollision2(player.GetHightVertex())) {
				player.SetHightpos(map.GetBlockSize());
			}

			if (map.BlockLeftCollision2(player.GetSideVertex())) {
				player.SetLeftPos(map.GetBlockSize());
			}

			if (map.BlockRightCollision2(player.GetSideVertex())) {
				player.SetRightPos(map.GetBlockSize());
			}


			if (map.GoalBottomCollision2(player.GetHightVertex())) {
				player.Initialize();
				ball.Initialize(160, 200);
				ball2.Initialize(1030, 200);
				map.KeyReturn(3, 36, 2, 3);
				map.GoalAudio();
				No = GAME3;
			}

			if (map.GoalLeftCollision2(player.GetSideVertex())) {
				player.Initialize();
				ball.Initialize(160, 200);
				ball2.Initialize(1030, 200);
				map.KeyReturn(3, 36, 2, 3);
				map.GoalAudio();
				No = GAME3;
			}

			if (map.GoalRightCollision2(player.GetSideVertex())) {
				player.Initialize();
				ball.Initialize(160, 200);
				ball2.Initialize(1030, 200);
				map.KeyReturn(3, 36, 2, 3);
				map.GoalAudio();
				No = GAME3;
			}

			if (map.GoalTopCollision2(player.GetHightVertex())) {
				player.Initialize();
				ball.Initialize(160, 200);
				ball2.Initialize(1030, 200);
				map.KeyReturn(3, 36, 2, 3);
				map.GoalAudio();
				No = GAME3;
			}

			if (map.KeyBottomCollision(player.GetHightVertex())) {
				map.KeyChange(3, 36, 2, 3);
				diffusionflag = 1;
			}

			if (map.KeyLeftCollision(player.GetSideVertex())) {
				map.KeyChange(3, 36, 2, 3);
				diffusionflag = 1;
			}

			if (map.KeyRightCollision(player.GetSideVertex())) {
				map.KeyChange(3, 36, 2, 3);
				diffusionflag = 1;
			}

			if (map.KeyTopCollision(player.GetHightVertex())) {
				map.KeyChange(3, 36, 2, 3);
				diffusionflag = 1;
			}

			if (diffusionflag == 1) {
				map.KeyCangeEfect(1168, 112);
				if (map.GetEfectFlag() == 0) {
					diffusionflag = 0;
				}
			}

			 dx = ball2.GetPosition().x - player.GetPosition().x;
			 dy = ball2.GetPosition().y - player.GetPosition().y;

			 d = dx * dx + dy * dy;
			 dis = player.Getradius() + ball2.Getradius();
			
			if (d <= (dis * dis) + 400) {
				player.Parry(keys);

			}

			 dx2 = ball.GetPosition().x - player.GetPosition().x;
			 dy2 = ball.GetPosition().y - player.GetPosition().y;

			 d2 = dx2 * dx2 + dy2 * dy2;
			 dis2 = player.Getradius() + ball2.Getradius();

			if (d2 <= (dis2 * dis2) + 400) {
				player.Parry(keys);

			}
			///
			/// ↑更新処理ここまで
			///
			///
			/// ↓描画処理ここから
			///
			map.Draw2();
			ball.Draw();
			ball2.Draw();
			player.Draw();

			
			/// 
			/// ↑描画処理ここから
			/// 
			break;

			case GAME3:
			///
			/// ↓更新処理ここから
			///
				player.Update(keys);

				ball.Update();
				ball2.Update();

				//当たり判定
				if (map.BlockBottomCollison3(player.GetHightVertex())||map.LockBottomCollision3(player.GetHightVertex())) {
					player.SetUnderPos(map.GetBlockSize());
				}
				else {
					player.Fall();
				}

				if (map.BlockTopCollision3(player.GetHightVertex()) || map.LockTopCollisio3(player.GetHightVertex())) {
					player.SetHightpos(map.GetBlockSize());
				}

				if (map.BlockLeftCollision3(player.GetSideVertex())|| map.LockLeftCollision3(player.GetSideVertex())) {
					player.SetLeftPos(map.GetBlockSize());
				}

				if (map.BlockRightCollision3(player.GetSideVertex())|| map.LockRightCollision3(player.GetSideVertex())) {
					player.SetRightPos(map.GetBlockSize());
				}


				if (map.GoalBottomCollision3(player.GetHightVertex())) {
					No = COMPLETE;
					map.GoalAudio();
					map.KeyReturn2(15, 1, 15, 2, 22, 34);
					map.KeyReturn3(9, 33, 10, 33, 12, 3);
					map.KeyReturn4(5, 25, 5, 26, 12, 36);
				}

				if (map.GoalLeftCollision3(player.GetSideVertex())) {
					No = COMPLETE;
					map.GoalAudio();
					map.KeyReturn2(15, 1, 15, 2, 22, 34);
					map.KeyReturn3(9, 33, 10, 33, 12, 3);
					map.KeyReturn4(5, 25, 5, 26, 12, 36);
				}

				if (map.GoalRightCollision3(player.GetSideVertex())) {
					No = COMPLETE;
					map.GoalAudio();
					map.KeyReturn2(15, 1, 15, 2, 22, 34);
					map.KeyReturn3(9, 33, 10, 33, 12, 3);
					map.KeyReturn4(5, 25, 5, 26, 12, 36);
				}

				if (map.GoalTopCollision3(player.GetHightVertex())) {
					No = COMPLETE;
					map.GoalAudio();
					map.KeyReturn2(15, 1, 15, 2, 22, 34);
					map.KeyReturn3(9, 33, 10, 33, 12, 3);
					map.KeyReturn4(5, 25, 5, 26, 12, 36);
				}

				if (map.KeyBottomCollision3(player.GetHightVertex())) {
					map.KeyCange2(15, 1, 15, 2, 22, 34);
					diffusionflag = 1;
				}

				if (map.KeyLeftCollision3(player.GetSideVertex())) {
					map.KeyCange2(15, 1, 15, 2, 22, 34);
					diffusionflag = 1;
				}

				if (map.KeyRightCollision3(player.GetSideVertex())) {
					map.KeyCange2(15, 1, 15, 2, 22, 34);
					diffusionflag = 1;
				}

				if (map.KeyTopCollision3(player.GetHightVertex())) {
					map.KeyCange2(15, 1, 15, 2, 22, 34);
					diffusionflag = 1;
				}

				if (map.KeyBottomCollision5(player.GetHightVertex())) {
					map.KeyCange2(9, 33, 10, 33, 12, 3);
					diffusionflag = 2;
				}

				if (map.KeyLeftCollision5(player.GetSideVertex())) {
					map.KeyCange2(9, 33, 10, 33, 12, 3);
					diffusionflag = 2;
				}

				if (map.KeyRightCollision5(player.GetSideVertex())) {
					map.KeyCange2(9, 33, 10, 33, 12, 3);
					diffusionflag = 2;
				}

				if (map.KeyTopCollision5(player.GetHightVertex())) {
					map.KeyCange2(9, 33, 10, 33, 12, 3);
					diffusionflag = 2;
				}

				if (map.KeyBottomCollision6(player.GetHightVertex())) {
					map.KeyCange2(5, 25, 5, 26, 12, 36);
					diffusionflag = 3;
				}

				if (map.KeyLeftCollision6(player.GetSideVertex())) {
					map.KeyCange2(5, 25, 5, 26, 12, 36);
					diffusionflag = 3;
				}

				if (map.KeyRightCollision6(player.GetSideVertex())) {
					map.KeyCange2(5, 25, 5, 26, 12, 36);
					diffusionflag = 3;
				}

				if (map.KeyTopCollision6(player.GetHightVertex())) {
					map.KeyCange2(5, 25, 5, 26, 12, 36);
					diffusionflag = 3;
				}
				if (diffusionflag == 1) {
					map.KeyCangeEfect(64, 464);
					if (map.GetEfectFlag() == 0) {
						diffusionflag = 0;
					}
				}
				if (diffusionflag == 2) {
					map.KeyCangeEfect(1040, 320);
					if (map.GetEfectFlag() == 0) {
						diffusionflag = 0;
					}
				}
					if (diffusionflag == 3) {
						map.KeyCangeEfect(832, 176);
						if (map.GetEfectFlag() == 0) {
							diffusionflag = 0;
						}
					}
				dx = ball2.GetPosition().x - player.GetPosition().x;
				dy = ball2.GetPosition().y - player.GetPosition().y;

				d = dx * dx + dy * dy;
				dis = player.Getradius() + ball2.Getradius();
				
				if (d <= (dis * dis) + 400) {
					player.Parry(keys);

				}

				dx2 = ball.GetPosition().x - player.GetPosition().x;
				dy2 = ball.GetPosition().y - player.GetPosition().y;

				d2 = dx2 * dx2 + dy2 * dy2;
				dis2 = player.Getradius() + ball2.Getradius();
				
				if (d2 <= (dis2 * dis2) + 400) {
					player.Parry(keys);

				}
			///
			/// ↑更新処理ここまで
			///
			///
			/// ↓描画処理ここから
			///
				Novice::ScreenPrintf(0, 0, "%d", diffusionflag);
				map.Draw3();
				ball.Draw();
				ball2.Draw();
				player.Draw();
			/// 
			/// ↑描画処理ここから
			/// 
			break;

			case COMPLETE:
				if (keys[DIK_RETURN]) {
					No = TITLE;
				}

				
				Novice::DrawSprite(0, 0, comprete, 1, 1, 0.0f, WHITE);
				break;
		}
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
