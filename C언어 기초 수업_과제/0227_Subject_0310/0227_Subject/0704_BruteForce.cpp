/*
	10���� ���ڰ� ���� ��,
	7 15 21 8 14 25 10 11 17 5
	�� �� ������ �� ���ڰ� �� 100�� �Ǵ� 8���� ���� ã��
	(��� ������ �ݺ����� �ִ��� ������ ���� ������ �� ��� �ϰڴ�)
	- ��� ���� �� - 100 = X
	- �� ���� ��� ���� X�� ������ ã�� ���ϸ� ���̴�.
*/

#include <iostream>

using namespace std;

void Print(int arr[], int size, int i, int j)
{
	for (int k = 0; k < size; k++)
	{
		if (arr[k] == arr[i] || arr[k] == arr[j])
			continue;

		cout << arr[k] << " ";
	}
}

int main()
{
	int arr[10] = { 7, 15, 21, 8, 14, 25, 10, 11, 17, 5 };
	int sum1 = 0; // sum1 : 10�� ���� ��
	
	int arr1[2];

	for (auto const num : arr)
	{
		sum1 += num;
	}

	int sum2 = sum1 - 100; // sum2 : 2�� ���� ��

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (sum2 == arr[i] + arr[j])
			{
				Print(arr, 10, i, j);
				cout << endl;
			}

		}
	}
	
	return 0;
}