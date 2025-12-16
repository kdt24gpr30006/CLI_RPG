#pragma once
#include "../Skill.h"
#include "../../Base/CharaBase.h"

class AttackSkill : public Skill
{
protected:
	// UŒ‚—Í
	int attackPower = 0;

public:

	AttackSkill(int useMp, std::string name, int argPower) : Skill(useMp, name), attackPower(argPower){}

	/// <summary>
	/// ƒXƒLƒ‹‚ğÀs‚·‚é
	/// </summary>
	int Execute(CharaBase& user, CharaBase& target) override;
};