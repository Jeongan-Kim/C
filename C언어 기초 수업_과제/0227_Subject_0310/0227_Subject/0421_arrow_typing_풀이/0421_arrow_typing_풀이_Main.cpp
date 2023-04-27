#include "stdafx.h"

#define ARROWNUM 10
#define SUCCESS 5
#define TIMELIMIT 10

void Start();
void ReSet(); //ȭ�� ����
bool Update(); //Ű�ԷµǸ鼭 ������Ʈ �Ǵ� ȭ��
void Render(); //������ ȭ��

Stopwatch current_time;

enum class Arrow
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

Arrow answer[ARROWNUM];

int curSuccess = 0; //���� ����
int curArrow = 0;

int main()
{
	Start();
	ReSet();

	while (Update())
	{
		Render();
	}

	return 0;
}

void Start()
{
	system("title TypingGame");
	system("mode con:cols=60 lines =30"); //�ܼ�â�� ũ�� ����

	{
		//Ŀ�� �������� �����ִ� �ڵ�
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	cout << "########ȭ��ǥ Ÿ���� ����!!########" << endl;

	system("pause"); //Ű�� �Էµɶ����� �Ͻ� �����Ǵ� �ڵ�.
	system("cls");
}

void ReSet()
{
	current_time.Start();
	curArrow = 0;

	for (int i = 0; i < ARROWNUM; i++)
	{
		int arrow = Math::Random(0, 3);

		switch (arrow)
		{
		case 0:
		{
			answer[i] = Arrow::UP;
			break;
		}
		case 1:
		{
			answer[i] = Arrow::DOWN;
			break;
		}
		case 2:
		{
			answer[i] = Arrow::RIGHT;
			break;
		}
		case 3:
		{
			answer[i] = Arrow::LEFT;
			break;
		}
		default: break;
		}
	}
}

bool Update()
{
	if (_kbhit())
	{
		int key;

		key = _getch();

		if (key == 224)
		{
			key = _getch();
			if (answer[curArrow] == static_cast<Arrow>(key))
			{
				++curArrow;

				if (ARROWNUM <= curArrow) //ȭ��ǥ �� ���� ���
				{
					ReSet();
					++curSuccess;

					if (SUCCESS <= curSuccess)
					{
						cout << "�¸�!!" << endl;
						return false;
					}
				}
			}
			else
			{
				curArrow = 0;
			}
		}
	}

	if (TIMELIMIT <= current_time.GetElapsedTimeSec()) //���ѽð� �ʰ�
	{
		cout << "�й�!!" << endl;
		return false;
	}
	return true;
}

void Render()
{
	system("cls");

	cout << "TIME : ";

	for (int i = 0; i < TIMELIMIT; i++)
	{
		if (current_time.GetElapsedTimeSec() < i)
			cout << "��";
	}

	cout << endl;

	for (int i = 0; i < ARROWNUM; i++)
	{
		if (curArrow <= i)
		{
			switch (answer[i])
			{
			case Arrow::UP:
			{
				cout << "��";
				break;
			}
			case Arrow::DOWN:
			{
				cout << "��";
				break;
			}
			case Arrow::RIGHT:
			{
				cout << "��";
				break;
			}
			case Arrow::LEFT:
			{
				cout << "��";
				break;
			}
			}
		}
		else
		{
			cout << "��";
		}
	}
	cout << endl;

	cout << "���� Ƚ�� : " << SUCCESS = curSuccess << endl;
}
