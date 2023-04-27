#include <iostream>
#include <math.h>

using namespace std;

int bingo[5][5];

void Swap(int sour1, int dest1, int sour2, int dest2, int** bingo)
{
	int temp = bingo[sour1][dest1];
	bingo[sour1][dest1] = bingo[sour2][dest2];
	bingo[sour2][dest2] = temp;
}

void shuffle(int n, int bingoSize, int** bingo) //n�� ����
{
	for (int i = 0; i < n; i++)
	{
		int sour1 = rand() % bingoSize;
		int dest1 = rand() % bingoSize;
		int sour2 = rand() % bingoSize;
		int dest2 = rand() % bingoSize;

		Swap(sour1, dest1, sour2, dest2, bingo);
	}
}

void Print(int** bingo, int bingoSize)
{

	for (int y = 0; y < bingoSize; y++)
	{
		for (int x = 0; x < bingoSize; x++)
		{
			if (bingo[x][y] != -1)
				printf("%d\t", bingo[x][y]);
			else
				printf("X\t");
		}
		printf("\n");
	}
}

bool Check(int bingoSize, int** bingo, int input)
{
	bool ischeck = false;

	for (int y = 0; y < bingoSize; y++)
	{
		for (int x = 0; x < bingoSize; x++)
		{
			if (input == bingo[x][y])
			{
				bingo[x][y] = -1;
				ischeck = true;
			}
		}
	}

	if (!ischeck)
	{
		printf("�ߺ��� �����Դϴ�.\n");
		return false;
	}

	return true;
}

void Count(int& bingocount, int bingoSize, int** bingo)
{
	bingocount = 0;

	for (int y = 0; y < bingoSize; y++)
	{
		int Xcount = 0;
		{
			for (int x = 0; x < bingoSize; x++)
			{
				if (bingo[x][y] == -1)
					Xcount++;
			}
		}

		if (Xcount == bingoSize) bingocount++;
	}

	for (int x = 0; x < bingoSize; x++)
	{
		int Ycount = 0;
		{
			for (int y = 0; y < bingoSize; y++)
			{
				if (bingo[x][y] == -1)
					Ycount++;
			}
		}

		if (Ycount == bingoSize) bingocount++;
	}

	int Ccount = 0;
	int Ccount2 = 0;

	for (int i = 0; i < bingoSize; i++)
	{
		if (bingo[i][i] == -1)
			Ccount++;
		if (bingo[i][(bingoSize - 1) - i] == -1)
			Ccount2++;
	}
	if (Ccount == bingoSize) bingocount++;
	if (Ccount2 == bingoSize) bingocount++;
}

int main()
{
	srand((unsigned int)time(NULL));

	int** bingoUser;
	int** bingoCom;

	int bingoSize = 0;

	int input, bingocountUser, bingocountCom;
	bingocountUser = bingocountCom = 0; // �� �� ���ÿ� �ʱ�ȭ

	cout << "���� ������ �Է� : ";
	cin >> bingoSize;

	//�����Ҵ� 1������ �迭 ������� ���� 2������ �ǰԲ�.
	bingoUser = new int* [bingoSize]; 
	bingoCom = new int* [bingoSize];

	for (int i = 0; i < bingoSize; i++)
	{
		bingoUser[i] = new int[bingoSize];
		bingoCom[i] = new int[bingoSize];
	}

	for (int y = 0; y < bingoSize; y++)
	{
		for (int x = 0; x < bingoSize; x++)
		{
			bingoUser[x][y] = y * bingoSize + x;
			bingoCom[x][y] = y * bingoSize + x;
		}
	}

	shuffle(1000, bingoSize, bingoUser);
	shuffle(1000, bingoSize, bingoCom);

	while (1)
	{
		system("cls");

		if (bingocountUser > 2)
		{
			Print(bingoUser, bingoSize);
			cout << "���� ���� : " << bingocountUser << endl;
			exit(1);
		}

		if (bingocountCom > 2)
		{
			Print(bingoCom, bingoSize);
			cout << "���� ���� : " << bingocountCom << endl;
			exit(1);
		}

		cout << "���� ���� : " << bingocountUser << endl;
		Print(bingoUser, bingoSize);
		cout << " ********************************* " << endl;
		Print(bingoUser, bingoSize);
		cout << "���� ���� : " << bingocountCom << endl;

		cin >> input;

		if (input >= pow(bingoSize, 2) || input < 0)
		{
			cout << "�ٽ� �Է��� �ּ���." << endl;
			continue;
		}

		if (!Check(bingoSize, bingoUser, input))
		{
			cout << "�ߺ��� �����Դϴ�." << endl;
		}
		if (!Check(bingoSize, bingoCom, input))
		{
			cout << "�ߺ��� �����Դϴ�." << endl;
		}

		int checkCom = -1;
		while (checkCom == -1)
		{
			checkCom = bingoCom[rand() % bingoSize][rand() % bingoSize];
		}

		if (!Check(bingoSize, bingoUser, checkCom))
		{
			cout << "�ߺ��� �����Դϴ�." << endl;
		}
		if (!Check(bingoSize, bingoCom, checkCom))
		{
			cout << "�ߺ��� �����Դϴ�." << endl;
		}

		Count(bingocountUser, bingoSize, bingoUser);
		Count(bingocountCom, bingoSize, bingoCom);
	}
	return 0;
}