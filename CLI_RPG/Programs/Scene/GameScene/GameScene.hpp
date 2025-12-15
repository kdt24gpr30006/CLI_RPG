#pragma once
#include <memory>
#include "../../System/SceneManager/Scene.hpp"
#include "../../System/Map/DungeonMap.hpp"		// MAP
#include "GameState/GameState.hpp"
#include "../../Chara/Base/CharaBase.h"
#include "../../BattleView/BattleView.h"

namespace InGame {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();

		void Update() override;
		void Render() override;

		// 状態変更
		void ChangeState(std::unique_ptr<GameState> newState);
		// ダンジョンマップ取得
		DungeonMap* GetDungeonMap() const { return dungeonMap.get(); }
		// プレイヤーキャラクター取得
		CharaBase* GetPlayerChar() const { return playerChar.get(); }
//		// 敵キャラクターリスト取得
//		const std::vector<std::unique_ptr<CharaBase>>& GetEnemyChars() const { return enemyChars; }
		// 戦闘描画取得
		BattleRenderer* GetBattleRenderer() const { return battleRenderer.get(); }
	private:
		// 現在の状態
		std::unique_ptr<GameState> currentState;
		// ダンジョン
		std::unique_ptr<DungeonMap> dungeonMap;
		// プレイヤーキャラクター
		std::unique_ptr<CharaBase> playerChar;
		// 戦闘の描画
		std::unique_ptr<BattleRenderer> battleRenderer;
	};
}