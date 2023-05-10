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
## const vs constexpr
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

## C스타일 문자열(포인터로 선언)
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
무조건 null만 받는 ptr도 있다. 잘 쓰이지는 않는다.
```cpp
std::nullptr_t nptr;
```