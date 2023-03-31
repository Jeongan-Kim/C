#include <stdio.h>

void MakeSnail(int num, int arr[][10]); //�ִ� ũ�� 10, 10. �� �̻��� ���� ���� ����
void PrintSnail(int num, int arr[][10]);

int main()
{
	int num = 0;
	int arr[10][10] = { 0 };

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	MakeSnail(num, arr);
	PrintSnail(num, arr);

	return 0;
}

void MakeSnail(int num, int arr[][10])
{
	int direction = 1; // ����
	int count = 0; //�� ��
	int row = -1; //���� �ε���
	int column = 0; //���� �ε��� => direction ���� ���ϸ鼭 ����� �� ����

	while (1)
	{
		for (int i = 0; i < num; i++)
		{
			row += direction;
			arr[column][row] = ++count; //[0][0] [0][1] [0][2] [0][3] [0][4]
		}

		num--; //5�� ���� �� ������ 4���̹Ƿ�

		if (num == 0) break;

		for (int i = 0; i < num; i++)
		{
			column += direction;
			arr[column][row] = ++count; //[1][4] ... [4][4]
		}

		direction = -direction; //�̷��� �ϸ� �� for���� �ٽ� ���� ��, �� �ε����� �����ϰ� �ȴ�.
	}
}

void PrintSnail(int num, int arr[][10])
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf(" %3d", arr[i][j]); //3d => �� �տ� 3�ڸ� ������ �ֵ�, ���� �ڸ����� Ŀ���� �� ���鿡 ä������ ��.
		}
		printf("\n");
	}
}
