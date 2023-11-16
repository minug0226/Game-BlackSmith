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

private:
	// 정의되지 않은 비공개(private) 함수
	void operator=(const Knight& k)
	{

	}

private:
	int _hp = 100;
};



int main()
{
	Knight k1;
	Knight k2;

	// 복사 연산자 
	k1 = k2;



	return 0;
}

```