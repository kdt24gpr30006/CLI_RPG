#pragma once
#include <array>
#include <windows.h>
#include "../Singleton/Singleton.hpp"
#include "KeyCode.h"

// 入力処理関係
class InputManager : public Singleton<InputManager> {
	friend class Singleton<InputManager>;
public:
	// 更新
	void Update() {
		for (int i = 0; i < 256; i++)
		{
			prevKey[i] = currKey[i];
			SHORT keyState = GetAsyncKeyState(i);
			currKey[i] = (keyState & 0x8000) != 0;
		}
	}

	// 押された瞬間
	bool IsKeyDown(KeyCode k) const {
		return currKey[(static_cast<uint8_t>(k))];
	}
	// 押されている間
	bool IsKeyPressed(KeyCode k) const {
		return prevKey[static_cast<uint8_t>(k)] && !currKey[static_cast<uint8_t>(k)];
	}
	// 離された瞬間
	bool IsKeyReleased(KeyCode k) const {
		return !prevKey[static_cast<uint8_t>(k)] && currKey[static_cast<uint8_t>(k)];
	}
private:
	// 今回はコンソールなのでキーボード入力のみ対応
	std::array<bool, 256> prevKey{};	// 前回のキー状態
	std::array<bool, 256> currKey{};	// 今回のキー状態
};