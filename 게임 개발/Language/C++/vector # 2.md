# vector # 2

```cpp
#include <iostream>
using namespace std;
#include <vector>

// 오늘의 주제 : vector # 2

int main()
{
	// 컨테이너 (Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근 

	// 반복자 (Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int>v(10);
	
	// type에 맞게 알아서 변환
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	// 어떤 특정 클래스 타입이다.
	// 얘가 포인터랑 유사한 개념이다.
	// vector<int>::iterator it;
	// int* ptr;

	// vector의 iterator를 반환
	// it = v.begin();
	// ptr = &v[0];

	// cout << (*it) << endl;
	// cout << (*ptr) << endl;

	// int a = 1;
	// (b = 1, a = 2)
	// int b = a++;
	// (c = 2, a = 2)
	// int c = ++a;
	
	// 다음 데이터로 넘어가기
	// it++;
	// ++it;
	// ptr++;
	// ++ptr;

	// 이전 데이터로 돌아가기
	// it--;
	// --it;
	// ptr--;
	// --ptr;

	// 큼지막하게 넘어가기
	// it += 2;

	// 이전이전으로 돌아가기
	// it = it - 2;

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	// 더 복잡해보이는데?
	// // 다른 컨테이너는 v[i] 와 같은 인덱스 접근이 안 될 수도 있음 (인접 접근에 대한 이야기)
	// iterator는 vector 뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	// 다른 자료구조로 다른 컨테이너로 넘어가기 수월해진다는 장점이 있다.
	// 그래서 선택의 여부 vector 한에서만.
	// 아래를 고를 수도 있다.
	// 	for (vector<int>::size_type i = 0; i < v.size(); i++)
	// 	v[i] = i;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}
	
	// 위와 같다. 포인터가 숨겨져 있다 라고 할수 있다는걸 보여줌.
	// 시작 포인터와 끝나는 포인터 지점을 정해주기
	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// 수정안하고 READ 하기만 할때 씀.
	// const int*; 와 같다.
	vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100;

	// 역방향 반복자도 존재한다.
	// [                    ] 끝에서 처음으로, 거꾸로 이동하는 반복자
	// 생각보다 역방향으로 쓰는, 실질적으로 활용하는 일은 거의 생기진 않을것이다.
	for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
	{
		cout << (*rit) << endl;
	}

	return 0;
};
```