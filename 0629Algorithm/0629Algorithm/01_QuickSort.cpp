//���� �ڷᱸ��, ���� �ڷᱸ��(��, Ʈ������)
/*
	Big O ǥ���
	O(1), O(logn), O(n), O(nlogn), O(n^2), O(2^n), O(n!)

	Quit Sort�� nlogn �ӵ� ����(���� ��). ���� ȿ������ ����

	�ǹ����� ������ ����, �ǹ��� �������� ���� ���� ����(l��), ū ���� ������(r��).
	2�� ���� ���� �ǹ������� �ϸ� �߾Ӱ��� �ǹ����� ������ ��.
*/

#include <iostream>

using namespace std;

void QuickSort1(int* arr, int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int left = start + 1; //���� Ŀ��
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

	QuickSort1(arr, start, right - 1);
	QuickSort1(arr, right + 1, end);
}

void QuickSort2(int* arr, int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int left = start + 1; //���� Ŀ��
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

	QuickSort2(arr, start, right - 1);
	QuickSort2(arr, right + 1, end);
}

void Print(int* arr, int size, string str)
{
	cout << str << endl;

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n'; // endl���� ���� �� ������. endl�� ���� ������ ����ָ鼭 �ϱ� ������ 
}

int main()
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	Print(arr, 10, "PREV : ");
	//QuickSort2(arr, 0, 9);
	QuickSort1(arr, 0, 9);
	Print(arr, 10, "NEXT : ");


	return 0;
}