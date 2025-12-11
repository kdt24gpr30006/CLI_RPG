#include "BattleState.hpp"
#include "../MoveState/MoveState.hpp"
#include "../../../System/Input/InputManager.hpp"

InGame::BattleState::BattleState()
{
	stateName = "Battle";
}

void InGame::BattleState::Update(GameScene& scene)
{
	bool input = InputManager::Instance().IsKeyReleased(KeyCode::Space);
	if (input)
	{
		scene.ChangeState(std::make_unique<MoveState>());
	}
}

void InGame::BattleState::Render(GameScene& scene)
{
}
