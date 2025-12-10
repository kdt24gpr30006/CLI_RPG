#include "TitleScene.hpp"
#include <iostream>
#include "../GameScene/GameScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"
#include "../../System/Input/InputManager.hpp"
#include "../../System/View/View.hpp"

TitleScene::TitleScene() {
	Text::View::Instance().Text("TitleScene", Text::Color::Green);
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
