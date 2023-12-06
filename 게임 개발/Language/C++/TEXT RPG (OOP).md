# TEXT RPG (OOP)

## Files

### CPP files

- CPP_Stdudy.cpp (main)
- Player.cpp
- Monster.cpp
- Creature.cpp
- Game.cpp
- Field.cpp

### Header files

- Player.h
- Monster.h
- Creature.h
- Game.h
- Field.h

## Code

CPP_Study.cpp

```cpp
#include <iostream>
using namespace std;
#include "Game.h"

// 오늘의 주제 : TextRPG (OOP)

int main()
{
	srand((unsigned int) time(nullptr));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return 0;
};
```

Player.cpp

```cpp
#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "-----------------------" << endl;
	cout << "[플레이어 정보] " << "HP: " << _hp << " ATT: " << _attack << " DEF : " << _defence << endl;
	cout << "-----------------------" << endl;
}
```

Monster.cpp

```cpp
#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "-----------------------" << endl;
	cout << "[몬스터 정보] " << "HP: " << _hp << " ATT: " << _attack << " DEF : " << _defence << endl;
	cout << "-----------------------" << endl;
}
```

Creature.cpp

```cpp
#include "Creature.h"
#include <iostream>
using namespace std;

void Creature::OnAttacked(Creature* attacker)
{
	int damgae = attacker->_attack - _defence;
	if (damgae < 0)
		damgae = 0;

	_hp -= damgae;
	if (_hp < 0)
		_hp = 0;
}
```

Game.cpp

```cpp
#include <iostream>
// namespace = 이름 공간 std::cout 
// using nmaespace >> std를 붙이지 않아도 됨 cout
using namespace std;
#include "Game.h"
#include "Player.h"
#include "Field.h"

Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game()
{
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;
}

void Game::Init()
{
	_field = new Field();
} 

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();

	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "-------------------" << endl;
		cout << "캐릭터를 생성하세요!" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "-------------------" << endl;

		cout << "> ";

		int input = 0;
		cin >> input;

		if (input == PT_Knight)
		{
			_player = new Knight();
		}
		else if (input == PT_Archer)
		{
			_player = new Archer();
		}
		else if (input == PT_Mage)
		{
			_player = new Mage();
		}
	}
}
```

Field.cpp

```cpp
#include "Field.h"
#include <iostream>
#include "Monster.h"
#include "Player.h"
using namespace std;

Field::Field() : _monster(nullptr)
{

}

Field::~Field() 
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();
	
	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = 1 + rand() % 3;

	switch (randValue)
	{
	case MT_SLIME:
		_monster = new Slime();
		break;
	case MT_ORC:
		_monster = new Orc();
		break;
	case MT_SKELETON:
		_monster = new Skeleton();
		break;
	}
}

void Field::StartBattle(Player* player)
{
	// 무한 루프
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		// 플레이어->몬스터 공격
		_monster->OnAttacked(player);
		
		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		// 몬스터->플레이어 공격
		player->OnAttacked(_monster);

		if (player->IsDead())
		{
			// 생명주기때문에, 얘는 제일 높은 Game이 관리하기에.
			// 결국 Game.h가 도맡아서 nullptr을 해줘야함.
			player->PrintInfo();
			break;
		}
	}
}
```

Player.h

```cpp
#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

// [ [ Creature ] ]
// [              ]
// include 해서 가져와야함. Creature.h

class Player : public Creature
{
public:
	Player(int playerType) : Creature(CT_PLAYER), _playerType(playerType)
	{

	}

	virtual ~Player()
	{

	}

	virtual void PrintInfo();

protected:
	int _playerType;

};

class Knight : public Player
{
public:
	Knight() : Player(PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}
};

class Archer : public Player
{
public:
	Archer() : Player(PT_Archer)
	{
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player
{
public:
	Mage() : Player(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}
};
```

Monster.h

```cpp
#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELETON = 3,
};

class Monster : public Creature
{
public:
	Monster(int monsterType) 
		: Creature(CT_MONSTER), _monsterType(monsterType)
	{

	}

	virtual void PrintInfo();

protected:
	int _monsterType;
};

class Slime : public Monster
{
public:
	Slime() : Monster(MT_SLIME)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
};

class Orc : public Monster
{
public:
	Orc() : Monster(MT_ORC)
	{
		_hp = 80;
		_attack = 8;
		_defence = 3;
	}
};

class Skeleton : public Monster
{
public:
	Skeleton() : Monster(MT_SKELETON)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
};
```

Creature.h

```cpp
#pragma once

enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1,
};

class Creature
{
public:
	Creature(int creatureType)
		: _creatureType(creatureType), _hp(0), _attack(0), _defence(0)
	{

	
	}

	virtual ~Creature()
	{

	}

	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }

protected:
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;

};
```

Game.h

```cpp
#pragma once
// 순환구조가 되지않게끔 include 사용을 주의하자

// 전방 선언
class Player;
class Field;

// [ [ Player ] ]
// [            ]

// is - a
// has - a
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();
	void Filed();
private:

	// 좋지 않다. 이렇게 되면 의존성이 너무 높아진다. 나중가면 기사인지 궁수인지 모르게 될 수도 있다.
	// Player _player;

	// 우선적으로 이런 방식을 선호하자
	// [ 4~8 ] 크기 --->> [			]
	Player* _player;
	Field* _field;
};
```

Field.h

```cpp
#pragma once

// 포인터 즉 주소를 담는 바구니들이라서 그냥 전방선언만 해줘도 된다.
class Player;
class Monster;

class Field
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();

	void StartBattle(Player* player);

private:
	Monster* _monster;

};
```