#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

//원소에 접근하는 포인터같은 것.

using namespace std;

int main()
{
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		vector<int>::iterator iter;//iterator 선언
		iter = container.begin(); //맨 앞을 가리키게 선언

		while (iter != container.end()) //끝까지 하나씩 접근
		{
			cout << *iter << " "; //포인터니까 역참조를 통해 출력
			++iter;
		}
		cout << endl;

		for (vector<int>::iterator iter = container.begin(); iter != container.end(); iter++) //정석으로 쓰면
			cout << *iter << " ";
		cout << endl;

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl << endl;
	}

	{
		list<int> container;

		for (int i = 0; i < 10; i++)
			container.push_back(i);

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl << endl;
	}

	{
		set<int> container;
		for (int i = 0; i < 10; i++)
			container.insert(i);

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl << endl;
	}

	{
		map<int, char> container;
		for (int i = 0; i < 10; i++)
			container.insert(make_pair(i, i + 32));

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << iter->first << " : " << iter->second << " ";
		cout << endl << endl;

		//단어게임 과제를 예시로 들면
		int answer;
		for (auto iter = container.begin(); iter != container.end(); iter++)
		{
			cin >> answer;

			if (container.find(answer) != container.end())
				cout << container.find(answer)->first << " " << container.find(answer)->second;
			else
				break;
		}
	}
	return 0;
}