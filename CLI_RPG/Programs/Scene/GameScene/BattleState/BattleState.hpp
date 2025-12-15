#include "../GameState/GameState.hpp"
#include "../GameScene.hpp"

namespace InGame {
    class BattleState : public GameState {
    public:
        BattleState();
        void Update(GameScene& scene) override;
        void Render(GameScene& scene) override;
    };
}