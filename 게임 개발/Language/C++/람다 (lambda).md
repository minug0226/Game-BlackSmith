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

		struct FindItemByItemId
		{
			FindItemByItemId(int itemId) : _itemId(itemId)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId;
			}

			int _itemId;
		};

		struct  FindItem
		{
			FindItem(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId && item._rarity == _rarity && item._itemType == _type;
			}

			int _itemId;
			Rarity _rarity;
			ItemType _type;
		};
		
		// 클로저 (closure) : 람다에 의해 만들어진 실행시점 객체
		auto isUniqueLambda = [](Item& item) 
			{ 
				return item._rarity == Rarity::Unique; 
			}; // 람다 표현식 (lambda expression)

		// 식을 써도 되지만, isUniqueLambda를 써도 된다.
		auto findIt = std::find_if(v.begin(), v.end(), [](Item& item) { return item._rarity == Rarity::Unique; });
		if (findIt != v.end())
		{
			cout << "아이템 ID : " << findIt->_itemId << endl;
		}
		
		int itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		// [] 캡처(caputure) : 함수 객체 내부에 변수를 저장하는 개념과 유사
		// 사진을 찰칵 [캡처]하듯... 일종의 스냅샷을 찍는다고 이해
		// 기본 캡처 모드 : 값(복사) 방식(=) 참조 방식(&)
		// 변수마다 캡처 모드를 지정해서 사용 가능 : 값 방식(name) 참조 방식(&name)
		auto findByItemIdLambda = [&](Item& item) 
			{
				return item._itemId == itemId; 
			};

		itemId = 10;

		auto findItTwo = std::find_if(v.begin(), v.end(), findByItemIdLambda);
		if (findItTwo != v.end())
		{
			cout << "아이템 ID : " << findItTwo->_itemId << endl;
		}

		auto findByItem = [=, &type](Item& item) 
			{
				return item._itemId == itemId && item._rarity == rarity && item._itemType == type;
			};

		auto findItThree = std::find_if(v.begin(), v.end(), FindItem(itemId, rarity, type));
		if (findItThree != v.end())
		{
			cout << "아이템 ID : " << findItThree->_itemId << endl;
		}

		{
			class Knight
			{
			public:
				auto ResetHpJob()
				{
					auto f = [=]() 
					{ 
						_hp = 200;
					};

					return f;
				}

			public:
				int _hp = 100;
		
			};

			class Functor
			{
			public:
				Functor(Knight* k) : _knight(k)
				{

				}

				void operator()()
				{
					_knight->_hp = 200;
				}
			public:
				Knight* _knight;
			};

			Knight* k = new Knight();
			auto job = k->ResetHpJob();
			delete k;
			job();
		}


		// [캡처](인자값) { 실행코드 }
	}

	return 0;
}

```