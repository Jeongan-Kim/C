#include <stdio.h>

//두 수를 입력받아 최대공약수와 최소공배수를 출력하시오.


int main()
{
	int div_num; //약수
	int A, B; // 입력받은 두 수
	int G = 1; //최대공약수
	int L = 1; //최소공배수

	printf("최대공약수와 최소공배수를 구할 두 수를 입력하세요. : ");
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
	printf("최대공약수는 %d이고, 최소공배수는 %d입니다.\n", G, L);
	return 0;
}

