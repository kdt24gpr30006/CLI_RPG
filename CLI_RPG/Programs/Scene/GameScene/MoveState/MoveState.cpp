#include "MoveState.hpp"
#include "../BattleState/BattleState.hpp"
#include "../../../System/Input/InputManager.hpp"


InGame::MoveState::MoveState()
{
	stateName = "Move";
}

void InGame::MoveState::Update(GameScene& scene)
{
	bool input = InputManager::Instance().IsKeyReleased(KeyCode::Space);
	if (input)
	{
		scene.ChangeState(std::make_unique<BattleState>());
	}
}

void InGame::MoveState::Render(GameScene& scene)
{
//	scene.GetDungeonMap()->Render();
}
