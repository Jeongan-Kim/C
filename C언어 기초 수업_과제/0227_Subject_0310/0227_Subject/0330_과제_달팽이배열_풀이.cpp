#include <stdio.h>

void MakeSnail(int num, int arr[][10]); //최대 크기 10, 10. 그 이상은 터질 수도 있음
void PrintSnail(int num, int arr[][10]);

int main()
{
	int num = 0;
	int arr[10][10] = { 0 };

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &num);

	MakeSnail(num, arr);
	PrintSnail(num, arr);

	return 0;
}

void MakeSnail(int num, int arr[][10])
{
	int direction = 1; // 방향
	int count = 0; //들어갈 수
	int row = -1; //가로 인덱스
	int column = 0; //세로 인덱스 => direction 값을 더하면서 만들어 줄 것임

	while (1)
	{
		for (int i = 0; i < num; i++)
		{
			row += direction;
			arr[column][row] = ++count; //[0][0] [0][1] [0][2] [0][3] [0][4]
		}

		num--; //5번 가고 그 다음은 4번이므로

		if (num == 0) break;

		for (int i = 0; i < num; i++)
		{
			column += direction;
			arr[column][row] = ++count; //[1][4] ... [4][4]
		}

		direction = -direction; //이렇게 하면 위 for문이 다시 돌때 열, 행 인덱스가 감소하게 된다.
	}
}

void PrintSnail(int num, int arr[][10])
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf(" %3d", arr[i][j]); //3d => 수 앞에 3자리 공백을 주되, 수가 자리수가 커지면 그 공백에 채워지게 함.
		}
		printf("\n");
	}
}
