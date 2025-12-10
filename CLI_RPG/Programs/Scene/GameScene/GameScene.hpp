#pragma once
#include <memory>
#include "../../System/SceneManager/Scene.hpp"
#include "../../System/Map/DungeonMap.hpp"		// MAP

class GameScene : public Scene {
public:
	GameScene();
	~GameScene();

	void Update() override;
	void Render() override;
private:
	std::unique_ptr<DungeonMap> dungeonMap;

	// ‚¢‚Á‚½‚ñ‰¼
	struct PlayerData {
		int x = 0;
		int y = 0;
		int level = 1;
		std::string name = "Hero";
		int hp = 10;
		int atk = 1;
	};
	std::shared_ptr<PlayerData> player;
};