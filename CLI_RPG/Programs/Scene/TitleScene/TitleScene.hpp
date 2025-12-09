#pragma once
#include "../../System/SceneManager/Scene.hpp"

class TitleScene : public Scene {
public:
	TitleScene();
	~TitleScene();
	
	void Update() override;
	void Render() override;
};