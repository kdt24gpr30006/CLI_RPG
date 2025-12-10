#include "CharaBase.h"
#include <algorithm>

void CharaBase::TakeDamage(int argDmg)
{
	// UŒ‚‚ðH‚ç‚¢0–¢–ž‚È‚ç0‚É
	this->data.hp = std::max(this->data.hp - argDmg, 0);
}
