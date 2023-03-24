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
		printf("���� ���� �߰�! ���ݷ��� �ö����ϴ�.\n");
		playerptr->atk += 20; //(*playerptr).atk
		printf("���� ���ݷ� : %d\n", playerptr->atk);

		Sleep(1000);
		system("cls");
		break;
	case 1:
		printf("���� ���� �߰�! ü���� �ö����ϴ�.\n");
		playerptr->hp += 100;
		printf("���� ü�� : %d\n", playerptr->hp);

		Sleep(1000);
		system("cls");
		break;
	case 2:
		int m_num = rand() % 3;
		int m_hp = m[m_num].hp;

		printf("%s�� �������ϴ�! ������ �����մϴ�.\n", m[m_num].name);

		while (1)
		{
			printf("�÷��̾��� ����! %d��ŭ �������� �����ϴ�.\n", playerptr->atk);

			m_hp -= playerptr->atk;

			Sleep(1000);
			if (m_hp <= 0)
				m_hp = 0;
			printf("%s�� ü�� : %d\n", m[m_num].name, m_hp);

			if (m_hp <= 0)
			{
				playerptr->exp += m[m_num].exp;
				printf("����ġ : %d\n", playerptr->exp);

				Sleep(1000);
				system("cls");
				break;
			}

			printf("%s�� ����! %d��ŭ �������� �޾ҽ��ϴ�.\n", m[m_num].name, m[m_num].atk);

			Sleep(1000);
			playerptr->hp -= m[m_num].atk;
			if (playerptr->hp <= 0)
				playerptr->hp = 0;
			printf("%s�� ü�� : %d\n", playerptr->name, playerptr->hp);
			

			if (playerptr->hp <= 0)
			{
				printf("%s�� �׾����ϴ�. �й�!\n", playerptr->name);
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
	printf("*** RPG ���� ***\n���� �԰� �������� ���� �����ϼ���.\n");

	Player p1; //���� �÷����� ĳ���� 
	Player* playerptr = &p1;
	printf("���� �÷����� ĳ������ ������ �Է��� �ּ���.\n");

	//ĳ���� ���� �Է�
	printf("�÷��̾� �̸� : ");
	scanf_s("%s", &p1.name, sizeof(p1.name));
	printf("�÷��̾� ü�� : ");
	scanf_s("%d", &p1.hp);
	printf("�÷��̾� ���ݷ� : ");
	scanf_s("%d", &p1.atk);
	p1.exp = 0;
	p1.gold = 0;

	Monster m[3] =
	{
		{ "�̵", 100, 100, 50 },
		{ "�Ϻ�", 150, 150, 80 },
		{ "��", 120, 180, 200 }
	};

	printf("- - - ���� ����! - - -\n");
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

	int my_posx = 1;//�÷��̾� ��ġ ��ǥ
	int my_posy = 1;

	while (1)
	{
		if (p1.hp <= 0)
		{
			printf("ĳ���Ͱ� �׾����ϴ�.\n");
			return;
		}
		else if (map[4][12] == 3)
		{
			printf("���� �����߽��ϴ�. �¸�!!\n");
			return;
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (map[i][j] == 0)
					printf("  ");
				else if (map[i][j] == 1)
					printf("��");
				else if (map[i][j] == 2)
					printf("��");
				else if (map[i][j] == 3)
					printf("��");
				else if (map[i][j] == 4)
					printf("��");
			}
			printf("\n");
		}

		char key1 = _getch();
		char key2 = _getch();
		if (key1 == -32)
		{
			switch (key2) //ȭ��ǥ �Է�(��72,��80, ��75, ��77)
			{
			case 72: //��
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

			case 80: //��
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
			case 75: //��
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
			case 77: //��
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
				printf("�߸� �����̽��ϴ�. ȭ��ǥ�� �����ϼ���.\n");
				Sleep(300);
				system("cls");
				break;
			}
		}

	}





}
