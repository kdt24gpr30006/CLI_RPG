#pragma once
#include <string>

class CharaBase;

class Skill
{
protected:
    // 使用MP
	int useMp = 0;
    // スキル名
	std::string skillName = "none";
public:

	Skill(int mp, std::string argName) : useMp(mp), skillName(argName) {}

    /// <summary>
    /// 使用MPを取得
    /// </summary>
    /// <returns></returns>
    int GetUseMp() const { return useMp; }

    /// <summary>
    /// MPが足りるか
    /// </summary>
    bool CanUseSkill(int mp) const;

    /// <summary>
    /// スキル名の取得
    /// </summary>
    const std::string& GetName() const { return skillName; }

    /// <summary>
    /// スキルを実行する
    /// </summary>
    virtual int Execute(CharaBase& user, CharaBase& target) = 0;
};

