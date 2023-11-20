# delete (삭제된 함수)

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : delete (삭제된 함수)
class Knight
{
public:

public:
	// 정의되지 않은 비공개(private) 함수
	// 어떤 함수를 더이상 사용하고 싶지않다. (delete)
	void operator=(const Knight& k) = delete;

	// 모든 것을 뚫는 창 vs 절대 방패
	friend class Admin;

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산
		k1 = k;
	}
};

int main()
{
	Knight k1;
	Knight k2;

	// 복사 연산자 
	k1 = k2;

	Admin admin;
	admin.CopyKnight(k1);

	return 0;
}

```