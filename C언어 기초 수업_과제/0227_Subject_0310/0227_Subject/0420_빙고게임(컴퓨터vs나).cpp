#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define X 5
#define Y 5

using namespace std;

void Swap(int x1, int y1, int x2, int y2, int arr[X][Y])
{
	int temp = arr[x1][y1];
	arr[x1][y1] = arr[x2][y2];
	arr[x2][y2] = temp;
}

void shuffle(int n, int arr[X][Y])
{
	for (int i = 0; i < n; i++)
	{
		int x1 = rand() % X;
		int y1 = rand() % X;
		int x2 = rand() % X;
		int y2 = rand() % X;

		Swap(x1, y1, x2, y2, arr);
	}
}


class Player
{
public:
	string name;
	int myBingo[X][Y];

	void setData(string myname)
	{
		name = myname;
	}

	void setBingo()
	{
		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				myBingo[x][y] = x * 5 + y + 1;
			}
		}

		shuffle(1000, myBingo);
	}

	void selectNum(int mySelect)
	{
		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				if (myBingo[x][y] == mySelect)
				{
					//cout << "�÷��̾" << myBingo[x][y] << "�� ����ϴ�." << endl;
					myBingo[x][y] = 0;
					
				}
			}
		}
	}

	void Erase(int comSelect)
	{
		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				if (myBingo[x][y] == comSelect)
				{
					//cout << "�÷��̾" << myBingo[x][y] << "�� ����ϴ�." << endl;
					myBingo[x][y] = 0;
				}
			}
		}
	}
};


class Computer
{
public:
	string name = "��ǻ��";
	int comBingo[X][Y];
	int comSelect;

	void setBingo()
	{
		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				comBingo[x][y] = x * 5 + y + 1;
			}
		}

		shuffle(1000, comBingo);
	}

	void selectNum()
	{		
		while (1)
		{
			int comSelect1 = rand() % X;
			int comSelect2 = rand() % X;

			if (comBingo[comSelect1][comSelect2] != 0)
			{
				comSelect = comBingo[comSelect1][comSelect2];			
				//cout << "��ǻ�Ͱ�" << comSelect << "�� ����ϴ�." << endl;
				comBingo[comSelect1][comSelect2] = 0;
				break;
			}		
		}
		cout << endl << name << "�� ���� " << comSelect << "(��)�� �����߽��ϴ�." << endl;
	}

	void Erase(int mySelect)
	{
		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				if (comBingo[x][y] == mySelect)
				{
					//cout << "��ǻ�Ͱ�" << comBingo[x][y] << "�� ����ϴ�." << endl;
					comBingo[x][y] = 0;
				}
			}
		}
	}
};


int BingoCount(int arr[X][Y])
{
	int bingoCount = 0;
	for (int y = 0; y < Y; y++)
	{
		int Xcount = 0;
		for (int x = 0; x < X; x++)
		{
			if (arr[x][y] == 0)
				Xcount++;
		}

		if (Xcount == X)
			bingoCount++;
	}

	for (int x = 0; x < X; x++)
	{
		int Ycount = 0;
		for (int y = 0; y < Y; y++)
		{
			if (arr[x][y] == 0)
				Ycount++;
		}

		if (Ycount == Y)
			bingoCount++;
	}

	int ACount = 0, BCount = 0;//A�� \ �밢��, B�� / �밢��

	for (int i = 0; i < X; i++)
	{
		if (arr[i][i] == 0)
			ACount++;
		if (arr[i][(X - 1) - i] == 0)
			BCount++;
	}
	if (ACount == 5)
		bingoCount++;
	if (BCount == 5)
		bingoCount++;

	return bingoCount;
}


int CheckWin(Player player, Computer computer, int myBingo[X][Y], int comBingo[X][Y])
{
	if (BingoCount(myBingo) == 3 && BingoCount(comBingo) != 3)
	{
		cout << player.name << "(��)�� �¸��߽��ϴ�." << endl;
		return 0;
	}
	else if (BingoCount(myBingo) != 3 && BingoCount(comBingo) == 3)
	{
		cout << computer.name << "(��)�� �¸��߽��ϴ�." << endl;
		return 0;
	}
	else if (BingoCount(myBingo) == 3 && BingoCount(comBingo) == 3)
	{
		cout << computer.name << "(��)��" << computer.name << "(��)�� ���ÿ� 3 ���� �޼��߽��ϴ�.\n���º�!" << endl;
		return 0;
	}
	else
		return 1;
}

void bingoPrint(int arr[X][Y])
{
	for (int x = 0; x < X; x++)
	{
		for (int y = 0; y < Y; y++)
		{
			if (arr[x][y] == 0)
				cout << "X" << "\t";
			else
				cout << arr[x][y] << "\t";
		}
		cout << endl;
	}
}




int main()
{
	srand((unsigned int)time(NULL));
	cout << "���� ������ �����մϴ�." << endl << endl;;

	string myname;
	cout << "�÷��̾��� �̸��� �Է��ϼ��� : ";
	cin >> myname;
	cout << endl;

	Player player;
	Computer computer;

	player.setData(myname);
	player.setBingo();
	computer.setBingo();
	
	cout << player.name << "�� ���� �� : " << BingoCount(player.myBingo) << endl;
	bingoPrint(player.myBingo);
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << computer.name << "�� ���� �� : " << BingoCount(computer.comBingo) << endl;
	bingoPrint(computer.comBingo);

	int checkWin = 1;

	while (1)
	{	
		int mySelect;
		cout << endl << player.name << "(��)�� ������ ���ڸ� �Է��ϼ���. => ";
		cin >> mySelect;
		cout << endl;

		player.selectNum(mySelect);
		computer.Erase(mySelect);

		Sleep(1000);
		system("cls");

		{
			cout << player.name << "�� ���� �� : " << BingoCount(player.myBingo) << endl;
			bingoPrint(player.myBingo);
			cout << "--------------------------------------------------" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << computer.name << "�� ���� �� : " << BingoCount(computer.comBingo) << endl;
			bingoPrint(computer.comBingo);
		}
		checkWin = CheckWin(player, computer, player.myBingo, computer.comBingo);
		if (checkWin == 0)
			break;

		Sleep(1000);

		computer.selectNum();
		player.Erase(computer.comSelect);

		Sleep(2000);
		system("cls");

		{
			cout << player.name <<"�� ���� �� : " << BingoCount(player.myBingo) << endl;
			bingoPrint(player.myBingo);
			cout << "--------------------------------------------------" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << computer.name << "�� ���� �� : " << BingoCount(computer.comBingo) << endl;
			bingoPrint(computer.comBingo);
		}


		checkWin = CheckWin(player, computer, player.myBingo, computer.comBingo);
		if (checkWin == 0)
			break;
	}

	return 0;
}