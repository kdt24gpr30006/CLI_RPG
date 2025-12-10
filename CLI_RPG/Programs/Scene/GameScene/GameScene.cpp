#include "GameScene.hpp"
#include <iostream>
#include "../../System/View/View.hpp"
#include "../../System/Input/InputManager.hpp"

GameScene::GameScene() {
	Text::View::Instance().Text("GameScene", Text::Color::Green);
	// マップ読み込み
	dungeonMap = std::unique_ptr<DungeonMap>(new DungeonMap());
	// ファイル読み込み
	dungeonMap->LoadFromCSV("Assets/Data/Mapdata.csv");

	// 初期化
	player = std::make_shared<PlayerData>();
	player->x = 1;
	player->y = 1;
}

GameScene::~GameScene() {
}

void GameScene::Update() {
    // 移動処理（矢印キーが効かない場合に備えて WASD をフォールバックで使う）
    auto tryMove = [&](int dx, int dy) {
        int nx = player->x + dx;
        int ny = player->y + dy;
        int tile = dungeonMap->GetTile(nx, ny);
        if (tile == 1) {
            Text::View::Instance().Text("壁がある。移動できない。");
            return;
        }
        if (tile == 2) {
            Text::View::Instance().Text("敵がいる。攻撃してから進め。");
            return;
        }
        player->x = nx;
        player->y = ny;
        };

    // 矢印キーまたは WASD のどちらかで移動判定
    if (InputManager::Instance().IsKeyPressed(KeyCode::Up) || InputManager::Instance().IsKeyPressed(KeyCode::W)) {
        tryMove(0, -1);
    }
    else if (InputManager::Instance().IsKeyPressed(KeyCode::Down) || InputManager::Instance().IsKeyPressed(KeyCode::S)) {
        tryMove(0, 1);
    }
    else if (InputManager::Instance().IsKeyPressed(KeyCode::Left) || InputManager::Instance().IsKeyPressed(KeyCode::A)) {
        tryMove(-1, 0);
    }
    else if (InputManager::Instance().IsKeyPressed(KeyCode::Right) || InputManager::Instance().IsKeyPressed(KeyCode::D)) {
        tryMove(1, 0);
    }

    // 攻撃処理（Zキー）
    if (InputManager::Instance().IsKeyDown(KeyCode::Z)) {
        const int dirs[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
        bool attacked = false;
        for (auto& d : dirs) {
            int tx = player->x + d[0];
            int ty = player->y + d[1];
            if (dungeonMap->GetTile(tx, ty) == 2) {
                dungeonMap->SetTile(tx, ty, 0);
                Text::View::Instance().Text("敵を攻撃して倒した！", Text::Color::Yellow);
                attacked = true;
                break;
            }
        }
        if (!attacked) {
            Text::View::Instance().Text("攻撃したが敵はいなかった。");
        }
    }
}

void GameScene::Render()
{
	Text::View::Instance().Clear();

	dungeonMap->Render();

    Text::View::Instance().Text("Player 位置: (" + std::to_string(player->x) + "," + std::to_string(player->y) + ")  HP:" + std::to_string(player->hp) + " ATK:" + std::to_string(player->atk), Text::Color::Blue);

	// キー入力待ち　マップ確認用
//	int a;
//	std::cin >> a;
//	dungeonMap->ChangeFloor(a);
}
