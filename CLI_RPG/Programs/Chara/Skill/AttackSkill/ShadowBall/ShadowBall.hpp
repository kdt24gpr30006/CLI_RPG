#include "../../Skill.h"
#include "../AttackSkill.hpp"
#include "../../../Base/CharaBase.h"

class ShadowBall : public AttackSkill
{

public:

	ShadowBall() : AttackSkill(10, "シャドウボール", 50) {}

};