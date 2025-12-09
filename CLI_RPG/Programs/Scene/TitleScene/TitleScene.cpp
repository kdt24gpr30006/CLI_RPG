#include "TitleScene.hpp"
#include <iostream>
#include "../GameScene/GameScene.hpp"
#include "../../System/SceneManager/SceneManager.hpp"

TitleScene::TitleScene() {
	std::cout << "TitleScene" << std::endl;
}

TitleScene::~TitleScene() {
}

void TitleScene::Update() {
	std::cout << "1を押したらゲームシーンに移行" << std::endl;
	int input = -1;
	std::cin >> input;
	if (input == 1) {
		SceneManager::Instance().ChangeScene<GameScene>();
	}
}

void TitleScene::Render() {
}
