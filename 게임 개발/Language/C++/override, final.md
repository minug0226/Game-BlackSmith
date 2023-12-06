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
	virtual void Attack()
	{
		cout << "Creature!" << endl;
	}


};


class Player : public creature
{
public:
	// final 은 이제 Player에서만 쓰고 더이상은 상속받지않겠다 의미
	virtual void Attack() final
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// 재정의(override)
	// final일 경우 재정의 불가능
	virtual void Attack() override
	{
		cout << "Knight!" << endl;
	}

private:
	int _stamina = 100;

};


int main()
{
	Player* p = new Knight();

	p->Attack();

	return 0;
}

```

