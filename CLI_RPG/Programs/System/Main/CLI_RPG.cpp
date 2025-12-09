#ifdef _DEBUG
#define ENTRY_POINT int main()
#else
#include<Windows.h>
#define ENTRY_POINT int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#endif // _DEBUG

#include <iostream>
#include "../Scene/SceneManager.hpp"

ENTRY_POINT
{
	SceneManager::Instance().Update();
	SceneManager::Instance().Render();
	std::cout << "Hello World!\n";
}