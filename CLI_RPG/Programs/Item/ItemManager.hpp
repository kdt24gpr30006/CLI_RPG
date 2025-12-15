#pragma once
#pragma once
#include <vector>
#include <memory>
#include "../Item/Item.hpp" 

namespace InGame {

    class ItemManager {
    public:
        ItemManager();
        ~ItemManager();

        // アイテムを追加
        void AddItem(std::unique_ptr<Item> item);

        const Item* GetItemByName(const std::string& name) const;

        // 現在のアイテムリスト全体を取得
        const std::vector<std::unique_ptr<Item>>& GetItemList() const { return itemList; }

        // アイテムリストをクリア
        void ClearItems();

    private:
        std::vector<std::unique_ptr<Item>> itemList;

    };

} // namespace InGame