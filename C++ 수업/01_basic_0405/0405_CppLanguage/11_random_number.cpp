#include <iostream>
#include <random>

#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	//C스타일 난수 생성 방식
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10);
	}

	cout << endl; //한줄 띄우기

	//C++스타일 난수 생성 방식
	random_device rd; //난수 생성할 시드값(컴퓨터가 마주하는 모든 경우의 랜덤한 상황

	mt19937 messenne(rd());

	uniform_int_distribution<> randNUM(1, 10);// 동일한 확률로 난수가 생성되게 하는 작업(분포도) : 동일한 확률로 1부터 10까지 나오게 함.

	for (int i = 0; i < 10; i++)
		cout << randNUM(messenne) << " ";

	cout << endl;

	return 0;
}

