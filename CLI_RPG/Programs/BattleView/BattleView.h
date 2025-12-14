#pragma once
#include "../Chara/Base/CharaBase.h"
#include "../../System/View/View.hpp"

class BattleRenderer {
public:
    // キャラクターステータスを描画する関数
    void RenderState(const CharaData& state) {
        // ステータス表示
        Text::View::Instance().Text("Name：");
        Text::View::Instance().Append(state.name);
        Text::View::Instance().Text("Hp：");
        Text::View::Instance().Append(state.hp);
    }
};