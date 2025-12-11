#include "CharaBase.h"
#include <algorithm>

int CharaBase::GetAttack()
{
	return data.atk;
}

void CharaBase::TakeDamage(int argDmg)
{
	data.hp -= argDmg;

	// HP‚ª0ˆÈ‰º‚É‚È‚Á‚½‚ç€–Sˆ—
	if (data.hp <= 0)
	{
		data.hp = 0;
		Die();
	}
}

void CharaBase::Heal(int healHp)
{
	data.hp += healHp;
	// Å‘åHP‚ğ’´‚¦‚È‚¢‚æ‚¤‚É
	if (data.hp > data.maxhp)
	{
		data.hp = data.maxhp;
	}
}

bool CharaBase::IsAlive()
{
	return data.hp > 0;
}
