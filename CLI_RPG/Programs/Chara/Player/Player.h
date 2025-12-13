#pragma once
#include "../../Chara/Base/CharaBase.h"

class Player : public CharaBase
{
public:
    Player(const CharaData& d) : CharaBase(d) {}

    void Die() override 
    {
        int a = 0;
    }
};
