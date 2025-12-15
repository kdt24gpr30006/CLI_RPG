#include "../GameState/GameState.hpp"
#include "../GameScene.hpp"

namespace InGame {
    class BattleState : public GameState {
    public:
        BattleState();
        void Update(GameScene& scene) override;
        void Render(GameScene& scene) override;
        // 敵キャラクターリスト
        std::vector<std::unique_ptr<CharaBase>> enemyChars;
    };
}