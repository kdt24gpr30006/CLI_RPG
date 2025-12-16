#include "CharaFactory.hpp"

// 敵の初期ステータスを設定
void CharaFactory::InitCharaData()
{
    // 勇者 (YUUSHA) のステータス
    CharaData yuushaData;
    yuushaData.name = "勇者";
    yuushaData.hp = 120;
    yuushaData.maxhp = 120;
    yuushaData.ad = 20;
    yuushaData.ap = 50;
    yuushaData.mp = 300;
    yuushaData.maxmp = 30;
    yuushaData.def = 8;
    yuushaData.faction = Faction::Player;
    charaDataMap.insert({ CharaType::YUUSHA, yuushaData });

    // スライムのステータス
    CharaData slimeData;
    slimeData.name = "スライム";
    slimeData.hp = 10;
    slimeData.maxhp = 10;
    slimeData.ad = 2;
    slimeData.ap = 0;
    slimeData.mp = 0;
    slimeData.maxmp = 0;
    slimeData.def = 1;
    slimeData.faction = Faction::Enemy;
    charaDataMap.insert({ CharaType::SLIME, slimeData });

    // ゴブリンのステータス
    CharaData goblinData;
    goblinData.name = "ゴブリン";
    goblinData.hp = 25;
    goblinData.maxhp = 25;
    goblinData.ad = 5;
    goblinData.ap = 0;
    goblinData.mp = 0;
    goblinData.maxmp = 0;
    goblinData.def = 2;
    goblinData.faction = Faction::Enemy;
    charaDataMap.insert({ CharaType::GOBLIN, goblinData });

    // ゴーレムのステータス
    CharaData golemData;
    golemData.name = "ゴーレム";
    golemData.hp = 300;
    golemData.maxhp = 300;
    golemData.ad = 30;
    golemData.ap = 0;
    golemData.mp = 0;
    golemData.maxmp = 0;
    golemData.def = 7;
    golemData.faction = Faction::Enemy;
    charaDataMap.insert({ CharaType::GOLEM, golemData });

    // ラスボスのステータス
    CharaData dragonData;
    dragonData.name = "BOSS ドラゴン";
    dragonData.hp = 500;
    dragonData.maxhp = 500;
    dragonData.ad = 40;
    dragonData.ap = 0;
    dragonData.mp = 0;
    dragonData.maxmp = 0;
    dragonData.def = 15;
    dragonData.faction = Faction::Enemy;
    charaDataMap.insert({ CharaType::DRAGON, dragonData });
}

std::unique_ptr<CharaBase> CharaFactory::CreateChara(CharaType type) const
{
    // 指定されたデータを探す
    auto it = charaDataMap.find(type);

    if (it == charaDataMap.end())
    {
        // データが見つからない場合はnullptr
        return nullptr;
    }

    // データを取得
    const CharaData& data = it->second;

    // Factionを見て生成するクラスを判断する
    switch (data.faction)
    {
    case Faction::Enemy:
        return std::make_unique<Enemy>(data);

    case Faction::Player:
        return std::make_unique<Player>(data);

    default:
        // データが見つからない場合はnullptr
        return nullptr;
    }
}