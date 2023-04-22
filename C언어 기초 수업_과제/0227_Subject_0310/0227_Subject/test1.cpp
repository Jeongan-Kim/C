#include <iostream>
#include <random>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using namespace std;

void gameRulePrint()
{
	cout << "******** 화살표 타이핑 게임 ********" << endl
		<< "1. 화면에 출력된 화살표를 제한 시간 안에 순서대로 입력하세요." << endl
		<< "2. 틀리면 처음부터 다시 입력하세요." << endl
		<< "3. 목숨을 모두 소진하기 전에 최고 점수를 달성해 보세요." << endl << endl
		<< "-----아무 키나 누르면 게임이 시작됩니다.-----" << endl;

	while (1)
	{
		if (_kbhit()) //키 입력 시 화면 초기화.
		{
			system("cls");
			break;
		}
	}
}

random_device rd;
mt19937 messenne(rd());
uniform_int_distribution<> randNUM(0, 3);

class arrowGame
{
	int arrow[10]{ 0 };


public:

	void arrowCheck(int inputNum, int inputValue2)
	{
		if (arrow[inputNum] == inputValue2)
			inputNum++;
		else
			inputNum = 0;

		cout << inputNum << endl;
	}

	void arrowSet()
	{
		for (int i = 0; i < 10; i++)
		{
			arrow[i] = randNUM(messenne);
		}
	}

	void arrowPrint(int inputNum)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i < inputNum)
				cout << "☆  ";
			else if (i >= inputNum)
			{
				if (arrow[i] == 0)
					cout << "↑  ";
				else if (arrow[i] == 1)
					cout << "↓  ";
				else if (arrow[i] == 2)
					cout << "←  ";
				else if (arrow[i] == 3)
					cout << "→  ";
			}
		}
		cout << endl;
	}
};

class Player
{

public:
	int mistake = 0;
	int success = 0;
	int inputValue1 = 0;
	int inputValue2 = 0;
	int inputNum = 0;

	void InputValue()
	{
		switch (inputValue2)
		{
		case 72:
			inputValue2 = 0;
			break;
		case 80:
			inputValue2 = 1;
			break;
		case 75:
			inputValue2 = 2;
			break;
		case 77:
			inputValue2 = 3;
			break;
		}

	}




};

int main()
{
	gameRulePrint();
	arrowGame arrowgame;
	Player player;

	while (1)
	{
		arrowgame.arrowSet();
		while (1)
		{
			if (_kbhit()) //키가 입력되면 화살표 확인
			{
				player.inputValue1 = _getch();

				if (player.inputValue1 != 224)
				{
					player.inputValue1 = 0;
					continue;
				}
				player.inputValue2 = _getch();

				player.InputValue();

			}
			arrowgame.arrowCheck(player.inputNum, player.inputValue2); //화살표 입력(맞으면 별로 바뀜)

		}
	}

	return 0;
}