#include <iostream>
#include <list>

using namespace std;
//list
//삽입, 삭제가 빈번하게 이루어질때, 원소들을 순차적으로 접근할때 사용하기 좋음
/*
list는 맨앞과 맨 뒤만 기억하고 있고,
사이사이 원소들은 서로서로 앞뒤를 알고 있음.
임의의 위치 원소에 바로 접근은 힘들지만 순차적으로 접근해야 함.
*/
int main()
{
	list<int> list;

	for (int i = 0; i < 10; i++)
		list.push_back(i); //원소 삽입

	//임의의 원소를 찍으려면
	//범위 기반 for문사용
	for (const auto& ele : list)
		cout << ele << " ";

	cout << endl;

	return 0;
}