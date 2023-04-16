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
	bool isStar; //별이 떨어지고 있는지 없어졌는지 확인용
}Star;

typedef struct Player
{
	int x;
	int y;
}Player;

void gotoxy(int x, int y) //windows.h 파일에 들어있음, 커서를 옮기는 함수, 좌표를 찾아주는 함수
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Star star[WIDTH];
Player player;

void init() //초기값
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
			printf("점수 : %d\n", score);
		}
	}
}

bool collidPlayer() //별과 플레이어가 부딪혔는지 확인
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == true && star[i].y == player.y && star[i].x == player.x)
		{
			printf("\n\n점수 : %d\n", score);
			printf("게임 종료\n");
			return true;
		}
	}
	return false;
}

int isKeyDown(int key) //비트에 따라서 키가 눌렸는지 확인해 주는 함수
{
	return((GetAsyncKeyState(key) & 0x8000) != 0);
}

void movePlayer()
{
	if (isKeyDown(VK_LEFT)) //왼쪽 화살표
		player.x--;
	if (isKeyDown(VK_RIGHT)) //오른쪽 화살표
		player.x++;
	if (isKeyDown(VK_UP)) //위쪽 화살표
		player.y--;
	if (isKeyDown(VK_DOWN)) //아래쪽 화살표
		player.y++;

	if (player.x < 1)//벽에 부딪혔을때
		player.x = 1;
	if (player.x > WIDTH - 1)
		player.x = WIDTH - 1;
	if (player.y < 1)//벽에 부딪혔을때
		player.y = 1;
	if (player.y > HEIGHT)
		player.y = HEIGHT;
}

void printGame() //사건이 있을때마다 맵을 생성하게끔
{
	system("cls");

	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar)
		{
			gotoxy(star[i].x, star[i].y);
			printf("☆");
		}
	}

	gotoxy(player.x, player.y);
	printf("△");

	for (int i = 0; i < WIDTH + 1; i++)
	{
		gotoxy(i, 0);
		printf("■"); //천장

		for (int j = 1; j < HEIGHT + 1; j++) //세로
		{
			gotoxy(i, j);
			if (i == 0 || i == WIDTH)
			{
				printf("■");
			}
		}

		gotoxy(i, HEIGHT + 1);
		printf("■");// 바닥
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