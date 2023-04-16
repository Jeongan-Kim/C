#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15

typedef struct Star
{
	int x;
	int y;
	bool isStar; //���� �������� �ִ��� ���������� Ȯ�ο�
}Star;

typedef struct Player
{
	int x;
	int y;
}Player;

void gotoxy(int x, int y) //windows.h ���Ͽ� �������, Ŀ���� �ű�� �Լ�, ��ǥ�� ã���ִ� �Լ�
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Star star[WIDTH];
Player player;

void init() //�ʱⰪ
{
	for (int i = 0; i < WIDTH; i++)
		star[i].isStar = false;

	player.x = WIDTH / 2;
	player.y = HEIGHT;
}

void createStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == false)
		{
			star[i].x = rand() % WIDTH;
			star[i].y = 0;
			star[i].isStar = true;
			return;
		}
	}
}

void shootingStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == true)
		{
			star[i].y++;
		}
	}
}

int score = 0;

void destroyStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == true && star[i].y > HEIGHT)
		{
			star[i].isStar = false;
			score += 100;
			printf("���� : %d\n", score);
		}
	}
}

bool collidPlayer() //���� �÷��̾ �ε������� Ȯ��
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == true && star[i].y == player.y && star[i].x == player.x)
		{
			printf("\n\n���� : %d\n", score);
			printf("���� ����\n");
			return true;
		}
	}
	return false;
}

int isKeyDown(int key) //��Ʈ�� ���� Ű�� ���ȴ��� Ȯ���� �ִ� �Լ�
{
	return((GetAsyncKeyState(key) & 0x8000) != 0);
}

void movePlayer()
{
	if (isKeyDown(VK_LEFT)) //���� ȭ��ǥ
		player.x--;
	if (isKeyDown(VK_RIGHT)) //������ ȭ��ǥ
		player.x++;
	if (isKeyDown(VK_UP)) //���� ȭ��ǥ
		player.y--;
	if (isKeyDown(VK_DOWN)) //�Ʒ��� ȭ��ǥ
		player.y++;

	if (player.x < 1)//���� �ε�������
		player.x = 1;
	if (player.x > WIDTH - 1)
		player.x = WIDTH - 1;
	if (player.y < 1)//���� �ε�������
		player.y = 1;
	if (player.y > HEIGHT)
		player.y = HEIGHT;
}

void printGame() //����� ���������� ���� �����ϰԲ�
{
	system("cls");

	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar)
		{
			gotoxy(star[i].x, star[i].y);
			printf("��");
		}
	}

	gotoxy(player.x, player.y);
	printf("��");

	for (int i = 0; i < WIDTH + 1; i++)
	{
		gotoxy(i, 0);
		printf("��"); //õ��

		for (int j = 1; j < HEIGHT + 1; j++) //����
		{
			gotoxy(i, j);
			if (i == 0 || i == WIDTH)
			{
				printf("��");
			}
		}

		gotoxy(i, HEIGHT + 1);
		printf("��");// �ٴ�
	}

}

int main()
{
	init();

	srand((unsigned int)time(NULL));

	while (!(collidPlayer()))
	{
		createStar();
		shootingStar();
		destroyStar();

		movePlayer();

		printGame();

		Sleep(30);
	}
	return 0;
}