# TextRPG

```cpp
#include <iostream>
using namespace std;

// 오늘의 주제 : TextRPG

enum PlayerType
{
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3,
};

enum MonsterType
{
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3,
};

int playerType;
int hp;
int attack;
int defence;

int monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
    srand(time(0));
    EnterLobby();

    return 0;
}

void EnterLobby()
{
    while (true)
    {
        cout << "---------------" << endl;
        cout << "로비에 입장했습니다!" << endl;
        cout << "---------------" << endl;

        // 플레이어 직업 선택
        SelectPlayer();

        cout << "---------------" << endl;
        cout << "(1) 필드 입장 (2) 게임 종료" << endl;
        cout << "---------------" << endl;

        int input;
        cin >> input;

        if (input == 1)
        {
            EnterField();
        }
        else
        {

        }
    }
}
void SelectPlayer()
{
    cout << "---------------" << endl;
    cout << "직업을 골라주세요!" << endl;
    cout << "(1) 기사 (2) 궁수 (3) 마법사" << endl;
    cout << "---------------" << endl;

    cin >> playerType;

    if (playerType == PT_Knight)
    {
        cout << "기사 생성중... !" << endl;
        hp = 150;
        attack = 10;
        defence = 5;
        return;
    }
    else if (playerType == PT_Archer)
    {
        cout << "궁수 생성중... !" << endl;
        hp = 100;
        attack = 15;
        defence = 3;
        return;
    }
    else if (playerType == PT_Mage)
    {
        cout << "기사 생성중... !" << endl;
        hp = 100;
        attack = 20;
        defence = 0;
        return;
    }
}

void EnterField()
{
    while (true)
    {
        cout << "---------------" << endl;
        cout << "필드에 입장했습니다!" << endl;
        cout << "---------------" << endl;

        cout << "[PLAYER] HP : " << hp << " / ATT : " << attack << " / DEF : " << defence << endl;

        CreateRandomMonster();

        cout << "---------------" << endl;
        cout << "(1) 전투 (2) 도주" << endl;
        cout << "> ";

        int input;
        cin >> input;

        if (input == 1)
        {
            EnterBattle();
            if (hp == 0)
                return;
        }
        else
        {
            return;
        }
    }

}

void CreateRandomMonster()
{
    // 1 ~ 3
    monsterType = 1 + (rand() % 3); 

    switch (monsterType)
    {
    case MT_Slime:
        cout << "슬라임 생성중....! (HP: 15 / ATT: 5 / DEF: 0)" << endl;
        monsterHp = 15;
        monsterAttack = 5;
        monsterDefence = 0;
        break;
    case MT_Orc:
        cout << "오크 생성중....! (HP: 40 / ATT: 10 / DEF: 3)" << endl;
        monsterHp = 40;
        monsterAttack = 10;
        monsterDefence = 3;
        break;
    case MT_Skeleton:
        cout << "해골 생성중....! (HP: 80 / ATT: 15 / DEF: 5)" << endl;
        monsterHp = 80;
        monsterAttack = 15;
        monsterDefence = 5;
        break;
    }
}
void EnterBattle()
{
    while (true)
    {
        int damage = attack - monsterDefence;
        if (damage < 0)
            damage = 0;

        monsterHp -= damage;
        if (monsterHp < 0)
            monsterHp = 0;

        cout << "몬스터 남은 체력 : " << monsterHp << endl;
        if (monsterHp == 0)
        {
            cout << "몬스터를 처치했습니다!" << endl;
            return;
        }

        damage = monsterAttack - defence;
        if (damage < 0)
            damage = 0;

        // 반격
        hp -= damage;
        if (hp < 0)
            hp = 0;

        cout << "플레이어 남은 체력 : " << hp << endl;
        if (hp == 0)
        {
            cout << "당신은 사망했습니다. Game Over" << endl;
            return;
        }
    }
}
```

**‘구조체’**도 미리 예습했다.

```cpp
#include <iostream>
using namespace std;

// 오늘의 주제 : TextRPG

enum PlayerType
{
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3,
};

enum MonsterType
{
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3,
};

// 구조체 ( 예습 )
struct ObjectInfo
{
    int type;
    int hp;
    int attack;
    int defence;
};

ObjectInfo playerInfo;

ObjectInfo monsterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
    srand(time(0));
    EnterLobby();

    return 0;
}

void EnterLobby()
{
    while (true)
    {
        cout << "---------------" << endl;
        cout << "로비에 입장했습니다!" << endl;
        cout << "---------------" << endl;

        // 플레이어 직업 선택
        SelectPlayer();

        cout << "---------------" << endl;
        cout << "(1) 필드 입장 (2) 게임 종료" << endl;
        cout << "---------------" << endl;

        int input;
        cin >> input;

        if (input == 1)
        {
            EnterField();
        }
        else
        {

        }
    }
}
void SelectPlayer()
{
    cout << "---------------" << endl;
    cout << "직업을 골라주세요!" << endl;
    cout << "(1) 기사 (2) 궁수 (3) 마법사" << endl;
    cout << "---------------" << endl;

    cin >> playerInfo.type;

    if (playerInfo.type == PT_Knight)
    {
        cout << "기사 생성중... !" << endl;
        playerInfo.hp = 150;
        playerInfo.attack = 10;
        playerInfo.defence = 5;
        return;
    }
    else if (playerInfo.type == PT_Archer)
    {
        cout << "궁수 생성중... !" << endl;
        playerInfo.hp = 100;
        playerInfo.attack = 15;
        playerInfo.defence = 3;
        return;
    }
    else if (playerInfo.type == PT_Mage)
    {
        cout << "기사 생성중... !" << endl;
        playerInfo.hp = 100;
        playerInfo.attack = 20;
        playerInfo.defence = 0;
        return;
    }
}

void EnterField()
{
    while (true)
    {
        cout << "---------------" << endl;
        cout << "필드에 입장했습니다!" << endl;
        cout << "---------------" << endl;

        cout << "[PLAYER] HP : " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF : " << playerInfo.defence << endl;

        CreateRandomMonster();

        cout << "---------------" << endl;
        cout << "(1) 전투 (2) 도주" << endl;
        cout << "> ";

        int input;
        cin >> input;

        if (input == 1)
        {
            EnterBattle();
            if (playerInfo.hp == 0)
                return;
        }
        else
        {
            return;
        }
    }

}

void CreateRandomMonster()
{
    // 1 ~ 3
    monsterInfo.type = 1 + (rand() % 3); 

    switch (monsterInfo.type)
    {
    case MT_Slime:
        cout << "슬라임 생성중....! (HP: 15 / ATT: 5 / DEF: 0)" << endl;
        monsterInfo.hp = 15;
        monsterInfo.attack = 5;
        monsterInfo.defence = 0;
        break;
    case MT_Orc:
        cout << "오크 생성중....! (HP: 40 / ATT: 10 / DEF: 3)" << endl;
        monsterInfo.hp = 40;
        monsterInfo.attack = 10;
        monsterInfo.defence = 3;
        break;
    case MT_Skeleton:
        cout << "해골 생성중....! (HP: 80 / ATT: 15 / DEF: 5)" << endl;
        monsterInfo.hp = 80;
        monsterInfo.attack = 15;
        monsterInfo.defence = 5;
        break;
    }
}
void EnterBattle()
{
    while (true)
    {
        int damage = playerInfo.attack - monsterInfo.defence;
        if (damage < 0)
            damage = 0;

        monsterInfo.hp -= damage;
        if (monsterInfo.hp < 0)
            monsterInfo.hp = 0;

        cout << "몬스터 남은 체력 : " << monsterInfo.hp << endl;
        if (monsterInfo.hp == 0)
        {
            cout << "몬스터를 처치했습니다!" << endl;
            return;
        }

        damage = monsterInfo.attack - playerInfo.defence;
        if (damage < 0)
            damage = 0;

        // 반격
        playerInfo.hp -= damage;
        if (playerInfo.hp < 0)
            playerInfo.hp = 0;

        cout << "플레이어 남은 체력 : " << playerInfo.hp << endl;
        if (playerInfo.hp == 0)
        {
            cout << "당신은 사망했습니다. Game Over" << endl;
            return;
        }
    }
}
```
