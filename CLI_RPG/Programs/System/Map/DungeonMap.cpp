#include "DungeonMap.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

DungeonMap::DungeonMap() {
    width = 0;
    height = 0;
    currentFloor = 1;
}

 
bool DungeonMap::LoadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: ファイルが開けません -> " << filename << std::endl;
        return false;
    }
	// 既存データをクリア
    floors.clear();
	// 現在の階層を初期化
    std::string line;
    int loadingFloor = 1;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t floorPos = line.find("FLOOR");
        if (floorPos != std::string::npos)
        {
			// "FLOOR"の後に続く数字を抽出
            std::string afterFloor = line.substr(floorPos + 5);
            std::string numStr;
            for (char c : afterFloor)
            {
                if (std::isdigit(c))
                {
                    numStr += c;
                }
                else if (!numStr.empty())
                {
					// 数字以外の文字が出てきたら終了
                    break;
                }
            }
			// 数字が取れたら階層を設定
            if (!numStr.empty())
            {
                loadingFloor = std::stoi(numStr);
            }
            else
            {
				throw std::runtime_error("FLOOR指定に数字が含まれていません。");
            }
            continue;
        }
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            if (cell.empty()) continue;
            bool isNumber = true;
            for (char c : cell) {
                if (!std::isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber) {
                row.push_back(std::stoi(cell));
            }
            else {
                row.push_back(1);
            }
        }
        if (!row.empty()) {
            floors[loadingFloor].push_back(row);
        }
    }
    // １階からスタートしておく
    ChangeFloor(1);
    return !floors.empty();
}

void DungeonMap::ChangeFloor(int floorNum) {
    if (floors.count(floorNum)) {
        currentFloor = floorNum;
        height = static_cast<int>(floors[currentFloor].size());
        width = (height > 0) ? static_cast<int>(floors[currentFloor][0].size()) : 0;
    }
    else
    {
        std::cerr << "Error: " << floorNum << "階のデータが存在しません。" << std::endl;
    }
}

void DungeonMap::Render() const {
    if (floors.count(currentFloor) == 0) return;

    const auto& currentGrid = floors.at(currentFloor);
    std::cout << "=== Floor " << currentFloor << " ===" << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int tile = currentGrid[y][x];
            char symbol = '?';

            switch (tile) {
            case 0: symbol = '.'; break;
            case 1: symbol = '#'; break;
            case 2: symbol = 'E'; break;
            case 3: symbol = '<'; break;
            case 4: symbol = '>'; break;
            default: symbol = ' '; break;
            }
            std::cout << symbol << " ";
        }
        std::cout << std::endl;
    }
}

int DungeonMap::GetTile(int x, int y) const {
    if (floors.count(currentFloor) == 0) return 1;
    if (x < 0 || x >= width || y < 0 || y >= height) return 1;

    return floors.at(currentFloor)[y][x];
}