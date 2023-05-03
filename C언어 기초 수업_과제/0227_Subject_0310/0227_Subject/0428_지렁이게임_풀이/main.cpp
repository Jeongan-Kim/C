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
constexpr int boardColMax = 30; //컴파일 타임에 초기화 되어 있는 게 안전하므로 콘스트 expr 붙이기

constexpr float delaySec = 0.2f;

list<Pos> snake;
Direction snakeDir; //움직일 방향

Pos foodPos; //먹이 위치
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
		//커서 깜빡임을 없애주는 코드
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	//맵 세팅, 지렁이 세팅
	{
		Pos startPos = { boardColMax / 2, boardRowMax / 2 }; //시작 좌표
		snake.push_back(Pos{ startPos.x, startPos.y });
		snake.push_back(Pos{ startPos.x - 1, startPos.y });
		snake.push_back(Pos{ startPos.x - 2, startPos.y });

		snakeDir = RIGHT;//처음에는 오른쪽으로 알아서 움직이게 설정
	}

	Food();
}

bool Update()
{
	currentTime.Start();

	Pos next = snake.front();//다음 좌표 : 움직인 부분 맨앞에 머리를 넣어줌

	while (currentTime.GetElapsedTimeSec() < delaySec) // 함수 실행 시간이 딜레이 시간보다 작을 때 방향키를 눌렀으면 while문이 돌아감
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

	//종료 조건
	{
		if (next.x <= 0 || next.x > boardColMax - 2) return false;
		if (next.y <= 0 || next.y > boardRowMax - 2) return false;

		for (const auto& body : snake) //몸 전체를 체크해서 머리가 몸에 닿았는지 확인
		{
			if (next.x == body.x && next.y == body.y) return false;
		}

		if (foodPos.x == next.x && foodPos.y == next.y)
		{
			snake.push_back(snake.back());
			Food();
		}
	}

	//앞으로 가면 앞은 추가하고 뒤는 삭제되어야 함
	snake.push_front(next);
	snake.pop_back();

	return true;
}

void Render()
{
	system("cls");

	{
		//벽 그리기
		for (int row = 0; row < boardRowMax; row++)
		{
			gotoxy(0, row);
			cout << "※";
			gotoxy(boardColMax - 1, row);
			cout << "※";
		}

		for (int col = 0; col < boardColMax; col++)
		{
			gotoxy(col, 0);
			cout << "※";
			gotoxy(col, boardRowMax - 1);
			cout << "※";
		}
	}
		//지렁이 위치
		{
			for (auto iter = snake.begin(); iter != snake.end(); iter++) //iter도 포인터 같은 애
			{
				gotoxy(iter->x, iter->y);

				if (iter == snake.begin())
					cout << "★";
				else
					cout << "☆";
			}
		}

		{
			//점수
			static int score = 0;
			score += 100;

			gotoxy(foodPos.x, foodPos.y);
			cout << "＠";

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
