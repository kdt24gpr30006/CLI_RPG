#pragma once
#include <string>
#include "../Chara/Base/CharaBase.h"

// アイテムデータ構造体
struct itemdata{

	std::string name = "none";
	
	int heel_value = 0;

};

//　アイテムクラス
class Item {

public:

	itemdata data;

	Item(const itemdata& d) :data(d) {

	}

	// アイテム使用
	void Use(class CharaBase* target);
};