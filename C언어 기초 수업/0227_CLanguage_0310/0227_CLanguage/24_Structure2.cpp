#include <stdio.h>
#include <math.h> //다양한 수학 공식이 들어있는 라이브러리 

#define NUM 2

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float height;
};

//struct Human h;
Human h; //struct를 생략할 수 있음(C에서는 오류남)

typedef int my_int; //typedef : 그래도 C에서 생략하고 싶을때, 변수에 별칭을 넣어주는 매크로 같은 것.
my_int mi; //== int mi;

typedef struct _Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
}Monster;

Monster m1;

typedef struct //익명 구조체 : 이름이 없으면 .
{
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
}Player;

Player p1;

Player p2 = { "주인공", 500, 100, 10, 100 }; //넣고자 하는 정보를 순차적으로 초기화하면 됨.

typedef struct
{
	int xpos;
	int ypos;
}Point;

void input_human();

int main()
{
	//Point pos; //구조체 이름 초기화
	//pos.xpos = 20;
	//pos.ypos = 30;//이름을 이용해서 이렇게도 초기화 가능

	//printf("%d\n", pos.xpos);
	//printf("%d\n", pos.xpos);
	//

	//두 점 사이의 거리

	{
		//Point pos1, pos2; // 두 점
		//double distance; // 거리를 저장할 변수

		//printf("Point pos1 : ");
		//scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

		//printf("Point pos2 : ");
		//scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

		//distance = sqrt((double)pow((pos1.xpos - pos2.xpos), 2) + pow((pos1.ypos - pos2.ypos), 2)); //제곱근, 제곱

		//printf("두 점 사이의 거리는  : %d\n", distance);
	}

	input_human();

	return 0;
}

void input_human()
{
	struct Human hu[NUM];

	printf("%d명의 입력 받기", NUM);

	for (int i = 0; i < NUM; i++)
	{
		printf("이름 입력 = > ");
		scanf_s("%s", &hu[i].name, sizeof(hu->name));

		printf("성별 입력 = > ");
		scanf_s("%s", &hu[i].gender, sizeof(hu->gender));

		printf("나이 입력 = > ");
		scanf_s("%d", &hu[i].age);

		printf("키 입력 = > ");
		scanf_s("%f", &hu[i].height);

		printf("\n");
	}

	for (int i = 0; i < NUM; i++)
	{
		printf("이름 : %s, 성별 : %s, 나이 : %d, 키 : %.2f\n", //%.2f소수 두번째점까지 나타내겠다?
			hu[i].name, hu[i].gender, hu[i].age, hu[i].height);
	}
}
