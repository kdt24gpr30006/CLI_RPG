#include "BattleState.hpp"
#include "../MoveState/MoveState.hpp"
#include "../../../System/Input/InputManager.hpp"
#include "../../../Chara/CharaFactory/CharaFactory.h"

InGame::BattleState::BattleState(GameScene& scene)
{
	stateName = "Battle";
	scene.GetDungeonMap()->Render();
	//Text::View::Instance().Render();
	//Text::View::Instance().Clear();

}

void InGame::BattleState::Update(GameScene& scene)
{
	bool spaceinput = InputManager::Instance().IsTrigger(KeyCode::Space);

	if (spaceinput)
	{
		// 戦闘終了時 敵のリストをクリア
		scene.GetEnemyChars().clear();

		scene.ChangeState(std::make_unique<MoveState>(scene));
		scene.GetDungeonMap()->AdvanceFloor();
		Text::View::Instance().Render();
		Text::View::Instance().Clear();
	}
	bool enterinput = InputManager::Instance().IsTrigger(KeyCode::Enter);
	if (enterinput)
	{
		// ゲームの作成
		// コマンド選択画面の作成と入力待機を作成する
		// 最初はプレイヤーとエネミーのステータス表示する
		auto& player = scene.GetPlayerChar();
		for (auto& p : player) {
			scene.GetBattleRenderer()->RenderState(p->GetCharaData());
		}
		Text::View::Instance().Line();
		// エネミーのステータス表示
		auto& enemy = scene.GetEnemyChars();
		for (auto& e : enemy) {
			scene.GetBattleRenderer()->RenderState(e->GetCharaData());
		}
		Text::View::Instance().Render();
	}

}

void InGame::BattleState::Render(GameScene& scene)
{

}