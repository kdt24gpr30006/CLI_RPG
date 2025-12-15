#include "MoveState.hpp"
#include "../BattleState/BattleState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/Enemy/EnemySpawner.hpp"

InGame::MoveState::MoveState(GameScene& scene)
{
	Text::View::Instance().Clear();
	stateName = "Move";
	scene.GetDungeonMap()->Render();
	Text::View::Instance().Text("エンターで戦闘");
	Text::View::Instance().Render();
}

void InGame::MoveState::Update(GameScene& scene)
{
	bool input = InputManager::Instance().IsTrigger(KeyCode::Enter);
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
		scene.GetEnemyChars() = std::move(battleEnemies);
		/*
		*
		*  複数の敵用
		*	std::vector<std::unique_ptr<CharaBase>> newEnemies =
		*	EnemySpawner::SpawnEnemiesForFloor(currentFloor);
		*
		*	scene.GetEnemyCharsRef() = std::move(newEnemies);
		*/

		scene.ChangeState(std::make_unique<BattleState>(scene));
	}
}

void InGame::MoveState::Render(GameScene& scene)
{
	//	scene.GetDungeonMap()->Render();
}