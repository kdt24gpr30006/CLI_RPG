#pragma once
#include "../../System/SceneManager/Scene.hpp"

class ResultScene : public Scene {
public:
	ResultScene(int floor);
	~ResultScene();

	void Update() override;
	void Render() override;
};