#pragma once
#include <vector>
#include <string>
#include <map>

class DungeonMap {
private:
	// 各階層のマップデータの格納
    std::map<int, std::vector<std::vector<int>>> floors;

    int currentFloor = 1; // 現在の階層
    int width = 0;        // 現在の階層の幅
    int height = 0;       // 現在の階層の高さ

public:
    DungeonMap();

	// CSVファイルからマップデータを読み込む関数
    bool LoadFromCSV(const std::string& filename);
	// マップ描画
    void Render() const;
    // 敵の除外用に使う予定
    void SetTile(int x, int y, int tile);
	// 指定した座標のタイルを取得
    int GetTile(int x, int y) const;

    // 階層を切り替える関数
    void ChangeFloor(int floorNum);

    // 今何階にいるか取得
    int GetCurrentFloor() const { return currentFloor; }

};