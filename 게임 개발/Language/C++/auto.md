# auto

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : auto

class Knight
{
public:

public:
	int _hp;
};

int main()
{
	// Modern C++ (C++11)
	
	//int a = 3;
	//float b = 3.14f;
	//double c = 1.23;
	//Knight d = Knight();
	//const char* e = "rookiss";

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "rookiss";

	// auto 는 일종의 조커 카드
	// 형식 연역 (type deduction)
	// -> 말이 되게 잘 맞춰봐~ (추론)
	// 추론 규칙은 생각보다 복잡해질 수 있다.

	// 주의!
	// 기본 auto는 const, & 무시!!!!!!!!!!!!!!!
	int& reference = a;
	const int cst = a;

	auto test1 = reference;
	auto test2 = cst;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		auto& data = v[i];

		data = 100;
	}

	// 아무튼 이제 기존의 타입은 잊어버리고 auto만 사용할래요.
	// NO! (주관적인 생각)
	// -> 타이핑이 길어지는 경우 OK
	// -> 가독성을 위해 일반적으로는 놔두는게 좋다.
	
	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
```