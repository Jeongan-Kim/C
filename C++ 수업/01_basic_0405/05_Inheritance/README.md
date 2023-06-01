# 01_Inheritance(상속의 기본)
```cpp
class Mother
{
private: //프리빗 변수는 상속도 안됨.
	int a;

public:
	auto GetA() const
	{
		cout << "Mother" << endl;
		return a;
	}

	void SetA(const int& a) { this->a; }

protected: //부모 자식만 쓸 수 있는 변수들
	int b;
	int c;
};

class Child : public Mother //마더 클래스의 멤버들을 public으로 받음
{
	int b; //전역 멤버 변수
public:
	auto GetA() const
	{
//		a; //마더 프리빗 변수는 사용 불가능
		c; //마더에 있는 것 사용 가능
		b; //child 변수 b
		Mother::b; //마더 클래스의 변수 b

		cout << "Child" << endl;
		return Mother::GetA(); //child 의 겟 함수가 아니라 마더의 겟 함수
	}
};
int main()
{
	Child c;
	c.SetA(10); //child 클래스에는 SetA함수가 없지만 부모 클래스에 있기에 호출이 가능

	c.GetA(); //child클래스의 멤버 함수(이름이 같으므로 부모 클래스의 멤버함수 GetA는 하이딩됨.)
	c.Mother::GetA(); //부모 클래스의 GetA를 호출하려면 명시적으로 이름을 알려줘야 함.

	return 0;
}
```

# 02_상속의 예시
두 클래스의 멤버 변수, 멤버 함수가 겹치는 게 많을 댸, 공통적인 요소를 묶는 클래스를 만들어 상속하기도 한다. person을 물려 받아서 각각 재정의하는 방식.
## person.h
```cpp
class Person
{
protected: //자식에서 사용할 수 있게.
	std::string name;

public:
	Person() = default; //기본 생성자
	Person(const std::string& name) :name(name)	{}
    //이 생성자를 만들면서 기본 생성자가 없어지는데, 자식 클래스에서는 기본 생성자가 필요하므로 위에 기본 생성자를 만들어 줌.

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }
};
```

## Student.h
```cpp
class Student : public Person //상속 접근 지정자
{
//	std::string name;

public:
	Student(const std::string& name) //자식 클래스에 없어도 부모 클래스에 변수가 있다면 초기화가 가능하다.
		:Person(name)	{}
	void Study() {} //확장 : 자식 클래스만의 함수
	//auto GetName() const { return name; }
	//void SetName(const std::string& name) { this->name = name; }
	//부모 클래스와 겹치는 부분 삭제 가능
}
```

## Teacher.h
```cpp
class Teacher
{
//	std::string name;
public:
	Teacher(const std::string& name)
		:Person(name)	{}

	void Teach() {} //확장
};
```

# 03_Inheritance_and_access_specifier

|상속 접근 지정자     |부모 클래스          |자식클래스|
|:--------------------:|:--------------------|:---------|
|    public            |  public             | public|
|                       | protected           |protected|
|                        |private             |접근 불가|
|    protected          | public              |protected|
|                       |protected           |protected|
|                        |private             |접근 불가|
|    private            | public              |private|
|                        |protected           |private|
|                       |private             |접근 불가|

```cpp
class Base //부모 클래스
{
private:
    int privateData;

protected:
    int protectedData;

public:
    int publicData;
    void Test() {}
};

class Derived : private Base //상속 접근 지정자 private
{
public: //아무리 여기서 public으로 해도 다음 자식 클래스에서는 사용 불가. 상속 접근 지정자를 우선으로 제한시키기 때문에. 객체를 생성해도 불가.
    Derived()
    {
        Test();
        publicData;
        protectedData;
        //privateData; 이건 불가
    }
};

class A : public Derived
{
public:
    A()
    {
        //Test();
        //publicData;
        //protectedData;
        //전부 사용 불가.
    }
};
```

# 04_Inheritance_and_casting ★
## up casting vs down casting
객체 지향 프로그래밍에서 상속관계에 있는 클래스 간의 형 변환을 의미한다.
### up casting
- 자식 클래스의 포인터나 참조를 부모 클래스의 포인터나 참조로 형 변환하는 것.
- 상속 관계에서 부모 클래스가 가지고 있는 멤버들만 접근할 수 있게 한다.
- 부모 클래스의 접근을 허용하면서도, 실제로는 자식 클래스의 객체를 다룰 수 있게 해주는 것.
```cpp
class Parent {
public:
    void ParentMethod() {} // 부모 클래스의 메서드 내용
};

class Child : public Parent {
public:
    void ChildMethod() {} // 자식 클래스의 메서드 내용
};

int main() {
    Child childObj;
    Parent* parentPtr = &childObj;  // 업 캐스팅
    parentPtr->ParentMethod();     // 부모 클래스의 메서드 호출 가능
    // parentPtr->ChildMethod();    // 컴파일 오류: 부모 클래스 포인터로 자식 클래스의 메서드에 직접 접근 불가 ★
    return 0;
}
```

### down casting
- 부모 클래스의 포인터나 참조를 자식 클래스의 포인터나 참조로 형 변환하는 것.
- 부모 클래스의 포인털르 통해 자식 클래스의 멤버에 접근하고 사용할 수 있음.
- 명시적 형 변환을 해 줘야 함. ★
- 컴파일 타임에는 오류 확인 불가하니 실행 시간에 유효성을 확인해야 함. ★
```cpp
class Parent {
public:
    void ParentMethod() {} // 부모 클래스의 메서드 내용
};

class Child : public Parent {
public:
    void ChildMethod() {} // 자식 클래스의 메서드 내용
};

int main() {
    Parent parentObj;
    Child* childPtr = dynamic_cast<Child*>(&parentObj);  // 다운 캐스팅 ★
    if (childPtr != nullptr) 
    {
        childPtr->ChildMethod();  // 자식 클래스의 메서드 호출 가능
    } 
    else 
    {
        // 다운 캐스팅 실패 처리
    }
    return 0;
}
```

# 05_construction_order_of_derived_class
생성자가 자식 클래스에서 어떤 순서로 만들어지는지 알아보자.
```cpp
class A			   { public: A() { cout << "A constructor" << endl; } };
class B : public A { public: B() { cout << "B constructor" << endl; } };
class C : public B { public: C() { cout << "C constructor" << endl; } };
class D : public C { public: D() { cout << "D constructor" << endl; } };

int main()
{
	D d;
    /*
    A constructor
    B constructor
    C constructor
    D constructor
    */
	return 0;
}
```

# 06_destruction_order_of_derived_class
소멸자가 자식 클래스에서 어떤 순서로 만들어지는지 알아보자.
```cpp
class A //클래스 크기는 4바이트
{
	int a;
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A distructor " << endl; }
};

class B : public A
{   //A를 상속 받았으니 int a도 있다고 생각하고 클래스 크기는 더블 두개로 16바이트(내부 단편화 문제, 패딩(padding) 바이트 방식으로 저장하기 때문에)
	//메모리 한 줄에 앞에서 채워 저장하고 뒤에 남는 부분을 패딩이라고 함
	double b;
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B distructor " << endl; }
};


int main()
{
	B b;
	//생성은 부모가 먼저, 소멸은 자식이 먼저(LIFO 형식)
	/*
		A constructor
		B constructor
		B distructor
		A distructor
	*/
	return 0;
}
```

# 07_multi_inheritance
두 개 이상의 클래스를 상속 받은 것
```cpp
class USBDevice
{
	int id;
public:
	USBDevice() = default; //기본 생성자
	USBDevice(int id) : id(id) {} //매개변수있는 생성자

	auto GetId() const { return id; }
	void PlugAndPlay() {}
};

class NetworkDevice
{
	int id;
public:
	NetworkDevice() = default; //기본 생성자
	NetworkDevice(int id) : id(id) {} //매개변수있는 생성자

	auto GetId() const { return id; }
	void Networking() {}
};

class USBNetworkDevice :public USBDevice, public NetworkDevice //★
{
public:
	USBNetworkDevice(int usbId, int netId)
		: USBDevice(usbId), NetworkDevice(netId) {}
        //어떤 변수를 누구한테 줄지는 모르므로.

	USBNetworkDevice(int id)
		: USBDevice(id), NetworkDevice(id) {}
        //이렇게도 가능(오버로딩)
};

int main()
{
	USBNetworkDevice device(1, 2);//부모 클래스 두개 다 생김

	device.PlugAndPlay();
	device.Networking(); //부모클래스 멤버 함수 사용 가능

	device.USBDevice::GetId();
	device.NetworkDevice::GetId();
	return 0;
}
```

# 08_Overriding_and_final
다형성에는 오버로딩과 오버라이딩이 있다.
- 오버라이딩 : 부모클래스에서 물려 받은 것을 재정의하는 것.
- 함수 이름과 매개변수 등이 같은데 다른 기능을 함. 부모클래스의 멤버함수가 하이딩됨. 오버로딩된 것들도 다 가려짐
## Overriding
- virtual 함수 : 가상 함수 -> 상속해줄 클래스에서 오버라이딩할 것을 명시해 주는 것.(안써도 상관은 없음)
- 그래도 쓰는 이유는 자식 클래스에서 오버라이딩할때 실수로 같게 쓰지 않았을 때 오류처리해주는 것.
- 최상위 부모클래스에서만 써주면 됨,(부모 -> 자식 1-> 자식2, 이럴때 자식 1에서는 자식 2로 상속할떄 virtual을 안써도 된다는 의미)
- override를 붙이면 오버라이딩한다는 것을 명시적으로 보여주고 원본 함수가 있는지 확인도 할 수 있음, 생략 가능

```cpp
class A /*final*/ 
{
public:
	virtual void Print(int x) { cout << "A" << endl; } 
	int i = 0;
};

class B /*final*/:public A
{
public:
	void Print(int x) override /*final*/ { cout << "B" << endl; } //상속 받은 함수를 오버라이딩
};

class C : public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;

	a.Print(1);
	b.Print(2);
	return 0;
}
```

## final
- 더이상 이 클래스를 상속하지 않게 하는 키워드(함수에만 써서 특정 함수만 상속 불가하게 할 수도 있음)

# 09_Covariant(공변성) ★
- 객체 지향 프로그래밍의 다형성 관점에서, 상속관계에 있는 클래스나 인터페이스 사이에서 타입 변환을 얘기한다.
- 자식 클래스가 부모 클래스의 타입으로 사용될 수 있다.
- 공변적인 관계 : 부모 클래스와 자식 클래스의 관계에서 자료형이 보존되는 경우
```cpp
class A
{

public:
	virtual A* GetThisPointer() //나를 반환하는 것
	{ 
		cout << "A" << endl; 
		return this; //나를 가리키는 주소 반환
	}

	void Print() { cout << "A" << endl; }
};

class B :public A
{
public:
	B* GetThisPointer() override //B포인터는 A의 성질도 가지고 있다
	{
		cout << "B" << endl;
		return this; //A클래스에서 오버라이딩을 했어도 A 멤버 함수가 사라지는 것이 아니기 떄문에 리턴값이 달라도 오류가 안난다.
	}

	void Print() { cout << "B" << endl; }
};

int main()
{
	B b;

	b.Print();
	cout << "Address : " << b.GetThisPointer() << endl; //B클래스의 객체 주소가 찍힘
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl; //해당 자료형이 뭔지 문자열로 반환해줌
	/*
	B
	B
	Address : 000000D3CD8FF988
	typeid : class B * __ptr64
	*/

	A& ref = b;//ref자체는 A의 것이지만 b로 초기화를 해서, 값은 B의 주소가 나오지만 타입이나 소속은 A ★
	ref.Print();
	cout << "Address : " << ref.GetThisPointer() << endl;
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl;
	/*
	A
	B
	Address : 000000D3CD8FF988
	typeid : class A * __ptr64
	*/
	return 0;
}
```

# 10_derived_class_object_and_base_class_pointer
부모 클래스의 포인터와 자식 클래스의 객체
```cpp
class Animal
{
	string name;
public:
	Animal(string name) : name(name) {}
	virtual void Speak() const { cout << "??" << endl; } //울음 소리 저장
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {} //부모클래스 생성자 통해서 이름 받아오기
	void Speak() const override { cout << "야옹" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	void Speak() const override { cout << "멍멍" << endl; }
};

int main()
{
	//각각 클래스들의 배열 만들기
	Cat cats[]{ Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[]{ Dog("dog1"), Dog("dog2"), Dog("dog3"), Dog("dog4"), Dog("dog5") };

	for (const auto& cat : cats)
		cat.Speak();

	for (const auto& dog : dogs)
		dog.Speak();

	//부모 클래스로 upcasting 해주기 ★
	Animal* animals[]
	{
		&cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
        &dogs[0], &dogs[1], &dogs[2], &dogs[3], &dogs[4]
	};
	for (const auto& animal : animals) //??가 출력됨. (upcasting 되면서 생기는 문제->virtual, override 키워드를 써서 바꾸면 문제 해결) ★
		animal->Speak();
	return 0;
}
```

# 11_virtual_function_and_polymorphism
가상 함수와 가상 함수 테이블에 대해 알아보자.
- 가상함수의 주소가 같아서, 가상함수는 가상함수 테이블(멤버 함수의 주소를 오버라이딩 함수 주소로 교체 해주는 등의 일을 함)을 이용함. ★
```cpp
class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1() { cout << "A1" << endl; } //가상함수 테이블에 차례대로 virtual 함수의 주소가 저장됨.
	virtual void Print2() { cout << "A2" << endl; }
	virtual void Print3() { cout << "A3" << endl; }
	virtual void Print4() final { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1() { cout << "B1" << endl; } //가상함수의 오버라이딩 형태이므로, A의 print1의 주소를 덮어 씌우고 저장됨.(주소가 같아짐)
	virtual void Print2() { cout << "B2" << endl; }
	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1() { cout << "C1" << endl; }
	virtual void Print2() final { cout << "C2" << endl; }
//	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() { cout << "D1" << endl; }
//	virtual void Print2() final { cout << "D2" << endl; }
//	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};


int main()
{
	A a;
	a.Print1();

	B b;
	b.Print1();

	C c;
	c.Print1();

	D d;
	d.Print1();

	A& refB = b; //최상위 부모 클래스를 이용해서 자식 클래스의 참조자를 만듬
	A& refC = c;
	A& refD = d;

	cout << "###### D" << endl;

	refD.Print();
	refD.Print1();
	refD.Print2();
	refD.Print3();
	refD.Print4(); //final로 막혀서 직전 부모클래스의 값이 찍힘, 가장 마지막에 오버라이딩한 멤버 함수가 찍힘.
/*  A
    D1
    C2
    B3
    A4 
*/
	return 0;
}
```