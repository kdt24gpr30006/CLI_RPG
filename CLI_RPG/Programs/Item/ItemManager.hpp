#pragma once
#pragma once
#include <vector>
#include <memory>
#include "../Item/Item.hpp" 

namespace InGame {

    class ItemManager {
    public:

		// コンストラクタとデストラクタ
        ItemManager();
        ~ItemManager();

        // アイテムを追加
        void AddItem(std::unique_ptr<Item> item);

        const Item* GetItemByName(const std::string& name) const;

        // 現在のアイテムリスト全体を取得
        const std::vector<std::unique_ptr<Item>>& GetItemList() const { return itemList; }

        // アイテムリストをクリア
        void ClearItems();

		// アイテム数を取得
		size_t GetItemCount() const { return itemList.size(); }

        // 名前の取得
		std::string GetName(int index) const;

		// アイテムをインデックスで削除
        void RemoveItem(int index);

    private:
        std::vector<std::unique_ptr<Item>> itemList;

    };

} // namespace InGame