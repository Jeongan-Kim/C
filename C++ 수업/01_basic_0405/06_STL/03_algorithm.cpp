#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>

using namespace std;

random_device rd;
mt19937_64 mt(rd());

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
		container.push_back(i);

	shuffle(container.begin(), container.end(), mt);//mt는 시드값.(위에서 설정해줌)

	for (auto iter = container.begin(); iter != container.end(); iter++) //선언 먼저 안해줘도 이 안에서 잡힘.
		cout << *iter << " ";
	cout << endl;

	auto iter = min_element(container.begin(), container.end()); //최솟값을 찾아서 넣고.
	cout << *iter << endl; //출력.

	iter = max_element(container.begin(), container.end()); //최댓값을 찾아서 넣고.
	cout << *iter << endl; //출력.

	iter = find(container.begin(), container.end(), 7); //7번째값 찾아서 넣기
	cout << *iter << endl;


	sort(container.begin(), container.end());//정렬 알고리즘, 퀵 정렬 시스템

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}