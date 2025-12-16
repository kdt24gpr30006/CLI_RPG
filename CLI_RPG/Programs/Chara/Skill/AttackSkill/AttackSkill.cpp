#include "AttackSkill.hpp"

int AttackSkill::Execute(CharaBase& user, CharaBase& target)
{
    // ここでダメージ計算をする
    int damage = attackPower;

    // ターゲットにダメージを与える
    target.TakeDamage(damage);

    return damage;
}
