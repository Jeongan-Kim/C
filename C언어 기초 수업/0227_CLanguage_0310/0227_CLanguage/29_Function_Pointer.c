#include <stdio.h>

void pointer_and_function();//함수들도 메인메모리에 저장이 되므로 주소를 갖고 있음.
void mini_RPG2();

int main()
{
	//pointer_and_function();
	mini_RPG2();
	return 0;
}

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }
//함수를 불러와 쓰기 위해 저장함 => 그러기 위해 함수 포인터를 사용.

typedef struct _player
{
	char name[256];
	char location[256];
	int hp;
	void(*ifDead[5])(struct _player*); //플레이어가 죽었을때 일어날 이벤트를 다룰 함수 포인터 초기화.
}player;

void printDead(player* p)
{
	printf("%s 사망\n", p->name); //포인터 매개변수이므로 포인터로 접근

	return;
}

void revive(player* p)
{
	printf("%s 소생\n", p->name); //포인터 매개변수이므로 포인터로 접근
	p->hp = 200;
	return;
}

void moveToTown(player* p)
{
	printf("%s 마을로 이동\n", p->name); //포인터 매개변수이므로 포인터로 접근
	strcpy(p->location, "Town"); //문자는 카피 함수를 써야 함.
	return;
}

void pointer_and_function()
{
	//연산자에 따라서 함수를 호출해주는 것
	char op = '\0';//우선 NULL값으로 초기화
	printf("연산자 입력 : ");
	scanf_s(" %c", &op, (int)sizeof(op));

	int x = 0;
	printf("피연산자 입력 : ");
	scanf_s("%d", &x);

	int y = 0;
	printf("피연산자 입력 : ");
	scanf_s("%d", &y);

	int(*compute)(int, int) = NULL; //int가 두개가 들어간 int형 함수 포인터 생성

	switch (op)
	{
	case'+': compute = Add; break; //함수에 아무것도 들어있지 않으면 안되서 NULL 체크도 해줘야 좋음.
	case'-': compute = Sub; break;
	}

	if (compute != NULL)
		printf("결과 : %d\n", compute(x, y));

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
	p.ifDead[2] = moveToTown; //캐릭터 초기화할때 넣어도 되는가?

	printf("%s의 위치 : %s, HP : %d\n", p.name, p.location, p.hp);

	int damage = 0;

	while (1)
	{
		printf("받을 피해 입력(현재 체력 : %d) : ", p.hp);
		scanf_s("%d", &damage);

		p.hp -= damage;

		if (p.hp <= 0)
		{
			for (int i = 0; i < 3; i++)
			{
				if (p.ifDead[i] != NULL)//안정성 높이기 위한 조건
					p.ifDead[i](&p);	
			}
			break;
		}

	}

	printf("%s의 위치 : %s, HP : %d\n", p.name, p.location, p.hp); //잘 되었는지 확인.

}
