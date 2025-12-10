#pragma once
#include <vector>
#include <string>
#include "../Singleton/Singleton.hpp"
#include <iostream>

namespace Text {
	enum class Color {
		Red,
		Green,
		Blue,
		Yellow,
		Default
	};

	class View : public Singleton<View> {
		friend class Singleton<View>;
	public:

		// 描画
		void Text(const std::string& text) {
			// コンソールに出力
			std::cout << text << std::endl;
		}
		// 描画（色の指定を追加）
		void Text(const std::string& text, Color color) {
			// 色に応じてコンソールの文字色を変更
			switch (color) {
			case Color::Red:
				std::cout << "\033[31m";
				break;
			case Color::Green:
				std::cout << "\033[32m";
				break;
			case Color::Blue:
				std::cout << "\033[34m";
				break;
			case Color::Yellow:
				std::cout << "\033[33m";
				break;
			case Color::Default:
			default:
				std::cout << "\033[0m";
				break;
			}
			// コンソールに出力
			std::cout << text << "\033[0m" << std::endl; // 出力後に色をリセット
		}

		// エラー表示
		void Error(const std::string& errorText) {
			// コンソールにエラー出力
			std::cerr << "\033[31mError: " << errorText << "\033[0m" << std::endl; // 赤色で表示
		}
	};
}