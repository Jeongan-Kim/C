/*
	10개의 숫자가 있을 때,
	7 15 21 8 14 25 10 11 17 5
	이 중 더했을 때 숫자가 딱 100이 되는 8개의 숫자 찾기
	(어떻게 돌려야 반복문을 최대한 줄일지 예외 조건을 잘 줘야 하겠다)
	- 모두 더한 수 - 100 = X
	- 두 수를 골라 합이 X인 조합을 찾아 제하면 답이다.
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
	int sum1 = 0; // sum1 : 10개 수의 합
	
	int arr1[2];

	for (auto const num : arr)
	{
		sum1 += num;
	}

	int sum2 = sum1 - 100; // sum2 : 2개 수의 합

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