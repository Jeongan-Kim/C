#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

struct Player
{
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
};

struct Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
};
void event(Player* playerptr, Monster m[]);
void rpg();

int main()
{
	rpg();
	return 0;
}


void event(Player* playerptr, Monster m[])
{
	srand((unsigned int)time(NULL));

	int event = rand() % 3;
	

	switch (event)
	{
	case 0:
		printf("보물 상자 발견! 공격력이 올랐습니다.\n");
		playerptr->atk += 20; //(*playerptr).atk
		printf("현재 공격력 : %d\n", playerptr->atk);

		Sleep(1000);
		system("cls");
		break;
	case 1:
		printf("보물 상자 발견! 체력이 올랐습니다.\n");
		playerptr->hp += 100;
		printf("현재 체력 : %d\n", playerptr->hp);

		Sleep(1000);
		system("cls");
		break;
	case 2:
		int m_num = rand() % 3;
		int m_hp = m[m_num].hp;

		printf("%s를 만났습니다! 전투를 시작합니다.\n", m[m_num].name);

		while (1)
		{
			printf("플레이어의 공격! %d만큼 데미지를 입힙니다.\n", playerptr->atk);

			m_hp -= playerptr->atk;

			Sleep(1000);
			if (m_hp <= 0)
				m_hp = 0;
			printf("%s의 체력 : %d\n", m[m_num].name, m_hp);

			if (m_hp <= 0)
			{
				playerptr->exp += m[m_num].exp;
				printf("경험치 : %d\n", playerptr->exp);

				Sleep(1000);
				system("cls");
				break;
			}

			printf("%s의 공격! %d만큼 데미지를 받았습니다.\n", m[m_num].name, m[m_num].atk);

			Sleep(1000);
			playerptr->hp -= m[m_num].atk;
			if (playerptr->hp <= 0)
				playerptr->hp = 0;
			printf("%s의 체력 : %d\n", playerptr->name, playerptr->hp);
			

			if (playerptr->hp <= 0)
			{
				printf("%s가 죽었습니다. 패배!\n", playerptr->name);
				Sleep(1000);
				system("cls");
				break;
			}
		}
		break;
	}
}

void rpg()
{	
	printf("*** RPG 게임 ***\n☆을 먹고 강해져서 ♡에 도달하세요.\n");

	Player p1; //내가 플레이할 캐릭터 
	Player* playerptr = &p1;
	printf("내가 플레이할 캐릭터의 정보를 입력해 주세요.\n");

	//캐릭터 정보 입력
	printf("플레이어 이름 : ");
	scanf_s("%s", &p1.name, sizeof(p1.name));
	printf("플레이어 체력 : ");
	scanf_s("%d", &p1.hp);
	printf("플레이어 공격력 : ");
	scanf_s("%d", &p1.atk);
	p1.exp = 0;
	p1.gold = 0;

	Monster m[3] =
	{
		{ "이등병", 100, 100, 50 },
		{ "일병", 150, 150, 80 },
		{ "상병", 120, 180, 200 }
	};

	printf("- - - 게임 시작! - - -\n");
	Sleep(1000);
	system("cls");

	int map[9][14] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{1, 3, 0, 1, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 0, 2, 1, 0, 1, 0, 0, 1, 0, 2, 1, 0, 0},
		{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 2, 4, 1},
		{1, 2, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 2, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 0, 0, 1, 0, 1, 2, 0, 1, 2, 0, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
	};

	int my_posx = 1;//플레이어 위치 좌표
	int my_posy = 1;

	while (1)
	{
		if (p1.hp <= 0)
		{
			printf("캐릭터가 죽었습니다.\n");
			return;
		}
		else if (map[4][12] == 3)
		{
			printf("♡에 도달했습니다. 승리!!\n");
			return;
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (map[i][j] == 0)
					printf("  ");
				else if (map[i][j] == 1)
					printf("▦");
				else if (map[i][j] == 2)
					printf("☆");
				else if (map[i][j] == 3)
					printf("＠");
				else if (map[i][j] == 4)
					printf("♡");
			}
			printf("\n");
		}

		char key1 = _getch();
		char key2 = _getch();
		if (key1 == -32)
		{
			switch (key2) //화살표 입력(상72,하80, 좌75, 우77)
			{
			case 72: //상
			{
				if (map[my_posx - 1][my_posy] == 1)
				{
					Sleep(300);
					system("cls");
					continue;
				}
				else
				{
					map[my_posx][my_posy] = 0;
					my_posx--;
					if (map[my_posx][my_posy] == 2)
						event(playerptr, m);
					map[my_posx][my_posy] = 3;
					Sleep(300);
					system("cls");
				}
				break;
			}

			case 80: //하
			{
				if (map[my_posx + 1][my_posy] == 1)
				{
					Sleep(300);
					system("cls");
					continue;
				}
				else
				{
					map[my_posx][my_posy] = 0;
					my_posx++;
					if (map[my_posx][my_posy] == 2)
						event(playerptr, m);
					map[my_posx][my_posy] = 3;
					Sleep(300);
					system("cls");
				}
				break;
			}
			case 75: //좌
			{
				if (map[my_posx][my_posy - 1] == 1)
				{
					Sleep(300);
					system("cls");
					continue;
				}
				else
				{
					map[my_posx][my_posy] = 0;
					my_posy--;
					if (map[my_posx][my_posy] == 2)
						event(playerptr, m);
					map[my_posx][my_posy] = 3;
					Sleep(300);
					system("cls");
				}
				break;
			}
			case 77: //우
			{
				if (map[my_posx][my_posy + 1] == 1)
				{
					Sleep(300);
					system("cls");
					continue;
				}
				else
				{
					map[my_posx][my_posy] = 0;
					my_posy++;
					if (map[my_posx][my_posy] == 2)
						event(playerptr, m);
					map[my_posx][my_posy] = 3;
					Sleep(300);
					system("cls");
				}
				break;
			}
			default:
				printf("잘못 누르셨습니다. 화살표로 조종하세요.\n");
				Sleep(300);
				system("cls");
				break;
			}
		}

	}





}
