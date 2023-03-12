#include <stdio.h>

/*
	��� �Լ�
	-��ȭ��

	4! = 4 3 2 1 = 4*3!
*/
void Recursive(int num) //��� �Լ�
{
	if (num == 0)
		return; //break�� �ݺ��������� ����ϴ� �򰥸��� ����

	printf("Hello to myself\n");
	Recursive(num - 1); // �� �ȿ��� �ٽ� ���� ȣ���ϴ� �� (���� �Լ��̱⿡ ���� ������ �ʿ���)
}

int Factorial(int n)
{
	/*
		n*(n-1)*(n-2)*(n-1)* ... *(n-(n-2))*2*1
		=>n*(n-1)!		
	*/

	if (n == 0)
		return 1;

	return n * Factorial(n - 1); //�ڱ� �ڽ��� ȣ�������ν� �ݺ��Ǹ鼭 ���� �پ ���� ���丮�� �Լ�ó�� �����.
}

int main()
{
	Recursive(3);

	int n;
	scanf_s("%d", &n);

	printf("%d", n, Factorial(n));

	return 0;
}