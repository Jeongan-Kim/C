#include <stdio.h>
#define Game 1
#define GameManual 2
#define Option 3
#define Exit 4

int main()
{
	//short s1 = 10;
	//int i = s1;

	//float f1 = 100;
	//printf("%f\n", f1);

	//int i2 = 500;
	//unsigned char c1 = i2;
	//printf("%d\n", c1);

	//float f2 = 1.25f;
	//int i3 = f2;
	//printf("%d\n", i3);

	//int a = 10, b = 4;
	//float div = (float)a / b; //a�� ����� ����ȯ�� �� ���̰�, b�� �ڵ� ����ȯ�� �� ���̴�. �� �� ū ������ �ٲ�.
	//printf("%f\n", div);

	//int number = 0;
	//printf("������ �Է��� �ּ��� : ");
	//scanf_s("%d", &number);

	//if (number % 2 == 0)
	//	printf("¦��\n");
	//else
	//{
	//	printf("¦���� �ƴϳ׿�\n");
	//	printf("Ȧ��\n");
	//}

	//char key;

	//printf("��� �������� ���ðڽ��ϴ�? : ");
	//scanf_s(" %c", &key, sizeof(key));

	//if (key == 'w')
	//	printf("��");
	//else if (key == 's')
	//	printf("�Ʒ�");
	//else if (key == 'a')
	//	printf("����");
	//else if (key == 'd')
	//	printf("������");
	//else
	//	printf("�߸� �Է��Ͽ����ϴ�.");

	//int number2;
	//printf("���ڸ� �Է��� �ּ��� : ");
	//scanf_s("%d", &number2);
	//if (number2 < 10)
	//{
	//	if (number2 <= 5)
	//		printf("5���� �۰ų� ���� ��");
	//	else
	//		printf("5���� ũ�� 10���� ���� ��");
	//}
	//else
	//	printf("10���� ũ�ų� ���� �� �Դϴ�.");

	//char c1, c2;
	//int d;

	//printf("���ڸ� �Է��Ͻÿ� : ");
	//scanf_s("%c", &c1);

	//printf("������ �Է��Ͻÿ� : ");
	//scanf_s("%d", &d);

	//getchar();

	//printf("���ڸ� �Է��Ͻÿ� : ");
	//scanf_s("%c", &c2);

	//printf("c1 : %c\n, d : %d\n, c2 : %c\n", c1, d, c2);

	//char c3;
	//scanf_s("%c", &c3);
	//printf("%c", c3);


	//int selmenu;
	//printf("�޴��� �����ϼ���. [1. ���ӽ���, 2. ���� ����, 3. ����, 4. ����]");
	//scanf_s("%d", &selmenu);

	//switch (selmenu)
	//{
	//	case 1:
	//		printf("������ �����մϴ�.");
	//		break;
	//	case 2:
	//		printf("���� ������ ���ϴ�.");
	//		break;
	//	case 3:
	//		printf("���� ����");
	//		break;
	//	case 4:
	//		printf("������ �����մϴ�.");
	//		break;
	//	default:
	//		printf("�߸� �Է��Ͽ����ϴ�.");
	//		break;

	//}

	
	//int selmenu;
	//printf("�޴��� �����ϼ���. [1. ���ӽ���, 2. ���� ����, 3. ����, 4. ����]");
	//printf("\n�Է� : ");
	//scanf_s("%d", &selmenu);

	//switch (selmenu)
	//{
	//case Game:
	//	printf("������ �����մϴ�.");
	//	break;
	//case GameManual:
	//	printf("���� ������ ���ϴ�.");
	//	break;
	//case Option:
	//	printf("���� ����");
	//	break;
	//case Exit:
	//	printf("������ �����մϴ�.");
	//	break;
	//default:
	//	printf("�߸� �Է��Ͽ����ϴ�.");
	//	break;

	//}


int time = 0;
int number = 0;

printf("�ð��� �Է��� �ּ��� : ");
scanf_s("%d", &time);

if (time < 12)
{
	number = 1;
}
else if (time > 12)
{
	number = 2;
}
else if (time == 12)
{
	number = 3;
}
else
printf("�߸� �Է��Ͽ����ϴ�.\n");

switch (number)
{
case 1:
	printf("����\n");
	break;
case 2:
	printf("����\n");
	break;
case 3:
	printf("����\n");
	break;
default:
	break;
}
	return 0;
}