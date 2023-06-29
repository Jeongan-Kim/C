//선형 자료구조, 비선형 자료구조(예, 트리구조)
/*
	Big O 표기법
	O(1), O(logn), O(n), O(nlogn), O(n^2), O(2^n), O(n!)

	Quit Sort는 nlogn 속도 정도(빠른 편). 가장 효율적인 정렬

	피벗값을 지정한 다음, 피벗을 기준으로 작은 것은 왼쪽(l값), 큰 것은 오른쪽(r값).
	2로 나눈 값을 피벗값으로 하면 중앙값을 피벗으로 지정한 것.
*/

#include <iostream>

using namespace std;

void QuickSort(int* arr, int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int left = start + 1; //왼쪽 커서
	int right = end;

	while (left <= right)
	{
		while (arr[left] < arr[pivot] && left <= end)
			left++;
		while (arr[right] > arr[pivot] && right >= start)
			right--;

		if (left >= right) break;

		swap(arr[left], arr[right]);
	}

	swap(arr[pivot], arr[right]);

	QuickSort(arr, start, right - 1);
	QuickSort(arr, right + 1, end);
}

void Print(int* arr, int size, string str)
{
	cout << str << endl;

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n'; // endl보다 조금 더 빠르다. endl은 버퍼 공간을 비워주면서 하기 때문에 
}

int main()
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	Print(arr, 10, "PREV : ");
	QuickSort(arr, 0, 9);
	Print(arr, 10, "NEXT : ");

	return 0;
}