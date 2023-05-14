# 00_OOP(객체지향, Object Oriented Programming)
pop(절차지향, Procedual Oriented Programming)는 코드 순서대로 실행되고, OOP는 객체 단위로 실행된다.
## 객체지향의 4대 특징
### 	추상화(Abstraction)
- 모델링이라고 보면 됨. 특성을 조합해 주는 것.
### 캡슐화(Encapsulation) (정보은닉(Informaiotn hiding))
- 객체의 속성이나 동작 같은 것들을 클래스로 묶는 것.
- 외부에 필요한 내용만 공개해서 나만의 변수들은 숨기는 것은 정보은닉(리모콘의 회로 구조는 몰라도 버튼을 통해서 사용할 수 있는 것)
### 상속(Inheritance)
- 상위, 하위 클래스가 존재(상위의 특성을 물려 받는 하위 클래스가 있어서 "재사용과 확장"의 의미가 있음)
### 다형성(Polymorphism)
- 하나의 객체가 여러가지 자료형을 가지고 있는 것
    - 오버로딩 : 같은 이름 함수가 여러 개 있는 데 매개변수 등의 자료형을 달리 해서 구별하는 것.
	- 오버라이딩 : 부모 클래스에서 상속 받은 것을 자식 클래스에서 재정의하는 것.

# 01_class
간단하게 변수만 쓸 때에는 struct가 좋고, 동작을 나타내는 등으로 쓸 때에는 class가 좋음.
## 접근 지정자
C++의 접근 지정자는 객체지향의 중요한 특징인 '캡슐화'를 지원하는 역할을 한다.
- private : 동일한 클래스 멤버 함수만 접근 가능
- public : 외부 함수도 접근 가능
- protected : 자신과 자신을 상속받는 클래스만 접근 가능

## struct
```cpp
struct person
{
private : //struct도 접근 지정자를 쓸 수 있지만 private를 생략했을 때 class처럼 자동으로 은닉되지는 않음.

	string name;
	int age;
	float height;
	float weight;
	bool favorite;
};
```

## class
```cpp
class Person //선언 자체가 캡슐화, 접근 지정자를 통해 공개할 정보 등을 지정할 수 있음
{
public: //활동들을 다룸
	void Work() //멤버 함수
	{}
	
	void Sleep()
	{}

protected: //나와 자식 클래스에서만 쓸 수 있는 정보

private: //이 클래스 안에서만 사용 가능한 정보, 보통 변수를 다룸
//private를 생략해도 자동으로 은닉된 정보로 인식됨.

	string name; //멤버 변수
	int age;
	float height;
	float weight;
	bool favorite;
};

int main()
{	
    Person p; // 이렇게 해야 실체가 생겨서 object, instance라고 할 수 있음
	person p1; //struct

	p1.age= 1; //error, private는 접근 불가능하므로
	p.Sleep();
	return 0;
}
```

# 02_encapsulation(캡슐화)
```cpp
class Data
{
	int hp;
	int attack;
	float exp; //밑에 private로 명시해 주거나 위에 써주거나 취향 차이.

public:
	void SetData(int hpData, int attackData, float expData)//맴버의 데이터를 초기화 또는 수정하기 위해서는 함수 안에서 해주는 게 좋음
	{
		hp = hpData;
		attack = attackData;
		exp = expData;
	}

	void SetData2(Data data) //이렇게도 넣어줄 수 있음.
	{
		hp = data.hp;
		attack = data.attack;
		exp = data.exp;
	}

	//밖에서 private변수에 접근할 수 없지만 접근하고 싶을때 쓰는 함수
	//객체지향 시스템을 지키면서 접근은 가능하게 쓰는 것
	int GetHp() { return hp; }
	int GetAttack() { return attack; } //이렇게 쓰면 오버헤드(처리 시간이 더 오래 걸리거나 메모리가 쓰이는 등)가 일어날 수 있긴 함
};
```

# 03_Constructor(생성자)
클래스의 객체가 생성되었을 때, 객체를 초기화하는 목적으로 실행하는 함수이다.
함수와 동일하지만 반환값은 존재하지 않는다.
## 기본 생성자(Default constructor)
### 디폴트 생성자
- 매개 변수를 갖지 않거나, 모두 기본값이 설정된 매개 변수를 가지고 있는 생성자.
- 클래스를 인스턴스화할 때 사용자가 초기값을 제공하지 않으면 기본 생성자가 호출된다.
### 매개 변수가 있는 생성자를 사용한 초기화
- 클래스의 인스터스 별 멤버 변수의 값을 특정한 값으로 초기화하고 싶은 경우, 생성자에 매개변수를 선언할 수 있다.

## 복사 생성자(Copy constructor)
- 외부에 존재하는 원본을 복사해서 대입하는 생성자.
- 원본 데이터는 변경하지 않고, 오직 새롭게 초기화되는 인스턴스 변수들에게 '복사'만 하는 것.

## 이동 생성자(Move constructor)
- R-value로 값을 가져와서 이동시키는 것.
```cpp
class Fraction
{
public:
	Fraction() // 기본 생성자 : class랑 이름이 같다.
	{}
	//생성자도 오버로딩이 가능함.

	Fraction(int a, int b)
    {}
	//생성자도 default parameter를 해줄 수도 있지만 모호성 문제때문에 조심해야 함.
	//Fraction(int a = 7, int b = 8)
	//{}

	//복사 생성자
	Fraction(const Fraction& data) //외부에 존재하는 원본을 복사해서 호출하는 방식.(안전하게 const붙여서 가져오기)
	{}

	//이동 생성자
	Fraction(Fraction&& data) noexcept //R value reference로 가져옴. 나 자체를 가져오는 것. noexcept는 예외처리 할 수 없다고 할때 써줌
	{}

private:
	int numerator = 10;
	int denominator = 10;
};

int main()
{
	Fraction frac; //객체 생성.
	Fraction frac1(1, 2); //다른 생성자를 만들었을 때에는 기본 생성자가 무시됨.
	Fraction frac11(1.0, 3); //자료형이 다르지만 오류는 나지 않고 값이 잘림.
	//Fraction frac111{ 1.0, 3 }; 더 엄격한 경우라서 오류 남.

	Fraction frac2(frac1); //복사 생성자 호출할때
	Fraction frac3(std::move(frac1)); //이동 생성자 호출할때
	return 0;
}
```

# 04_Constructor_member_initializer(생성자로 멤버 변수 초기화)
인스턴스화 됨과 동시에 멤버 변수를 초기화하는 것이 필요할때 사용한다.
```cpp
class Data
{
public:
	Data(int aData, int bData, int cData) //생성과 동시에 초기화(변수들이 상수화되기 전에 해야 할 필요가 있기에)
		:a(aData), b(bData), c(cData)     //이렇게 하면 바로 초기화가됨.
	{
/*		a = aData;
		b = bData;
		c = cData;*/ //이런 방식은 매개변수를 복사해서 넣기 때문에 속도가 느림.
	}

private :
	const int a = 10;
	const int b = 10;
	const int c = 10;
};

int main()
{
	Data data1(20, 20, 20);
	return 0;
}
```

# 05_delegeting_constructor(위임 생성자)
어떤 특정 멤버 변수를 다른 걸로 초기화하고 싶을 때 사용한다.
## 첫번째 방법
```cpp
class Student
{
public:
	Student(const int& id, const string& name) //값이 바뀌지 않게 const
		:id(id), name(name) // 이름이 같아도 괄호로 형식 구분이 되므로 괜찮음.
	{}

	//id는 0으로 두고, 이름만 계속 바꾸고 싶다면
	Student(const string& name) 
		:Student(0, name) //다시 나를 불러서 이렇게 하면 됨.(위임 생성자)
	{}

private:
	int id;
	string name;
};
```

## 두번째 방법
```cpp
class Student2
{
public:
	Student(const int& id, const string& name)
	{
		Initialize(id, name); //함수를 만들어서 이렇게도 가능
	}

	Student2(const string& name)
	{
		Initialize(0, name);
	}

	void Initialize(const int& id, const string& name)
	{
		//TODO : 나중에 초기화 해주기 // 보기 - 작업목록에서 볼 수 있음 ( 주석 쉽게 찾는 방법 )
	}

private:
	int id;
	string name;
};
```

# 06_destructor(소멸자)
- 생성자처럼 프로그램이 끝나거나 객체가 소멸될때 자동으로 실행되는 함수이다.
- 반환형이 없고, 할당된 것을 해제하는 용도로 사용한다.
## 기본 형태
```cpp
class Test
{
public:
	Test() //class가 생성될 때 무조건 실행됨
	{
		cout << "Constructor" << endl;
	}

	~Test() //class가 없어질 때 무조건 실행됨
	{
		cout << "Destructor" << endl;
	}
};
```

## 동적할당 해제도 간편히하는 형태
```cpp
class IntArray
{
public:
	IntArray(const int& inLength)
	{
		length = inLength;
		arr = new int[length]; //배열 동적할당
		cout << "constructor" << endl;
	}

	~IntArray()
	{
		delete[] arr; //배열 동적할당 해제
		cout << "destructor" << endl;
	}

private :
	int* arr = nullptr;
	int length = 0;
};
```

# 07_this_pointer_and_chaining_member_function
## this_pointer
객체 자신을 가리키는 용도로 사용되는 포인터
- self reference 형태이다.
- 자료형이 정해져 있지 않다.
```cpp
class Test
{
	int num;

public:
	Test(int n) : num(n)
	{
		cout << "num : " << num << endl;
		cout << "num address : " << &num << endl; 
		cout << "this address : " << this << endl; // Test 자기 자신을 가리키는 포인터
        //this 값 = &num 값
	}

	void ShowTestData()
	{
		cout << num << endl;
	}

	Test* GetThisPointer() //이렇게 반환하기도 함.
	{
		return this;
	}
};

int main()
{
	Test t1(100);
	Test* ptr1 = t1.GetThisPointer(); 
    //Test 클래스의 포인터를 선언해, this를 저장한 것.
    //ptr1은 num의 주소값을 갖게됨.
	cout << ptr1 << endl; //this의 값이 나옴 = &num
	ptr1->ShowTestData(); //num값이 나옴

	return 0;
}
```

## chaining member function
자기 자신을 연쇄적으로 호출하는 함수. -> (return *this)
```cpp
cout << "a" << "b" << "c" << "d" << "e" << endl; //이것도 일종의 chaining
```
### 연산 함수로 표현하고 싶을 때
```cpp
class Calc
{
	int value;

public:
	Calc(int value) : value(value) {}

	void Add(int value) { this->value += value; }
	void Sub(int value) { this->value -= value; }
	void Mul(int value) { this->value *= value; }
	void Div(int value) { this->value /= value; }
	void Mod(int value) { this->value %= value; }
};

int main()
{
    Calc calc(10);
	calc.Add(5);
	calc.Sub(2); // 원래는 이런식으로 여러 문장을 써야 함.
    return 0;
}
```
이렇게 하면 연산 하나하나 써야 하니 귀찮다. 이를 연쇄적 함수 표현으로 나타내면 편리하다.
```cpp
class Calc
{
	int value;

public:
	Calc(int value) : value(value) {}

	//연쇄적으로 편리하게 쓰기 위해, 반환값이 나 자체인 셀프 리턴 형식으로 함수를 적는다.
	Calc& Add(int value) { this->value += value; return *this; } 
    //*this 참조값을 통해 나 자신의 주소 안으로 들어온다는 의미.
    //Calc&는 반환형이며, 반환형이 Calc 클래스의 객체의 참조자를 반환한다는 것을 의미.
    //객체의 참조자를 반환하면, 해당 객체에 대한 수정이 가능해짐.
	Calc& Sub(int value) { this->value -= value; return *this; }
	Calc& Mul(int value) { this->value *= value; return *this; }
	Calc& Div(int value) { this->value /= value; return *this; }
	Calc& Mod(int value) { this->value %= value; return *this; }
};

int main()
{
	Calc calc(10);
	calc.Add(5).Div(2).Mod(3).Mod(4).Sub(1); //한 줄로 쓸 수 있어 간편하다.

	//익명개체를 호출해서 연쇄적 계산하는 것도 가능(이름 선언을 안해준다는 것)
	//ananimous object
	Calc(20).Add(1).Add(2); //그러나 이것은 1회용이고 사용은 불가능함. 이름이 없기 때문에.

	return 0;
}
```
메서드를 통해 객체의 멤버 변수를 수정하고자 할때에는 함수 반환형에 꼭 &연산자를 붙여 줘야 한다. (ex. Calc&)

# 09_class_and_const(const 멤버 알아보기)  ★
클래스 내부에서 멤버 함수 뒤에 붙은 const키워드는 해당 멤버 함수가 객체 내부 상태를 변경하지 않는다는 것을 나타낸다. 즉, const멤버 함수는 해당 객체의 상태를 읽을 수만 있고 변경할 수는 없다.
```cpp
int GetValue() const { return value; }
// 호출된 객체를 상수화하고 멤버 변수 값을 수정하지 않겠다는 의미를 가진 const 멤버 함수

int& GetValue() { return value1; }
//호출된 객체를 수정하겠다는 의미를 가진 non-const 멤버 함수

int& GetValue() const { return value; }
// 멤버 함수 자체를 상수화 하는 것. 호출되는 객체를 상수화 한다.
// 객체를 수정하지 않으며(read-only) 호출된 객체를 변경할 수 없다는 것을 나타내기 위한 것

const int& GetValue() { return value; }
// 상수 객체의 값을 반환
// 객체를 수정하지 않고(read-only) 호출된 객체의 값을 가져오기 위해 사용
```

```cpp
class Data
{
	int value1;
	mutable int value2;

public:
	Data() : value1(0) {}

	int& GetValue() { cout << "not const" << endl; return value1; }

	int& GetValue1() const { cout << " const"; return value1; } 
    //함수 자체에 const가 붙은 경우 const가 붙지 않은 변수를 쓰려고 하면 오류가 남.
	//const 멤버 함수 내에서는 변수들이 상수 취급이 되기 때문에 변경이 불가능하므로.
	const int& GetValue1() const { cout << "const"; return value1; } 
    //오버로딩 함수.
    //const int& 는 레퍼런스를 사용하여 int형 상수를 반환하는 것을 의미.
    //반환값이 상수이므로 반환값을 수정할 수 없도록 보장하는 역할을 하기에 오류가 안남.

	void SetValue(int value) const { this->value1 = value; } //value가 상수화 돼서 수정 불가. 이때 수정할 수 있게 사용하는 키워드(mutable)가 있음
	void SetValue(int value) const { this->value2 = value; }
	const void SetValue2(int value) const { this->value2 = value; }
};
```

# 10_static_member_variable
클래스의 모든 객체들이 공유하는 변수. 
- 클래스의 일부분으로 메모리에 한 번 할당되며, 프로그램이 종료될 때까지 존재한다.
- 클래스 선언 내부에서 선언하며, 일반적으로 private 멤버로 선언되어 클래스 외부에서는 접근할 수 없다. 
- 접근할때에는 클래스 이름으로 접근할 수 있다.(객체 이름으로는 접근 불가)
```cpp
class Test
{
public:
	int value = 1; //Test가 생성될때까지는 설계도만 있고 실체는 없음

	static int count; //static은 생성이 되어야 하므로 바깥에서 반드시 초기화를 해줘야 함.

	static const int test = 10; //const는 선언과 동시에 초기화가 이루어져야 하므로 이때는 안에서 초기화 가능
};
```

# 11_static_member_function
클래스의 객체가 아닌, 클래스 자체에 속하는 함수. 모든 객체가 공유하며 클래스 이름으로 호출.
- static 멤버 함수 내에서는 오직 static 멤버 변수와 static 멤버 함수만 접근할 수 있다.(static 멤버 함수는 객체에 종속되지 않고 클래스에 속해 있기 때문)
- static 멤버 함수는 클래스의 멤버 변수를 직접 접근할 수 없다. (static 멤버 함수가 호출되는 시점에서 객체가 생성되지 않았을 수도 있기 때문)
- static 멤버 함수는 일반 멤버 함수와는 달리 this 포인터를 가지지 않는다. 대신 클래스의 이름으로 호출됩니다.
- 클래스의 인스턴스 갯수를 추적, 해당 클래스의 모든 객체가 공유해야 하는 정보를 관리하는 함수 등으로 쓰인다.
```cpp
class Test
{
	int value;
	static int value2;

public:
	Test() {}
	void Temp1() { this->value; }
	void Temp1() const { this->value; } //상수함수라서 오버로딩 가능

	static void Temp2() { this->value; } //error. 
    //static함수에서는 this call불가능.
	//그래서 같은 종류로 단순히 포함되기만한 변수(static 변수)만 사용 가능.
	static void Temp2() { value2; }
};

int main()
{
	Test t1;
	t1.Temp1(); //일반적인 멤버 함수 호출

	Test::Temp2(); //static함수는 이렇게 호출. 
	//일반 함수 취급을 한다고 생각하면 됨, 그래서 함수 포인터도 가능
	void (*ptr1)() = Test::Temp2;
	//void (*ptr2)() = Test::Temp1; //this call형식이기에 소유자를 알 수 없어서 이건 불가능

	return 0;
}
```
## member_pointer(멤버 포인터)
객체를 만들고 사용해야 한다는 주의점이 있다.
```cpp
class Test
{
	int value;
	static int value2;

public:
	Test() {}
	void Temp1() { this->value; }
	void Temp1() const { this->value; } //상수함수라서 오버로딩 가능

	static void Temp2() { value2; }
};

int main()
{
	Test t1;

	//변수의 경우.
	int Test::* ptr2 = &Test::test; //test의 포인터. 지금은 아직 실체가 없음.
	t1.*ptr2 = 10; //test가 객체 t1의 변수라고 알려주는 것.

	//함수의 경우.
	void(Test:: * ptr3)() = &Test::Temp1; //Temp1의 포인터. 아직 실체가 없음.
	(t1.*ptr3)(); //Temp1가 객체 t1의 함수라고 알려주는 것.

	return 0;
}
```

# 12_SOLID_and_singleton_pattern
## SOLID(객체지향 설계 원칙) : 지켜야할 원칙
- 단일 책임 원책(Single Responsibility Principle) : 모든 클래스는 각각 하나의 기능만을 책임만 가져야 한다.

- 개방-폐쇄 원칙(Open Closed Principle) : 확장에는 열려 있고 수정에는 닫혀 있어야 한다. 기능을 추가할때 다른 코드들은 수정하지 않으면서 해야 함.

- 리스코프 치환 원칙(Liskov Substitution Principle) : 자식 클래스는 언제나 부모 클래스를 대체할 수 있다.(자식 클래스는 부모 클래스를 그대로 받아오므로)

- 인터페이스 분리 원칙(Interface Segregation Principle) : 한 클래스가 내가 사용하지 않을 인터페이스는 구현하지 말아야 한다.

- 의존 역전 원칙(Dependency Inversion Principle) : 클래스끼리 엮일때, 변화가 거의 없는 것에 의존해서 만들어야 한다.

## singleton_pattern
디자인 패턴 : 자주 쓰는 코드를 재사용할 수 있게 하는 것.
- 싱글톤 패턴 : 객체가 실체화되는 것이 한 번만 일어난 것. 간단한 일만 할 경우에 쓰임(여러 사람이 공유해서 하나를 사용하는 경우)
	- 하지만 하나가 너무 많은 일을 담당하면 "개방-폐쇄 원칙"에 위배되므로 왠만하면 사용 지양.

```cpp
class Audio
{
public:
	static Audio& GetInstance() //모든 객체가 공유하는 static 생성자
	{
		static Audio audio;
		return audio;
	}

	void OutSound(string music)
	{
		cout << "소리 출력 : " << music << endl;
	}

private: //프리빗으로 숨기거나 {}를 지우고 "= delete"를 붙여서 막을 수 있음. => 실체가 생성이 안됨.
	Audio() {} //기본 생성자
	Audio(const Audio& audio) = delete; //복사 생성자
	Audio& operator=(const Audio& audio) {}  //복사 대입 생성자
};

int main()
{
	//Audio a; 생성자를 다 막아놔서 생성이 안됨.

	string bgm("던전");
	Audio::GetInstance().OutSound(bgm); //싱글톤 방식. 실체를 만들면 메모리를 쓰기때문에 실체를 만들지 않고 가져다 쓰는 것.

	return 0;
}
```


# 13_friend_class
friend도 객체 지향을 부수는 것으로 여겨지기도 한다. 많이 쓰면 좋지 않다.
또한, 상속이 되지 않는다.

## friend global function
```cpp
class A
{
	int value = 1;

	friend void doSomething1(const A& a); //프리빗 영역이지만 friend 함수는 전역함수처럼 접근해서 쓸 수 있음.
	/*friend void doSomething2(const A& a)
	{
		cout << a.value << endl;
	}*///이렇게 내부에서 정의를 해 줘도 됨.
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

```

## friend member class(더 안전한 방법)
자신의 클래스의 private 멤버를 다른 클래스의 '특정 멤버 함수 내에서만' 접근 가능하게 하는 것.
```cpp
class A
{
public:
	void attack(B& b); //클래스 B의 프리빗 변수를 갖고 와서 씀, 객체를 생성하지 않게 참조 매개변수를 씀.

private:
	int a;
};

class B
{
	friend void A::attack(B& b); //B가 A한테 attack에서 모든 변수에 접근 가능하도록 허용한다는 뜻.
	//클래스 A의 멤버함수 attack을 선언할 때, 클래스 B를 friend로 취급하겠다는 코드.

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
```

## friend class
자신의 클래스의 private 멤버를 다른 클래스에서 접근 가능하게 하는 것.
```cpp
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
```

# 14_anonymous_object(익명 객체)
한번 쓰고 안쓸 것 같은 것은 굳이 실체화하지 않고 익명객체화 하자.
```cpp
class A
{
public:
	void print()
	{
		cout << "print" << endl; 
	}
};

int main()
{
	A().print(); // 이렇게 익명객체화하면 한번 쓰이고 삭제됨.
	return 0;
}
```

# 15_nested_types(중첩 자료형)
중첩 클래스(nested class) : 클래스나 구조체 안에 다른 클래스나 구조체를 선언하는 것을 말한다.
- 외부 클래스의 private 멤버에 대한 접근을 허용하면서도, 다른 클래스나 전역 namespace에서의 이름 충돌을 방지할 수 있다. 
- 코드의 가독성과 모듈화를 높여줄 수도 있다.
- 선언 시, 클래스 이름 앞에 외부 클래스 이름을 붙이는 방식으로 선언한다.
- 외부 클래스의 멤버함수 내에서만 중첩 클래스의 private 멤버에 접근할 수 있다.
```cpp
class Outer {
public:
    class Inner 
	{ // Inner 클래스를 Outer 클래스의 중첩 클래스로 선언
    public:
        void func() 
		{
            std::cout << "Hello from Inner!" << std::endl;
        }
    };
    void callInnerFunc() 
	{
        Inner innerObj; // Inner 클래스의 객체 생성
        innerObj.func(); // Inner 클래스의 멤버 함수 호출
    }
private:
    int x = 10;
};

int main() 
{
    Outer::Inner innerObj; // Outer 클래스의 중첩 클래스인 Inner 클래스의 객체 생성
    innerObj.func(); // Inner 클래스의 멤버 함수 호출
    Outer outerObj;
    outerObj.callInnerFunc(); // Outer 클래스의 멤버 함수 내에서 Inner 클래스의 멤버 함수 호출
    return 0;
}
```