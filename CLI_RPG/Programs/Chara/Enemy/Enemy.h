#pragma once
#include "../../Chara/Base/CharaBase.h"

class Enemy : public CharaBase
{
public:
    Enemy(const CharaData& d) : CharaBase(d) {}

    void Die()
    {
        int a = 0;
    }
};
