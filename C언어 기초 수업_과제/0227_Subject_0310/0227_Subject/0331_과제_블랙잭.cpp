#include <stdio.h>

int N, M;
int arr[100];
int answer = 10;
int* pAnswer = &answer;

int Blackjack(int A, int B, int C, int arr[100], int M)
{
	int Add = arr[A] + arr[B] + arr[C];

	if (Add <= M && answer < Add)
		*pAnswer = Add;
	
	if (A == 2 && B == 1 && C == 0)
		return answer;

	if (C == 0 && B != 1)
		return Blackjack(A, B - 1, B - 2, arr, M);
	else if (B == 1 && C == 0)
		return Blackjack(A - 1, A - 2, A - 3, arr, M);
	else
		return Blackjack(A, B, C - 1, arr, M);
}

int main()
{	
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);

	Blackjack(N-1, N - 2, N - 3, arr, M);
	printf("%d", answer);

	return 0;
}