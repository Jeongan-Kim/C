#include <iostream>
//부분 특수화

using namespace std;

//#pragma region 1. 일반 함수 부분 특수화
//template <class T, int size>
//class StaticArray //정적 배열 클래스
//{
//	T arr[size]; //non타입으로
//
//public:
//	T* GetArray() { return arr; }
//
//	T& operator[](int index)
//	{
//		return arr[index];
//	}
//
//	void Print1()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << (*this)[i] << ' '; //arr[i] 자체가 자신 것이므로 this로 써도 됨
//		}
//		cout << endl;
//	}
//};
//
//template<typename T, int size>
//void Print2(StaticArray<T, size>& arr) //내 클래스의 객체를 하나 받아와서 입력.
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//}
//
////이 함수를 char형일때만 특수화하고 싶을때
//template<int size>
//void Print2(StaticArray<char, size>& arr)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i]; //문자열이니까 띄어쓰기 없이 써주게끔
//	}
//	cout << endl;
//}
//
//#pragma endregion

#pragma region 2. 클래스 멤버 함수 부분 특수화
//상속을 이용해서 부분 특수화를 해줘야 함
template <class T, int size>
class StaticArray_Base
{
	T arr[size]; 

public:
	T* GetArray() { return arr; }

	T& operator[](int index)
	{
		return arr[index];
	}

	virtual void Print1() //오버라이딩할 수 있게 virtual 키워드 붙이기
	{
		for (int i = 0; i < size; i++)
		{
			cout << (*this)[i] << ' '; 
		}
		cout << endl;
	}
};

//일반적으로 상속할때
template<class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{

};

//char 형일때만 특수화
template<int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
	void Print1() override
	{
		for (int i = 0; i < size; i++)
		{
			cout << (*this)[i];
		}
		cout << endl;
	}
};


#pragma endregion

int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.Print1();
	//Print2(int4); //템플릿화 시킨 함수로도 가능.

	StaticArray<char, 6> char6;
	char6[0] = 'H';
	char6[1] = 'E';
	char6[2] = 'L';
	char6[3] = 'L';
	char6[4] = 'O';
	char6[5] = '\n';

	char6.Print1();
	//Print2(char6);
	return 0;
}