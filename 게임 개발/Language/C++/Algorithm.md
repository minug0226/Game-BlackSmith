# Algorithm

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : 알고리즘

int main()
{
	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (데이터를 어떻게 사용할 것인가?)
	// 둘은 1+1 짝궁 같은 느낌이다.

	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if

	srand(static_cast<unsigned int>(time(nullptr)));
	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it = v.end();

		// TODO
		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data == number)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}

		// 위에서 만든 로직과 같음. 참 쉬워지죠?
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end())
		{
			// 못찾았음
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}
	}
	

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;
		vector<int>::iterator it;

		// TODO
		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if ((data % 11) == 0)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}

		// find_if 를 사용하기 위해
		struct CanDivideBy11
		{
			bool operator() (int n) 
			{
				return(n % 11) == 0;
			}
		};

		// 함수객체를 마지막에.
		// 끝에 CanDivideBy11() 를 Value로 넣어도 되지만
		// 이와 같이 람다 형식 -> 1회성 함수 만드는 방식을 사용할 수도 있다.
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n) { return (n % 11) == 0; });
		if (itFind == v.end())
		{
			// 못찾았음
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		// TODO
		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if ((data % 2) != 0)
			{
				count++;
			}
		}

		struct IsOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());
		
		// 모든 데이터가 홀수입니까?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닙니까?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());
	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		// TODO
		for (unsigned int i = 0; i < v.size(); i++)
		{
			v[i] *= 3;
		}

		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n = n * 3;
			}
		};

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Q5) 홀수인 데이터를 일괄 삭제해주세요!
	{
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		// 1 4 3 5 8 2
		// 4 8 2 5 8 
	
		// remove(v.begin(), v.end(), 4);
		
		struct IsOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};
		
		// remove_if 는 데이터를 날려주는 부분은 전혀없고
		// 순서를 재조정해주고 필요한 데이터를 모아놓고
		// 사용하지 않아서 날려도 되는 값들을 첫 위치를 반환해주는 역할을 함
		vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
		
		// 이렇게해줘야 불필요한 값들도 삭제를 해준다.
		v.erase(it, v.end());

		// 따라서 remove_if 를 사용할거면 erase를 함께 사용해주자.
		// 위 코드를 이렇게 한번에 쓰는게 좋아보인다!
		v.erase(remove_if(v.begin(), v.end(), IsOdd()));

		int a = 3;
	}

	return 0;
}
```