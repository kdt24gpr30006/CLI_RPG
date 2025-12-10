#include "GameScene.hpp"
#include <iostream>
#include "../../System/View/View.hpp"

GameScene::GameScene() {
	Text::View::Instance().Text("GameScene", Text::Color::Green);
	// マップ読み込み
	dungeonMap = std::unique_ptr<DungeonMap>(new DungeonMap());
	// ファイル読み込み
	dungeonMap->LoadFromCSV("Assets/Data/Mapdata.csv");
}

GameScene::~GameScene() {
}

void GameScene::Update() {
}

void GameScene::Render()
{
	dungeonMap->Render();
	// キー入力待ち　マップ確認用
	int a;
	std::cin >> a;
	dungeonMap->ChangeFloor(a);
}
