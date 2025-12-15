#include "BattleState.hpp"
#include "../MoveState/MoveState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/CharaFactory/CharaFactory.h"

void InGame::BattleState::UpdateSelection(GameScene& scene)
{
	// 攻撃
	if (InputManager::Instance().IsTrigger(KeyCode::Num1)) {
		AddMessage("プレイヤーの攻撃！");
		CurrentPhase(BattlePhase::PlayerAttack);
	}
	// 魔法
	else if (InputManager::Instance().IsTrigger(KeyCode::Num2)) {
		AddMessage("魔法を唱えた！...しかし何も起きなかった。");
		CurrentPhase(BattlePhase::EnemyTurn);
	}
	// アイテム
	else if (InputManager::Instance().IsTrigger(KeyCode::Num3)) {
		AddMessage("アイテムを使った！...しかし何も持っていない。");
		CurrentPhase(BattlePhase::EnemyTurn);
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
			phase = BattlePhase::Victory; // 勝利フェーズへ
		}
		else {
			// 敵が生きていれば、次は敵のターン
			phase = BattlePhase::EnemyTurn;
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
			phase = BattlePhase::Defeat; // 敗北フェーズへ
		}
		else {
			// 生きていればコマンド選択に戻る
			phase = BattlePhase::SelectCommand;
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
	//bool spaceinput = InputManager::Instance().IsTrigger(KeyCode::Space);

	//if (spaceinput)
	//{
	//	// 戦闘終了時 敵のリストをクリア
	//	scene.GetEnemyChars().clear();
	//	// 移動状態へ変更
	//	scene.ChangeState(std::make_unique<MoveState>(scene));
	//	// 階層を進める
	//	scene.GetDungeonMap()->AdvanceFloor();
	//	Text::View::Instance().Render();
	//	Text::View::Instance().Clear();
	//}
	//bool enterinput = InputManager::Instance().IsTrigger(KeyCode::Enter);
	//if (enterinput)
	//{
	//	// ゲームの作成
	//	// コマンド選択画面の作成と入力待機を作成する
	//	// 最初はプレイヤーとエネミーのステータス表示する
	//	auto& player = scene.GetPlayerChar();
	//	for (auto& p : player) {
	//		scene.GetBattleRenderer()->RenderState(p->GetCharaData());
	//	}
	//	Text::View::Instance().Line();
	//	// エネミーのステータス表示
	//	auto& enemy = scene.GetEnemyChars();
	//	for (auto& e : enemy) {
	//		scene.GetBattleRenderer()->RenderState(e->GetCharaData());
	//	}
	//	Text::View::Instance().Render();
	//}
	switch (phase) {
	case BattlePhase::SelectCommand:
		UpdateSelection(scene);
		break;
	case BattlePhase::PlayerAttack:
		UpdatePlayerAttack(scene);
		break;
	case BattlePhase::EnemyTurn:
		UpdateEnemyTurn(scene);
		break;
	case BattlePhase::Victory:
		// Enterキーで探索に戻る
		if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
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
		// ゲームオーバー処理 (とりあえずEnterで終了など)
		if (InputManager::Instance().IsTrigger(KeyCode::Enter)) {
			exit(0); // 仮：強制終了
		}
		break;
	}

}

void InGame::BattleState::Render(GameScene& scene)
{
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
	else if (phase == BattlePhase::Victory) {
		Text::View::Instance().Text("Enterキーで次へ進む", Text::Color::Green);
	}
	else {
		Text::View::Instance().Text("Enterキーで進む", Text::Color::Default);
	}

	Text::View::Instance().Render();

}