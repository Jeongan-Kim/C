#include <iostream>
// [] 배열 인덱스에 접근하는 연산자(?)
using namespace std;

class IntArray //배열 클래스
{
	int list[3];

public:
	//int Get(int index) { return list[index]; }
	//void Set(int index, int value) { list[index] = value; }

	//int* GetList() { return list; }


	int& operator[] (int index)
	{
		if (index < 0 || index >= 10)
		{
			cout << "Array index out of bound exception" << endl;
		}

		return list[index];
	}
};

int main()
{
	//int arr[3] = { 1, 2, 3 };
	//cout << arr[-1] << endl;
	//cout << arr[3] << endl; //경계 검사를 하지 않기 때문에 컴파일은 되지만 쓰레기 값이 나옴. 그래서 배열 클래스를 만들어서 사용하기도 함.

	IntArray list;
	//list.Set(0, 1);
	//list.Set(1, 2);
	//list.Set(2, 3);

	//cout << list.Get(0) << endl;
	//cout << list.Get(1) << endl;
	//cout << list.Get(2) << endl;
	//클래스 안의 함수 형태이므로 찍어볼때 매우 귀찮음


	//auto arr = list.GetList(); //이러면 배열의 크기가 얼마인지 모르기 때문에 연산자 오버로딩을 하는 것.

	//arr[0] = 1;
	//arr[1] = 2;
	//arr[2] = 3;


	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[3] << endl;
	cout << list[20] << endl; //오류 처리 완료.


	return 0;
}