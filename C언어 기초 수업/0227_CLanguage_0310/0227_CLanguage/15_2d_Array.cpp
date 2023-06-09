#include <stdio.h>

#define ROWS 5
#define COLS 3 //古滴稽 走舛

//切戟莫[楳][伸];

/*
 int arr[3];
 けけし
 => arr[2]

 2託据>
	int arr[3][5]

	けけけけけ
	けけけけけ
	けけけしけ
	五乞軒拭澗 尻紗旋生稽 煽舌鞠嬢 赤製

	=> arr[2][3] 2楳 3伸稽 羨悦

3託据>
	int arr[3][5][7]

*/

//initialize
int arrOne[10]; //掩戚亜 10昔 壕伸
int arrTwo[5][5]; //亜稽 室稽 掩戚亜 5昔 壕伸
float arrThree[3][3][3]; //亜稽 室稽 株戚亜 3昔 float莫 壕伸

int arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
//1 2 3
//4 5 6
int arr3[2][3] = { 1, 2, 3 };
int arr4[][3] = { 1, 2, 3 }; //楳精 持繰背辞 拙失 亜管
int arr5[][3] = { {1, 2}, {3, 4, 5}, {6} };//3楳 3伸促軒
//int arr6[2][] = { 1, 2, 3, 4, 5, 6 }; 伸精 持繰戚 照喫

void printArr();
void Score();
void floor();
void board();

int main()
{
	printArr();

	Score();

	//floor();

	board();

	int arr7[4][2];

	printf("壕伸税 穿端 郊戚闘 滴奄 : %d郊戚闘\n", sizeof(arr7));
	printf("壕伸税 1楳 郊戚闘 滴奄 : %d郊戚闘\n", sizeof(arr7[0])); // arr7[0] 精 1楳幻 啄嬢層 依

	printf("壕伸税 据社税 鯵呪 : %d\n", sizeof(arr7) / sizeof(int)); //sizeof(arr7[0][0])亀 亜管?
	printf("壕伸税 楳税 鯵呪 : %d\n", sizeof(arr7) / sizeof(arr7[0]));
	printf("壕伸税 伸税 鯵呪 : %d\n", sizeof(arr7[0]) / sizeof(arr7[0][0]));

	return 0;
}

#pragma region print_array
void printArr()
{
	//arr1
	printf("*** arr1 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//arr2
	printf("*** arr2 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//arr3
	printf("*** arr3 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}

	//arr4
	printf("*** arr4 ***\n");
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//arr5
	printf("*** arr5 ***\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr5[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

#pragma endregion

void Score()
{
	//楳 : 俳持, 伸 : 繊呪, 厩嬢 慎嬢 呪俳 授生稽 繊呪 走舛
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
	printf("\n厩嬢恥繊\t慎嬢恥繊\t呪俳恥繊\t\n");
	printf("%d\t\t%d\t\t%d\t\n", totalKor, totalEng, totalMath);

	koravg = totalKor / ROWS;
	engavg = totalEng / ROWS;
	mathavg = totalMath / ROWS;

	printf("\n厩嬢汝液\t慎嬢汝液\t呪俳汝液\t\n");
	printf("%d\t\t%d\t\t%d\t\n", koravg, engavg, mathavg);

	int student[5] = { 0 }; //俳持紺 恥繊

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			student[i] += score[i][j];
		}

		printf("%d腰属 俳持税 恥繊 : %d\n", i + 1, student[i]);
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
		printf("***%d寵 ***", i + 1);
		for (int j = 0; j < 3; j++)
		{
			printf("%d寵 %d硲 昔姥呪 : ", i + 1, j + 1);
			scanf_s("%d", &floor[i][j]);
		}
		for (int j = 0; j < 3; j++)
		{
			floor1[i] += floor[i][j];
		}

		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			printf("%d寵 昔姥呪 : %d誤", i + 1, floor1[i]);
		}

		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			total += floor1[i];
		}
		printf("恥 昔姥呪 %d\n", total);
	}
}

void board()  // 識持還 琶奄 溌昔
{
	int board[5][5];

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			board[x][y] = y * 5 + x; 
			// 0 5 10 15 20
			// 1 6 11 16 21 ...授生稽 脊径喫
		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			printf("%d\t", board[x][y]);
		}
		printf("\n");
	}

	printf("\n");

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			printf("%d\t", board[x][y]);
		}
		printf("\n");
	}
}

/*
1. 収切 醤姥 惟績 = 10腰 照拭 限備奄

陳濃斗 呪 3鯵, 鎧亜 薦獣廃 呪 3鯵
1 2 3
1 3 5 => 1strike 1ball => 戚杏 左壱 陳濃斗 収切研 限備澗 惟績
収切人 是帖亜 乞砧 旭生檎 什闘虞戚滴
収切澗 限澗汽 是帖亜 陥牽檎 瑳
焼森 陥牽檎 焼数

2. 杉害四 惟績

5  12 ?
?亜 5人 12 紫戚拭 級嬢亜澗 収切昔走 焼観走 溌昔馬澗 惟績
闘軍覗 朝球稽 馬奄(52舌=> 1~13亜 4舌梢 古腰 鹿走 省壱 廃腰 鹿製)
50000据 握壱 獣拙背辞 易 廃毒雁 1000据 戚雌 壕特, 限備檎 壕特廃 幻鏑 儀聖 骨.
儀戚 蒸暗蟹 朝球 52舌戚 乞砧 社遭鞠檎 惟績 魁

*/
