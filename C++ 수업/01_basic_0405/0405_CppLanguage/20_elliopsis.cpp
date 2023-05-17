#include <iostream>
#include <cstdarg>

using namespace std;

//가변함수
//매개변수로 들어오는 것들의 평균을 구해주는 함수를 만들어보자
double findAverage(int count, ...) //몇개가 들어올지 모르니까 ... 으로 씀
{
	double sum = 0;

	va_list lists;

	va_start(lists, count);

	for (int arg = 0; arg < count; arg++)
	{
		sum += va_arg(lists, int);
	}

	va_end(lists);//동적할당 해제해 주듯이 해제해 주는 것.

	return sum / count;
}

int main()
{
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(3, 1, 2, 3, 4, 5) << endl; // 5개를 넣어도 카운트 값에 맞는 개수만큼만 평균 계산에 들어감.

	return 0;
}

/*
절차 지향 : C언어
객체 지향

*/