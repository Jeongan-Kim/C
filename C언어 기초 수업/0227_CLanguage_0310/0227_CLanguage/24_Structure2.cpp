#include <stdio.h>
#include <math.h> //�پ��� ���� ������ ����ִ� ���̺귯�� 

#define NUM 2

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float height;
};

//struct Human h;
Human h; //struct�� ������ �� ����(C������ ������)

typedef int my_int; //typedef : �׷��� C���� �����ϰ� ������, ������ ��Ī�� �־��ִ� ��ũ�� ���� ��.
my_int mi; //== int mi;

typedef struct _Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
}Monster;

Monster m1;

typedef struct //�͸� ����ü : �̸��� ������ .
{
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
}Player;

Player p1;

Player p2 = { "���ΰ�", 500, 100, 10, 100 }; //�ְ��� �ϴ� ������ ���������� �ʱ�ȭ�ϸ� ��.

typedef struct
{
	int xpos;
	int ypos;
}Point;

void input_human();

int main()
{
	//Point pos; //����ü �̸� �ʱ�ȭ
	//pos.xpos = 20;
	//pos.ypos = 30;//�̸��� �̿��ؼ� �̷��Ե� �ʱ�ȭ ����

	//printf("%d\n", pos.xpos);
	//printf("%d\n", pos.xpos);
	//

	//�� �� ������ �Ÿ�

	{
		//Point pos1, pos2; // �� ��
		//double distance; // �Ÿ��� ������ ����

		//printf("Point pos1 : ");
		//scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

		//printf("Point pos2 : ");
		//scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

		//distance = sqrt((double)pow((pos1.xpos - pos2.xpos), 2) + pow((pos1.ypos - pos2.ypos), 2)); //������, ����

		//printf("�� �� ������ �Ÿ���  : %d\n", distance);
	}

	input_human();

	return 0;
}

void input_human()
{
	struct Human hu[NUM];

	printf("%d���� �Է� �ޱ�", NUM);

	for (int i = 0; i < NUM; i++)
	{
		printf("�̸� �Է� = > ");
		scanf_s("%s", &hu[i].name, sizeof(hu->name));

		printf("���� �Է� = > ");
		scanf_s("%s", &hu[i].gender, sizeof(hu->gender));

		printf("���� �Է� = > ");
		scanf_s("%d", &hu[i].age);

		printf("Ű �Է� = > ");
		scanf_s("%f", &hu[i].height);

		printf("\n");
	}

	for (int i = 0; i < NUM; i++)
	{
		printf("�̸� : %s, ���� : %s, ���� : %d, Ű : %.2f\n", //%.2f�Ҽ� �ι�°������ ��Ÿ���ڴ�?
			hu[i].name, hu[i].gender, hu[i].age, hu[i].height);
	}
}
