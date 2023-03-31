#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//c����� �����Ҵ�
//malloc : �����Ҵ�  => �츮�� ���� �Ҵ����ְ� ���� ������ ��� ��(�ȱ׷� �޸� ������ �Ͼ). �׷��� �� Ÿ�Ӷ� ũ�Ⱑ �����ȴ�. (�ݴ� ���� ������ �߿� ũ�Ⱑ ������)


void dynamic_allocation();
char* scanName();


char name[30]; //���� �ذ��� ���� ���� ������ �������� �ذ��

char* readName()//�̸���  ���� �о���� �Լ��� ����� ����.
{
	/*char name[30];*/
	printf("�̸��� �Է��Ͻÿ� : ");
	gets(name); //������ �����ؼ� �޾ƿ��� ��.

	return name;
}

//�Լ��� ���ٰ� ���͵� ���� �����ǰ� �� �������� ����� �ؾ� �ϴ� ���� �۾��� ���� �ʾƵ� �Ǵ� �� "���� �Ҵ�"!

int main()
{
	//{
	//	char* name1;
	//	char* name2; 

	//	name1 = readName();
	//	printf("name1 : %s\n", name1);

	//	name2 = readName(); //�� �Լ��� ������ ���� �޸� �Ҵ��� �����Ǿ� 
	//	printf("name2 : %s\n", name2); //����ؼ� ����� ���� �ȳ����Ե�. (���� ���� ������ ���)
	//}

	//dynamic_allocation();
	{
		char* name = scanName();

		printf("name : %s\n", name);

		free(name);
		name = NULL;
	}
	
	return 0;
}

//	<����>
// ���� ����(https://www.acmicpc.net/problem/2798)
//
//��� ���, �ȵǸ� for�� ���
//
//brute(������) ��� ��츦 Ȯ���ϰڴٴ� ��

void dynamic_allocation() //�츮�� �ּҿ� ���� ������ �ϱ� ���ؼ��� �����͸� ��� ��.
{
	//malloc
	{
		int* ptr = NULL;
		int num = 5;

		ptr = (int*)malloc(sizeof(int) * num); //int �� ������, int��¥���̰� ���̰�  num�� ���� �Ҵ��ϰڴٴ� ��


		if (ptr == NULL)
		{
			printf("�޸� �Ҵ� ����!!\n");

			exit(EXIT_FAILURE); //exit(0);�̶� ����  0�̸� ���� ����, 1�̸� �������ٴ� �� => 1
			//exit(EXIT_SUCCESS); //���� ��ȯ => 0
		}

		printf("Before dfree 0x%p\n", ptr);

		free(ptr); //�Ҵ��� �����ϴ� ��

		printf("After dfree 0x%p\n", ptr); //���� �������� �ּҰ� ��µ� => ��� ������(dangling pointer) : ������ ������ ����Ű�� �ִ� ������

		ptr = NULL; //�׷��� NULL�� �ʱ�ȭ���� ����� ��.

		printf("After dfree 0x%p\n", ptr); //���� �����
		
		
		//free�ϰ� NULL�� �ʱ�ȭ �ι��ϱ� �������� define���� ���� ���� ����. => free�� �ص� NULL�ʱ�ȭ���� �ǰԲ�.
#define FREE(ptr) if(ptr != NULL) {free(ptr); ptr = NULL;}
	}


	//calloc
	{
		int size = 0;

		printf("���� �Ҵ� �� int�� ������ �޸� ���� �Է� => ");
		scanf_s("%d", &size);

		int* ma, * ca;
		ma = (int*)malloc(sizeof(int) * size);
		ca = (int*)calloc(size, sizeof(int)); // �ַϰ� ���°� �ٸ��� �����. �ؼ��� �ణ �ٸ� �� ����

		printf("\n�ʱ�ȭ ��\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n",   i, ma[i]); //�����Ⱚ
			printf("ca[%d] : %d\n\n", i, ca[i]); //0
		}
		//malloc�� �ʱ�ȭ�� �ȵż� ������ ���� ������ calloc�� �ʱ�ȭ�� �ڵ����� �Ǿ 0�� ���� => �ϴ� ������� �ȳ����� 0���� �ʱ�ȭ �ϴ� �ǰ�?

		for (int i = 0; i < size; i++) //�׷��� malloc�� �ʱ�ȭ�� �Ŀ��� ����� �Ѵ� 0���� ����
		{
			ma[i] = 0;
		}

		printf("\n�ʱ�ȭ ��\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n", i, ma[i]); //0
			printf("ca[%d] : %d\n\n", i, ca[i]); //0
		}

		//�ּ� �ʱ�ȭ�� �ʼ��� �� ������!
		free(ca);
		ca = NULL;

		free(ma);
		ma = NULL;
	}

	//realloc
	{
		//�̹� �Ҵ��� �Ŀ� ���� Ȯ���� �ϰ� ������ ���
		int size = 0;

		printf("���� �Ҵ� �� double�� ������ �޸� ���� �Է� => ");
		scanf_s("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr�� �Ҵ���� �ּ� : %p\n", ptr);

		for (int i = 0; i < size; i++)
			printf("ca[%d] : %lf\n", i, ptr[i]);

		printf("���Ҵ� �� double�� ������ �޸� ���� �Է� => ");
		scanf_s("%d", &size);

		ptr = (double*)realloc((double*)ptr, size);
		printf("\nptr�� ���Ҵ���� �ּ� : %p\n", ptr);

		for (int i = 0; i < size; i++)
			printf("ca[%d] : %lf\n", i, ptr[i]); //���Ҵ�� ������ �ʱ�ȭ�� �ȵ�. Ȯ���Ҷ� �ڿ� �ٸ� �Ҵ�� �޸𸮶� ���޾� ��������� �ʴ´ٸ� ���޾� ����� �ִ� ���ο� �ּҸ� ã�� ���Ҵ�Ǳ⵵ ��.

		printf("\n");

		free(ptr);
		ptr = NULL;
	}
	{
		int n = 5;
		double* ptr = (double*)malloc(n * sizeof(double));

		if (ptr != NULL)
		{
			for (int i = 0; i < n; i++)
				printf("ptr[%d] : %lf\n", i, ptr[i]);

			printf("\n");

			for (int i = 0; i < n; i++) //������ ����
				*(ptr + i) = (double)i;

			for (int i = 0; i < n; i++)
				printf("ptr[%d] : %lf\n", i, ptr[i]);
			printf("\n");

			free(ptr);
			ptr = NULL;
			
		}
	}


	//���� ����ȭ ���� : �޸� ���� ������ ��������� �������� ©�� �־ (����üó�� �������� �Ҵ� ������) �Ҵ��� �Ұ��� ����
	//�ܺ� ����ȭ ���� : �����Ҵ��� �ϸ鼭 �Ҵ�, ������ �ݺ��ϸ鼭 ���̻��� ƴ�� ���ܼ�. ������ ����ѵ� �Ҵ��� �Ұ��� ����
	//��� ������ || �޸� ���� ���� : �����Ҵ� �� �޸� �Ҵ� ������ ���ؼ�. �����Ͱ� �Ҵ� ������ ������ ����Ű�� ���� || �� ������ŭ�� �� ����ϴ� ����.
	
}

char* scanName()
{
	char buffer[100] = { 0 };

	printf("�̸��� �Է��Ͻÿ� : ");
	gets(name); 
	//scanf_s("%s", buffer, sizeof(buffer)); �� ����

	int size = strlen(buffer) + sizeof((char)('\0')); //���� ���� + NULL�������� ������

	if (size == sizeof((char)('\0')))
		return NULL;

	char* name = (char*)calloc(size, sizeof(char));

	if (name != NULL)
		strcpy_s(name, size, buffer);

	return name;
}
