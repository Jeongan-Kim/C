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
//	printf("�÷��̾��� ���ݷ� : %d\n", playerDamage);
//	printf("���� ���� ü�� : %d\n", enemyHp);
//
//	int attackCount = 0;
//	printf("�� �� �����Ͻðڽ��ϱ�? : ");
//	scanf_s("%d", &attackCount);
//
//	enemyHp -= playerDamage * attackCount;
//	printf("���� ���� ü�� : %d\n", enemyHp);
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
//	printf("������ �Ÿ� : %d\n", distance);
//
//	printf("�׷� ��Ÿ� : ");
//	scanf_s("%d", &grabRange);
//
//	grabRange >= distance ? catchenemy = true : catchenemy = false;
//	printf("���� ó���Ͽ�����? : %d\n", catchenemy);
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
	
	printf("���� �Ҽ��� : %f\n", f);
	printf("�ε� �Ҽ��� : %e\n", f);

	float sum = 0.1f;
	for (int i = 0; i < 1000; i++)
	{
		sum += 0.1;
	}

	printf("%f\n", sum);


	bool isDash = true;
	printf("ĳ���� �뽬 ���� : %d\n", isDash);
	
	unsigned char c3;
	unsigned int i2;

	char cc = 129;
	printf("signed char���� 129�� %d\n", cc);

	unsigned char ccc = 129;
	printf("unsigned char���� 129�� %d\n", ccc);

	return 0;
}