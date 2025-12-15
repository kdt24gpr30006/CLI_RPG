#include "ItemManager.hpp"
#include <iostream>
#include <algorithm> 
#include "../Item/Item.hpp"
namespace InGame {

    ItemManager::ItemManager() {
       
    }

    ItemManager::~ItemManager() {
     
    }

    void ItemManager::AddItem(std::unique_ptr<Item> item) {
        if (item) {
            itemList.push_back(std::move(item));
         
        }
    }

    const Item* ItemManager::GetItemByName(const std::string& name) const {
        // リスト全体を走査して、名前に一致するアイテムを探す
        auto it = std::find_if(itemList.begin(), itemList.end(),
            [&](const std::unique_ptr<Item>& item) {
                // itemdata構造体内のnameと比較
                return item->data.name == name;
            });

        if (it != itemList.end()) {
            return it->get(); // 見つかったアイテムのポインタを返す
        }
        return nullptr; // 見つからなかった
    }

    void ItemManager::ClearItems() {
        itemList.clear();
    }

    std::string ItemManager::GetName(int index) const
    {
		return itemList.at(index)->data.name;
    }

    void ItemManager::RemoveItem(int index)
    {
        if (index >= 0 && index < itemList.size()) {
            itemList.erase(itemList.begin() + index);
        }
    }
}