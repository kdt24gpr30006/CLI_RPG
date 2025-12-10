#pragma once
#include <vector>
#include <string>
#include "../Singleton/Singleton.hpp"
#include <iostream>

// いったん仮で作る
class View : public Singleton<View> {
	friend class Singleton<View>;
public:

	// 描画
	void RenderText(const std::string& text) {
		// コンソールに出力
		std::cout << text << std::endl;
	}

	// エラー表示
	void RenderError(const std::string& errorText) {
		// コンソールにエラー出力
		std::cerr << "\033[31m" << errorText << "\033[0m" << std::endl;
	}
};