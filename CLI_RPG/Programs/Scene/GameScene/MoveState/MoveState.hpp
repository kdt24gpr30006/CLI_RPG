#pragma once
#include "../GameState/GameState.hpp"
#include "../GameScene.hpp"

namespace InGame {
    class MoveState : public GameState {
		enum class MovePhase {
			Exploring,	// 探索？中
			PlayerItem,	// アイテム使用
		};

		MovePhase phase;	// 現在のフェーズ

    public:
		MoveState(GameScene& scene);
        void Update(GameScene& scene) override;
        void Render(GameScene& scene) override;

		void CurrentPhase(MovePhase newPhase) { phase = newPhase; }
		void UpdateExploring(GameScene& scene);
		void UpdatePlayerItem(GameScene& scene);
    };
}