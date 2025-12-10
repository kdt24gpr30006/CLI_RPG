#include "TitleScene.hpp"
#include <iostream>
#include "../GameScene/GameScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"
#include "../../System/Input/InputManager.hpp"

TitleScene::TitleScene() {
	std::cout << "TitleScene" << std::endl;
	std::cout << "スペースを押したらゲームシーンに移行" << std::endl;
}

TitleScene::~TitleScene() {
}

void TitleScene::Update() {
	if (InputManager::Instance().IsKeyDown(KeyCode::Space)) {
		SceneManager::Instance().ChangeScene<GameScene>();
	}
}

void TitleScene::Render() {
}
