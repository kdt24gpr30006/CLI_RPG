#include "../GameState/GameState.hpp"
#include "../GameScene.hpp"

namespace InGame {
    class BattleState : public GameState {
    private:
        enum class BattlePhase {
			SelectCommand,  // コマンド選択
			PlayerAttack,   // プレイヤーの通常攻撃
			PlayerMagic,    // プレイヤーの魔法攻撃
			PlayerItem,     // プレイヤーのアイテム使用
			EnemyTurn,      // 敵のターン
			Victory,        // 勝利
			Defeat          // 敗北
		};
        BattlePhase phase;           // 現在のフェーズ
        std::string message;
        bool isSceneChanging = false;
        void UpdateSelection(GameScene& scene);     // 選択
        void UpdatePlayerAttack(GameScene& scene);  // 攻撃実行
		void UpdatePlayerMagic(GameScene& scene);   // 魔法実行
		void UpdatePlayerItem(GameScene& scene);    // アイテム使用
        void UpdateEnemyTurn(GameScene& scene);     // 敵行動
		void CurrentPhase(BattlePhase newPhase) { phase = newPhase; }
        // メッセージ関連
        void AddMessage(const std::string& msg);
		void ClearMessage() { message.clear(); }
    public:
        BattleState(GameScene& scene);
        void Update(GameScene& scene) override;
        void Render(GameScene& scene) override;
    };
}