#pragma once
#include <unordered_map>
#include <memory>
#include "../../Chara/Base/CharaBase.h"
#include "../../Chara/CharaFactory/CharaType.hpp"
#include "../../Chara/Enemy/Enemy.h" 
#include "../../Chara/Player/Player.h"
#include "../../System/Singleton/Singleton.hpp"

class CharaFactory {

	std::unordered_map<CharaType, CharaData> charaDataMap;

	// ステータス初期化用
	void InitCharaData();

public:

	CharaFactory()
	{
		// ファクトリー生成時に各データを初期化
		InitCharaData();
	}
	~CharaFactory() = default;

	/// <summary>
	/// 指定されたタイプのオブジェクトを生成
	/// </summary>
	/// <param name="type">生成したい敵のタイプ</param>
	/// <returns>生成されたEnemyオブジェクトへのポインタ</returns>
	std::unique_ptr<CharaBase> CreateChara(CharaType type) const;
};
