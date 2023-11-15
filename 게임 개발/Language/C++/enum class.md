# enum class

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : enum class

//unscoped enum (범위 없는)
enum PlayerType
{
	PT_Knight,
	PT_Archer,
	PT_Mage
};

enum MonsterType
{
	MT_NONE,
};

enum class ObjectType
{
	Player,
	Monster,
	Projectile
};

int main()
{
	// enum class (scoped enum)
	// 1) 이름공간 분리 (scoped)
	// 2) 암묵적인 변환 금지
	double value = static_cast<double>(ObjectType::Player);

	int choice;
	cin >> choice;

	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}

	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));

	return 0;
}
```