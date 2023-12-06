# 포인터 vs 배열

```cpp
#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 배열

void Test(int a)
{
    a++;
}

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환된다. (char[] -> char*)
// 즉 배열의 내용 전체를 넘긴게 아니라, 시작주소 (포인터)를 넘긴다.
void Test(char a[])
{
    a[0] = 'x';
}

int main() 
{
    // 문자열 = 문자 배열

    // .rdata 주소[H][e][l][l][o][][W][o][r][l][d][\0]
    // test1[ 주소 ] << 8바이트
    const char* test1 = "Hello World";
    // test1[0] = 'R';
    // 데이터가 안에 있는 느낌보다 원격으로 주소를 가리켜서 있는것이라 데이터 수정이 안됨 물론 const의 영향도 있곘지만.
    
    // 4바이트 4바이트 씩 열심히 운반해서 만든 것
    // .data 주소 [H][e][l][l][o][][W][o][r][l][d][\0]
    // 별도의 바구니가 생성된 개념이 아니다.
    // test2 = 주소
    char test2[] = "Hello World";
    test2[0] = 'R';

    // cout << test2 << endl; // "Rello World"

    // 포인터는 [주소를 담는 바구니]
    // 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
    // - 다만 [배열 이름]은 '바구니 모음'의 [시작 주소] 을 의미하는데, 이게 중요하다. 데이터를 다 옮겨온다는게 아니라 성능좋게 주소로 찍어준다는 의미.

    // 배열을 함수의 인자로 넘기게 되면?
    int a = 0;
    // [매개변수][RET][지역변수(a=0)]
    Test(a);
    cout << a << endl;

    // test2가 바뀔까? 안바뀔까? -> 바뀐다!
    // 실질적으로 자기 주소값만 넘겨주는것이기에 바뀌는 것이다.
    Test(test2);
    cout << test2 << endl;

    return 0;
}
```