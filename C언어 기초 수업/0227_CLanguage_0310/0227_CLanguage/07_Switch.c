#include <stdio.h> //# : �� ó����, �� ���α׷��� �����ϱ� ���� ������ �ּ��� ��� ��

//��ũ�� ���(�� ���ڸ� �� ���ڷ� ġȯ) : �ڵ�� �˾ƺ��� ���� ����� �� �߿��ϱ� ������ �̸� ����ϸ� ����
#define Game 1
#define GameManual 2
#define Option 3
#define Exit 4
/*
	switch(����) //break�� ������ ������ ������ �Ǵ� �Լ�
	{
	case �� :
		���;
		break;
	case ��2 : 
		���;
		break;
	default :
		���� ��� ó��;
		break;
	}

*/

int main()
{
	//int selmenu;
	//printf("�޴��� �����ϼ��� [1. ���� ����, 2. ���� ����, 3. ���� 4. ����]"); //������ �� ������ �ƴ϶� ���� ������ ���������� switch���� ��
	//printf("\n�Է� : ");
	//scanf_s("%d", &selmenu);

	//switch (selmenu)
	//{
	//case 1:
	//	printf("\n������ �����մϴ�\n");
	//	break;
	//case 2:
	//	printf("���� ����\n");
	//	break;
	//case 3:
	//	printf("���� ����\n");
	//	break;
	//case 4:
	//	printf("���� ����\n");
	//	break;
	//default:
	//	printf("�߸� �Է��ϼ̽��ϴ�\n");
	//	break;
	//}

	//char selmenu;
	//printf("�޴��� �����ϼ��� [1. ���� ����, 2. ���� ����, 3. ���� 4. ����]"); //������ �� ������ �ƴ϶� ���� ������ ���������� switch���� ��
	//printf("\n�Է� : ");
	//scanf_s(" %c", &selmenu);

	//switch (selmenu)
	//{
	//case Game:
	//	printf("\n������ �����մϴ�\n");
	//	break;
	//case GameMenual:
	//	printf("���� ����\n");
	//	break;
	//case Option:
	//	printf("���� ����\n");
	//	break;
	//case Exit:
	//	printf("���� ����\n");
	//	break;
	//default:
	//	printf("�߸� �Է��ϼ̽��ϴ�\n");
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
	{
		printf("�߸� �Է��Ͽ����ϴ�\n");
	}

	switch (number)
	{
	case 1:
		printf("����\n");
		break;
	case 2:
		printf("����\n");
		break;
	case 3:
		printf("����\n"); //�� ������ ��� �극��ũ ���� �Ƚ���..(?)
	default:
		break;  //������ ���� ������ �׳� �극��ũ�� �ɾ ��
	}
	return 0;
}