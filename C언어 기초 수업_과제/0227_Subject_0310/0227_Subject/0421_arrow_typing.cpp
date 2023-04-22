#include <iostream>
#include <random>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <chrono>

/*
1. ���� �� ����
2. ���� ����
	-���� �ð�(ȭ��ǥ Ÿ���ΰ� ���þ��� �帧) : 10��
	-ȭ��ǥ ���� ����
	-ȭ��ǥ �Է�(�տ������� ���ʴ��)
	-ȭ��ǥ ��ġ�ϸ� �� ������� ����
	-���� Ƚ���� ���� ��� ( ���� -> ���� �� +1000�� )
3. ��� ������ ������ ���� ���
4. ���� Ƚ�� ��� ���� �� ���� ����
	-���� ���
*/

using namespace std;

void gameRulePrint() //���� �� ���, ���� ���� üũ
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
	int score = 0; //���� ���� : �� ���� ������ ������ 1000�� ȹ��
	int lifeCount = 5; //���� ��� 5�� ����

public:
	void timeStream(int gameTime) //"����������������" ó�� ���� �ð� ���
	{
		cout << "���� �ð� : ";
		for (int i = gameTime; i < 15; i++)
		{
			cout << "��";
		}
		cout << endl;
	}

	void arrowCheck(int& inputNum, int& inputValue) //�÷��̾ �Է��� ���� �������� üũ
	{
		if (arrow[inputNum] == inputValue)
			inputNum++;
		else
		{
			inputNum = 0;
			lifeCount--;
		}
	}

	void arrowSet() //�����ϰ� ȭ��ǥ �迭 ����
	{
		for (int i = 0; i < 10; i++)
		{
			arrow[i] = randNUM(messenne);
		}
	}

	void arrowPrint(int inputNum) //ȭ��ǥ �迭 ��� ( �÷��̾ ���� ȭ��ǥ��ŭ�� ���� ��� )
	{
		for (int i = 0; i < 10; i++)
		{
			if(i < inputNum)
				cout << "��  ";
			else if (i >= inputNum)
			{
				if(arrow[i] == 0)
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

	void ScoreNLife(int mistake, int success) //���� ����� ���� ���
	{
		score = success * 1000;
		lifeCount -= mistake;
		cout << "���� ��� : " << lifeCount << ", ���� ���� : " << score << endl;
	}

	int gameOver(int gameTime) //���� ���� üũ : �ð� ����, ��� ��� ����
	{
		if (gameTime >= 15)
		{
			cout << "���� �ð� �ȿ� �������� ���߽��ϴ�." << endl << "-----------GAME OVER------------" << endl;
			return 0;
		}
		else if (lifeCount == 0)
		{
			cout << "���� ����� �����ϴ�." << endl << "-----------GAME OVER------------" << endl;
			return 0;
		}
	}

	int gameSuccess(int& inputNum, int& success) // �� ���� ���� üũ
	{
		if (inputNum == 10)
		{
			inputNum = 0;
			success++;
			return 0;
		}
	}

};

class Player
{

public:
	int mistake = 0; //���� Ƚ��
	int success = 0; //���� ���� ��
	int inputValue = -1; //�Էµ� ȭ��ǥ�� ���� ����
	int inputNum = 0; //�� ������ Ǫ�� ���� ���� ȭ��ǥ ��

	void InputValue() //�÷��̾ �Է��� ���� ������ �����ϱ� ���� �Լ�.
	{
		switch (inputValue)
		{
		case 72:
			inputValue = 0;
			break;
		case 80:
			inputValue = 1;
			break;
		case 75:
			inputValue = 2;
			break;
		case 77:
			inputValue = 3;
			break;
		}
	}
};

int main()
{
	int gameTime = 0; //���� �ð�
	gameRulePrint();

	arrowGame arrowgame;
	Player player;

	while (1)
	{
		auto start = chrono::steady_clock::now(); //���ο� ������ ���۵Ǵ� �������� �ð� ���.
		int gameTime = 0;

		arrowgame.arrowSet();

		while (1)
		{			
			system("cls");

			arrowgame.timeStream(gameTime); //�ð� ���
			arrowgame.arrowPrint(player.inputNum); //ȭ��ǥ ���
			arrowgame.ScoreNLife(player.mistake, player.success); //���, ���� ���

			
			if (arrowgame.gameOver(gameTime) == 0) //���� ���� üũ
				return 0;

			if (arrowgame.gameSuccess(player.inputNum, player.success) == 0) //���� üũ
				break;
			


			if (_kbhit()) //Ű�� �ԷµǸ� ȭ��ǥ Ȯ��
			{
				int temp = _getch();

				if (temp != 224)
					continue;

				player.inputValue = _getch();
				player.InputValue();
				arrowgame.arrowCheck(player.inputNum, player.inputValue); //ȭ��ǥ �Է�(������ ���� �ٲ�)
			}


			Sleep(10); 

			auto end = chrono::steady_clock::now(); //�� �������� ���� �ð�
			gameTime = chrono::duration_cast<chrono::seconds>(end - start).count(); //����� �ð� ��
		}	
	}

	return 0;
}