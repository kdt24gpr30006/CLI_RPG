#pragma once
#include "../../System/SceneManager/Scene.hpp"

class ResultScene : public Scene {
public:
	ResultScene();
	~ResultScene();

	void Update() override;
	void Render() override;
};