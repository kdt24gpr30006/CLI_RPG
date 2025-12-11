#pragma once
#include <vector>
#include <string>
#include "../Singleton/Singleton.hpp"
#include <iostream>

// メモ
// coutだといろいろ不都合が出てくる
// なのでstd::vectorとかでやって、書き換えとか
// なにかしら入力されたらクリアにして再描画
// みたいな感じにする
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
			buffer.push_back(text);
		}
		// 描画（色の指定を追加）
		void Text(const std::string& text, Color color) {
			std::string coloredText = GetColorCode(color) + text + GetColorCode(Color::Default);
			buffer.push_back(coloredText);
		}

		// エラー表示
		void Error(const std::string& errorText) {
			Text("Error: " + errorText, Color::Red);
		}

		void Render() {
			std::cout << "\033[H\033[2J";

			for (const auto& line : buffer) {
				std::cout << line << std::endl;
			}

			buffer.clear();
		}
	private:
		std::vector<std::string> buffer;
		std::string GetColorCode(Color color) {
			switch (color) {
			case Color::Red:    return "\033[31m";
			case Color::Green:  return "\033[32m";
			case Color::Blue:   return "\033[34m";
			case Color::Yellow: return "\033[33m";
			case Color::Default:
			default:            return "\033[0m";
			}
		}
	};
}