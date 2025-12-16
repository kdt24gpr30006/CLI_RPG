#pragma once

// 敵か味方か判定用
enum class Faction
{
	Enemy,  // 敵
	Player, // 味方
	NONE,	
};

enum class CharaType
{
	YUUSHA,	// 勇者
	SLIME,	// スライム
	GOBLIN,	// ゴブリン
	GOLEM,  // ゴーレム
	DRAGON,	// ドラゴン
};
