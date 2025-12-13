#pragma once
#include <string>
#include "../../Chara/CharaFactory/CharaType.h"

/// <summary>
/// キャラクターの情報
/// </summary>
struct CharaData
{
	std::string name = "none";
	int hp = 1;
	int maxhp = 1;
	int ad = 1;
	int ap = 1;
	int def = 1;
	Faction faction = Faction::NONE;
};

class CharaBase
{
protected:


public:
	CharaData data;

	CharaBase() = default;
	CharaBase(const CharaData& d) : data(d) {}
	virtual ~CharaBase() = default;

	/// <summary>
	/// 攻撃力の取得
	/// </summary>
	int GetAttack() const;

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	void TakeDamage(int argDmg);

	/// <summary>
	/// 回復
	/// </summary>
	void Heal(int healHp);

	/// <summary>
	/// 生存確認
	/// </summary>
	/// <returns> 生きているならtrue 死んでいるなら false </returns>
	bool IsAlive();

	/// <summary>
	/// やられたとき処理
	/// </summary>
	virtual void Die() = 0;
};