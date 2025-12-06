#include "SceneManager.hpp"

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