#include <stdio.h>

//����� �̸��� �ο��ϴ� ��

void myEnum();

int main()
{
	myEnum();
	return 0;
}

void myEnum()
{
	{ //��ũ�� ����� �ϴ� ��
	#define RED 0
	#define ORG 1
	#define YEL 2

		int c = 0;

		printf("���� �Է� : ");
		scanf_s("%d", &c);

		if (c == RED)
			printf("red\n");
		else if(c == ORG)
			printf("orange\n");
		else if(c == YEL)
		printf("yellow\n");
	}
	{
		enum color
		{
			Red, //0   
			Orange, //1 
			//Orange = 10( �Ǵ� a �ƽ�Ű�ڵ��)//�ƹ��ų� ���� ������ �ָ� �װ� �������� 1��ŭ ���ϰ� ���鼭 �˾Ƽ� ����
			Yellow //2 => �ϳ��� �����ϸ鼭 �����. 
		};

		int c = 0;

		printf("���� �Է� : ");
		scanf_s("%d", &c);

		if (c == Red)
			printf("red\n");

		if (c == Orange)
			printf("orange\n");

		if (c == Yellow)
			printf("yellow\n");

		for (c = Red; c <= Yellow; c++) //C������ ����, ���ڷ� �̾Ƽ� �� ���� ����, ��� ������ ����
			printf("%d, ", c);
	}
}


// ���� => ������ �迭 : �ε��� �ٲ㼭 ����ϴ� ���̵� �̿��ؼ� ���ۺ��� ���� ���