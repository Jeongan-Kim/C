#include "stdafx.h"

void SetUP();
bool Update();
void Render();
void Food();

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

enum Direction
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

struct Pos
{
	int x;
	int y;
};

constexpr int boardRowMax = 20;
constexpr int boardColMax = 30; //������ Ÿ�ӿ� �ʱ�ȭ �Ǿ� �ִ� �� �����ϹǷ� �ܽ�Ʈ expr ���̱�

constexpr float delaySec = 0.2f;

list<Pos> snake;
Direction snakeDir; //������ ����

Pos foodPos; //���� ��ġ
Stopwatch currentTime;

int main()
{
	system("pause");

	SetUP();

	while (Update())
	{
		Render();
	}
	return 0;
}

void SetUP()
{
	{
		//Ŀ�� �������� �����ִ� �ڵ�
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	//�� ����, ������ ����
	{
		Pos startPos = { boardColMax / 2, boardRowMax / 2 }; //���� ��ǥ
		snake.push_back(Pos{ startPos.x, startPos.y });
		snake.push_back(Pos{ startPos.x - 1, startPos.y });
		snake.push_back(Pos{ startPos.x - 2, startPos.y });

		snakeDir = RIGHT;//ó������ ���������� �˾Ƽ� �����̰� ����
	}

	Food();
}

bool Update()
{
	currentTime.Start();

	Pos next = snake.front();//���� ��ǥ : ������ �κ� �Ǿտ� �Ӹ��� �־���

	while (currentTime.GetElapsedTimeSec() < delaySec) // �Լ� ���� �ð��� ������ �ð����� ���� �� ����Ű�� �������� while���� ���ư�
	{
		if (_kbhit() == true)
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();

				switch (key)
				{
				case UP: snakeDir = UP; break;
				case LEFT: snakeDir = LEFT; break;
				case RIGHT: snakeDir = RIGHT; break;
				case DOWN: snakeDir = DOWN; break;
				}
			}
		}
	}

	switch (snakeDir)
	{
	case UP: next.y--; break;
	case LEFT: next.x--; break;
	case RIGHT: next.x++; break;
	case DOWN: next.y++; break;
	}

	//���� ����
	{
		if (next.x <= 0 || next.x > boardColMax - 2) return false;
		if (next.y <= 0 || next.y > boardRowMax - 2) return false;

		for (const auto& body : snake) //�� ��ü�� üũ�ؼ� �Ӹ��� ���� ��Ҵ��� Ȯ��
		{
			if (next.x == body.x && next.y == body.y) return false;
		}

		if (foodPos.x == next.x && foodPos.y == next.y)
		{
			snake.push_back(snake.back());
			Food();
		}
	}

	//������ ���� ���� �߰��ϰ� �ڴ� �����Ǿ�� ��
	snake.push_front(next);
	snake.pop_back();

	return true;
}

void Render()
{
	system("cls");

	{
		//�� �׸���
		for (int row = 0; row < boardRowMax; row++)
		{
			gotoxy(0, row);
			cout << "��";
			gotoxy(boardColMax - 1, row);
			cout << "��";
		}

		for (int col = 0; col < boardColMax; col++)
		{
			gotoxy(col, 0);
			cout << "��";
			gotoxy(col, boardRowMax - 1);
			cout << "��";
		}
	}
		//������ ��ġ
		{
			for (auto iter = snake.begin(); iter != snake.end(); iter++) //iter�� ������ ���� ��
			{
				gotoxy(iter->x, iter->y);

				if (iter == snake.begin())
					cout << "��";
				else
					cout << "��";
			}
		}

		{
			//����
			static int score = 0;
			score += 100;

			gotoxy(foodPos.x, foodPos.y);
			cout << "��";

			gotoxy(0, boardRowMax);
			cout << "Score : " << score << endl;
		}
}

void Food()
{
	foodPos.x = Math::Random(1, boardColMax - 2);
	foodPos.y = Math::Random(1, boardColMax - 2);

	for (auto iter = snake.begin(); iter != snake.end(); iter++)
	{
		if (foodPos.x == iter->x && foodPos.y == iter->y)
		{
			iter = snake.begin();
			foodPos.x = Math::Random(1, boardColMax - 2);
			foodPos.y = Math::Random(1, boardColMax - 2);
		}
	}
}
