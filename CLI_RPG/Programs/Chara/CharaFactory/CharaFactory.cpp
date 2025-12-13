#include "CharaFactory.h"

// 敵の初期ステータスを設定
void CharaFactory::InitCharaData()
{
    // 勇者 (YUUSHA) のステータス
    CharaData yuushaData;
    yuushaData.name = "勇者";
    yuushaData.hp = 120;
    yuushaData.maxhp = 120;
    yuushaData.ad = 20;
    yuushaData.ap = 10;
    yuushaData.def = 8;
    yuushaData.faction = Faction::Player; 
    charaDataMap.insert(std::make_pair(CharaType::YUUSHA, yuushaData));

    // スライムのステータス
    CharaData slimeData;
    slimeData.name = "スライム";
    slimeData.hp = 10;
    slimeData.maxhp = 10;
    slimeData.ad = 2;
    slimeData.ap = 0;
    slimeData.def = 1;
    slimeData.faction = Faction::Enemy;
    charaDataMap.insert(std::make_pair(CharaType::SLIME, slimeData));

    // ゴブリンのステータス
    CharaData goblinData;
    goblinData.name = "ゴブリン";
    goblinData.hp = 25;
    goblinData.maxhp = 25;
    goblinData.ad = 5;
    goblinData.ap = 1;
    goblinData.def = 2;
    goblinData.faction = Faction::Enemy;
    charaDataMap.insert(std::make_pair(CharaType::GOBLIN, goblinData));

    // ドラゴンのステータス
    CharaData dragonData;
    dragonData.name = "ドラゴン";
    dragonData.hp = 500;
    dragonData.maxhp = 500;
    dragonData.ad = 30;
    dragonData.ap = 20;
    dragonData.def = 15;
    dragonData.faction = Faction::Enemy;
    charaDataMap.insert(std::make_pair(CharaType::DRAGON, dragonData));
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