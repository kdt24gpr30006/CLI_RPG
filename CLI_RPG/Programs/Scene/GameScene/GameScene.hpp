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
};