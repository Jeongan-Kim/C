#include <stdio.h> //ǥ�� ����� ����
#include <stdbool.h> //standard bool

/*
	Data Type(�ڷ���)
*/

/*
	bit�� byte
	bit : ���� ���� ������ ����
	byte : 1byte == 8bit, �� �� �ڸ� ũ��
*/

/*
	char
	int
	longlong
	float
	double
	long double
*/
int main()
{
	//char : �� ���ڸ� ǥ���� �� ��� - 1byte
	char c1 = 'A';//���ڸ� ���� ������ ���� ����ǥ�� ��� ��
	char c2 = 65; //ASCII(�ƽ�ƽ)�ڵ带 ���� ���ڸ� ��ǻ�Ͱ� ���ڷ� �ؼ���

	printf("Character c1 : %c\n", c1);
	printf("Character c2 : %c\n", c2);
	printf("Character size : %d\n", sizeof(char)); //sizeof �� �� ��ü�� ũ��(byte)�� ��Ÿ��
	printf("Character size : %d\n", sizeof(c1));

	//������
	short s = 1; //2byte (-32768 ~ +32767)
	int num = 0; //4byte (-21�� ~ +21��)
	printf("num : %d\n", num);
	printf("int size : %d\n", sizeof(int));

	//�Ǽ��� - �ε�(���� ���ƴٴѴ�)�Ҽ��� ���
	float f = 0.123f; //4byte, f�� ���� �ٿ���� ��
	double d = 0.1234; //8byte, double�� float���� �⺻���̱⿡ �׳� ����

	printf("���� �Ҽ��� : %f\n", f);
	printf("�ε� �Ҽ��� : %e\n", f); //�ε��Ҽ����� ǥ���ϴ� ���ĺ��� e

	//�ε� �Ҽ����� ����
	float sum = 0.1f;

	for (int i = 0; i < 1000; i++) //�ݺ���, 0.1�� 1000�� ���Ѵٴ� ��
	{
		sum += 0.1;
	}

	printf("%f\n", sum);


	//����
	bool isDash = true; //1byte
		//bool isDash = false��� �ϸ� �Ʒ� 0�� ��µ� ����

	printf("ĳ���� �뽬 ���� : %d\n", isDash);

	unsigned char c3; //��� ������ �������� �ʰ� ���� �ι� �Ҹ��� �� 0 ~ 255
	unsigned int i2; //0 ~ 42��

	//char cc = 129;
	//printf("%d\n", cc);
	//char���� 127�����ۿ� ���� ������ ���ļ� -127�� ���´�.

	unsigned char cc = 129;
	printf("%d\n", cc);

	signed int ii;

	return 0; //int main�̱� ������ ���������� ��ȯ�Ͽ� ���α׷��� �����ڴٴ� ��
}

/*
	<���� ����>
	ASCII �ڵ尡 � ������� �̷���� �ִ���, � ������ �����ϱ�
	��ǻ���� �Ǽ� ǥ�� ���

*/