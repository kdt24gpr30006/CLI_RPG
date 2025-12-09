#include "SceneManager.hpp"
#include "../../Scene/TitleScene/TitleScene.hpp"

SceneManager::SceneManager()
{
    // Å‰‚Íƒ^ƒCƒgƒ‹
    currentScene = std::make_unique<TitleScene>();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
    if (nextScene) {
        currentScene = std::move(nextScene);
    }

    if (currentScene) {
        currentScene->Update();
    }
}

void SceneManager::Render()
{
    if (currentScene) {
        currentScene->Render();
    }
}