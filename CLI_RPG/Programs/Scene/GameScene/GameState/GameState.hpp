#pragma once
#include <string>

// 前方宣言
namespace InGame { class GameScene; }

namespace InGame {
    class GameState {
    protected:
		std::string stateName;
        std::string message;

    public:
        virtual ~GameState() = default;

        virtual void Update(GameScene& scene) = 0;
        virtual void Render(GameScene& scene) = 0;
        std::string GetStateName() const { return stateName; }

        // メッセージ関連
        void AddMessage(const std::string& msg);
        void ClearMessage() { message.clear(); }
    };
}