#include "MoveState.hpp"
#include "../BattleState/BattleState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/Enemy/EnemySpawner.hpp"

InGame::MoveState::MoveState()
{
	stateName = "Move";
	//Text::View::Instance().Render();
	//Text::View::Instance().Clear();
}

void InGame::MoveState::Update(GameScene& scene)
{
	bool input = InputManager::Instance().IsTrigger(KeyCode::Space);
	if (input)
	{
		// 現在の階層を取得
		int currentFloor = scene.GetDungeonMap()->GetCurrentFloor();


		// 階層に沿ったキャラクター生成
		std::vector<std::unique_ptr<CharaBase>> battleEnemies;

		std::unique_ptr<CharaBase> newEnemies =
			EnemySpawner::SpawnEnemiesForFloor(currentFloor);

		battleEnemies.push_back(std::move(newEnemies));

		// 生成したリストをセット
		scene.GetEnemyCharsRef() = std::move(battleEnemies);

		/*
		*
		*  複数の敵用
		*	std::vector<std::unique_ptr<CharaBase>> newEnemies =
		*	EnemySpawner::SpawnEnemiesForFloor(currentFloor);
		*
		*	scene.GetEnemyCharsRef() = std::move(newEnemies);
		*/

		scene.ChangeState(std::make_unique<BattleState>());
	}
}

void InGame::MoveState::Render(GameScene& scene)
{
	//	scene.GetDungeonMap()->Render();
}