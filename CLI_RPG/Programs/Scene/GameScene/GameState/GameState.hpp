#pragma once
#include <string>

// ‘O•ûéŒ¾
namespace InGame { class GameScene; }

namespace InGame {
    class GameState {
    protected:
		std::string stateName;
    public:
        virtual ~GameState() = default;

        virtual void Update(GameScene& scene) = 0;
        virtual void Render(GameScene& scene) = 0;
        std::string GetStateName() const { return stateName; }
    };
}