#ifdef _DEBUG
#define ENTRY_POINT int main()
#else
#include<Windows.h>
#define ENTRY_POINT int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#endif // _DEBUG

#include <iostream>
#include "../SceneManager/SceneManager.hpp"
#include "../Input/InputManager.hpp"

ENTRY_POINT
{
	while (true) {
		// キー入力の更新
		InputManager::Instance().Update();
		// シーンの更新と描画
		SceneManager::Instance().Update();
		SceneManager::Instance().Render();
	}
	std::cout << "Hello World!\n";
}