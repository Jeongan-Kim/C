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
					//cout << "플레이어가" << myBingo[x][y] << "를 지웁니다." << endl;
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
					//cout << "플레이어가" << myBingo[x][y] << "를 지웁니다." << endl;
					myBingo[x][y] = 0;
				}
			}
		}
	}
};


class Computer
{
public:
	string name = "컴퓨터";
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
				//cout << "컴퓨터가" << comSelect << "를 지웁니다." << endl;
				comBingo[comSelect1][comSelect2] = 0;
				break;
			}		
		}
		cout << endl << name << "가 숫자 " << comSelect << "(을)를 선택했습니다." << endl;
	}

	void Erase(int mySelect)
	{
		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				if (comBingo[x][y] == mySelect)
				{
					//cout << "컴퓨터가" << comBingo[x][y] << "를 지웁니다." << endl;
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

	int ACount = 0, BCount = 0;//A는 \ 대각선, B는 / 대각선

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
		cout << player.name << "(이)가 승리했습니다." << endl;
		return 0;
	}
	else if (BingoCount(myBingo) != 3 && BingoCount(comBingo) == 3)
	{
		cout << computer.name << "(이)가 승리했습니다." << endl;
		return 0;
	}
	else if (BingoCount(myBingo) == 3 && BingoCount(comBingo) == 3)
	{
		cout << computer.name << "(와)과" << computer.name << "(이)가 동시에 3 빙고를 달성했습니다.\n무승부!" << endl;
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
	cout << "빙고 게임을 시작합니다." << endl << endl;;

	string myname;
	cout << "플레이어의 이름을 입력하세요 : ";
	cin >> myname;
	cout << endl;

	Player player;
	Computer computer;

	player.setData(myname);
	player.setBingo();
	computer.setBingo();
	
	cout << player.name << "의 빙고 수 : " << BingoCount(player.myBingo) << endl;
	bingoPrint(player.myBingo);
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << computer.name << "의 빙고 수 : " << BingoCount(computer.comBingo) << endl;
	bingoPrint(computer.comBingo);

	int checkWin = 1;

	while (1)
	{	
		int mySelect;
		cout << endl << player.name << "(이)가 선택할 숫자를 입력하세요. => ";
		cin >> mySelect;
		cout << endl;

		player.selectNum(mySelect);
		computer.Erase(mySelect);

		Sleep(1000);
		system("cls");

		{
			cout << player.name << "의 빙고 수 : " << BingoCount(player.myBingo) << endl;
			bingoPrint(player.myBingo);
			cout << "--------------------------------------------------" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << computer.name << "의 빙고 수 : " << BingoCount(computer.comBingo) << endl;
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
			cout << player.name <<"의 빙고 수 : " << BingoCount(player.myBingo) << endl;
			bingoPrint(player.myBingo);
			cout << "--------------------------------------------------" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << computer.name << "의 빙고 수 : " << BingoCount(computer.comBingo) << endl;
			bingoPrint(computer.comBingo);
		}


		checkWin = CheckWin(player, computer, player.myBingo, computer.comBingo);
		if (checkWin == 0)
			break;
	}

	return 0;
}