#pragma once
#include <cstdint>
#include <Windows.h>

// キーコード定義
// ''でやるのなんかキモイからキーコード定義しとくね
enum class KeyCode : uint8_t {
	A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F', G = 'G',
	H = 'H', I = 'I', J = 'J', K = 'K', L = 'L', M = 'M', N = 'N',
	O = 'O', P = 'P', Q = 'Q', R = 'R', S = 'S', T = 'T', U = 'U',
	V = 'V', W = 'W', X = 'X', Y = 'Y', Z = 'Z',

	Key0 = '0', Key1 = '1', Key2 = '2', Key3 = '3', Key4 = '4',
	Key5 = '5', Key6 = '6', Key7 = '7', Key8 = '8', Key9 = '9',

	Space = VK_SPACE,
	Enter = VK_RETURN,
	Escape = VK_ESCAPE,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	Up = VK_UP,
	Down = VK_DOWN,
	Tab = VK_TAB,
	Backspace = VK_BACK,
	Shift = VK_SHIFT,
	Control = VK_CONTROL,
	Alt = VK_MENU,
};