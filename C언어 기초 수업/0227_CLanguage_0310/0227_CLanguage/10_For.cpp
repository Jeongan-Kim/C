//#define _CRT_SECURE_NO_WARNINGS  //scanf ���� �ȳ��� ���ִ� ��
//#pragma warning(disable:4996) 
#include <stdio.h>

//��ɹ� ���� Ƚ���� �����ְ� ������ ����ϴ� �Լ� for
/*
	for(�ʱ��; ���ǽ�; ������(����))  //���ǽ��� �����̸鼭 bool�Լ���� ���� ��
	{
		��ɹ�;
	}
*/
int main()
{
	//for (int i = 0; i < 5; i++) //0���� �����ϴ� �Ϳ� �ͼ�������, ���� ������ ��ȣ �ȿ��� �ѹ��� �� �� ����. ��ȣ�� �����̶�� ���� ����
	//{
	//	printf("for�� ��ɾ� %d�� �ݺ���\n", i);
	//}

	//printf("\n");

	////bool => false : 0, true : 1    0�ܿ��� true�� �Ǵ��ϱ⵵ ��.

	//for (int i = 5; i; i--) //���ǽ��� true�� false�θ� �Ǵܵ�. i�� 0�̵Ǹ� false�� �Ǵ��Ͽ� ����
	//{
	//	printf("for�� ��ɾ� %d�� �ݺ���\n", i);
	//}

	//for (;;)
	//{
	//	printf("���ѷ���\n");

	//}

	//printf("\n");

	//���۰� �ȿ� �ԷµǸ鼭 �Է¹��� ������ ����ϸ鼭 for���� ���ư��� �ణ ���������� �Լ�
	//char num1, num2; 
	//for (; int count = scanf_s("%c %c", &num1, sizeof(num1), &num2, sizeof(num2));) 
	//{
	//	printf("%d\n", count);
	//	while (getchar() != '\n'); 
	//}

	//for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2)
	//{
	//	printf("%d ", i);
	//	printf("%d\n", j);
	//}

	//printf("\n");

	////3�� ����� ������ ���߱�
	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		break; //�ݺ��� �ȿ����� ����� �� �ִ� Ű����

	//	printf("%d ", i);
	//}

	//printf("\n");

	////3�� ����� ������ ����� �������� �ʰ� �� ���ٷ� �ٽ� ���ư�
	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		continue;  //�ݺ��� �ȿ����� ����� �� �ִ� Ű����

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

	/*
		��ø for�� // i�� 1�� ����, j�� ���� ��
	*/
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//
	////������
	//for (int i = 2; i < 10; i++)
	//{
	//	printf("***������ %d�� ����!***\n", i);
	//	
	//	for (int j = 1; j < 10; j++)
	//	{
	//		printf("%d * %d = %d\n", i, j, i * j);
	//	}
	//	printf("***������ %d�� ��!***\n", i);
	//}

	//���̾Ƹ�� ũ�Ⱑ �ٲ� ������

	/*

	���� 1�� ����
	���� 2�� -1 ���·� �þ

	*/

	int num;
	printf("���̾Ƹ�� ũ�� �Է� : ");
	scanf_s("%d", &num);

	for (int i = 0; i < (num / 2 + 1); i++)
	{
		for (int j = i; j < (num / 2 + 1); j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (i * 2 + 1); k++)// 0*0, 1*2, 2*3
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = (num / 2 + 1) - 1; i > 0; i--)
	{
		for (int j = i; j <= (num / 2 + 1); j++)
		{
			printf(" ");
		}
		for (int k = 0; k < ((i - 1) * 2 + 1); k++)
		{
			printf("*");
		}
		printf("\n");

		//abs ���� �Լ�
		printf(" 1 : %d\n", abs(1));
		printf("-1 : %d\n", abs(-1));


	return 0;
}

/*
	*
	**
	***
	****
	*****


	*****
	****
	***
	**
	*


	*****
	 ****
	  ***
	   **
		*

		*
	   **
	  ***
	 ****
	*****

	  *
	 ***
	*****
	 ***
	  *


*/