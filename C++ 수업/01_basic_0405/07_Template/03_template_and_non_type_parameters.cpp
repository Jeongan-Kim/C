#include <iostream>
#include <array>
//자료형이 아닌 템플릿?
//여러 자료형의 배열을 만들때, 다 써주지 않고 템플릿으로 다 다룰 수 있다.
using namespace std;

template<typename T, unsigned int SIZE> //템플릿 매개 변수가 다름 <어떤 타입이든 가능, 몇개를 넣을지>
class MyArray
{
public:
	MyArray() = default;
	~MyArray() {}

	T& operator[](int index)
	{
		return arr2[index];
	}

private:
	T arr1[10]; //정적할당과 비슷함
	T arr2[SIZE]; //컴파일 타임에 값이 들어가기에 문제는 없음
};

int main()
{
	MyArray<int, 10> arr1;//int형 10개인 배열
	MyArray<float, 20u> arr2; //u는 unsigned int라는 의미

	for (int i = 0; i < 10; i++)
		arr1[i] = i;

	for (int i = 0; i < 20; i++)
		arr2[i] = i;

	for (int i = 0; i < 20; i++)
		cout << arr2[i] << ' ';


	array<int, 10> arr3; //array헤더를 추가해서 만드는 것과 비슷함.

	for (int i = 0; i < 10; i++)
		arr3[i] = i;

	for (int i = 0; i < 10; i++)
		cout << arr3[i] << ' ';

	return 0;
}