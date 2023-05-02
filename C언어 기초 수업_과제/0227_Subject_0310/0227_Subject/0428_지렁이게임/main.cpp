#include "stdafx.h"

/*
	지렁이 게임 : 먹이 먹으면 꼬리가 하나 늘어나고
	내 꼬리에 부딪히거나 벽에 부딪히면 게임 오버.
	(지렁이를 나타낼때 배열보다 list를 활용해 주는 게 더 좋음)
*/
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define X 19 //맵 가로 길이
#define Y 19 //맵 세로 길이

void Start();
void ReSet(); //화면 세팅
bool Update(); //키입력되면서 업데이트 되는 화면
void Render(); //랜더링 화면

struct WormPosition
{
	int x;
	int y;

	WormPosition(int i, int j)
	{
		x = i;
		y = j;
	}
};

list<WormPosition> wormPosition; //지렁이 위치 list

int map[X][Y] = { 0 };
int curScore = 0;
int starNum = 0; //별 개수 체크(먹어야 생성되게끔)

void PrintMap(int map[X][Y]);
bool move(int key2);

int main()
{
	Start();
	ReSet();
	while (Update())
	{
		Sleep(100);
		Render();
	}
	return 0;
}

void Start()
{
	system("title WormGame");
	system("mode con cols=60 lines=30"); //콘솔창의 크기 조정

	{
		//커서 깜빡임을 없애주는 코드
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	cout << "######## 지렁이 게임 ########" << endl;

	cout << "1. 랜덤하게 나타는 별을 모아 점수를 얻으세요." << endl;
	cout << "2. 벽 또는 꼬리에 부딪히면 게임 오버입니다." << endl;

	system("pause"); //키가 입력될때까지 일시 정지되는 코드.
	system("cls");
}



void ReSet()
{
	curScore = 0;


	for (int i = X / 2 + 1; i < X / 2 + 4; i++) //지렁이 길이 3으로 시작. 
	{
		wormPosition.push_back(WormPosition(i, Y / 2 + 1));
	}


	for (int x = 0; x < X; x++)
	{
		for (int y = 0; y < Y; y++)
		{
			if (x == 0 || x == X - 1)
				map[x][y] = 1; //벽
			else if (y == 0 || y == Y - 1)
				map[x][y] = 1;
			else
				map[x][y] = 0;
		}
	}

	for (const auto& ele : wormPosition)
	{
		map[ele.x][ele.y] = 3; //지렁이 몸
	}
	map[X / 2 + 1][Y / 2 + 1] = 2; //지렁이 머리
}

int key2 = 0;

bool Update()
{
	if (_kbhit())
	{
		int key1;
		key1 = _getch();

		if (key1 == 224)
		{
			key2 = _getch();
			if (move(key2) == false)
			{
				return false;
			}
		}
	}
	else if (key2 != 0)
	{
		if (move(key2) == false)
		{
			return false;
		}
	}

	while (starNum == 0)
	{
		int star[2]; //랜덤하게 별 생성
		star[0] = Math::Random(1, X - 2);
		star[1] = Math::Random(1, Y - 2);
		if (map[star[0]][star[1]] == 0)// 지렁이와 겹치지 않게 생성
		{
			map[star[0]][star[1]] = 4;
			starNum = 1;
			break;
		}
	}

	return true;
}

void Render()
{
	system("cls");

	cout << "점수 : " << curScore << endl;

	PrintMap(map);
}

void PrintMap(int map[X][Y])
{
	for (int x = 0; x < X; x++)
	{
		for (int y = 0; y < Y; y++)
		{
			if (map[x][y] == 0)
				cout << "  ";
			if (map[x][y] == 1)
				cout << "▦";
			if (map[x][y] == 2)
				cout << "＠";
			if (map[x][y] == 3)
				cout << "●";
			if (map[x][y] == 4)
				cout << "☆";
		}
		cout << endl;
	}
}

bool move(int key2)
{
	int temp1 = wormPosition.front().x;
	int temp2 = wormPosition.front().y;
	map[temp1][temp2] = 3;
	switch (key2)
	{
	case UP:
		temp1--;
		break;
	case DOWN:
		temp1++;
		break;
	case LEFT:
		temp2--;
		break;
	case RIGHT:
		temp2++;
		break;
	default:
		break;
	}
	wormPosition.push_front(WormPosition(temp1, temp2));
	if (map[temp1][temp2] == 4)
	{
		map[temp1][temp2] = 2;
		starNum = 0;
		curScore += 100;
		return true;
	}
	else if (map[temp1][temp2] == 1)
	{
		cout << "벽에 부딪혔습니다. 패배!" << endl;
		return false;
	}
	else if (map[temp1][temp2] == 3)
	{
		cout << "몸에 부딪혔습니다. 패배!" << endl;
		return false;
	}
	else
	{
		map[temp1][temp2] = 2;
		map[wormPosition.back().x][wormPosition.back().y] = 0;
		wormPosition.pop_back();
		return true;
	}

}