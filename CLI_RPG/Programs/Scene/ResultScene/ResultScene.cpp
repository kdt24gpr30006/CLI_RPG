#include "ResultScene.hpp"
#include <iostream>
#include "../TitleScene/TitleScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"
#include "../../System/Input/InputManager.hpp"
#include "../../System/View/View.hpp"

//　ResultScene クラスのコンストラクタ
ResultScene::ResultScene(int floor) {
	//　画面表示をクリア
	Text::View::Instance().Clear();
	Text::View::Instance().System("ResultScene");
	//　クリアした階層
	std::string msg = "攻略した階層：" + std::to_string(floor);
	Text::View::Instance().Text(msg, Text::Color::Yellow);
	Text::View::Instance().Text("エンターを押してタイトルへ", Text::Color::Default);
	Text::View::Instance().Render();
	Text::View::Instance().Clear();
}

ResultScene::~ResultScene() {
}

void ResultScene::Update() {
	bool input = InputManager::Instance().IsTrigger(KeyCode::Enter);
	if (input)
	{
		SceneManager::Instance().ChangeScene<TitleScene>();
	}
}

void ResultScene::Render() {

}