#include "GameScene.hpp"
#include <iostream>
#include "../../System/View/View.hpp"
#include "../../System/Input/InputManager.hpp"
#include "MoveState/MoveState.hpp"
#include "../../Chara/CharaFactory/CharaFactory.hpp"
#include "../../Chara/Skill/Skill.h"
#include "../../Chara/skill/AttackSkill/ShadowBall/ShadowBall.hpp"
#include "../../Chara/skill/AttackSkill/AttackSkill.hpp"

InGame::GameScene::GameScene()
{
	Text::View::Instance().System("GameScene");
	// マップ読み込み
	dungeonMap = std::unique_ptr<DungeonMap>(new DungeonMap());
	// ファイル読み込み
//	dungeonMap->LoadFromCSV("Assets/Data/Mapdata.csv");
	// プレイヤーキャラクター生成
	CharaFactory factory = CharaFactory();
	playerChar.push_back(factory.CreateChara(CharaType::YUUSHA));

	// スキル(シャドウボール)追加
	playerChar[0]->AddSkill(std::make_unique<ShadowBall>());

	// シーンの設定
	ChangeState(std::make_unique<MoveState>(*this));
	// 戦闘描画生成
	battleRenderer = std::make_unique<BattleRenderer>();
	// アイテムマネージャー生成
	itemManager = std::make_unique<ItemManager>();

	itemdata potionData;
	potionData.name = "Potion";
	potionData.heel_value = 50;

	// ItemManagerを通じてアイテムを追加
	// とりあえず５個ぶち込む
	for (int i = 0; i < 5; i++)
	{
		itemManager->AddItem(std::make_unique<Item>(potionData));
	}
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
