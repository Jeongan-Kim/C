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

	shuffle(container.begin(), container.end(), mt);//mt�� �õ尪.(������ ��������)

	for (auto iter = container.begin(); iter != container.end(); iter++) //���� ���� �����൵ �� �ȿ��� ����.
		cout << *iter << " ";
	cout << endl;

	auto iter = min_element(container.begin(), container.end()); //�ּڰ��� ã�Ƽ� �ְ�.
	cout << *iter << endl; //���.

	iter = max_element(container.begin(), container.end()); //�ִ��� ã�Ƽ� �ְ�.
	cout << *iter << endl; //���.

	iter = find(container.begin(), container.end(), 7); //7��°�� ã�Ƽ� �ֱ�
	cout << *iter << endl;


	sort(container.begin(), container.end());//���� �˰���, �� ���� �ý���

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}