# 00_컴파일 타임 vs 런타임
## 컴파일 타임
- 소스 코드가 컴파일러에 의해 기계어 코드로 변환되는 시간
- 컴파일러가 이 과정에서 소스 코드를 분석하고, 오류를 검출하며, 기계어 코드를 생성한다.
- 프로그램의 구조, 문법, 타입 등을 겁사하여 최적화(프로그램 실행 속도를 향상시키는데 도움을 줌)를 수행한다.

## 런타임
- 프로그램이 실행되는 동안의 시간
- 프로그램이 실행되면서 메모리에 할당되고, CPU에서 명령어를 실행하며 입출력을 수행한다.
- 런타임 오류는 프로그램이 실행 중에 발생하는 오류로, 미리 검출할 수 없다.
- 프로그램의 실제 동작을 확인할 수 있으며, 런타임 오류의 원인을 파악할 수 있다.
- 동적할당, 예외처리, 다양한 입출력 등 동적인 요소를 다룰 수 있다.

# 01_Hello
```cpp
#include <iostream>
```
input output 입출력의 흐름이라는 의미로 기본적을 쓰는 헤더 파일
만약 c언어에서 쓰던 stdio.h를 쓰고 싶다면, <cstudio>를 사용하면 된다.

```cpp
std::cout << "Hello, c++!!" << std::endl;
std::cout << "Hello, c++!!" << "\n";
```

std라는 namespace에 있는 키워드들을 꺼내 쓰는 느낌으로 'std::'라고 쓴다.
cout은 출력, endl은 \n와 같은 의미로 개행이다.

```cpp
std::cout << "x = " << x << "y = " << y << std::endl;
std::cout << "x = " << x << " " << "y = " << y << std::endl;
std::cout << "x + y = " << x + y << std::endl;
```
이렇게 값을 출력하고 싶을 때도 간편하다.

# 02_input_output_stream
## stream
- '>>' : input operator(입력 연산자)
- '<<' : output operator(출력 연산자)

```cpp
int a;
std::cin >> a;
std::cout << "입력한 숫자 : " << a << std::endl;
```
a에 scanf처럼 값을 입력할 수 있고, print처럼 값을 출력할 수 있다.


## 조정자(manipulator)
출력할 값의 형태를 조정자를 통해 조정할 수 있다.
```cpp
int num = 100;
std::cout << std::oct << num << std::endl; //8진수      144
std::cout << std::dec << num << std::endl; //10진수     100
std::cout << std::hex << num << std::endl; //16진수     64

std::cout << std::showbase << std::showpos; //한번 쓰면 showbase가 켜진 것.showbase(어떤 진수인지), showpos(부호)
std::cout << std::oct << num << std::endl; //앞에 0이 붙음   0144
std::cout << std::dec << num << std::endl; //앞에 +가 붙음   +100
std::cout << std::hex << num << std::endl; //앞에 0x가 붙음  0x64
std::cout << std::noshowbase << std::noshowpos; //한번 쓰면 showbase가 꺼진 것.
```

```cpp
bool is_true = true;
bool is_false = false;

std::cout << std::boolalpha; //이것도 한번 쓰면 켜짐, true false를 영어로쓰라는 말
std::cout << is_true << std::endl;  //true
std::cout << is_false << std::endl; //false

std::cout << std::noboolalpha; //끄기
std::cout << is_true << std::endl;  //1
std::cout << is_false << std::endl; //0
```

# 03_variable(변수)
## initialization(초기화)
- copy initialization : 할당 연산자를 이용
- direct initialization : 소괄호 이용
- uniform initialization : 중괄호 이용
```cpp
int x = 10; //copy initialization
int y(10); // direct initialization
int z{ 10 }; //uniform initialization
```
변수를 여러 방법으로 초기화할 수 있지만 차이점을 살펴 보자면,
변수 초기화를 할 때 자료형과 값이 맞지 않을 경우
copy 초기화는 컴파일 오류는 나지 않고 경고만 하지만, uniform 초기화는 에러가 난다.

```cpp
int a = 1.1; //warning 컴파일 오류는 안나지만 더 안전하게 해보라 경고 나옴. 0.1이 잘리기때문
int b{ 1.1 }; //error int 형에 double형을 넣엇다는 것이 명확하므로 오류
char c = 500; //warning 값이 잘림
char d{ 500 }; //error 
```

## limits(한계값)
아래처럼 각 자료형의 한계값을 확인해 볼 수 있다.
```cpp
std::cout << std::numeric_limits<short>::max() << std::endl;
std::cout << std::numeric_limits<int>::min() << std::endl;
std::cout << std::numeric_limits<int>::max() << std::endl;
std::cout << std::numeric_limits<float>::min() << std::endl;
std::cout << std::numeric_limits<float>::max() << std::endl;
```

## casting(형변환)
값을 호출 또는 출력할때 형변환을 하는 방식을 알아보자.
```cpp
std::cout << k << std::endl;
std::cout << (int)k << std::endl; //(int)k : 명시적 형변환 << C스타일, 강제적
std::cout << int(k) << std::endl; //C++스타일
std::cout << static_cast<int>(k) << std::endl; //C++스타일, 제일 안전, 제일 많이 씀
```
## const vs constexpr ★
### 상수 구문이 쓰이는 경우
- 상수는 코드의 가독성을 높인다. 특히, 마법의 숫자(magic number)를 피할 수 있다.
- 상수는 유지보수를 쉽게 한다.
- 멀티 스레드 시스템에서 개체 간 자원 경쟁을 피할 수 있다.
- 가끔 컴파일 시간에 무언가를 평가하는 것이 성능 향상으로 이어질 수 있다.
- 시스템 요구사항을 좀 더 직접적으로 표현할 수 있다. (e.g. 임베디드 시스템에서 불변 데이터를 읽기 전용 메모리에 넣는 경우 등)


c++에서는 상수(constant)의 의미를 부여하기 위해 const와 constexpr 두 가지를 사용한다.
### const
- 단순 상수값 만드는 것.
- "절대 바꿀 수 없다"
- 멤버 함수에만 사용 가능
- 멤버 변수를 바꿀 수 없음

### constexpr
- 컴파일 시간에 평가하여 비용을 절감한다.(런타임때 자료형이 정해진다)
- 멤버와 비멤버 함수에 둘다 사용 가능
- 멤버 변수를 바꿀 수 있음

```cpp
const     double PI1 = 3.141592653589793;
constexpr double PI2 = 3.141592653589793;

constexpr double PI3 = PI1;  // error
constexpr double PI3 = PI2;  // ok

static_assert(PI1 == 3.141592653589793, "");  // error
static_assert(PI2 == 3.141592653589793, "");  // ok

constexpr int a(123); //컴파일 할 때 이미 결정됨 : 컴파일 상수
int num;
std::cin >> num;
const int b(num); //실행을 해봐야지만 안다. : 런타임 상수
constexpr int b(num); //error
```

# 04_namespace(이름 공간)
```cpp
std::cout ~ //std 이름 공간의 cout을 호출

using namespace std; //이름 지정 없이 함수를 호출할 수 있다.
cout ~;

using std::cin; //cin을 쓸 때에 이름 지정을 하지 않겠다.
std::cout ~; //ok
cout ~; //error
cin ~; //ok
```

이름 지정자(::)를 통해 이름이 같은 지역변수와 전역변수를 구별할 수 있다.
```cpp
int a = 10;

int main()
{
    int a = 20;

    a++; // 지역변수 a
    cout << a << endl; // 21

    ::a++; // 전역변수 a
    cout << a << endl; // 11

    return 0;
}
```
# 05_macro_function
## 매크로
- 단순 치환 방식
```cpp
#define NUM 10

#define PLUS(a, b) ((a) + (b)) // 괄호 안치면 a + b 오류 나기 쉬움
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) // 여러 자료형을 넣어도 계산 가능
```

## inline(매크로 함수)
- 매크로와 다르게 괄호를 귀찮게 다 쳐주지 않아도 돼서 편함.
- 일반 함수보다 속도가 빠름
- 일반 함수가 속도가 빠르면 컴퓨터가 자동으로 inline화 해줌.
```cpp
inline int Max(int a, int b)
{
	return (a > b) ? a : b; //자료형이 정해지므로 타입을 잘 맞춰 써야 함
}
```

# 06_type_inference(타입 추론)
자료형이 다른 두 변수를 계산할 때, 자료형을 계산할 귀찮음 없이 컴파일러가 알아서 타입 랭킹에 따라 자료형을 추론해줌.
```cpp
int a = 10;
float b = 3.14f;
double c = 45.0;

float result = a + b; //정석
auto result = a + b;  //컴퓨터가 알아서 해줌
```
auto를 함수 반환형으로도 사용할 수 있다.
```cpp
auto add(int x, int y) //매개변수를 auto로 받아올 수는 없음.
{
	return x + y;
}

auto add(int x, int y) -> int //계산 시간이 오래 걸릴때에는 후위 반환 타입을 명시해 줄 수 있음.(편의성은 떨어짐)
{
	return x + y;
}
```

# 07_function_overloading
함수 이름은 같으나 매개변수, 반환형 등을 차별화하여 구별하는 것
```cpp
int add(int a, int b) {	return a + b;}
float add(float a, float b) {return a + b;}
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }

void output(int value) {}
void output(unsigned int value){}
void output(float value){}

using integer = int; //int a == integer a
//integer add(integer a, integer b) { return a + b; } 위 첫번째 함수와 같은 모양이니까 쓸 수 없음.
```
함수를 호출할 때 매개변수에 의해 모호성 오류가 생길 수 있으니 주의
```cpp
auto result1 = add(10, 20); //자료형을 계산하기 귀찮으니 auto사용
auto result2 = add(10.1f, 20.0f);
auto result3 = add(10, 20, 30);

output(1); //모호성 오류가 생김(int 인지 unsigned 인지 모호하니까)
output(1.0f);

output('c'); 
//자신과 일치하는 함수를 찾지 못하면 형 변환을 해서 비슷한 걸 찾음
//char, unsigned char, short, int 순으로
```

# 08_default_parameter
함수를 선언할 때 기본적인 default값을 말한다. 함수를 호출할 때 매개변수에 아무것도 입력하지 않았을때 기본(default)값.
- overloading과 같이 쓰면 위험함.(모호성 문제)
- 단순한 값뿐만아니라 연산자, 함수 등을 이용해서 다양하게 설정할 수 있다.

```cpp
void print(int x = 7) // 아무것도 안들어오면 7을 넣었다고 보자.
{
	cout << x << endl;
}

void print(int x, int y = 7) // 매개변수 하나에만 기본 값을 줘도 되는데, 앞 매개변수는 생략 가능하지만 뒤 매개변수를 생략하는 것은 안됨.
{
	cout << x << y << endl;
}

void test(int x = 10, int y = 10, int z = 10)
{
    cout << x << y << z << endl;
}

int main()
{
	print(); // 7
	//print(2); // 2인데, 두번째 print 함수에서 y를 생략하고 x에만 2를 넣은 것과 모호성 문제가 일어남

	test(10, 10, 3); // 10 10 3
    // 바꿔 주고 싶은 자리의 매개변수만 바꿔 주고 나머지는 명시해줘야함.
    test(3); // 3 10 10

	return 0;
}
```

# 09_string(문자열)
- 알파벳 하나하나와 띄어쓰기를 포함하여 메모리 상의 연속적으로 나열되며, 마지막에는 '\0'(NULL)로 끝나는 배열이다.

c++에서 string을 사용하려면 string 헤더파일을 써 줘야 함.
## C스타일 문자열(배열로 선언)
```cpp
char myStr[] = "Hello C";  //메모리 공간은 컴파일러가 알아서 할당
char myStr[7] = "Hello C"; //메모리 미리 할당
```

## C스타일 문자열(포인터로 선언) ★
- string이라는 변수를 포인터변수로 선언하기에 주소값을 저장한다.(문자열의 첫번째 항을 가리키는 주소)
```cpp
char* myStr2 = "Hello C"; 
//포인터로 선언하는 문자열은 상수로 초기화 되는 거라 수정이 불가. 
const char* myStr2 = "Hello C"; 
//C++에서는 상수화를 꼭 해줘야 함.
```
## c++스타일 문자열 선언
```cpp
string str = "Hello C++"; 
string a("Hello, ");
string b("C++!!"); //직접 초기화
```

## string 연산
```cpp
cout << str.size() << endl; //NULL제외 길이
cout << str.length() << endl; //NULL제외 길이

string c = a + b; //문자열 연산 -> Hello, C++!!
c += ", good!!"; //-> Hello, C++!!, good!!

cout << c[4] << endl; //문자열의 4번째 원소 출력
```

# 10_pointer
C에서 포인터 변수는 반드시 null로 초기화 해줘야 했다.
```cpp
int* ptr = nullptr; //NULL이 아니라 nullptr
int* ptr2(nullptr);
int* ptr3{ nullptr };
```
무조건 null만 받는 ptr도 있다. 잘 쓰이지는 않는다.  ★
```cpp
std::nullptr_t nptr;
```

# 11_random_number
## C스타일 난수 생성 방식
```cpp
#include <stdlib.h>
#include <time.h>

srand((unsigned int)time(NULL));

for (int i = 0; i < 10; i++)
{
	printf("%d ", rand() % 10);
}
```

## C++스타일 난수 생성 방식
```cpp
#include <random>
random_device rd; //난수 생성할 시드값(컴퓨터가 마주하는 모든 경우의 랜덤한 상황

mt19937 messenne(rd());

uniform_int_distribution<> randNUM(1, 10);// 동일한 확률로 난수가 생성되게 하는 작업(분포도) : 동일한 확률로 1부터 10까지 나오게 함.

for (int i = 0; i < 10; i++)
	cout << randNUM(messenne) << " ";
```

# 12_array
## C스타일 방식
```cpp
int arr1[] = { 1, 2, 3, 4, 5 };
```
## C++스타일 방식
```cpp
int arr2[]{ 1, 2, 3, 4, 5 };
int arr3[](1, 2, 3, 4, 5); //소괄호는 불가능  ★
```

## STL(Standard Template Libraries)
배열 구조를 간단하게 짜고 싶을때 사용
### template : <> (간단하게만 알아보자)  ★
함수나 클래스를 개별적으로 다시 작성하지 않아도 여러 자료형으로 사용할 수 있도록 만든 틀.
```cpp
std::array<int, 5> arr4; //int 가 5개인 arr4라는 배열이 선언됨, 더 직관적
array<int, 5> arr5{ 1, 2, 3, 4, 5 }; //초기화도 가능
```
배열 속 특정 원소에 접근하고 싶을때
```cpp
cout << arr5[0] << endl; 
cout << arr5[1] << endl; 
cout << arr5.at(2) << endl; //at으로 원소에 접근 가능
cout << arr5.at(3) << endl;
cout << arr5.at(4) << endl;
cout << arr5.size() << endl; //size()로 사이즈 측정 가능

//차이점
cout << arr5[5] << endl; //쓰레기값 나오지만 어쨌든 접근은 됨.
cout << arr5.at(5) << endl; //error. 대신 느림. 안정적.
```


# 13_dynamic_memory_allocation(동적할당)
## C스타일 동적할당
- 사이즈를 매개변수로 받고, 반환형이 void* 형이므로 크기와 캐스팅을 활용해야 함.
- 메모리를 동적으로 할당하는 것만이 목적이어서, 초기값을 지정해줄 수 없음.
```cpp
#include <stdlib.h> //헤더 파일 필요

int* ptr = (int*)malloc(5 * sizeof(int));

if (ptr == NULL)
	exit(1); //예외 처리를 해줬어야 안전했음

free(ptr);
ptr = NULL;
```

## C++스타일 동적할당 ★
- 할당할 자료형을 지정하면 알아서 할당할 자료형의 포인터로 넘어오기 때문에 같은 자료형의 포인터 변수로 받아오기만 하면 된다.
- 할당과 동시에 초기화 가능
- 생성자(객체를 자동으로 초기화해주는 함수)를 자동으로 호출.(malloc과 가장 큰 차이점)
```cpp
//별도의 헤더파일 필요없음

int* ptr1 = new int; 
delete ptr; //해제, 널 초기화 해주지 않아도 됨

int* ptr2 = new int(7); //크기를 직접 초기화
delete ptr2;

int* ptr3 = new int{ 7 };
delete ptr3;

int* ptr4 = new(std::nothrow) int{ 7 }; 
//안정적으로 예외처리를 해주기 위해서 이렇게 초기화
	
if (ptr4 == nullptr) //예외 처리
	std::cout << "Error";

if (ptr4 != nullptr)
	delete ptr4;
	
//배열처럼
int* arr = new int[10]{ 1, 2, 3, 4, 5, 6 };
delete[] arr;

//포인터 배열을 2차원처럼 사용 가능
int** ptrArr = new int* [5];

ptrArr[0] = new int[10];
ptrArr[1] = new int[10];
ptrArr[2] = new int[10];
ptrArr[3] = new int[10];
ptrArr[4] = new int[10];

//지울때에는 안에 것부터 지우고 바깥을 지움
for (int i = 0; i < 5; i++)
	delete[] ptrArr[i];

delete ptrArr;
```

## 구조체 동적할당 ★
```cpp
struct Test
{
	int a;
	int b;
	std::string str;

	void printNUM()
	{
		std::cout << "Hello" << std::endl;
	}
};

int main()
{
    Test* test = new Test;

    test->a = 10;
    test->b = 20;
    test->str = "hello";
    test->printNUM();

    return 0;
}
```
## malloc vs new
- malloc은 구조체에서 pod(plain old data : 연속된 메모리) 타입을 인자로 받아와서 쓸 수 있음
- string, 함수 같은 건 pod 타입이 아니라서 malloc 쓸 수 없음.
- malloc의 경우, realloc이라는 함수로 재할당이 가능하지만, new에는 이에 대응하는 것이 없기때문에 새로 할당 -> 복사 -> 해제 하는 과정을 거쳐야 한다. 하지만 객체의 경우 반드시 new / delete 를 사용해서 할당 / 해제 해주어야 한다. 객체가 아닌 경우에 재할당이 빈번하게 일어난다면, malloc / free 가 더 좋은 선택이 될 수 있다.

# 14_structures
여러 개의 변수를 가진 객체를 프로그래밍 할 때 사용.
```cpp
struct person
{
	void __thiscall Print(/* person* */)
	{
		cout << age << endl;
	}

	int age;
	float weight = 50.0f;
	string name = "Jeongan";
};

int main()
{
	person p1;

	p1.Print(); //멤버변수에 접근 시
	//person::Print(); //이렇게는 불가능
	return 0;
}
```

# 15_reference(참조자)_variable

## reference(참조자)
```cpp
int a = 10;
int& b = a;
```
이때, b는 a의 참조자이다. int형 변수의 참조자를 만든 것으로 자료형 뒤에 &를 붙인 것이다.
포인터 타입의 참조자라면, int*&로 쓰면 된다. 
- b가 a의 참조자이다 = b는 a의 또다른 이름이다.
- 즉, b에 어떠한 작업을 하든 사실상 a에 작업을 하는 것과 마찬가지이다.

참조자는 포인터와 상당히 유사한 개념이지만 차이점이 있다.

## 포인터 vs 참조자
- 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다. ★
	```cpp
	int& b; //error
	```
	위와 같은 문장은 불가능.
	```cpp
	int* p;
	```
	반면에 포인터는 가능하다. 

- 레퍼런스가 한 번 참조자가 되면 절대로 다른 이의 참조자가 될 수 없다.
	```cpp
	int a = 10;
	int& b = a;
	int c = 20;
	int& b = c; //error  ★
	```
	이 코드는 b가 a의 참조자이기도 하고 c의 참조자이기도 해버려서 a = c라는 말이다.

	반면에 포인터는 누구를 가리키는지 자유롭게 바뀔 수 있다.
	```cpp
	int a = 10;
	int* p = &a; // p 는 a 를 가리킨다.
	int b = 3;
	p = &b // 이제 p 는 a 를 버리고 b 를 가리킨다 ★
	```
- 레퍼런스는 메모리 상에 존재하지 않을 수도 있다.
	```cpp
	int a = 10;
	int& b = a;
	```
	이때 b라는 참조자는 메모리를 갖고 있지 않아도 된다. a로 대치해버리면 되기 때문에!
	하지만 항상 메모리 상에 존재하지 않는 것은 아니다. ★

- 여러가지 참조자 예시
	```cpp
	int x;
	int& y = x; //y는 x의 참조자.
	int& z = y; //z는 y의 참조자(?). -> 참조자의 참조자가 아니라 x의 참조자를 선언하라는 의미. 
	//즉, z는 x의 참조자.
	```
	```cpp
	int& a = 4; //error. 상수 값은 리터럴이기에 참조 불가능
	const int& a = 4; //상수 참조자라면 리터럴도 참조할 수 있다. 불변이기에.
	// 리터럴 : 소스 코드 상에서 고정된 값을 가지는 것.
	int b = a; //a는 4라는 상수를 참조하는 const 참조자이므로 b = 4 라는 의미가 된다.

## L-value
- & 연산자를 통해 주소값을 알아낼 수 있는 값. 주소값을 취할 수 있는 값.
- 기본적으로 식별자를 가지고 다른 값을 복사 받을 수 있다.
- 대입이 가능하다.
- 어떠한 표현식의 왼쪽 오른쪽 모두에 올 수 있다.

## R-value
- 주소값을 취할 수 없는 값
- 연산 등을 할 때만 잠깐 존재할 뿐 연산이 끝나면 사라지는 값.
- 상수이거나 식별자가 존재하지 않아서 자신의 상태를 수정할 수가 없다.
- 어떠한 표현식의 오른쪽에만 올 수 있다.
```cpp
int a = 3; //a : L-value, b : R-value


int& b = a; //b : L-value
int& c = 3; //error. R-value를 참조할 수 없음.
```
이렇게 L-value 참조자(b)도 L-value가 될 수 있다.
함수에 넣어보면,
```cpp
int Test1(int& a) //원본값이 복사되어 들어가서 원본값을 바꾸겠다.(copy)
{
	return a; //원본 값이 수정됨.
}

int Test2(int&& a) //원본값이 없으므로 이 안에서만 쓰고 말겠다.(move)
{
	return a;
}
```

# 16_range_based_for_loop(범위기반 반복문)
범위 기반 for문 : 범위가 있어야지만 쓸 수 있다.
```cpp
int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

//일반적으로 알고 있는 for문
for (int i = 0; i < sizeof(fibonacci) / sizeof(int); i++)
	cout << fibonacci[i] << endl;

//위 식을 범위 기반 for문으로 쓰면
for (const auto& number : fibonacci) 
//fibonacci 범위의 수들을 변동 없이(const) 참조해서(&) 하나씩 접근하겠다.
	cout << number << endl;

for (const auto& number : { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 })
	cout << number << endl;
```
하지만 범위가 없는 경우에는 쓸 수 없다. ★
```cpp
int* test = new int[10]; //범위는 10이지만 초기화가 안돼서 범위가 없다?
for (auto t : test); //error
```

# 17_type_information
여러 자료형으로 오버로딩 함수를 만들고 싶을 때, 간단하게 쓰는 방법을 알아보자.
```cpp
int add(int a, int b) { return a + b; }
short add(short a, short b) { return a + b; }
float add(float a, float b) { return a + b; }
```
이렇게 모든 자료형에 대한 덧셈 함수를 만들기 번거로우니, Template(템플릿)을 사용해서 간단하게 쓸 수 있다.
- Template : 프로그래머가 원하는 타입을 넣어주면 알아서 코드를 찍어내는 틀.
```cpp
template <typename T> //<class T>라고 써도 됨
T add(T a, T b) 
{
	return a + b;
}
```

# 18_assert  ★
디버깅 버전에서 오류 체크를 하기 위한 구문(컴파일은 되지만 실행 중 오류남)
```cpp
#include <cassert> //필요한 헤더파일

int a;
cin >> a;

//a에 들어온 숫자가 0일 경우 오류 체크를 하려면
assert(a != 0);
//괄호 안이 true면 지나가고, false면 error.
assert(false); //무조건 error.
assert(a != 0 && "a is 0") //오류 시 출력할 구문도 추가 가능.
```
static assert(정적 어설션) : 컴파일 도중에 error가 나게 하는 것. (프로그램 실행 자체가 안됨.)
```cpp
static_assert(false);

const int a = 6;
const int b = 8;
static_assert(a < b, "a가 b보다 크다."); //오류 출력창에 나오는 구문
```

# 19_function_pointer ★
- 함수도 포인터로 가리킬 수 있다. 즉, 함수도 주소가 있다. 

```cpp
int Func(int a, int b) 
{
    return a + b;
}
int main() 
{
    printf("함수 Func의 주소 : %p\n", &Func); //&함수이름
}
```
- 함수 포인터는 함수를 또 다른 함수의 인수로 전달할 떄 유용하게 사용된다.
```cpp
int function(int, int) { } //함수1 선언
int (*ptr_func) (int, int); //함수1의 포인터 선언
int function2(int, int, ptr_func); //함수 포인터를 매개변수로 사용
```

## 함수 포인터 선언 방법 
### 1.
```cpp
int(*ptrFunc) (int a, int b);
//함수 반환형(함수 포인터 이름) (매개 변수)
//매개 변수가 없다면 빈 괄호나 void 사용
```
### 2. typedef 키워드를 이용하면 복잡한 함수 포인터 형에 새로운 이름을 붙일 수 있다.
```cpp
int function(int, int) { }

typedef int(*ptrFunc) (int a, int b); //ptrFunc이 이러한 형태의 포인터들의 이름이 된다.(구조체처럼)
ptrFunc ptr_func = function; 
```

### 3. auto 키워드를 이용하면 복잡한 함수 포인터 형으로 자동 타입 변환이 된다.
```cpp
auto ptr_func = function;
```

### 4. <functional> 헤더 파일을 사용하여 선언하는 방법
```cpp
#include <functional>
int function(int, int) { }

std::function<int(int, int)> ptr_func = function;
```

# 20_elliopsis(생략 부호 '...')
- 함수를 선언할 때, 매개변수가 정해지지 않았으면 할때 생략 부호 '...'를 쓴다.
- 매개 변수가 정해지지 않은 함수 = 가변 함수(variadic function)
- va_list로 생성 -> va_start와 va_end로 시작과 끝을 설정

```cpp
#include <cstdarg> //생략부호를 위한 헤더 파일

double findAverage(int count, ...) // 파라미터로 받아올 argument의 갯수
{ 

double sum = 0;

    va_list list; // list를 생성한다.

    va_start(list, count); // list의 개수에 해당하는 count를 넘겨준다.

    for(int arg = 0; arg < count; arg++) // 필요한 계산을 해준다.
        sum += va_arg(list, int); // 어떤 타입으로 사용할지는 정헤져있어야 한다.

    va_end(list);

return sum / count;    
}

int main()
{
    cout << findAverage(1, 1, 2, 3, "hello", 'c') << endl;
    cout << findAverage(3, 1, 2, 3) << endl;
    cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
    cout << findAverage(10, 1, 1, 2, 3, 4, 5) << endl;
    //인자를 여러개 넣어도 카운트 값에 맞는 개수만큼만 평균 계산에 들어감

    return 0;
}
```