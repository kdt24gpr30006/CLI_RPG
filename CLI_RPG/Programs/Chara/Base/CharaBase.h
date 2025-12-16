#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../../Chara/CharaFactory/CharaType.hpp"
#include "../Skill/Skill.h"

class Skill;

/// <summary>
/// キャラクターの情報
/// </summary>
struct CharaData
{
	std::string name = "none";		 // 名前
	int hp = 1;						 // 体力
	int maxhp = 1;					 // 最大体力
	int ad = 1;						 // 攻撃力
	int ap = 1;						 // 魔法攻撃力
	int mp = 1;						 // 魔力
	int maxmp = 1;                   // 最大魔力
	int def = 1;					 // 防御力
	Faction faction = Faction::NONE; // 敵か味方
};

class CharaBase
{
protected:

	CharaData data;

public:
	// スキルリスト
	std::unique_ptr<Skill> skill;

	CharaBase() = default;
	CharaBase(const CharaData& d) : data(d) {}
	virtual ~CharaBase() = default;

	/// <summary>
	/// スキルを追加する
	/// <summary>
	void AddSkill(std::unique_ptr<Skill> newSkill)
	{
		skill = std::move(newSkill);
	}

	/// <summary>
	/// スキルを使用
	/// </summary>
	/// <param name="target"></param>
	int UseSkill(CharaBase& target)
	{
		if (skill == nullptr) // CanUseSkill は Skill::GetUseMp を使う
		{
			// スキルがない
			return -1;
		}

		// MPを消費
		ReduceMp(skill->GetUseMp());

		// スキル効果の実行 (ShadowBall -> AttackSkill::Executeが呼び出される)
		return skill->Execute(*this, target);
	}

	/// <summary>
	/// 攻撃力の取得
	/// </summary>
	int GetAttack() const;

	/// <summary>
	/// 魔法攻撃力の取得
	/// </summary>
	int GetMagicAttack() const;

	/// <summary>
	/// MPを減らす
	/// </summary>
	/// <param name="costMp"></param>
	void ReduceMp(int costMp);

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
	bool IsAlive() const;

	/// <summary>
	/// やられたとき処理
	/// </summary>
	virtual void Die() = 0;

	/// <summary>
	/// キャラクターの全部の情報
	/// </summary>
	CharaData GetCharaData() const { return data; }
};