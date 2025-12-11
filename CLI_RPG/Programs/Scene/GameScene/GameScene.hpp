#pragma once
#include <memory>
#include "../../System/SceneManager/Scene.hpp"
#include "../../System/Map/DungeonMap.hpp"		// MAP
#include "GameState/GameState.hpp"

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
	private:
		// 現在の状態
		std::unique_ptr<GameState> currentState;
		// ダンジョン
		std::unique_ptr<DungeonMap> dungeonMap;
	};
}