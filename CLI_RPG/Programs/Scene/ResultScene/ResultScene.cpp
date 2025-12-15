#include "ResultScene.hpp"
#include <iostream>
#include "../TitleScene/TitleScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"
#include "../../System/Input/InputManager.hpp"
#include "../../System/View/View.hpp"

ResultScene::ResultScene() {
	Text::View::Instance().System("ResultScene");
	Text::View::Instance().Text("スペースキーを押してタイトルへ", Text::Color::Default);
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}

ResultScene::~ResultScene() {
}

void ResultScene::Update() {
	bool input = InputManager::Instance().IsTrigger(KeyCode::Space);
	if (input)
	{
		SceneManager::Instance().ChangeScene < TitleScene > ();
	}
}

void ResultScene::Render() {

}