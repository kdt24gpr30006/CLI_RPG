#include "TitleScene.hpp"
#include <iostream>
#include "../GameScene/GameScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"
#include "../../System/Input/InputManager.hpp"
#include "../../System/View/View.hpp"

TitleScene::TitleScene() {
	Text::View::Instance().Text("TitleScene", Text::Color::Green);
	Text::View::Instance().Text("スペースを押したらゲームシーンに移行");
}

TitleScene::~TitleScene() {
}

void TitleScene::Update() {
	if (InputManager::Instance().IsKeyDown(KeyCode::Space)) {
		SceneManager::Instance().ChangeScene<InGame::GameScene>();
	}
}

void TitleScene::Render() {
	Text::View::Instance().Text("=== タイトルシーン ===", Text::Color::Yellow);
	Text::View::Instance().Text("スペースキーを押してゲーム開始", Text::Color::Default);
	Text::View::Instance().Render();
}
