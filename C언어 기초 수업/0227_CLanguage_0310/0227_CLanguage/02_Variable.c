#include <stdio.h>

/*
Variable(����)
-���� �� �ִ� ������

Constant(���)
-������ �ʴ� ������(������)
*/

int main()
{
	//���� ���� ��� : Datatype name;
	int a; //int(integer, ����)�� ������ Ÿ��, ����(declaration)
	a = 10; //initialize(�ʱ�ȭ), =(���� ������) : ���ٴ� �ǹ̰� �ƴ϶� ����

	
	printf("%d\n", a);

	a = 11; //������ �ٲ� �� �����Ƿ� ���� ����, ���� �� ������ int ������� ����

	printf("%d\n", a);

	int b = 20; //����� ���ÿ� �ʱ�ȭ
	printf("%d\n", b);
	/*
	b�� �ʱ�ȭ�� ��
	b=20�� �´�
	int b = 20�̶�� �ϸ� ���� ������ �� ���� ���̶� ����

	*/
	b = 30;

	int result;
	result = a + b;
	printf("��� : %d\n", result);

	//���� ǥ���
	//�밡���� ǥ���(���� ���� �Ⱦ�)
	int i_age;
	int intweight;

	//���� ���� ���, hp�� count�� ���� ���� ���̹Ƿ� 3���� ������� �� �� �ִ�.
	int hpCount; //ī�� ǥ���(������ ����)
	int HpCount; //�Ľ�Į ǥ���(�Լ��� ����)
	int hp_count; //������ũ ǥ���

	int a1;
	//int 1a; ���� �տ� ���� �Ұ�
	//int 1 a; ���� ���� ���� �Ұ�
	//int for, int if (���߿� ������� �̷� �ܾ �� ��)

	return 0;
}