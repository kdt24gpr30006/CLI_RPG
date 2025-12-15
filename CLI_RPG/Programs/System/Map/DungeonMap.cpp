#include "DungeonMap.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "../View/View.hpp"

DungeonMap::DungeonMap() {
    width = 0;
    height = 0;
    currentFloor = 1;
}

void DungeonMap::AdvanceFloor()
{
    int nextFloor = currentFloor + 1;
    if (nextFloor <= MaxFloors) {
        currentFloor = nextFloor;
    }
    Text::View::Instance().Text("階層を上がった...", Text::Color::Yellow);
    Text::View::Instance().Text("現在の階層: " + std::to_string(currentFloor), Text::Color::Yellow);
}

void DungeonMap::Render() const
{
	Text::View::Instance().Text("現在の階層: " + std::to_string(currentFloor), Text::Color::Yellow);
}


 
//bool DungeonMap::LoadFromCSV(const std::string& filename) {
//	// ファイルを開く
//    std::ifstream file(filename);
//	// ファイルが開けなかったらエラーを表示します
//    if (!file.is_open())
//    {
//        Text::View::Instance().Error("マップファイル " + filename + " を開けませんでした。");
//        return false;
//    }
//	// 既存データをクリア
//    floors.clear();
//	// 現在の階層を初期化
//    std::string line;
//    int loadingFloor = 1;
//	// ファイルを１行ずつ読み込む
//    while (std::getline(file, line)) {
//		if (line.empty()) continue;             // 空行はスキップ
//		size_t floorPos = line.find("FLOOR");   // FLOORの位置を検索
//		if (floorPos != std::string::npos)      // FLOORが見つかった場合
//        {
//			// FLOORの後に続く数字を抽出
//            std::string afterFloor = line.substr(floorPos + 5);
//			// 数字部分のみを取り出す
//            std::string numStr;
//			// 数字以外の文字が出たら終了
//            for (char c : afterFloor)
//            {
//				// 数字かどうかをチェック
//                if (std::isdigit(c))
//                {
//					// 数字を追加
//                    numStr += c;
//                }
//                else if (!numStr.empty())
//                {
//					// 数字以外の文字が出てきたら終了
//                    break;
//                }
//            }
//			// 数字が取れたら階層を設定
//            if (!numStr.empty())
//            {
//                loadingFloor = std::stoi(numStr);
//            }
//            else
//            {
//                Text::View::Instance().Error("FLOOR指定に数字が含まれていません。");
//				throw std::runtime_error("FLOOR指定に数字が含まれていません。");
//            }
//            continue;
//        }
//		// 行データ作成
//        std::vector<int> row;
//		// セル分割
//        std::stringstream ss(line);
//		// 各セルの処理
//        std::string cell;
//		// セルをカンマで分割して処理
//        while (std::getline(ss, cell, ',')) {
//			// 空セルはスキップ
//            if (cell.empty()) continue;
//			// 数字かどうかをチェック
//            bool isNumber = true;
//			// 各文字を確認
//            for (char c : cell) {
//				// 数字でなければフラグを折る
//                if (!std::isdigit(c)) {
//                    isNumber = false;
//                    break;
//                }
//            }
//			// 数字なら変換して追加
//            if (isNumber) {
//                row.push_back(std::stoi(cell));
//            }
//			// 数字でなければ１
//            else {
//                row.push_back(1);
//            }
//        }
//		// 行データが空でなければ追加
//        if (!row.empty()) {
//            floors[loadingFloor].push_back(row);
//        }
//    }
//    // １階からスタートしておく
//    ChangeFloor(1);
//    return !floors.empty();
//}

//void DungeonMap::ChangeFloor(int floorNum) {
//	// 指定された階層が存在するか確認
//    if (floors.count(floorNum)) {
//		// 存在すれば階層を変更
//        currentFloor = floorNum;
//		// 幅と高さを更新
//        height = static_cast<int>(floors[currentFloor].size());
//        width = (height > 0) ? static_cast<int>(floors[currentFloor][0].size()) : 0;
//    }
//    else
//    {
//        Text::View::Instance().Error("指定された階層 " + std::to_string(floorNum) + " は存在しません");
//    }
//}

//void DungeonMap::Render() const {
//    // 存在確認
//    if (floors.count(currentFloor) == 0) return;
//
//	// 現在のマップデータ取得
//    const auto& currentGrid = floors.at(currentFloor);
//    // 見やすくするためにつけとくよ
//    Text::View::Instance().Text("=== Floor " + std::to_string(currentFloor) + " ===", Text::Color::Yellow);
//	// マップ描画
//    for (int y = 0; y < height; ++y) {
//        for (int x = 0; x < width; ++x) {
//            int tile = currentGrid[y][x];
//            char symbol = '?';
//            // タイルはあとで変更する可能性あり
//            switch (tile) {
//            case 0: symbol = '.'; break;
//            case 1: symbol = '#'; break;
//            case 2: symbol = 'E'; break;
//            case 3: symbol = '<'; break;
//            case 4: symbol = '>'; break;
//            default: symbol = ' '; break;
//            }
//            std::cout << symbol << " ";
//        }
//        std::cout << std::endl;
//    }
//}

//void DungeonMap::SetTile(int x, int y, int tile) {
//	// 存在確認
//    if (floors.count(currentFloor) == 0) return;
//    if (x < 0 || x >= width || y < 0 || y >= height) return;
//    floors[currentFloor][y][x] = tile;
//}

//int DungeonMap::GetTile(int x, int y) const {
//	// 存在確認
//    if (floors.count(currentFloor) == 0) return 1;
//    if (x < 0 || x >= width || y < 0 || y >= height) return 1;
//
//    return floors.at(currentFloor)[y][x];
//}