#include <stdio.h>

//�� ���� �Է¹޾� �ִ������� �ּҰ������ ����Ͻÿ�.


int main()
{
	int div_num; //���
	int A, B; // �Է¹��� �� ��
	int G = 1; //�ִ�����
	int L = 1; //�ּҰ����

	printf("�ִ������� �ּҰ������ ���� �� ���� �Է��ϼ���. : ");
	scanf_s("%d %d", &A, &B);

	printf("\n");

	for (int i = 2; i < A;)
	{
		div_num = i;
		if (A % div_num == 0 && B % div_num == 0)
		{
			G *= div_num;
			L *= div_num;
			A /= div_num;
			B /= div_num;
		}
		else
			i++;
		
	}
	L *= A * B;
	printf("�ִ������� %d�̰�, �ּҰ������ %d�Դϴ�.\n", G, L);
	return 0;
}

