#pragma once
#include "../GameState/GameState.hpp"
#include "../GameScene.hpp"

namespace InGame {
    class MoveState : public GameState {
    public:
		MoveState();
        void Update(GameScene& scene) override;
        void Render(GameScene& scene) override;
    };
}