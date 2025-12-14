#pragma once
#include <vector>
#include <string>
#include "../Singleton/Singleton.hpp"
#include <iostream>

// メモ
// coutだといろいろ不都合が出てくる
// なのでstd::vectorとかでやって、書き換えとか
// なにかしら入力されたらクリアにして再描画
// みたいな感じにできたらいいなと思う
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
		// 数字用
		void Text(int number) {
			buffer.push_back(std::to_string(number));
		}
		// 描画（色の指定を追加）
		void Text(const std::string& text, Color color) {
			std::string coloredText = GetColorCode(color) + text + GetColorCode(Color::Default);
			buffer.push_back(coloredText);
		}
		void Append(const std::string& text) {
			if (buffer.empty()) {
				// バッファが空なら、新しい行として追加
				buffer.push_back(text);
			}
			else {
				// すでにある最後の行の後ろに結合する
				buffer.back() += text;
			}
		}
		// 数字を今の行の後ろに追加
		void Append(int number) {
			Append(std::to_string(number));
		}
		// 色付きで追加
		void Append(const std::string& text, Color color) {
			std::string coloredText = GetColorCode(color) + text + GetColorCode(Color::Default);

			if (buffer.empty()) {
				buffer.push_back(coloredText);
			}
			else {
				// 色コードごと結合すれば、1行の中で部分的に色を変えられます
				buffer.back() += coloredText;
			}
		}
		// エラー表示
		void Error(const std::string& errorText) {
			Text("[Error]：" + errorText, Color::Red);
		}

		// システム
		void System(const std::string& systemText) {
			Text("[System]：" + systemText, Color::Green);
		}

		// 描画実行
		void Render() {
			std::cout << "\033[H\033[2J";
			for (const auto& line : buffer) {
				std::cout << line << std::endl;
			}
		}

		// バッファクリア
		void Clear() {
			buffer.clear();
		}

	private:
		std::vector<std::string> buffer;
		std::vector<std::string> lastBuffer;
		// 色コード取得
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