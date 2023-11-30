# 스마트 포인터 (smart pointer)

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : 스마트 포인터(smart pointer)

class Knight
{
public:
	Knight()
	{
		cout << "Knight 생성" << endl;
	}
	~Knight()
	{
		cout << "Knight 소멸" << endl;
	}	


	void Attack()
	{
		if (_target)
		{
			_target->_hp -= _damage;
			cout << "HP: " << _target->_hp << endl;
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	Knight* _target = nullptr;
};;

template<typename T>
class SharedPtr
{

};

int main()
{
	Knight* k1 = new Knight();
	Knight* k2 = new Knight();

	k1->_target = k2;

	delete k2;

	k1->Attack();

	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
	// shared_ptr : 참조 횟수를 기록해서, 참조 횟수가 0이 되면 자동으로 delete를 호출한다
	// weak_ptr : shared_ptr을 참조하지만, 참조 횟수를 증가시키지 않는다
	// unique_ptr : 오직 1개의 포인터만이 해당 객체를 참조할 수 있다


	return 0;
}

```

