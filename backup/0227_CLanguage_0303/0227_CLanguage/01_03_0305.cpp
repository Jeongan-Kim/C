#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
	////���� ����
	//printf("%d, ", rand() % 10);

	//srand((unsigned int)time(NULL));

	//printf(" % d, ", rand() % 10);

	////while��

	//bool study = true;
	//while (study)
	//{
	//	printf("Hello World!\n");
	//	
	//	printf("���� ���ΰ���? [�� : 1, �ƴϿ� : 0] -> ");
	//	int answer = -1;
	//	scanf_s("%d", &answer);

	//	if (answer == 0)
	//	{
	//		study = false;
	//	}
	//}



	//char key;
	//while (true)
	//{
	//	printf("�̵�Ű �Է� : ");
	//	key = _getch();

	//	if (key == 'q')
	//		break;

	//	switch (key)
	//	{
	//	case'w':printf("��\n"); break;
	//	case's':printf("��\n"); break;
	//	case'a':printf("��\n"); break;
	//	case'd':printf("��\n"); break;
	//	default: printf("�߸�����\n"); break;
	//	}
	//}


	//const int secretCode = 123123;

	//int password = 0;
	//int tryCount = 0;

	//do
	//{
	//	if (tryCount >= 3)
	//	{
	//		printf("3ȸ ����, ���� ���!\n");
	//		break;
	//	}
	//	printf("��й�ȣ �Է� (3ȸ ���� �� ���, ���� ���� Ƚ�� : %d)\n", tryCount);
	//	scanf_s("%d", &password);

	//	tryCount++;
	//} while (password != secretCode);

	//for (int i = 0; i < 5; i++)
	//{
	//	printf("for�� ��ɾ� %d�� �ݺ���\n", i);
	//}

	//printf("\n");

	//for (int i = 5; i; i--)
	//{
	//	printf("for�� ��ɾ� %d�� �ݺ���\n", i);
	//}

	//for (;;)
	//{
	//	printf("���ѷ���\n");
	//}

	int num1, num2;
	for (; int count = scanf_s("%d %d", &num1, &num2);)
	{
		printf("%d\n", count);
		while (getchar() != '\n');
	}

	//for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2)
	//{
	//	printf("%d ", i);
	//	printf("%d\n", j);
	//}

	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		break;

	//	printf("%d ", i);
	//}

	//printf("\n");


	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		continue;

	//	printf("%d ", i);
	//}

	//printf("\n");

	//for (int c = 'A'; c <= 'Z'; c++)
	//	printf("%c ", c);

	//printf("\n");

	//for (int c = 'Z'; c >= 'A'; c--)
	//	printf("%c ", c);

	//printf("\n");

	//int total = 0;
	//int num = 0;

	//printf("0���� num������ ���� ���ϱ�. num : ");
	//scanf_s("%d", &num);

	//for (int i = 0; i <= num; i++)
	//{
	//	total += i;
	//}
	//printf("0���� %d������ ���� = %d\n", num, total);

//for (int i = 0; i < 5; i++)
//{
//	for (int j = 0; j < 5; j++)
//	{
//		printf("*");
//	}
//	printf("\n");
//}
//
//for (int i = 2; i < 10; i++)
//{
//	printf("***������ %d�� ����!***\n", i);
//
//	for (int j = 1; j < 10; j++)
//	{
//		printf("%d * %d = %d\n", i, j, i * j);
//	}
//	printf("***������ %d�� ��!***\n\n", i);
//}
	return 0;
}