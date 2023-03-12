#include <stdio.h>

#define ROWS 5
#define COLS 3

void Score();
void floor();
void board();

int main()
{
	//Score();

	//floor();

	board();


	return 0;
}

void Score()
{
	int score[ROWS][COLS] = { {85, 60, 70}, {90, 100, 80}, {50, 60, 70},
		{70, 80, 68}, {40, 90, 100} };
	int totalKor = 0, totalEng = 0, totalMath = 0;
	int koravg = 0, engavg = 0, mathavg = 0;

	for (int i = 0; i < ROWS; i++)
	{
		totalKor += score[i][0];
		totalEng += score[i][1];
		totalMath += score[i][2];
	}
	printf("\n±¹¾î ÃÑÁ¡\t¿µ¾î ÃÑÁ¡\t¼öÇÐ ÃÑÁ¡\t\n");
	printf("%d\t\t%d\t\t%d\t\n", totalKor, totalEng, totalMath);

	koravg = totalKor / ROWS;
	engavg = totalEng / ROWS;
	mathavg = totalMath / ROWS;

	printf("\n±¹¾îÆò±Õ\t¿µ¾îÆò±Õ\t¼öÇÐÆò±Õ\t\n");
	printf("%d\t\t%d\t\t%d\t\n", koravg, engavg, mathavg);

	int student[5] = { 0 };

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			student[i] += score[i][j];
		}
		printf("%d¹øÂ° ÇÐ»ýÀÇ ÃÑÁ¡ : %d\n", i + 1, student[i]);
	}

	float studentavg[5] = { 0 };
	
	for (int i = 0; i < ROWS; i++)
	{
		studentavg[i] = student[i] / COLS;
		printf("%d¹øÂ° ÇÐ»ýÀÇ Æò±Õ : %f\n", i + 1, studentavg[i]);
	}
	printf("\n");
}

void floor()
{
	int floor[3][3];
	int floor1[3] = { 0 };
	int total = 0;

	for (int i = 0; i < 3; i++)
	{
		printf("*** %d Ãþ ***\n", i + 1);
		for (int j = 0; j < 3; j++)
		{
			printf("%dÃþ %dÈ£ ÀÎ±¸ ¼ö : ", i + 1, j + 1);
			scanf_s("%d", &floor[i][j]);
		}

		for (int j = 0; j < 3; j++)
		{
			floor1[i] += floor[i][j];
		}
	}
		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			printf("%dÃþ ÀÎ±¸¼ö : %d¸í", i + 1, floor1[i]);
		}
		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			total += floor1[i];
		}
		printf("ÃÑ ÀÎ±¸¼ö %d\n", total);
	
}

void board()
{
	int board[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			board[i][j] = 5 * j + i;
		}
	}

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
}
