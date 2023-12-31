# 오른값 참조 (rvalue reference)

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : 오른값(rvalue) 참조와 std::move
class Pet
{

};

class Knight
{
public:

	void PrintInfo() const
	{

	}

	// 기본 생성자
	Knight() { cout << "Knight()" << endl; }
	// 복사 생성자
	Knight(const Knight& knight) { cout << "const Knight()" << endl; }
	// 이동 생성자
	Knight(Knight&& knight) { cout << "Knight(Knight&&)" << endl; }
	// 소멸자
	~Knight() { if (_pet) delete _pet; }
	// 복사 대입 연산자
	void operator = (const Knight& knight) 
	{ 
		cout << "operator = (const Knight&)" << endl; 
		
		// 깊은 복사
		_hp = knight._hp;

		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// 이동 대입 연산자
	void operator = (Knight&& knight)
	{
		cout << "operator = (Knight&&)" << endl;

		// 얕은 복사
		_hp = knight._hp;
		_pet = knight._pet;

		// 이동 대입 연산자는 원본을 무효화시켜야함
		knight._hp = 0;
		knight._pet = nullptr;
	}


public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) { }
// 왼값을 받는 참조 & (lvalue reference)
// Knight 원본을 넘겨줄테니까 너가 얘를 수정할수도 있고, 원본을 가지고 놀면 돼
void TestKnight_LvalueRef(Knight& knight) { }
// const 가 붙은 함수만 호출할 수 있게 됨. (const가 없으면 const가 붙은 함수를 호출할 수 없음)
// 내가 원본을 넘겨주긴 넘겨줄건데, 원본을 수정해선 안되고, 변경이 일어나는 짓거리는 해선 안돼. 읽기만 해
void TestKnight_ConstLvalueRef(const Knight& knight) { knight.PrintInfo(); }
// 오른값을 받는 참조 && (rvalue reference)
// 내가 원본을 넘겨줄텐데, 읽고 쓰고도 맘대로 할 수 있고, 걔는 더 이상 활용하지도 않을테니까 너 멋대로 해도 돼
void TestKnight_RvalueRef(Knight&& knight) {  } // 이동 대상!




int main()
{
	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체 즉 메모리에 이름이 있는 값
	// - rvalue : 단일식이 끝나면 사라지는 개체 즉 메모리에 이름이 없는 값 (임시 값, 열거형, 람다, i++ 등)

	int a = 3;		// a는 lvalue

	a = 4;			// 4는 rvalue


	Knight k1;		// k1은 lvalue

	TestKnight_Copy(k1);
	TestKnight_LvalueRef(k1);
	TestKnight_ConstLvalueRef(Knight());
	// 왼값 참조는 오른값을 받을 수 없음
	// 따라서 오른값을 받아야함
	TestKnight_RvalueRef(Knight());
	TestKnight_RvalueRef(static_cast<Knight&&>(k1));

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다 << 는 Hint를 주는 쪽에 가깝다!
	Knight k3;
	// 이동 대입 연산자 호출
	// k3 = static_cast<Knight&&>(k2);

	k3 = std::move(k2); // 오른값 참조로 캐스팅하는것과 같음
	// std::move의 본래 이름 후보 중 하나가 rvalue_cast

	// 포인터는 포인터인데 이 세상에서 하나만 존재해야함.
	// 유니크 포인터
	std::unique_ptr<Knight> uptr = std::make_unique<Knight>();
	std::unique_ptr<Knight> uptr2 = std::move(uptr);

	return 0;
}

```

