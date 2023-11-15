# 참조 vs 포인터

```cpp
#include <iostream>
using namespace std;

// 오늘의 주제 : 참조 vs 포인터

struct StatInfo
{
    int hp; // +0
    int attack; // +4
    int defence; // +8
};

// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
// 주소를 직접 건드리기때문에 원본값이 변경이 된다는 장점이 있음.
void CreateMonster(StatInfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;
}

// *가 붙어있지않으면 값방식
// [매개변수][RET][지역변수(info)][매개변수(info(100, 8, 5))][RET][지역변수]
void CreateMonster(StatInfo info)
{
    info.hp = 100;
    info.attack = 8;
    info.defence = 5;

}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음.

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(info                                        )][RET][지역변수]
void PrintInfoByCopy(StatInfo info)
{
    cout << "----------------------------" << endl;
    cout << "HP: " << info.hp << endl;
    cout << "ATT: " << info.attack << endl;
    cout << "DEF: " << info.defence << endl;
    cout << "----------------------------" << endl;
}
    
StatInfo* FindMonster()
{
    // TODO : Heap 영역에서 뭔가를 찾아봄
    // 찾았다!
    // return monster~;

    return nullptr;

}

StatInfo globalInfo;
// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void PrintInfoByPtr(StatInfo* info)
{   
    if (info == nullptr)
        return;

    cout << "----------------------------" << endl;
    cout << "HP: " << info->hp << endl;
    cout << "ATT: " << info->attack << endl;
    cout << "DEF: " << info->defence << endl;
    cout << "----------------------------" << endl;

    // Statinfo* const info -> 별 뒤에 붙인다면?
    // info 라는 바구니의 내용물(주소)을 바꿀 수 없음.
    // info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!
        

    // const StatInfo* info -> 별 앞에 붙인다면?
    // info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음.
    // '원격' 바구니의 내용물을 바꿀 수 없음.

    // info[ 주소값 ]                  주소값 [ 데이터 ]
    info = &globalInfo;

    info->hp = 10000;

    // 양쪽에 다 const StatInfo* const info 로 줘서 둘다 막아줄 수 있음.
    // 안정성을 도모할 수 있다는 장점이 있네 포인터가!
}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트
// - (참조 전달) StatInfo&는 8바이트
// 선택의 차이로 인한 성능차이가 일어날 수 밖에 없다.

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 진퉁을 건드리는!
// 일석이조의 방식!

// 참조같은 경우 어지간하면 상수랑 같이 씀.
// 안정성을 위해.
void PrintInfoByRef(const StatInfo& info)
{
    cout << "----------------------------" << endl;
    cout << "HP: " << info.hp << endl;
    cout << "ATT: " << info.attack << endl;
    cout << "DEF: " << info.defence << endl;
    cout << "----------------------------" << endl;

    // 신입이 왔다.
    // 이상한거 여기다가 넣으면?
    // info.hp = 10000;
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{
    info.hp = 1000;
}

int main()

{   
    StatInfo info;

    CreateMonster(&info);

    // 참조 vs 포인터 세기의 대결
    // 성능 : 똑같음!
    // 편의성 : 참조 승!

    // 1) 편의성 관련
    // 편의성이 좋다는게 꼭 장점만은 아니다.
    // 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데,
    // 참조는 자연스럽게 모르고 지나칠 수도 있다!
    // ex) 마음대로 고친다면?
    // const를 사용해서 이런 마음대로 고치는 부분 개선 가능

    // 참고로 포인터에서도 const를 사용 가능.
    // * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐의 따라 의미가 달라진다.
    // 안정성을 가져야한다는 결론을 얻을 수 있다.

    // 2) 초기화 여부
    // 참조 타입은 어떤 바구니의 2번째 이름 ( 별칭? )
    // -> 참조하는 대상이 없으면 안됨
    // 반면 포인터는 그냥 어떤- 주소라는 의미
    // -> 대상이 실존하지 않을 수도 있음
    // 포인터에서 '없다'는 의미로는 어떻게 ?
    // nullptr <- 어떠한 주소도 가리키지 않는다. that's like 0 
    // 참조 타입은 이런 nullptr이란 개념이 없다.

    StatInfo* pointer= nullptr; 
    pointer = &info;
    PrintInfoByPtr(pointer);

    StatInfo& reference = info;
    reference = info;
    PrintInfoByRef(reference);

    PrintInfoByPtr(&info);
    
    PrintInfoByRef(info);

    // 그래서 결론은?
    // 사실 Team By Team... 정해진 답은 없다.
    // ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
    // ex) 언리얼 엔진에선 reference도 애용

    // 선호 스타일)
    // - 없는 경우도 고려해야 한다면 pointer (null 체크 필수)
    // - 바뀌지 않고 읽는 용도 (readonly)만 사용하면 const ref&
    // - 그 외 일반적으로 ref  (명시적으로 호출할 때 OUT을 붙인다)
    // -- 단, 다른 사람이 pointer를 만들어놓은걸 이어서 만든다면, 계속 pointer (섞어 사용하진 않는다)
    ChangeInfo(OUT info);

    // Bonus) 포인터를 사용하던걸 참조로 넘겨주려면?
    // pointer[ 주소(&info) ] info[ 데이터 ]
    /*
    StatInfo& ref = *pointer;
    PrintInfoByRef(ref);
    아래 처럼 한줄로 가능.
    */
    PrintInfoByRef(*pointer);

    // Bonus) 참조로 사용하던걸 참조로 넘겨주려면?
    // pointer[ 주소 ] reference, info [ 데이터 ]
    PrintInfoByRef(&reference);

    return 0;
}
```