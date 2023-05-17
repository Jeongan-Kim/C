# 01_Arthmatic_operator(산술 연산자)
연산자 오버로딩 시 주의 사항 : 의도를 벗어나는 연산은 하지 않는 게 좋음.
- 우선 순위는 변하지 않음(+보다 *가 우선)
## 1. 전역 함수에 의한 연산자 오버로딩
```cpp
class Won
{
public:
	Won(int value) : value(value){}

	int GetValue() const { return value; }

private:
	int value;

	friend int operator+(const Won& lhs, const Won& rhs); //private지만 friend가 붙어서 전역함수처럼 쓰임, lhs 좌항, rhs 우항

	//생성자를 통해 만들어줄 수도 있음
	friend Won operator-(const Won& lhs, const Won& rhs) //함수 정의부를 클래스 안에서 써줘도 됨.
	{
		return lhs.value - rhs.value;
	}
};

int main()
{
	Won l(10), r(10);

	int result = l + r;
	cout << result << endl;

	Won result2(l - r); //result2라는 객체를 생성하면서 연산까지 동시에
    //객체 생성과 동시에 해도 되지만 결과는 getvalue로 가져와야 함
	cout << result2.GetValue() << endl;

	return 0;
}

int operator+(const Won& lhs, const Won& rhs)
{
	return lhs.value + rhs.value;
}
```

## 2. 산술 연산자 오버로딩
```cpp
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	//단항 연산자 +
	Vector operator+() const
	{
		return *this;
	}

	//단항 연산자 -
	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}


	//이항 연산자 +
	Vector operator+(const Vector& rhs)
	{
		return Vector{ x + rhs.x, y + rhs.y, z + rhs.z };
	}

	//이항 연산자 -
	Vector operator-(const Vector& rhs)
	{
		return Vector{ x - rhs.x, y - rhs.y, z - rhs.z };
	}


	//이항 연산자 *
	Vector operator*(const Vector& rhs)
	{
		return Vector{ x * rhs.x, x * rhs.y, x * rhs.z };
	}

	//이항 연산자 /
	Vector operator/(const Vector& rhs)
	{
		return Vector{ x / rhs.x, y / rhs.y, z / rhs.z };
	}

	//이항 연산자 * 3
	Vector operator*(const int n)
	{
		return Vector{ x * n, y * n, z * n };
	}

	//전위
	Vector& operator++()
	{
		x += 1; //이렇게 쓰거나
		++y; //이렇게 쓰면 됨
		++z;
		return *this;
	}

    //후위
	Vector& operator++(int) //구별하기 위해서 넣음 : dummy(아무 의미 없지만 구분하기 위해 쓰는 것)
	{
		//원본 값은 어딘 가 저장해 놓고 계산을 함.
		Vector temp = *this; //임시 변수에 원본값을 저장해 놓음
		++(*this); //이렇게 해도 됨
		return temp;//반환은 임시 변수에 저장해 놓은 이전 값을 넣음.
	}

private:
	int x;
	int y;
	int z;
};
```

# 02_input_output_operator
<<, >> 입출력 stream
```cpp
class Point
{
	int x;
	int y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	auto Getx() const { return x; }
	auto Gety() const { return y; }

	friend ostream& operator << (ostream& out, const Point& p) //ostream : 외부에서 값을 가져오는 것(출력)
	{
		out << "(" << p.x << ", " << p.y << ")" << endl;
		return out;
	}

	friend istream& operator >>(istream& in, Point& p) //istream : 외부에서 값을 가져오는 것(입력)
	{
		in >> p.x >> p.y;
		return in;
	}

};

int main()
{
	Point p1(0, 1), p2(5, 5);

	cout << p1 << ", " << p2 << endl; //이런게 원래는 안돼서 오버로딩 함수를 만들어줌.
	//입출력 stream은 chainng이 됨.

	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << ", " << p4 << endl;

	return 0;
}
```

# 03_Unary_Operator(단항 연산자)
- Unary plus (+) : 값을 양수로 만듭니다. (단순히 부호를 변경하는 것은 아님)
- Unary minus (-) : 값을 음수로 만듭니다.
- Logical NOT (!) : 불리언 값의 반대 값을 반환합니다.
- Bitwise NOT (~) : 비트의 값을 반전합니다.
- Address-of operator (&) : 변수의 주소를 반환합니다.
- Dereference operator (*) : 포인터 변수가 가리키는 메모리 위치의 값을 반환합니다.

'!' 연산자에 대해만 간단히 알아보자
```cpp
class Won
{
	int value;
public:
	Won(int value = 0) : value(value) {}

	bool operator !() const //넣은 값이 true or false인지 확인해서 반대로 리턴
	{
		return (value == 0) ? true : false;
	}

	friend ostream& operator << (ostream& out, const Won& won) //출력 오버로딩 함수
	{
		out << won.value;
		return out;
	}
};

int main()
{
	const Won w1(10);
	const Won w2(0);
	
	cout << !w1 << endl; //0

	cout << boolalpha; //알파벳으로 true or false를 나타내는 것
	cout << !w2 << endl; //true
	return 0;
}
```

# 04_relational_operator
두 개의 피연산자를 비교하여 불리언(bool)값을 반환하는 연산자.
- Equal to (==) : 두 값이 같은 경우 true를 반환합니다.
- Not equal to (!=) : 두 값이 다른 경우 true를 반환합니다.
- Greater than (>) : 첫 번째 값이 두 번째 값보다 큰 경우 true를 반환합니다.
- Less than (<) : 첫 번째 값이 두 번째 값보다 작은 경우 true를 반환합니다.
- Greater than or equal to (>=) : 첫 번째 값이 두 번째 값보다 크거나 같은 경우 true를 반환합니다.
- Less than or equal to (<=) : 첫 번째 값이 두 번째 값보다 작거나 같은 경우 true를 반환합니다.

```cpp
class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}
    int x() const { return x_; }
    int y() const { return y_; }

    bool operator==(const Point& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    bool operator<(const Point& other) const {
        return x_ < other.x_ || (x_ == other.x_ && y_ < other.y_);
    }

    bool operator>(const Point& other) const {
        return !(*this < other) && (*this != other);
    }

    bool operator<=(const Point& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Point& other) const {
        return (*this > other) || (*this == other);
    }

private:
    int x_;
    int y_;
};

```

## 정렬 오버로딩
```cpp
class Won
{
	int value;
	int value1;

public:
	Won(int value = 0) : value(value){}
	auto Getvalue() const { return value; }
	void Setvalue(const int& value) { this->value = value; }


	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	bool operator==(const Won& rhs) const
	{
		return value == rhs.value && value1 == rhs.value1;
	}

	bool operator!=(const Won& rhs) const
	{
		return !(*this == rhs);
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend bool test(const Won& lhs, const Won& rhs)
    {
	return lhs.Getvalue() > rhs.Getvalue();
    }
};

int main()
{
	//vector :동적 배열, new는 해제를 해줬어야 했는데 vector는 자동으로 해제가 됨.
	std::vector<Won> wons(20);

	int i = 1;
	for (auto& won : wons) //동적배열 vector 값 초기화
	{
		won.Setvalue(i);
		i++;
	}

	for (const auto& won : wons) // 1 2 3 4 5 6 7 8 9 10 11 ...
		cout << won << " ";
	cout << endl;

	random_shuffle(wons.begin(), wons.end()); //알고리즘 헤더에 있는 셔플 함수

	for (const auto& won : wons) // 13 2 10 3 1 12 8 ... (섞임)
		cout << won << " ";
	cout << endl;

	sort(wons.begin(), wons.end()); 
    //오름 차순으로 정렬됨.(객체지만 연산자 오버로딩을 한 상태라서 가능)
	
	for (const auto& won : wons) // 1 2 3 4 5 6 7 ...
		cout << won << " ";
	cout << endl;

	sort(wons.begin(), wons.end(), test); //내림 차순으로(test함수를 이용)

	for (const auto& won : wons) // 20 19 18 17 16 15 ...
		cout << won << " ";
	cout << endl;

	//람다식 함수 : 매개 변수에 함수를 넣는 것. 요청과 호출이 동시에 일어나지 않는 것(?) 엔터를 눌러야 실행이 되는 것.
	sort(wons.begin(), wons.end(), [](const Won& lhs, const Won& rhs)
		{
			return lhs.Getvalue() < rhs.Getvalue(); //오름차순 함수
		}
	); //[]함수를 매개변수로 넣어줄 건데 함수가 없다는 의미로 비워놓음. 정의를 이 안에서 해버림.

	for (const auto& won : wons) // 1 2 3 4 5 6 7 8 9 ...
		cout << won << " ";
	cout << endl;
	return 0;
}
```

# 05_subscipt_operator
배열 인덱스 연산자 '[ ]'를 오버로딩하여, 객체 내의 데이터나 멤버 변수를 인텍스 연산자를 사용해 접근할 수 있다. 
- 클래스 내에서 [ ]연산자에 대한 멤버 함수를 정의해야 한다.
- 인덱스 값은 객체 내의 원소의 개수나 범위에 따라 검사하여 'out of bounds' 에러를 방지해햐 한다.
## 인덱스 연산자 오버로딩을 하지 않았을 때, 배열 원소 접근
```cpp
class IntArray //배열 클래스
{
	int list[3];

public:
	int Get(int index) { return list[index]; } //list 원소 값 접근
	void Set(int index, int value) { list[index] = value; } //list 원소 값 초기화
	int* GetList() { return list; }
};

int main()
{
    //일반적으로 배열에 접근할 때
	int arr[3] = { 1, 2, 3 };
	cout << arr[-1] << endl;
	cout << arr[3] << endl; 
    //경계 검사를 하지 않기 때문에 컴파일은 되지만 쓰레기 값이 나옴. 그래서 배열 클래스를 만들어서 사용하기도 함.

	IntArray list; //객체 생성
	list.Set(0, 1); //list[0] = 1
	list.Set(1, 2); //list[1] = 2
	list.Set(2, 3); //list[2] = 3

	cout << list.Get(0) << endl; //list[0] 값 출력
	cout << list.Get(1) << endl; //list[1] 값 출력
	cout << list.Get(2) << endl; //list[2] 값 출력
	//클래스 안의 함수 형태이므로 찍어볼때 매우 귀찮음

	auto arr = list.GetList(); //클래스 내부의 list를 arr배열에 저장
    //이러면 배열의 크기가 얼마인지 모르기 때문에 연산자 오버로딩을 하는 것.
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	return 0;
}
```
## 인덱스 연산자 오버로딩을 했을 때, 배열 원소 접근
```cpp
class IntArray //배열 클래스
{
	int list[3];

public:
	int& operator[] (int index)
	{
		if (index < 0 || index >= 10) // 왜 3이 아니라 10이지? ★
		{
			cout << "Array index out of bound exception" << endl;
		}

		return list[index];
	}
};

int main()
{
	IntArray list;

	list[0] = 1;
	list[1] = 2;

	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[20] << endl; //오류 처리 완료.

	return 0;
}
```

# 06_paranthesis_operator(() 연산자)
- 클래스에서 () 연산자를 오버로딩하여 객체를 함수처럼 호출할 수 있다.
- 객체 내부에서 저장된 데이터나 멤버 변수를 이용하여 연산을 할 수 있다.
```cpp
class Counter
{
	int count = 0;

public:
	int operator()(int i) { return count += i; }
};

int main()
{
	Counter ct;

	cout << ct(10) << endl; 
    //함수 호출 형태로 객체를 쓸 수 있음 : Functor, Function Object
	cout << ct(20) << endl;
	cout << ct(30) << endl;

	return 0;
}
```

### 더 알아보기
```cpp
class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y =0) : xpos(x), ypos(y) {}

	Point operator+(const Point& pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class Adder
{
public:
	int operator() (const int& n1, const int& n2) //정수 덧셈으로 () 함수 정의
	{
		return n1 + n2;
	}
	double operator() (const double& n1, const double& n2) //실수 덧셈으로 () 함수 정의
	{
		return n1 + n2;
	}
	Point operator() (const Point& n1, const Point& n2) //구조체 자체를 더하는 덧셈으로 정의
	{
		return n1 + n2;
	}
	
};

int main()
{
	Adder adder; //객체 생성

	cout << adder(1, 2) << endl; //3
	cout << adder(1.5, 1.7) << endl; //3.2
	cout << adder(Point(3, 4), Point(7, 9)); //[10, 13]
	return 0;
}
```

# 07_typecase_operator(형변환 연산자)
해당 클래스나 구조체를 다른 타입으로 변환하기 위해 사용되며, 캐스팅 연산자로도 불린다.
- static_cast : 다른 타입으로의 명시적인 형변환을 수행합니다. 컴파일 타임에 실행됩니다.
- dynamic_cast : 다른 타입으로의 형변환이 가능한지 런타임에 체크하여, 가능하다면 변환합니다. 불가능한 경우에는 null 포인터를 반환합니다.
- const_cast : const나 volatile 한정자를 제거하여, 같은 타입으로 형변환합니다.
- reinterpret_cast : 포인터 타입 간의 형변환 또는 포인터와 정수 타입 간의 형변환을 수행합니다. 컴파일러에 따라 결과가 다르게 나올 수 있으므로, 주의해서 사용해야 합니다.
```cpp
class Won
{
	int value = 0;
public:
	Won(int value = 0) :value(value) {}

	operator int() //형변환 연산자 Won 객체를 int형으로 변환
	{
		return value;
	}
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

public:
	Point(float x, float y, float z)
		:x(x), y(y), z(z)
	{}

	operator float* () //형변환 연산자 Point 객체를 float형 포인터로 변환
	{
		return &x; //포인터를 사용하여 x값을 직접 참조할 수 있다.
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}
int main()
{
	Won w(10);
	Print(w); 
	//객체 출력하려고 할때 자료형이 맞지 않아 원래는 오류남. 이럴때 클래스 내부에서 클래스 자체를 형 변환해줌.

	Point p(1.0f, 1.0f, 3.0f);
	PrintPoint(p);
	return 0;
}
```

# 08_new_delete_operator
new는 동적 메모리 할당을 수행하는 연산자이다. 런터임에 메모리를 할당하고, 생성자를 호출하여 객체를 초기화할 수 있다.
```cpp
int* p = new int; //int형 객체를 동적 할당하는 것.
delete p; //할당한 메모리를 해제하는 것.

int* arr = new int[10]; //int형 배열을 동적 할당하는 것.
delete[] arr; //해제
```
new는 클래스 객체(인스턴스)를 동적으로 할당하는데 사용되기도 한다.

new 연산자를 사용하며 클래스의 생성자가 자동으로 호출되어 초기화가 수행된다.

new 연산자를 오버로딩(operator new)하면, 클래스의 객체가 동적으로 할당될 때 사용되는 메모리 할당 및 초기화 동작을 프러그래머가 정의한 방식으로 변경할 수 있다.
```cpp
class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}

	void* operator new(size_t size) 
	{
		void* adr = new char[size];
		return adr; 
		//char형 배열을 생성하여 size바이트 크기를 가지는 포인터이다.
		//컴파일러는 메모리 공간에 초기화해줘서 객체가 완성되고, 클래스에 맞게 형변환까지 해줌. 생성자까지 호출해준다는 것이 new와의 차이점.
	}

	void operator delete (void* adr) //할당 해제하는 것
	{
		delete[] adr;
	}
};

int main()
{
	Point* ptr = new Point(3, 4); //static으로 밖에 만들어진 형태.
	
	//멤버 함수는 객체가 생성된 다음에 호출이 될 수 있는데, new 나 delete오버로딩연산자는 static 함수 같은 것이라서 가능하다. 
	//Point p; 이렇게 객체가 생성된 
	return 0;
}
```

# 09_pointer_operator
'*', '->' 이 와 같은 포인터 관련 연산자들을 오버로딩하여 사용할 수 있다.
```cpp
class Number
{
	int num;

public:
	Number(int n) : num(n) {}

	//-> :객체 자체의 주소값을 반환
	Number* operator->()
	{
		return this;
	}

	//* :값을 찍어줌
	Number& operator*()
	{
		return *this;
	}

	void ShowData() {}

};

int main()
{
	Number num(20);

	(*num) = 30; //num 자체를 포인터 형태로 쓸 수 있음.
	num->ShowData(); //num.operator->()->ShowData(); 원래 이런 형태

	//사실 이런 형태
	num.operator*() = 30;
	return 0;
}
```

# 10_smart_pointer
smart_pointer의 개념적인 이해를 해보자.

스마트 포인터는 동적 메모리 할당을 안전하게 관리하기 위한 기능이다. 메모리 누수나 다른 문제가 발생할 가능성을 방지하기 위해, 메모리의 소유권을 추적하고 자동으로 메모리를 해제하는 기능을 제공한다.
- 일반적으로 포인터를 래핑하여 구현. 래핑된 포인터는 자동으로 메모리 해제를 한다.
- 복사와 대입 연산을 제한하여, 메모리의 소유권이 다른 객체로 이전되는 것을 방지한다.
```cpp
class Point
{
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	friend ostream& operator << (ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class SmartPtr
{

public:
	SmartPtr(Point* ptr) : posptr(ptr) {} 
	//Point클래스의 객체를 가리키는 포인터를 관리.

	//*, -> 연산자를 오버로딩하여 포인터가 가리키는 객체에 쉽게 접근할 수 있도록 함.
	Point& operator*() const
	{
		return *posptr;
	}

	Point* operator->() const
	{
		return posptr;
	}

	~SmartPtr() //객체가 없지만 가정을 하고 delete 과정을 만들어 줌
	{
		delete posptr;
	}

private:
	Point* posptr;
};

int main()
{
	//Point* ptr = new Point 이렇게 만들어야 하는 데 스마트 포인터로 동시에 만들어 줄 수 있음
	SmartPtr sptr1(new Point(1, 2)); //생성과 동시에 포인터 값을 넣어주겟다(★)
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));
	//SmartPtr 객체를 선언하여 Point 객체를 생성.

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20); //SetPos함수를 호출하여 xpos, ypos값을 변경.

	//프로그램이 종료되면서 자동으로 소멸자(SmartPtr의 소멸자)에 의해 Point 객체를 delete함.
	return 0;
}
```

# 11_copy_constructor_and_copy_initialization
## 복사 생성자
```cpp
class Test
{
	int num1;
	int num2;

public:
	Test(int n1, int n2) : num1(n1), num2(n2) //이렇게 만들어 주면 기본 생성자는 자동으로 사라짐.
	{}
};

int main()
{
	Test t1(1, 2);
	Test t2 = t1; //t2에 t1 복사되어 들어가면서(=) 생기는 동시에 복사 생성자가 자동 생성됨.
	//Test t2(t1); 이렇게도 가능

	return 0;
}
```

## 복사 대입 연산자
```cpp
class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int den = 0)
		: numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	//복사 생성자
	/*explicit*/ Fraction(const Fraction& fraction) //그대로 가져오니까 const, 내 자신이니까 & 붙여서
	{
		cout << "copy constructor" << endl;
	}
	//explicit를 앞에 붙이면 묵시적으로 복사생성자가 자동으로 만들어 주는 걸 막아줌

	//복사 대입 연산자
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}
};

Fraction CreateFraction() //이름 있는 객체 : 객체를 만드는 함수
{
	Fraction temp(5, 2); //생성자를 통해서 임시 객체를 만들어 준다음
	
	return temp; //반환함
}

int main()
{
	Fraction frac(3, 5); //객체 하나 만들고
	Fraction copy1(frac); //copy initialization(복사 생성자)
	Fraction copy2 = frac; //이것도 복사 생성자

	copy2 = frac; //copy assignment operator(복사 대입 연산자) =

	{
		int a = 5; //복사
		int b = a; //복사 대입
	}

	return 0;
}
```

```cpp
Fraction CreateFraction() //이름 있는 객체 : 객체를 만드는 함수
{
	Fraction temp(5, 2); //생성자를 통해서 임시 객체를 만들어 준다음
	
	return temp; //반환함
}

int main()
{
	CreateFraction(); //Fraction 클래스의 객체를 만드는 함수.
	//이때도 복사 생성자가 생김 -> 비효율적

	return 0;
}
```

# 12_RVO_NRVO  ★
컴파일러가 함수의 반환값을 최적화하는 기술
- RVO - Return value Optimization : 이름이 없는 경우 최적화가 가능
	- 함수의 반환값을 임시 객체를 생성하지 않고 바로 호출한 곳으로 전달함으로써 성능을 향상시킴.
	- 임시 객체의 생성이나 소멸이 일어나지 않는 것.
```cpp
Point func() //복사 생성자를 호출하지 않음
{
    Point p(1, 2);
    return p; //객체가 바로 호출한 곳으로 전달됨.
}
```

- NRVO - Named Return Value Optimization : 이름이 있는 경우, 이름있는 객체 생성 함수처럼 최적화가 힘듦
	- 함수 내에서 생성한 객체를 지역 변수에 저장한 다음 반환하는 최적화 기술.
	- 이름 있는 임시 객체가 만들어지면서 복사 생성자가 호출됨.
```cpp
Point func()
{
    Point p(1, 2);
    Point q = p; //지역 변수에 저장하 후 전달됨.(복사 생성자를 호출하지 않음)
    return q;
}
```

# 13_conversion_constructor(변환 생성자)  ★
하나의 인자를 받아 클래스 객체로 변환하는 생성자를 말한다.
```cpp
class Integer {
    private:
        int value;
    public:
        Integer(int v) : value(v) {}
		//Integer 객체를 생성할때 int값을 직접 전달하여 객체를 생성한다.
};
```

```cpp
class Fraction//분수
{
	int numerator; //분자
	int denominator; //분모

public:
	Fraction(int num, int den)
		:numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	//변환 생성자
	Fraction(int a) //매개 변수가 딱 하나 있 으면 변환 생성자(다른 자료형으로 형변환하고 싶을 때 사용)
		:numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}
};

void PrintFraction(Fraction frac) //이때도 복사돼서 매개변수로 객체가 들어가므로 복사 생성자가 생김
{
	//이때도 매개 변수가 어떤 int 같은 자료형이 아니라 객체로 들어오는 거지만, 자료형이 다른 게 들어와도
	//자동으로 형변환이 일어남
	//막아주려면 함수 앞에 explicit을 붙여주자.
	cout << frac << endl;
}
int main()
{
	Fraction frac3(1); //자료형이 올바름
	Fraction frac4('A'); //자료형이 char형으로 다르지만 자동으로 묵시적 형변환이 일어나서 들어감
	Fraction frac5(3.14f); //이또한 형변환이 일어나지만 자료값이 잘리긴 함.

	
	//이렇게 자료형이 맞지 않는 게 들어가서 실행 되는 게 가능한데, 막아주려면 함수 앞에 explicit을 붙여줌
	PrintFraction(1);
	PrintFraction('A');
	PrintFraction(3.14f);

	return 0;
}
```


# 14_assignment_operator(대입 연산자 = )   ★
객체에 값을 할당하기 위해 사용된다.

c++ 컴파일러는 자동으로 복사 생성자와 대입 연산자를 생성해 주지만, 객체 내의 동적할당된 메모리나 파일 포인터 등의 자원이 있는 경우에는 별도로 대입 연산자를 정의해 주어야 한다.
```cpp
class MyClass {
public:
    MyClass& operator=(const MyClass& rhs) 
	{
        if (this != &rhs) 
		{   // 자기 자신과 대입하는 경우 제외
            // 멤버 변수 값 복사
            this->member1 = rhs.member1;
            this->member2 = rhs.member2;
        }
        return *this; // 대입된 객체 리턴
    }
private:
    int member1;
    double member2;
};

int main()
{
	MyClass a, b, c;
	a = b = c; // 체이닝 가능

	return 0;
}
```

## 복사 생성자(깊은 복사)
```cpp
	Mystring(const Mystring& other) 
		//포인터로 복사했을 때에는 주소가 넘어옴(원본의 주소와 같아짐
		//-> 소멸자에 의해 없어지는데 other은남아있어서 소멸된 곳을 가리키는 상황이 생김(허상포인터)
		//그래서 동적할당을 이용해서 밖의 값과 같은 곳을 가리키지 않게끔 함(느리지만 안전)
	{
		this->length = other.length;
		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			data = nullptr;//잘못 들어왔을 경우 널로 초기화.
		}
	}
```

## 복사 대입 연산자
```cpp
	Mystring& operator = (const Mystring& other) //복사 대입 연산자를 만들지 않으면 자동으로 얕은 복사 대입 연산자가 만들어짐
	{
		if (this == &other) //나 자신을 할당하는 상황이 생기면
		{
			return *this;
		}

		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		cout << "copy assignment operator" << endl;
		this->length = other.length;

		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			this->data = nullptr;
		}

		return *this;
	}
```

## 이동 생성자
```cpp
	Mystring(Mystring&& other) //r-value 레퍼런스니까 &&
	{
		cout << "move constructor" << endl;

		this->data = std::move(other.data);
		this->length = std::move(other.length);
		//우측 값 레퍼런스를 통해 타입 캐스팅한다고 생각하자.

		//이후 other(우측값 레퍼런스)는 한번 쓰고 말거니까 더이상 쓸 수 없게 접근하지 못하게 해줌
		other.data = nullptr;
	}
```

## 이동 대입 연산자
```cpp
Mystring& operator = (Mystring&& other)
	{
		cout << "move assignment operator" << endl;

		if (this == &other) //prevent self-assignment(자기 자신을 할당하는 것)/ 이런 상황을 혹시 모르니 항상 방지해야 함
			return *this;

		//원본값과 같은 것을 가리키면 동적할당 해제할때 원본값도 해제해 버릴까봐. 같은 경우를 제외하도록 늘 확인해줌

		if (this->data != nullptr)
		{
			if (other.data != nullptr && this->data != other.data)
			{
				delete[] this->data;
				this->data = nullptr;

				this->data = std::move(other.data);
			}
		}
		else
			this->data = std::move(other.data);

		this->length = std::move(other.length);

		other.data = nullptr;

		return *this;
	}
```