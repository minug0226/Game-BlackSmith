# nullptr

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : nullptr

class Knight
{
public:
	void Test()
	{

	}
};

Knight* FindKnight()
{
	// TODO

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// nullptr 구현

class NullPtr
{
public:
	// 그 어떤 포인터와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}
private :
	void operator&() const; // 주소값 &을 막는다.
};

const NullPtr _NullPtr;

int main()
{
	int* ptr = 0; // 0 or NULL
	
	// 1) 오동작을 방지한다.
	Test(0); // Test(int)
	Test(NULL); // Test(int)
	Test(nullptr); // Test(*)

	// 2) 가독성
	auto knight = FindKnight();
	if (knight == nullptr)
	{

	}

	void (Knight::*memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == nullptr)
	{

	}

	nullptr_t whoami = nullptr;
	

	return 0;
}
```