#include "../GameState/GameState.hpp"
#include "../GameScene.hpp"

namespace InGame {
    class BattleState : public GameState {
    private:
        enum class BattlePhase {
			SelectCommand,  // コマンド選択
			PlayerAttack,   // プレイヤーの通常攻撃
			PlayerMagic,   // プレイヤーの魔法攻撃
			EnemyTurn,      // 敵のターン
			Victory,        // 勝利
			Defeat          // 敗北
		};
        BattlePhase phase;           // 現在のフェーズ
        std::string message;
        void UpdateSelection(GameScene& scene);   // 選択
        void UpdatePlayerAttack(GameScene& scene);// 攻撃実行
		void UpdatePlayerMagic(GameScene& scene);// 魔法実行
        void UpdateEnemyTurn(GameScene& scene);   // 敵行動
		void CurrentPhase(BattlePhase newPhase) { phase = newPhase; }
        void AddMessage(const std::string& msg);
    public:
        BattleState(GameScene& scene);
        void Update(GameScene& scene) override;
        void Render(GameScene& scene) override;
    };
}