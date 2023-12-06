# const 와 메모리 구조

```cpp
#include <iostream>
using namespace std;

// 오늘의 주제 : 데이터 연산3
// 데이터를 가공하는 방법에 대해서 알아봅시다.

unsigned char flag; // 부호를 없애야 >> 를 하더라도 부호 비트가 딸려오지 않음.

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 ( 변수를 상수화 한다고 함 )
// const 를 붙였음녀 초기값을 반드시 지정해야 함

// 그러면 const도 바뀌지 않는 읽기 전용
// .rodata?
// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러 (VS) 마음이라는 것.
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// 전역 변수

// [ 데이터 영역 ]  
int a = 2;

// .bss [ 초기값 없는 경우 ]
int b;        

// .rodata ( 읽기 전용 데이터 )
const char * msg = "Hello World";

int main()
{
	/*
	// 그러면 const도 바뀌지 않는 읽기 전용
	// .rodata?
	// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음
	// 그냥 컴파일러 (VS) 마음이라는 것.
	const int AIR = 0;
	const int STUN = 1;
	const int POLYMORPH = 2;
	const int INVINCIBLE = 3;
	이렇게 넣으면 스택 영역에 들어가는 경우가 될 가능성이 있음.  (이건 디테일의 이야기)
	*/

	//	[ 스택 영역 ]
	int c = 3;

#pragma region 비트 연산

	// 언제 필요한가? ( 사실 많이는 없음 )
	// 비트 단위의 조작이 필요할 때
	// - 대표적으로 BitFlag

	// ~ bitwise not																													
	// 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0으로 뒤바꿈

	// &  bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로, and를 한다.

	// | bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로, or를 한다.

	// ^ bitwise xor
	// 두 숫자의 모든 비트 쌍을 대상으로, xor를 한다. ( 같으면 싫고 다르면 좋다 = xor 뜻 )

	// << 비트 좌측 이동
	// 비트 열을 N만큼 왼쪽으로 이동
	// 왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 오른쪽의 N개의 비트는 0.
	// *2를 할 때 자주 보이는 패턴

	// >> 비트 우측 이동
	// 비트 열을 N만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 N개의 비트는 버림.
	// 왼쪽 생성되는 N개의 비트는	 
	// - 부호 비트가 존재할 경우 부호 비트를 따라감 ( 부호있는 정수라면 이 부분을 유의 )
	// - 아니면 0

	// 실습
	// 0b0000 [ 무적 ] [ 변이 ] [ 스턴 ] [ 공중부양 ]

	// 무적 상태를 만든다.
	flag = (1 << INVINCIBLE);  // 0000 1000 

	// 변이 상태를 추가한다. ( 무적 + 변이 )
	flag |= (1 << POLYMORPH); // 0000 1100

	// 무적인지 확인하고 싶다? ( 다른 상태는 관심 X )
	// bitmask ( 가면을 씌워서 원하는 부분을 추출했다. )cc
	bool invicible = (flag & (1 << INVINCIBLE)) != 0; // 0이냐 아니냐를 보면 무적인지 알 수 있다.

	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool stunOrInvincible = ((flag & 0b1010));
#pragma endregion
}
```