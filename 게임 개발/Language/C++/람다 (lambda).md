# 람다 (lambda)

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : 람다 (lambda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable,
};


enum class Rarity
{
	Common,
	Rare,
	Unique,
};

class Item
{
public:
	Item() { }
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _itemType(type) 
	{ 
	
	}


public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _itemType = ItemType::None;
};


int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉽게 만드는 문법
	// 람다 자체로 C++11에 '새로운' 기능이 들어간 것은 아니다.
	{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};


		auto findIt = std::find_if(v.begin(), v.end(), IsUniqueItem());
		if (findIt != v.end())
		{
			cout << "아이템 ID : " << findIt->_itemId << endl;
		}
	}

	return 0;
}

```