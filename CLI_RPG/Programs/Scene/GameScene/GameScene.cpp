#include "GameScene.hpp"
#include <iostream>
#include "../../System/View/View.hpp"
#include "../../System/Input/InputManager.hpp"
#include "MoveState/MoveState.hpp"

InGame::GameScene::GameScene()
{
	Text::View::Instance().Text("GameScene", Text::Color::Green);
	// マップ読み込み
	dungeonMap = std::unique_ptr<DungeonMap>(new DungeonMap());
	// ファイル読み込み
	dungeonMap->LoadFromCSV("Assets/Data/Mapdata.csv");
	// シーンの設定
	ChangeState(std::make_unique<MoveState>());
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
	std::cout << name << std::endl;
}
