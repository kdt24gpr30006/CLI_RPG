#include "SceneManager.hpp"

void SceneManager::Update()
{
    if (nextScene) {
        currentScene = std::move(nextScene);
        currentScene->Init();   // ˆê‰•K—v‚É‚È‚Á‚½‚Æ‚«—p‚ÌInit()
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