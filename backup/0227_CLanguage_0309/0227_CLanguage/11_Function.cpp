#include <stdio.h>

//�Լ� �����()
//{
//	�Լ� ���Ǻ�
//}

//��������x ��ȯ��o �Լ�
int getInt(void) //�ߺ��Ǵ� ������ �Լ��� ȣ���ؼ� ���� ���� ���� ��
{
	printf("���ڸ� �Է����ּ��� : ");

	int n;
	scanf_s("%d", &n);

	return n;
}

//��������o ��ȯ��o
int add(int x, int y)
{
	//int result = x + y;
	//return result;

	return x + y;  //��� ���� �ٷ� ��ȯ������ �־��൵��
}

//��������o ��ȯ��x �Լ�
void ShowNumber(int num)
{
	printf("���� ���� : %d\n", num);
}

//��������x ��ȯ��x �Լ� : �״�� �׳� ��¸� ��
void test()
{
	printf("111111111111111111");

	return; //�� �ᵵ �Ǵµ� �Լ��� ���������ڴٴ� �ǹ̷� �׳� ���ϸ� ��.

	printf("222222222222222222"); //������ �Լ��� �������Ƿ� �̰� ����.
}

int Compare(int num1, int num2); /////////�Լ� ����� : main���� ����ϱ� ���ؼ��� ���� �� �����(�ؿ� ������ ��Ʈ�� .)


int main(void) //void : �ƹ��͵� ���ٴ� �ǹ�, ������, ���� ���ڰ� ���� �ڸ�
{
	int x1 = 0;
	int y1 = 0;

	//printf("���ڸ� �Է����ּ��� : ");
	//scanf_s("%d", &x1);

	//printf("���ڸ� �Է����ּ��� : ");   //������ ���� �������� �� �Լ��� ȣ���� ��
	//scanf_s("%d", &y1);

	x1 = getInt();
	y1 = getInt();

	printf("%d + %d = %d\n", x1, y1, add(x1, y1));

	int num = getInt();
	ShowNumber(num); //�Լ� ȣ�� ����� �Լ� �̸��� �Ұ�ȣ���� ��������, �������ڰ� �ִ� ��� �ȿ� �� �ֱ�

	test();

	printf("�� �� �� ū ����? %d\n", Compare(x1, y1));

	return 0;
}

int Compare(int num1, int num2) //////////�Լ� ���Ǻ� ( �ʹ� ������ main �Լ� ������ ���ִ� ��)
{
	if (num1 > num2)
		return num1;
	else
	return num2;
}
