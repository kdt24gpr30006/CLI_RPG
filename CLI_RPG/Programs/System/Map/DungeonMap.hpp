#pragma once
#include <vector>
#include <string>
#include <map>

class DungeonMap {
private:
    std::map<int, std::vector<std::vector<int>>> floors;

    int currentFloor = 1; // Œ»İ‚ÌŠK‘w
    int width = 0;        // Œ»İ‚ÌŠK‘w‚Ì•
    int height = 0;       // Œ»İ‚ÌŠK‘w‚Ì‚‚³

public:
    DungeonMap();

    bool LoadFromCSV(const std::string& filename);
    void Render() const;
    int GetTile(int x, int y) const;

    // ŠK‘w‚ğØ‚è‘Ö‚¦‚éŠÖ”
    void ChangeFloor(int floorNum);

    // ¡‰½ŠK‚É‚¢‚é‚©æ“¾
    int GetCurrentFloor() const { return currentFloor; }
};