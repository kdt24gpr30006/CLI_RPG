#include "CharaBase.h"
#include <algorithm>

int CharaBase::GetAttack() const
{
	return data.ad;
}

int CharaBase::GetMagicAttack() const
{
	return data.ap;
}

void CharaBase::ReduceMp(int costMp)
{
	// MP‚ğŒ¸‚ç‚·
	data.mp -= costMp;
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

bool CharaBase::IsAlive() const
{
	return data.hp > 0;
}
