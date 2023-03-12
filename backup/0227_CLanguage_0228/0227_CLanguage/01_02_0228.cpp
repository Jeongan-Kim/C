#include <stdio.h>
#include <stdbool.h>
int main()
{
	int a = 10;
	int b = 3;
	int result;

	result = a + b;
	printf("%d\n", result);

	result = a - b;
	printf("%d\n", result);

	result = a * b;
	printf("%d\n", result);

	result = a / b;
	printf("%d\n", result);

	result = a % b;
	printf("%d\n", result);

	a += b;
	printf("%d\n", a);

	a = 1;
	b = 1;
	a = ++b;
	printf("a : %d, b : %d\n", a, b);

	a = 1;
	b = 1;
	a = b++;
	printf("a : %d, b : %d\n", a, b);

	//int num;
	//scanf_s("%d", &num);
	//printf("%d\n", num);

	//int num1, num2, num3;
	//scanf_s("%d %d %d", &num1, &num2, &num3);
	//printf("%d %d %d\n", num1, num2, num3);


//#pragma region Attack
//	int playerDamage = 50;
//	int enemyHp = 550;
//
//	printf("플레이어의 공격력 : %d\n", playerDamage);
//	printf("현재 적의 체력 : %d\n", enemyHp);
//
//	int attackCount = 0;
//	printf("몇 번 공격하시겠습니까? : ");
//	scanf_s("%d", &attackCount);
//
//	enemyHp -= playerDamage * attackCount;
//	printf("현재 적의 체력 : %d\n", enemyHp);
//
//
//
//#pragma endregion
//
//#pragma region Grab
//	int grabRange;
//	int distance = 300;
//	bool catchenemy = true;
//
//	printf("적과의 거리 : %d\n", distance);
//
//	printf("그랩 사거리 : ");
//	scanf_s("%d", &grabRange);
//
//	grabRange >= distance ? catchenemy = true : catchenemy = false;
//	printf("적을 처지하였나요? : %d\n", catchenemy);
//
//#pragma endregion


	char c1 = 'A';
	char c2 = 65;

	printf("Character c1 : %c\n", c1);
	printf("Character c2 : %c\n", c2);
	printf("Character size : %d\n", sizeof(char));
	printf("Character size : %d\n", sizeof(c1));

	short s = 1;
	int num = 0;
	printf("num : %d\n", num);
	printf("int size : %d\n", sizeof(int));

	float f = 0.123f;
	double d = 0.1234;
	
	printf("고정 소수점 : %f\n", f);
	printf("부동 소수점 : %e\n", f);

	float sum = 0.1f;
	for (int i = 0; i < 1000; i++)
	{
		sum += 0.1;
	}

	printf("%f\n", sum);


	bool isDash = true;
	printf("캐릭터 대쉬 유무 : %d\n", isDash);
	
	unsigned char c3;
	unsigned int i2;

	char cc = 129;
	printf("signed char에서 129는 %d\n", cc);

	unsigned char ccc = 129;
	printf("unsigned char에서 129는 %d\n", ccc);

	return 0;
}