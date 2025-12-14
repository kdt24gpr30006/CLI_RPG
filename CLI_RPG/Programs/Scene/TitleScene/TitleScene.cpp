#include "TitleScene.hpp"
#include <iostream>
#include "../GameScene/GameScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"
#include "../../System/Input/InputManager.hpp"
#include "../../System/View/View.hpp"

TitleScene::TitleScene() {
	Text::View::Instance().System("TitleScene");
	Text::View::Instance().Text("スペースキーを押してゲーム開始", Text::Color::Default);
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}

TitleScene::~TitleScene() {
}

void TitleScene::Update() {
	bool input = InputManager::Instance().IsTrigger(KeyCode::Space);
	if (input)
	{
		SceneManager::Instance().ChangeScene<InGame::GameScene>();
	}
}

void TitleScene::Render() {

}