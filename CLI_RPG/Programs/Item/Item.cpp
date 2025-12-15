#include "Item.hpp"

void Item::Use(CharaBase* target)
{
	if (data.heel_value > 0) {
		target->Heal(data.heel_value);
	}
}