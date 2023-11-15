# vector # 1

```cpp
#include <iostream>
using namespace std;
#include <vector>

// 오늘의 주제 : vector # 1

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조 / 알고리즘 들을 
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너 (Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근 

	// 동적 배열
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다.
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.

	// Q1) 여유분은 얼만큼이 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존의 데이터를 어떻게 처리할까?

	vector<int>v;

	// 생성과 동시에 resize가 가능하며 초기값도 정해줄 수 있다.
	// vector<int>v(1000, 0);

	// vector 그대로를 값을 넣어줄 수도 있다.	
	// vector<int>v2 = v; 

	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7....

	// resize (size의 시작을 말함)
	// v.resize(1000);

	// capacity (여유분을 포함한 용량 개수)
	// 1 2 3 4 6 9 13 19 28 42 63...

	// 면접에서도 나옴.
	// reserve (capacity의 첫 시작을 정해준다)
	// 1000 2000 4000 8000
	v.reserve(1000);

	// push_back (데이터를 추가한다)

	for (int i = 0; i < 1000; i++)
	{
		// v[i] = 100;
	    v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	// 임시로 만들어진 애는 swap을 통해서
	// 아무 정보도 안가지고 있게 만들 수 있다.
	// 임시 벡터이기에 소멸이 되버리는 것. (메모리 관리 실무 TIP)
	vector<int>().swap(v);
	cout << v.size() << " " << v.capacity() << endl;
	
	// 처음에 있는 데이터가 뭔지 본다.
	v.front();
	// 마지막에 있는 데이터가 뭔지 본다.
	v.back();
	// 마지막에 있는 데이터를 빼온다.
	v.pop_back(); 

	return 0;
};

s
```