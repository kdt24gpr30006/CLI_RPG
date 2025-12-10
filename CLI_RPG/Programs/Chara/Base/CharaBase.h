#pragma once
#include <string>


/// <summary>
/// キャラクターの情報
/// </summary>
struct CharaData
{
	int id;
	std::string name;
	int hp;
	int maxhp;
	int atk;
	int def;
};

class CharaBase
{
	CharaData data;

public:

	CharaBase() {}
	~CharaBase() {}

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	void TakeDamage(int argDmg);

	/// <summary>
	/// 生存確認
	/// </summary>
	/// <returns> 生きているならtrue 死んでいるなら false </returns>
	bool IsAlive();

	/// <summary>
	/// 攻撃処理
	/// </summary>
	void Attack();

	/// <summary>
	/// やられたとき処理
	/// </summary>
	void Die();

};