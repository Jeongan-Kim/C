#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

//���ҿ� �����ϴ� �����Ͱ��� ��.

using namespace std;

int main()
{
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		vector<int>::iterator iter;//iterator ����
		iter = container.begin(); //�� ���� ����Ű�� ����

		while (iter != container.end()) //������ �ϳ��� ����
		{
			cout << *iter << " "; //�����ʹϱ� �������� ���� ���
			++iter;
		}
		cout << endl;

		for (vector<int>::iterator iter = container.begin(); iter != container.end(); iter++) //�������� ����
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

		//�ܾ���� ������ ���÷� ���
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