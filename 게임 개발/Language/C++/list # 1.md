# list # 1

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 : list # 1

// vector : 동적 배열
// [          ]      ]

class Node
{
public:

public:
	Node* _next;
	Node* _prev;
	int	  _data;
};

// 단일 / 이중 / 원형
// list : 연결 리스트

// [1] -> [2] -> [3] -> [4] -> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <->

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;

	for(int i = 0; i < 100; i++)
		li.push_back(i);
	
	// vector 와 다르게 지원함
	// 효율적이라는거겠지
	// 이는 데이터를 앞에서 추가함
	// li.push_front(10);
	
	int size = li.size();
	// li.capacity(); -> 없음

	int first = li.front();
	int last = li.back();

	// li[3] = 10; -> 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	// 중간에 있는 값도 삭제할 수 있음
	// begin()으로 인해 맨 처음 데이터를 삭제
	li.erase(li.begin());

	// 맨 처음 데이터 삭제 ( 뺴온다라는 느낌이랑도 비슷 )
	li.pop_front();

	// value 값이랑 같은애는 다 삭제해줌
	// vector는 비효율적이여서 얘는 지원해주지 않았다는걸 잊지말자.
	li.remove(10);

	return 0;
};
```