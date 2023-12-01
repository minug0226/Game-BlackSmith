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
		if (_target.expired() == false)
		{
			shared_ptr<Knight> sptr = _target.lock();
			sptr->_hp -= _damage;
			cout << "HP: " << sptr->_hp << endl;
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target;
};;

class RefCountBlock
{
public:
	int _refCount = 1;
	int _weakRefCount = 0;
};;

template<typename T>
class SharedPtr
{
public:
	SharedPtr () { }

	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(consdt SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
	{
		if(_ptr != nullptr)
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
	}


	void operator = (const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;
		if (_ptr != nullptr)
			_block->_refCount++;
		cout << "RefCount : " << _block->_refCount << endl;
	}

	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				//delete _block;
				cout << "Delete Data" << endl;
			}

			
		}
	}

public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};

int main()
{

	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
	// shared_ptr : 참조 횟수를 기록해서, 참조 횟수가 0이 되면 자동으로 delete를 호출한다
	// weak_ptr : shared_ptr을 참조하지만, 참조 횟수를 증가시키지 않는다
	// unique_ptr : 오직 1개의 포인터만이 해당 객체를 참조할 수 있다
	SharedPtr<Knight> k2;

	{
		SharedPtr<Knight> k1(new Knight());
		k2 = k1;
	}

	shared_ptr<Knight> k3 = make_shared<Knight>();
	
	// k3 [  2]
	// k4 [  1]
	
	shared_ptr<Knight> k4 = make_shared<Knight>();
	k3->_target = k4;
	k4->_target = k3;




	k3->Attack();

	// shared_ptr의 순환구조 끊어주기
	// k3 ->_target = nullptr;
	// k4 ->_target = nullptr;

	// weak_ptr을 사용하면 생명주기 걱정은 안해도 됨
	// 다만, weak_ptr을 사용하려면 shared_ptr을 사용해야 함 ( 로직안에서 )

	
	unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> uptr2 = std::move(uptr);

	// 자 정리해보자
	// shared_ptr은 참조 횟수를 기록해서, 참조 횟수가 0이 되면 자동으로 delete를 호출한다
	// weak_ptr은 shared_ptr을 참조하지만, 참조 횟수를 증가시키지 않는다
	// unique_ptr은 오직 1개의 포인터만이 해당 객체를 참조할 수 있다 (복사를 강제로 하고싶으면 move를 사용해야 함)

	return 0;
}

```

