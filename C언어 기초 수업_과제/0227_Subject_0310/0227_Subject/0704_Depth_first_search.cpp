/*
	4 5

	0 0 1 1 0
	0 1 0 1 1
	1 0 1 0 1
	0 0 1 1 0

	1로 둘러싸인 0범위가 1개라고 쳣을 때,
	위 맵은 6이 출력되도록 만들기.
*/

#include <iostream>

using namespace std;



class Map
{
public:
	void MakeMap()
	{
		for (int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 5; j++)
				cin >> this->maparr[i][j];
		}
	}

	void PrintMap()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
				cout << this->maparr[i][j] << " ";
			cout << endl;
		}
	}

	int DFS(int i, int j)
	{
		if (i < 0 || i >= 4 || j < 0 || j >= 5)
			return 0;

		this->maparr[i][j] = 1;

		if (maparr[i + 1][j] == 0) //하
			DFS(i + 1, j);
		if (maparr[i][j + 1] == 0) //우
			DFS(i, j + 1);
		if (maparr[i][j - 1] == 0) //좌
			DFS(i, j - 1);

		return 1;
	}

	void NumOfZeroRange()
	{
		int count1 = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (this->maparr[i][j] == 0)
				{
					count1 += DFS(i, j);
				}
			}
		}
		this->count = count1;
	}

	void PrintCount()
	{
		cout << this->count << endl;
	}
private:
	int maparr[4][5] = { 0 }; 
	int count = 0; //1로 둘러싸인 0의 범위 개수
};

int main()
{
	Map map;
	map.MakeMap();
	map.PrintMap();
	map.NumOfZeroRange();

	map.PrintCount();

	return 0;
}