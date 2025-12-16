#include "MoveState.hpp"
#include "../BattleState/BattleState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/Enemy/EnemySpawner.hpp"

InGame::MoveState::MoveState(GameScene& scene)
{
	Text::View::Instance().Clear();
	stateName = "Move";
	phase = MovePhase::Exploring;
}

void InGame::MoveState::Update(GameScene& scene)
{
	bool input = InputManager::Instance().IsTrigger(KeyCode::Enter);
	// プレイヤーのステータス表示
	auto& players = scene.GetPlayerChar();
	Text::View::Instance().System("=== PLAYER ===");
	for (auto& p : players) {
		scene.GetBattleRenderer()->RenderState(p->GetCharaData());
	}
	Text::View::Instance().Text(""); // 改行
	Text::View::Instance().Line();

	switch (phase) {
	case MovePhase::Exploring:
		scene.GetDungeonMap()->Render();
		Text::View::Instance().Text("エンターで戦闘");

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
		UpdateExploring(scene);
		break;
	case MovePhase::PlayerItem:
		UpdatePlayerItem(scene);
		break;
	default:
		break;
	}
}

void InGame::MoveState::Render(GameScene& scene)
{
	if (phase == MovePhase::Exploring) {
		Text::View::Instance().Text("[1] アイテム");
	}
	else if (phase == MovePhase::PlayerItem) {
		Text::View::Instance().System("--- ITEM LIST ---");

		auto itemManager = scene.GetItemManager();
		const auto& list = itemManager->GetItemList();
		int count = itemManager->GetItemCount();

		for (int i = 0; i < count; ++i) {
			std::string line = "[" + std::to_string(i + 1) + "] " + list[i]->data.name;
			Text::View::Instance().Text(line);
		}

		Text::View::Instance().Text("[0] 戻る", Text::Color::Red);
	}
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}

void InGame::MoveState::UpdateExploring(GameScene& scene)
{
	if (InputManager::Instance().IsTrigger(KeyCode::Num1)) {
		ClearMessage();
		if (scene.GetItemManager()->GetItemList().empty()) {
			AddMessage("アイテムを持っていません！");
		}
		else {
			AddMessage("アイテムを選択してください\n(数字キー:選択 / 0:戻る)");
			CurrentPhase(MovePhase::PlayerItem);
		}
	}
}

void InGame::MoveState::UpdatePlayerItem(GameScene& scene)
{

	if (InputManager::Instance().IsTrigger(KeyCode::Num0)) {
		AddMessage("コマンド選択に戻る");
		CurrentPhase(MovePhase::Exploring);
		return;
	}

	auto itemManager = scene.GetItemManager();
	const auto& itemList = itemManager->GetItemList();
	auto& players = scene.GetPlayerChar();

	if (players.empty()) return;
	auto player = players[0].get();

	int count = itemManager->GetItemCount();

	for (int i = 0; i < count; ++i) {
		if (i >= itemList.size()) break;

		KeyCode key = static_cast<KeyCode>((int)KeyCode::Num1 + i);

		if (InputManager::Instance().IsTrigger(key)) {
			itemList[i]->Use(player);
			// メッセージ設定
			AddMessage(itemList[i]->data.name + " を使用した！");
			// 使ったので消費（リストから削除）
			itemManager->RemoveItem(i);
			// フェーズを探索に戻す
			CurrentPhase(MovePhase::Exploring);
			return;
		}
	}
}
