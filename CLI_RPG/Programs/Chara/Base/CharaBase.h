#pragma once
#include <string>


/// <summary>
/// キャラクターの情報
/// </summary>
struct CharaData
{
	int id = -1;
	std::string name = "";
	int hp = -1;
	int maxhp = -1;
	int atk = -1;
	int def = -1;
};

class CharaBase
{
protected:

	CharaData data;

public:

	CharaBase() = default;
	CharaBase(const CharaData& d) : data(d) {}
	virtual ~CharaBase() = default;

	/// <summary>
	/// 攻撃力の取得
	/// </summary>
	int GetAttack();

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