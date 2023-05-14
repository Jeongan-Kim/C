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
