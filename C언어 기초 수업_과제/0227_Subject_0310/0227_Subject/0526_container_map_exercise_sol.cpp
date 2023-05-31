#include <iostream>
#include <map>
#include <string>
//word game
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	string word;
	string answer;

	map<string, int> m1;
	map<int, string> m2;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> word;

		m1.insert(make_pair(word, i));
		m2.insert(make_pair(i, word));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> answer;

		if (m1.find(answer) != m1.end())
		{
			cout << m1.find(answer)->second << endl;
		}
		else if (m2.find(stoi(answer)) != m2.end())
		{
			cout << m2.find(stoi(answer))->second << endl;
		}
	}
	return 0;
}