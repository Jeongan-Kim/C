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
		char name[256]; //구조체의 멤버
		int age;
		float height;
	};

	struct person p = { "홍길동", 30, 175.25f };
	p.height = 180.35f;

	printf("p의 height : %f\n", p.height);
	printf("p의 height의 주소 : %0xp\n", &p.height); //%0xp와 0x%p의 차이?

	{
		struct book
		{
			char name[256];
			float price;
		};
		struct book b1;
	}
	//struct book b2; // 구조체도 지역변수 같은 성질이라 밖에서는 오류남. 그래서 전역변수로 정의하는 경우가 많음.

	{
		typedef struct
		{
			char given[256];
			char family[256];
		}names;

		typedef struct
		{
			names fullName; //구조체 멤버를 구조체로 쓰는 것.
			char mobile[256];
		}friendInfo;

		friendInfo myFriend[2] = //구조체 속에 구조체가 있을 때 초기화 방법.
		{
			{{"Jeongan", "Kim"}, "2831-5447"},
			{{"Seongho", "Jeong"}, "2458-2662"}
		};

		friendInfo* bestFriend;
		bestFriend = &myFriend[0]; //구조체의 주소를 호출할때에는 그냥 이름이 첫번째 원소를 말하는 게 아닐 수 있기 떄문에 인덱스 꼭 넣어줘야 함
		//0번째 애만 넣은 게 아니라 구조체 자체를 다 넣은 것임.

		printf("bestFriend[0] 이름\t : %s\n", (*bestFriend).fullName.given); //.연산이 *보다 더 먼저 호출돼서 괄호 쳐줘야 함
		printf("bestFriend[0] 성\t : %s\n", bestFriend->fullName.family); //(*bestFriend)이거랑 bestFriend->는 같은데, 괄호 형식은 중간에 쓰지 못하기때문에 화살표를 자주 씀

		bestFriend++; //1번으로 넘어감
		printf("bestFriend[1] 이름\t : %s\n", (*bestFriend).fullName.given); 
		printf("bestFriend[1] 성\t : %s\n", bestFriend->fullName.family);
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
			"player", 100, NULL //weapon을 초기화 하지 않았으니NULL로 일단 넣음.
		};

		weapon sword =
		{
			"Sword",
			"Legend",
			500
		};

		p.equipWeapon = &sword;

		printf("플레이어 이름\t : %s\n", p.name);
		printf("소지 무기\t :%s\n", p.equipWeapon->name);
		printf("소지 무기의 등급 :%s\n\n", p.equipWeapon->grade);

		weapon bow =
		{
			"Bow",
			"Common",
			30
		};

		p.equipWeapon = &bow;

		printf("플레이어 이름\t : %s\n", p.name);
		printf("소지 무기\t :%s\n", p.equipWeapon->name);
		printf("소지 무기의 등급 :%s\n\n", p.equipWeapon->grade);
	}
}
