#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void string();
int my_strlen(char str[]);
void my_strcpy(char dest[], int count, char src[]); //dest : ������
void my_strcat(char dest[], int count, char src[]);
int my_strcmp(char str1[], char str2[]);

//void my_strlen;// ��� ������ �ҷ��ͼ� ���� �ʰ� �Լ��� ���� ������.(4����)

int main()
{
	//string();
	//char str[100] = "hello C language"; //���� �ϳ� �ʱ�ȭ�� '', ���ڿ� �ʱ�ȭ�� "". ���ڿ��� �����ٴ� ���� ��ǻ�Ϳ��� �˷���� ��.

	//printf("strlen : %d\n", strlen(str)); //���ڿ��� ���̸� ���ִ� �Լ�(strlen) ������ ���������� ������ NULL�� �Ȼ�����.

	//char str1[20];
	//printf("strcpy : %s\n", strcpy(str1, str)); //str�� ���ڸ� str1�� �����ؼ� �־��ֶ�� �Լ�.

	//str[0] = 'z';
	//printf("strcmp : %d\n", strcmp(str, str1)); //���ڿ� �� �Լ�, -1, 0, 1

	//printf("strscat : %s\n", strcat(str, str1)); //str�ڿ� str1����������, NULL�����ϰ� ���ڿ� ��ġ�� �������� NULL�߰�����.

	//my_string
	{
		//strlen
		//char str[100] = "Hello";
		printf("%d\n", my_strlen("Hello")); // " "���·� �������� �־ �迭�� �ν���(C���������� ����)
		
		//strcpy
		char dest[9] = "";
		char src[] = "Hello";

		my_strcpy(dest, 9, src);

		printf("mystrcpy : %s\n", dest);

		//strcat
		char dest1[9] = "Cat";
		char src1[] = "Dog";

		my_strcat(dest1, 9, src1);
		printf("mystrcat : %s\n", dest);

		//strcmp
		char string[2][9] = { "Hello", "Hello" };

		printf("%s %s\n", string[0], string[1]);

		printf("mystrcmp : %d\n", my_strcmp(string[0], string[1]));
	}
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

int my_strlen(char str[])
{
	int count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}

void my_strcpy(char dest[], int count, char src[])
{
	int srcLength = my_strlen(src);

	if (srcLength < count)
		for (int i = 0; i <= srcLength; i++)
			dest[i] = src[i];
}

void my_strcat(char dest[], int count, char src[])
{
	int destLength = my_strlen(dest);
	int srcLength = my_strlen(src);

	if (destLength + srcLength < count)
		for (int i = 0; i <= srcLength; i++)
			dest[destLength + i] = src[i];
}

int my_strcmp(char str1[], char str2[])
{
	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
	{
		if (str1[i] > str2[i]) return +1;
		else if (str1[i] < str2[i]) return -1;
		//else return 0;
	}
	return 0;
}
