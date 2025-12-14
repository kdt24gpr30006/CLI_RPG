#include "BattleState.hpp"
#include "../MoveState/MoveState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/CharaFactory/CharaFactory.h"

InGame::BattleState::BattleState()
{
	stateName = "Battle";
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
	CharaFactory factory = CharaFactory();
	// 敵キャラクター生成
	enemyChars.push_back(factory.CreateChara(CharaType::SLIME));
	enemyChars.push_back(factory.CreateChara(CharaType::GOBLIN));
	enemyChars.push_back(factory.CreateChara(CharaType::DRAGON));
}

void InGame::BattleState::Update(GameScene& scene)
{
	bool spaceinput = InputManager::Instance().IsTrigger(KeyCode::Space);
	if (spaceinput)
	{
		scene.ChangeState(std::make_unique<MoveState>());
	}
	bool enterinput = InputManager::Instance().IsTrigger(KeyCode::Enter);
	if (enterinput)
	{
		scene.GetBattleRenderer()->RenderState(scene.GetPlayerChar()->GetCharaData());
	}
}

void InGame::BattleState::Render(GameScene& scene)
{
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}
