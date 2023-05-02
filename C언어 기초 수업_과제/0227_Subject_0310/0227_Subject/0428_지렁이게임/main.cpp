#include "stdafx.h"

/*
	������ ���� : ���� ������ ������ �ϳ� �þ��
	�� ������ �ε����ų� ���� �ε����� ���� ����.
	(�����̸� ��Ÿ���� �迭���� list�� Ȱ���� �ִ� �� �� ����)
*/
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define X 19 //�� ���� ����
#define Y 19 //�� ���� ����

void Start();
void ReSet(); //ȭ�� ����
bool Update(); //Ű�ԷµǸ鼭 ������Ʈ �Ǵ� ȭ��
void Render(); //������ ȭ��

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

list<WormPosition> wormPosition; //������ ��ġ list

int map[X][Y] = { 0 };
int curScore = 0;
int starNum = 0; //�� ���� üũ(�Ծ�� �����ǰԲ�)

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
	system("mode con cols=60 lines=30"); //�ܼ�â�� ũ�� ����

	{
		//Ŀ�� �������� �����ִ� �ڵ�
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	cout << "######## ������ ���� ########" << endl;

	cout << "1. �����ϰ� ��Ÿ�� ���� ��� ������ ��������." << endl;
	cout << "2. �� �Ǵ� ������ �ε����� ���� �����Դϴ�." << endl;

	system("pause"); //Ű�� �Էµɶ����� �Ͻ� �����Ǵ� �ڵ�.
	system("cls");
}



void ReSet()
{
	curScore = 0;


	for (int i = X / 2 + 1; i < X / 2 + 4; i++) //������ ���� 3���� ����. 
	{
		wormPosition.push_back(WormPosition(i, Y / 2 + 1));
	}


	for (int x = 0; x < X; x++)
	{
		for (int y = 0; y < Y; y++)
		{
			if (x == 0 || x == X - 1)
				map[x][y] = 1; //��
			else if (y == 0 || y == Y - 1)
				map[x][y] = 1;
			else
				map[x][y] = 0;
		}
	}

	for (const auto& ele : wormPosition)
	{
		map[ele.x][ele.y] = 3; //������ ��
	}
	map[X / 2 + 1][Y / 2 + 1] = 2; //������ �Ӹ�
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
		int star[2]; //�����ϰ� �� ����
		star[0] = Math::Random(1, X - 2);
		star[1] = Math::Random(1, Y - 2);
		if (map[star[0]][star[1]] == 0)// �����̿� ��ġ�� �ʰ� ����
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

	cout << "���� : " << curScore << endl;

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
				cout << "��";
			if (map[x][y] == 2)
				cout << "��";
			if (map[x][y] == 3)
				cout << "��";
			if (map[x][y] == 4)
				cout << "��";
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
		cout << "���� �ε������ϴ�. �й�!" << endl;
		return false;
	}
	else if (map[temp1][temp2] == 3)
	{
		cout << "���� �ε������ϴ�. �й�!" << endl;
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