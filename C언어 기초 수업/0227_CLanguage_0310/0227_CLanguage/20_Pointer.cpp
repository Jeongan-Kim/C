#include <stdio.h>

//������ : �ּҶ�� �����ϸ� ����, �̸��̳� �� �ּ� ��� ���� �ּҰ� ����(16������) , �����͵� ũ�Ⱑ ����
//������ ���� : �������� ���� �Է��ϴ� ����/ 4byte(x86), 8byte(x64)

int main()
{
	int num = 7;
	int* pnum; //������ �ѹ� ������ ����
	pnum = &num; //num�� �ּ�(���� �κ���)�� ������ ������ �ְ� ���� num�� �ǵ帱 ����.

	//int* pnum1 = &5;  ������ �־���� �ּҰ��� �����.

	printf("%d\n", *pnum);
	printf("%d\n\n", num);

	*pnum = 20; //*pnum == num //������ ������ ����Ű�� ���� ���� �ʱ�ȭ

	printf("%p\n", pnum); //%p�� �ּҰ�
	printf("%d\n", *pnum);
	printf("%d\n", num);
	printf("%p\n", &num);
	printf("%d\n", (int)sizeof(pnum));

	int* ptr; //�����Ⱚ���� �ʱ�ȭ��. �ǹ̰� ����. ���߿� �ʱ�ȭ�� �� �ְ� ������ NULL�� �ʱ�ȭ�س����� ��.
	int* ptr = NULL;


	return 0;
}