#include <stdio.h>

int main()
{
	//�ڵ� ����ȯ
	//���� �� ū ������ ������(������ �ս��� ���� �� �ִ�.)
	short s1 = 10;
	int i = s1; //��ǻ�Ϳ��� �ڵ� ����ȯ�� �Ǿ� s�� int�� ��ó�� �� = (int)s1

	float f1 = 100; //100�� int�������� float������ �� = (float)100
	printf("%f\n", f1); //�Ǽ��� ��Ȯ�ϰ� ǥ���� ����� ������ 100.00000�̶�� ��


	//ū �� ���� ������ ������
	int i2 = 500;
	unsigned char c1 = i2; //unsigned char�� 0~255�̹Ƿ� ���ļ� ������ �ս��� ��
	printf("%d\n", c1);

	float f2 = 1.25f;
	int i3 = f2; //�Ҽ��� �Ʒ� ���� ������ �ȴ�.
	printf("%d\n", i3);



	/*
	Ranking of types operations
	-long double > double > float
	-unsigned long long == long long
	-unsigned long == long
	-unsigned int == int
	-unsigned short == short
	-unsigned char == char //1byte
	-bool //1bit
	
	*/

	//����� ����ȯ
	//int a = 10, b = 4;
	//float div = a / b;  //a�� b�� �� ��ȯ���� �ؼ� ���� Ʋ��
	//printf("%f\n", div);

	int a = 10, b = 4;
	float div = (float)a / b; //���Ƿ� float������ ��ȯ(����� ����ȯ), �������̱⿡ ���� �͸��� �ƴ�
	printf("%f\n", div);

	return 0;
}