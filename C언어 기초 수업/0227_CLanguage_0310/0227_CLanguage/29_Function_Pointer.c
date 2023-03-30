#include <stdio.h>

void pointer_and_function();//�Լ��鵵 ���θ޸𸮿� ������ �ǹǷ� �ּҸ� ���� ����.
void mini_RPG2();

int main()
{
	//pointer_and_function();
	mini_RPG2();
	return 0;
}

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }
//�Լ��� �ҷ��� ���� ���� ������ => �׷��� ���� �Լ� �����͸� ���.

typedef struct _player
{
	char name[256];
	char location[256];
	int hp;
	void(*ifDead[5])(struct _player*); //�÷��̾ �׾����� �Ͼ �̺�Ʈ�� �ٷ� �Լ� ������ �ʱ�ȭ.
}player;

void printDead(player* p)
{
	printf("%s ���\n", p->name); //������ �Ű������̹Ƿ� �����ͷ� ����

	return;
}

void revive(player* p)
{
	printf("%s �һ�\n", p->name); //������ �Ű������̹Ƿ� �����ͷ� ����
	p->hp = 200;
	return;
}

void moveToTown(player* p)
{
	printf("%s ������ �̵�\n", p->name); //������ �Ű������̹Ƿ� �����ͷ� ����
	strcpy(p->location, "Town"); //���ڴ� ī�� �Լ��� ��� ��.
	return;
}

void pointer_and_function()
{
	//�����ڿ� ���� �Լ��� ȣ�����ִ� ��
	char op = '\0';//�켱 NULL������ �ʱ�ȭ
	printf("������ �Է� : ");
	scanf_s(" %c", &op, (int)sizeof(op));

	int x = 0;
	printf("�ǿ����� �Է� : ");
	scanf_s("%d", &x);

	int y = 0;
	printf("�ǿ����� �Է� : ");
	scanf_s("%d", &y);

	int(*compute)(int, int) = NULL; //int�� �ΰ��� �� int�� �Լ� ������ ����

	switch (op)
	{
	case'+': compute = Add; break; //�Լ��� �ƹ��͵� ������� ������ �ȵǼ� NULL üũ�� ����� ����.
	case'-': compute = Sub; break;
	}

	if (compute != NULL)
		printf("��� : %d\n", compute(x, y));

	printf("\n\n");
}

void mini_RPG2()
{
	player p =
	{
		"Wizard",
		"Dungeon",
		100,
		{NULL, NULL, NULL}
	};

	p.ifDead[0] = printDead;
	p.ifDead[1] = revive;
	p.ifDead[2] = moveToTown; //ĳ���� �ʱ�ȭ�Ҷ� �־ �Ǵ°�?

	printf("%s�� ��ġ : %s, HP : %d\n", p.name, p.location, p.hp);

	int damage = 0;

	while (1)
	{
		printf("���� ���� �Է�(���� ü�� : %d) : ", p.hp);
		scanf_s("%d", &damage);

		p.hp -= damage;

		if (p.hp <= 0)
		{
			for (int i = 0; i < 3; i++)
			{
				if (p.ifDead[i] != NULL)//������ ���̱� ���� ����
					p.ifDead[i](&p);	
			}
			break;
		}

	}

	printf("%s�� ��ġ : %s, HP : %d\n", p.name, p.location, p.hp); //�� �Ǿ����� Ȯ��.

}
