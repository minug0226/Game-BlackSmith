#  전달 참조 (forwarding reference)

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : 전달 참조(forwarding reference)
// 전달 참조란? 함수 인자가 rvalue인지 lvalue인지 구분하지 않고 받는 것

class Knight
{
public:
	// 기본생성자
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// 복사생성자
	Knight(const Knight&)
	{
		cout << "Knight(const Knight&)" << endl;
	}
	
	// 이동생성자
	Knight(Knight&&) noexcept
	{
		cout << "Knight(Knight&&)" << endl;
	}

};

void Test_RValueRef(Knight&& k) // 오른값 참조
{

}

void Test_Copy(Knight k)
{

}


template<typename T>
void Test_ForwardingRef(T&& param) // 전달 참조
{
	// 왼값 참조라면 왼값 참조, 오른값 참조라면 오른값 참조
	Test_Copy(std::forward<T>(param));
}


int main()
{
	// 보편 참조(universal reference)
	// 전달 참조 (forwarding reference) C++17

	// && &를 두번쓰면 오른값 참조

	Knight k1;

	Test_RValueRef(std::move(k1)); // rvalue로 캐스팅

	Test_ForwardingRef(k1);
	Test_ForwardingRef(std::move(k1));
	
	auto&& k2 = k1; // k2는 lvalue
	auto&& k3 = std::move(k1); // k3는 rvalue

	// 공통점 : 형식 연역 (type deduction)이 일어난다
	// 연역이란? "컴파일러가 알아서 형식을 추론해준다"

	// 전달 참조를 구별하는 방법
	// ---------------------------------
	
	Knight& k4 = k1; // 왼값 참조
	Knight&& k5 = std::move(k1); // 오른값 참조

	// 오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용 X
	// 오른값 참조 : 오른값만 참조할 수 있는 참조타입
	Test_RValueRef(std::move(k5));

	Test_ForwardingRef(k1); // 왼쪽값 참조로 실행
	Test_ForwardingRef(std::move(k1)); // 오른값 참조로 실행


	return 0;
}

```

