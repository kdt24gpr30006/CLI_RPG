#pragma once
#include "../../System/SceneManager/Scene.hpp"

class GameScene : public Scene {
public:
	GameScene();
	~GameScene();

	void Update() override;
	void Render() override;
};