#pragma once
#include "../Singleton/Singleton.hpp"

// マップ管理
class Map : public Singleton<Map> {
	friend class Singleton<Map>;
private:
	// 現在のマップ階層　どこにいるか
	int currentMap;
	// 最大マップ数
	const int MAX_MAP = 10;
public:
	// 現在のマップ階層
	const int GetCurrentMap() { return currentMap; }
	// 最大マップ数の取得
	const int GetMaxMap() { return MAX_MAP; }
	// 現在のマップの設定
	void SetCurrentMap(int argMap) { currentMap = argMap; }
	// 次の階層に移動
	void MoveMap() {
		// 次の階層
		int nextMap = currentMap + 1;
		// 移動
		SetCurrentMap(nextMap);
	}
};