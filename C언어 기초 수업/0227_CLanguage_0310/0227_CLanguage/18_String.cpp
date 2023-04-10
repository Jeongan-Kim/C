#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void string();

//void my_strlen;// ��� ������ �ҷ��ͼ� ���� �ʰ� �Լ��� ���� ������.(4����)

int main()
{
	string();
	char str[100] = "hello C language"; //���� �ϳ� �ʱ�ȭ�� '', ���ڿ� �ʱ�ȭ�� "". ���ڿ��� �����ٴ� ���� ��ǻ�Ϳ��� �˷���� ��.

	printf("strlen : %d\n", strlen(str)); //���ڿ��� ���̸� ���ִ� �Լ�(strlen) ������ ���������� ������ NULL�� �Ȼ�����.

	char str1[20];
	printf("strcpy : %s\n", strcpy(str1, str)); //str�� ���ڸ� str1�� �����ؼ� �־��ֶ�� �Լ�.

	str[0] = 'z';
	printf("strcmp : %d\n", strcmp(str, str1)); //���ڿ� �� �Լ�, -1, 0, 1, �� ���ڿ��� �� ū �ڵ带 ������ 1.

	printf("strscat : %s\n", strcat(str, str1)); //str�ڿ� str1����������, NULL�����ϰ� ���ڿ� ��ġ�� �������� NULL�߰�����.

	return 0;
}

void string() //���ڿ��� �����ٴ� ���� ��ǻ�Ϳ��� �˷���� ��. �� ����� ���������� ����
{
	char var1 = '\0';
	char var2 = 0;
	char var3 = (char)NULL;

	char notNULL = '0'; //�ƽ�Ű �ڵ尡 �����.

	printf("%d %d %d\n", var1, var2, var3);
	printf("%d\n", notNULL);

	{
		char hello[] = { 'H', 'e', 'l', 'l', 'o' };

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]);

		printf("\n%s\n", hello); //���ڿ� print������ %s, �����ٴ� ���� �Ⱦ˷��༭ �̻��ϰ� ����.

		hello[4] = '\0'; // �������� �����ٴ� NULL ���ڸ� ��.
		printf("\n%s\n", hello);
	}
	{
		char hello[] = "Hello"; // ���ڿ��� �ʱ�ȭ�ϸ� �ڵ����� �迭�� ������ ���� NULL�� ������ �� ���̵�.
		printf("\n%s\n", hello);
	}
}
