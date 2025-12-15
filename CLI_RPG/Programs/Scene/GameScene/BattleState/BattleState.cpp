#include "BattleState.hpp"
#include "../MoveState/MoveState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/CharaFactory/CharaFactory.h"
#include "../../../Scene/ResultScene/ResultScene.hpp"
#include "../../../System/SceneManager/SceneManager.hpp"

void InGame::BattleState::UpdateSelection(GameScene& scene)
{
	// 攻撃
	if (InputManager::Instance().IsTrigger(KeyCode::Num1)) {
		ClearMessage();
		AddMessage("プレイヤーの攻撃！");
		CurrentPhase(BattlePhase::PlayerAttack);
	}
	// 魔法
	else if (InputManager::Instance().IsTrigger(KeyCode::Num2)) {
		ClearMessage();
		AddMessage("プレイヤーの魔法攻撃！");
		CurrentPhase(BattlePhase::PlayerMagic);
	}
	// アイテム
	else if (InputManager::Instance().IsTrigger(KeyCode::Num3)) {
		ClearMessage();
		// アイテムがあるかチェック
		if (scene.GetItemManager()->GetItemList().empty()) {
			AddMessage("アイテムを持っていません！");
		}
		else {
			AddMessage("アイテムを選択してください\n(数字キー:選択 / 0:戻る)");
			CurrentPhase(BattlePhase::PlayerItem);
		}
	}
}

void InGame::BattleState::UpdatePlayerAttack(GameScene& scene)
{
	if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
		// プレイヤーとエネミー１体にするからベクターの最初の要素を取得
		auto& players = scene.GetPlayerChar();
		auto& enemies = scene.GetEnemyChars();
		if (players.empty() || enemies.empty()) return;
		auto player = players[0].get();
		auto enemy = enemies[0].get();
		// ダメージを与える
		int damage = player->GetAttack();
		enemy->TakeDamage(damage);
		// ログ更新
		AddMessage(enemy->GetCharaData().name + " に " + std::to_string(damage) + " のダメージ！");
		// 敵の生存確認
		if (!enemy->IsAlive()) {
			AddMessage("\n" + enemy->GetCharaData().name + " を倒した！(Win)");
			CurrentPhase(BattlePhase::Victory); // 勝利フェーズへ
		}
		else {
			// 敵が生きていれば、次は敵のターン
			CurrentPhase(BattlePhase::EnemyTurn);
		}
	}
}

void InGame::BattleState::UpdatePlayerMagic(GameScene& scene)
{
	if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
		auto& players = scene.GetPlayerChar();
		auto& enemies = scene.GetEnemyChars();
		if (players.empty() || enemies.empty()) return;
		auto player = players[0].get();
		auto enemy = enemies[0].get();
		// ダメージを与える
		int damage = player->GetMagicAttack();
		enemy->TakeDamage(damage);
		// ログ更新
		AddMessage(enemy->GetCharaData().name + " に " + std::to_string(damage) + " の魔法ダメージ！");
		// 敵の生存確認
		if (!enemy->IsAlive()) {
			AddMessage("\n" + enemy->GetCharaData().name + " を倒した！(Win)");
			CurrentPhase(BattlePhase::Victory); // 勝利フェーズへ
		}
		else {
			// 敵が生きていれば、次は敵のターン
			CurrentPhase(BattlePhase::EnemyTurn);
		}
	}
}

void InGame::BattleState::UpdatePlayerItem(GameScene& scene)
{
	if (InputManager::Instance().IsTrigger(KeyCode::Num0)) {
		AddMessage("コマンド選択に戻る");
		CurrentPhase(BattlePhase::SelectCommand);
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

			// 敵のターンへ
			CurrentPhase(BattlePhase::EnemyTurn);
			return;
		}
	}
}

void InGame::BattleState::UpdateEnemyTurn(GameScene& scene)
{
	if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
		auto& players = scene.GetPlayerChar();
		auto& enemies = scene.GetEnemyChars();
		if (players.empty() || enemies.empty()) return;
		auto player = players[0].get();
		auto enemy = enemies[0].get();
		// 敵の攻撃
		AddMessage(enemy->GetCharaData().name + " の攻撃！");
		int damage = enemy->GetAttack() - player->GetCharaData().def;
		if (damage < 1) damage = 1;
		player->TakeDamage(damage);
		AddMessage("\nプレイヤーは " + std::to_string(damage) + " のダメージを受けた。");
		// プレイヤーの生存確認
		if (!player->IsAlive()) {
			AddMessage("\n目の前が真っ暗になった...");
			CurrentPhase(BattlePhase::Defeat); // 敗北フェーズへ
		}
		else {
			// 生きていればコマンド選択に戻る
			CurrentPhase(BattlePhase::SelectCommand);
		}
	}
}

void InGame::BattleState::AddMessage(const std::string& msg)
{
	if (!message.empty()) {
		message += "\n";
	}
	message += msg;
}

InGame::BattleState::BattleState(GameScene& scene)
{
	stateName = "Battle";
	scene.GetDungeonMap()->Render();
	CurrentPhase(BattlePhase::SelectCommand);
	//Text::View::Instance().Render();
	//Text::View::Instance().Clear();
}

void InGame::BattleState::Update(GameScene& scene)
{
	switch (phase) {
	case BattlePhase::SelectCommand:
		UpdateSelection(scene);
		break;
	case BattlePhase::PlayerAttack:
		UpdatePlayerAttack(scene);
		break;
	case BattlePhase::PlayerMagic:
		UpdatePlayerMagic(scene);
		break;
	case BattlePhase::PlayerItem:
		UpdatePlayerItem(scene);
		break;
	case BattlePhase::EnemyTurn:
		UpdateEnemyTurn(scene);
		break;
	case BattlePhase::Victory:
		// Enterキーで探索に戻る
		if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
			isSceneChanging = true;
			// 敵リストクリア
			scene.GetEnemyChars().clear();
			// 階層を進める
			scene.GetDungeonMap()->AdvanceFloor();
			// 移動ステートへ
			scene.ChangeState(std::make_unique<MoveState>(scene));

			Text::View::Instance().Clear();
		}
		break;
	case BattlePhase::Defeat:
		// ゲームオーバー処理
		// resultに移動
		if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
			isSceneChanging = true;
			// ゲームオーバー処理
			SceneManager::Instance().ChangeScene<ResultScene>(scene.GetDungeonMap()->GetCurrentFloor());
		}
		break;
	}

}

void InGame::BattleState::Render(GameScene& scene)
{
	if (isSceneChanging) {
		return;
	}
	
	Text::View::Instance().Clear();

	// 敵のステータス表示
	auto& enemies = scene.GetEnemyChars();
	Text::View::Instance().System("=== ENEMIES ===");
	for (auto& e : enemies) {
		scene.GetBattleRenderer()->RenderState(e->GetCharaData());
	}
	Text::View::Instance().Text(""); // 改行

	// プレイヤーのステータス表示
	auto& players = scene.GetPlayerChar();
	Text::View::Instance().System("=== PLAYER ===");
	for (auto& p : players) {
		scene.GetBattleRenderer()->RenderState(p->GetCharaData());
	}
	Text::View::Instance().Text(""); // 改行
	Text::View::Instance().Line();

	// メッセージログ表示
	Text::View::Instance().Text(message, Text::Color::Yellow);
	Text::View::Instance().Line();

	// コマンド表示 (選択フェーズのときだけ)
	if (phase == BattlePhase::SelectCommand) {
		Text::View::Instance().Text("[1] 攻撃  [2] 魔法  [3] アイテム");
	}
	else if (phase == BattlePhase::PlayerItem) {
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
	else if (phase == BattlePhase::Victory) {
		Text::View::Instance().Text("Enterキーで次へ進む", Text::Color::Green);
	}
	else {
		Text::View::Instance().Text("Enterキーで進む", Text::Color::Default);
	}
	Text::View::Instance().Render();
}