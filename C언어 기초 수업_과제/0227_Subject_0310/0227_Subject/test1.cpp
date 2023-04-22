#include <iostream>
#include <random>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using namespace std;

void gameRulePrint()
{
	cout << "******** ȭ��ǥ Ÿ���� ���� ********" << endl
		<< "1. ȭ�鿡 ��µ� ȭ��ǥ�� ���� �ð� �ȿ� ������� �Է��ϼ���." << endl
		<< "2. Ʋ���� ó������ �ٽ� �Է��ϼ���." << endl
		<< "3. ����� ��� �����ϱ� ���� �ְ� ������ �޼��� ������." << endl << endl
		<< "-----�ƹ� Ű�� ������ ������ ���۵˴ϴ�.-----" << endl;

	while (1)
	{
		if (_kbhit()) //Ű �Է� �� ȭ�� �ʱ�ȭ.
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
				cout << "��  ";
			else if (i >= inputNum)
			{
				if (arrow[i] == 0)
					cout << "��  ";
				else if (arrow[i] == 1)
					cout << "��  ";
				else if (arrow[i] == 2)
					cout << "��  ";
				else if (arrow[i] == 3)
					cout << "��  ";
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
			if (_kbhit()) //Ű�� �ԷµǸ� ȭ��ǥ Ȯ��
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
			arrowgame.arrowCheck(player.inputNum, player.inputValue2); //ȭ��ǥ �Է�(������ ���� �ٲ�)

		}
	}

	return 0;
}