#include <stdio.h>

void pointer_and_structure();

int main()
{
	pointer_and_structure();
	return 0;
}

void pointer_and_structure()
{
	struct person
	{
		char name[256]; //����ü�� ���
		int age;
		float height;
	};

	struct person p = { "ȫ�浿", 30, 175.25f };
	p.height = 180.35f;

	printf("p�� height : %f\n", p.height);
	printf("p�� height�� �ּ� : %0xp\n", &p.height); //%0xp�� 0x%p�� ����?

	{
		struct book
		{
			char name[256];
			float price;
		};
		struct book b1;
	}
	//struct book b2; // ����ü�� �������� ���� �����̶� �ۿ����� ������. �׷��� ���������� �����ϴ� ��찡 ����.

	{
		typedef struct
		{
			char given[256];
			char family[256];
		}names;

		typedef struct
		{
			names fullName; //����ü ����� ����ü�� ���� ��.
			char mobile[256];
		}friendInfo;

		friendInfo myFriend[2] = //����ü �ӿ� ����ü�� ���� �� �ʱ�ȭ ���.
		{
			{{"Jeongan", "Kim"}, "2831-5447"},
			{{"Seongho", "Jeong"}, "2458-2662"}
		};

		friendInfo* bestFriend;
		bestFriend = &myFriend[0]; //����ü�� �ּҸ� ȣ���Ҷ����� �׳� �̸��� ù��° ���Ҹ� ���ϴ� �� �ƴ� �� �ֱ� ������ �ε��� �� �־���� ��
		//0��° �ָ� ���� �� �ƴ϶� ����ü ��ü�� �� ���� ����.

		printf("bestFriend[0] �̸�\t : %s\n", (*bestFriend).fullName.given); //.������ *���� �� ���� ȣ��ż� ��ȣ ����� ��
		printf("bestFriend[0] ��\t : %s\n", bestFriend->fullName.family); //(*bestFriend)�̰Ŷ� bestFriend->�� ������, ��ȣ ������ �߰��� ���� ���ϱ⶧���� ȭ��ǥ�� ���� ��

		bestFriend++; //1������ �Ѿ
		printf("bestFriend[1] �̸�\t : %s\n", (*bestFriend).fullName.given); 
		printf("bestFriend[1] ��\t : %s\n", bestFriend->fullName.family);
	}

	printf("\n\n");

	{
		typedef struct
		{
			char name[256];
			char grade[256];
			int damage;
			
		}weapon;

		typedef struct
		{
			char name[256];
			int hp;
			weapon* equipWeapon;

		}player;

		player p =
		{
			"player", 100, NULL //weapon�� �ʱ�ȭ ���� �ʾ�����NULL�� �ϴ� ����.
		};

		weapon sword =
		{
			"Sword",
			"Legend",
			500
		};

		p.equipWeapon = &sword;

		printf("�÷��̾� �̸�\t : %s\n", p.name);
		printf("���� ����\t :%s\n", p.equipWeapon->name);
		printf("���� ������ ��� :%s\n\n", p.equipWeapon->grade);

		weapon bow =
		{
			"Bow",
			"Common",
			30
		};

		p.equipWeapon = &bow;

		printf("�÷��̾� �̸�\t : %s\n", p.name);
		printf("���� ����\t :%s\n", p.equipWeapon->name);
		printf("���� ������ ��� :%s\n\n", p.equipWeapon->grade);
	}
}
