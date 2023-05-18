#include <iostream>
#include <cassert>//내부 조건이 false이면 터질 수 있도록 만들어줌
//대입 연산자, 이동 생성자(그 원본 자체를 받아오는 것, r-value)
using namespace std;

/*
	지금까지 배운 복사 생성자는 얕은 복사 생성자 였음
	deep copy vs shallow copy

	깊은 복사 : 멤버 대 멤버 복사가 생기는데, 포인터를 복사할때에는 얕은 복사를 하면(그대로 복사되기 때문에) 원본과 주소가 같아지는 문제가 생기지 않게 깊은 복사 생성자를 만들어줘야 함
	동적할당을 하면서 나중에 복사된 객체를 해제해서 없앨 때 원본도 같이 사라져 버리는 일이 일어나지 않게 하는 것.
*/

class Mystring 
{
public:
	char* data = nullptr;
	int length = 0;

public:
	Mystring(const char* const src = " ") //공백 문자열(nullptr이 들어오면 빈 문자열을 생성한다)
	{
		//이때, 아무것도 받아오지 않으면 터지게 만들어보자
		assert(src);

		length = strlen(src) + 1;
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0'; //마지막 문자는 공백으로 하기 위해서
	}

	//복사 생성자(깊은 복사)
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

	~Mystring()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	//복사 대입 연산자
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

	//이동 생성자 : 원본을 없애는 게 아니라 이동시킨다고 생각하자.
	Mystring(Mystring&& other) //r-value 레퍼런스니까 &&, l벨류처럼 받아와 지긴 함.
	{
		cout << "move constructor" << endl;

		this->data = std::move(other.data);
		this->length = std::move(other.length);
		//우측 값 레퍼런스를 통해 타입 캐스팅한다고 생각하자.

		//이후 other(우측값 레퍼런스)는 한번 쓰고 말거니까 더이상 쓸 수 없게 접근하지 못하게 해줌
		other.data = nullptr;
	}

	//이동 대입 연산자 : 원본을 잘라와서 쓰고 원래 자리에 있는 것은 없애버리는 것
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
};

int main()
{
	cout << "#############1###########" << endl;
	Mystring str("Hello");
	cout << (int*)str.data << endl; // 주소 찍기, &str.data로 찍으면 객체의 주소가 찍힘, 문자열이 저장된 공간의 주소를 int형으로 찍으려고 이렇게 씀. 
	cout << str.data << endl << endl; //값 찍기

	cout << "#############2###########" << endl;
	//copy
	{
		Mystring copy(str);
		copy = str;
		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	} //지역을 나오면서 복사된 객체는 사라짐

	cout << "#############3###########" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl; // 원본은 남아있는지 확인
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}

	cout << "#############4###########" << endl;
	//move
	{
		Mystring copy(std::move(str)); //copy로 이동했으니 str은 없어짐
		copy = std::move(str);

		cout << (int*)copy.data << endl;
		cout << copy.data << endl;
	}
	
	cout << "#############5###########" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}


	/*
	#############1###########
	0000022B865C20F0
	Hello

	#############2###########
	copy assignment operator
	0000022B865C2280
	Hello

	#############3###########
	0000022B865C20F0
	Hello

	#############4###########
	move constructor
	move assignment operator
	0000022B865C20F0
	Hello

	#############5###########
	0000000000000000
	
	
	*/

	return 0;
}

/*
	<과제>
	Test클래스를 하나 만들어서
	자동 호출되는 것들(특수맴버 함수, special member function)
	-기본, 복사, 복사대입, 이동, 이동대입, 소멸
	안보고 만들어보기.

*/