#include "GameScene.hpp"
#include <iostream>
#include "../../System/View/View.hpp"
#include "../../System/Input/InputManager.hpp"
#include "MoveState/MoveState.hpp"
#include "../../Chara/CharaFactory/CharaFactory.h"

InGame::GameScene::GameScene()
{
	Text::View::Instance().System("GameScene");
	// マップ読み込み
	dungeonMap = std::unique_ptr<DungeonMap>(new DungeonMap());
	// ファイル読み込み
	dungeonMap->LoadFromCSV("Assets/Data/Mapdata.csv");
	// プレイヤーキャラクター生成
	CharaFactory factory = CharaFactory();
	playerChar.push_back(factory.CreateChara(CharaType::YUUSHA));
	// 敵キャラクター生成
	enemyChars.push_back(factory.CreateChara(CharaType::SLIME));
	enemyChars.push_back(factory.CreateChara(CharaType::GOBLIN));
	enemyChars.push_back(factory.CreateChara(CharaType::DRAGON));
	// シーンの設定
	ChangeState(std::make_unique<MoveState>());
	// 戦闘描画生成
	battleRenderer = std::make_unique<BattleRenderer>();
}

InGame::GameScene::~GameScene()
{
}

void InGame::GameScene::Update()
{
	currentState->Update(*this);
}

void InGame::GameScene::Render()
{
	currentState->Render(*this);
}

void InGame::GameScene::ChangeState(std::unique_ptr<GameState> newState)
{
	currentState = std::move(newState);
	std::string name = currentState->GetStateName();
	Text::View::Instance().System(name);
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}
