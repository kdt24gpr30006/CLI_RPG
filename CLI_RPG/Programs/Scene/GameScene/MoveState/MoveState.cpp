#include "MoveState.hpp"
#include "../BattleState/BattleState.hpp"
#include "../../../System/Input/InputManager.hpp"


InGame::MoveState::MoveState()
{
	stateName = "Move";
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}

void InGame::MoveState::Update(GameScene& scene)
{
	bool input = InputManager::Instance().IsTrigger(KeyCode::Space);
	if (input)
	{
		scene.ChangeState(std::make_unique<BattleState>());
	}
}

void InGame::MoveState::Render(GameScene& scene)
{
//	scene.GetDungeonMap()->Render();
}
