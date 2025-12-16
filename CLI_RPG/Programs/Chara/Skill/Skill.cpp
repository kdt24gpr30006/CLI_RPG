#include "Skill.h"

bool Skill::CanUseSkill(int mp) const
{
	return mp >= useMp;
}
