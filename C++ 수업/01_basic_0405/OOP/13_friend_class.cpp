#include <iostream>
//friend도 객체 지향을 부수는 것으로 여겨지기도 함. 많이 쓰면 안좋음.
//friend는 상속이 안됨.
using namespace std;

#pragma region friend global function
class A
{
	int value = 1;

	friend void doSomething1(const A& a); //프리빗 영역이지만 friend 함수는 전역함수처럼 접근해서 쓸 수 있음.
	/*friend void doSomething2(const A& a)
	{
		cout << a.value << endl;
	}*///이렇게 써도 가능
};

void doSomething1(const A& a)
{
	cout << a.value << endl;
}

int main()
{
	A a;
	doSomething1(a);


	return 0;
}

#pragma endregion


#pragma region friend member class //이게 더 안전함.
class A
{
public:
	void attack(B& b); //클래스 B의 프리빗 변수를 갖고 와서 씀

private:
	int a;
};

class B
{
	friend void A::attack(B& b); //B가 A한테 attack에서 모든 변수에 접근 가능하도록 허용한다는 뜻.

private:
	int hp = 100;
};


void A::attack(B& b)
{
	cout << "b의 체력 : " << b.hp << endl;

	cout << "공격!" << endl;
	b.hp -= 10;
}

int main()
{
	A a;
	B b;

	//b.a; 이런건 불가능(?)
}

#pragma endregion


#pragma region friend class

class A
{
public:
	void PrintBValue1(class B& b);
	void PrintBValue2(class B& b);
};

class B
{
	friend class A; // B의 모든 멤버 변수를 A에서 접근 가능함.
	int value1 = 10;
	int value2 = 20;
};

void A::PrintBValue1(B& b)
{
	cout << b.value1 <<endl;
}

void A::PrintBValue2(B& b)
{
	cout << b.value2 << endl;
}

int main()
{
	A a;
	B b;

	a.PrintBValue1(b);
	a.PrintBValue2(b);
}

#pragma endregion


