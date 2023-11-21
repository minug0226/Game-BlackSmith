# override, final

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : override, final

class creature
{
public:

};


class Player : public creature
{
public:
	virtual void Attack()
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// 재정의(override)
	virtual void Attack() const
	{
		cout << "Knight!" << endl;
	}


};


int main()
{
	Player* player = new Knight();

	player->Attack();

	return 0;
}

```

