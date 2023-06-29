#include <iostream>

using namespace std;

void QuickSort(int* arr, int start, int end)
{
	if (start >= end) return;

	int pivot = start + (end - start) / 2; //Áß¾Ó ÇÇ¹þ°ª
	int left = start; 
	int right = end;

	while (left <= right)
	{
		while (arr[left] < arr[pivot] && left <= pivot)
			left++;
		while (arr[pivot] < arr[right] && pivot <= right)
			right--;

		if (left >= right) break;

		swap(arr[left], arr[right]);

		//cout << "left : " << left << "  right : " << right << '\n';

		//for (int i = 0; i < 10; i++)
		//	cout << arr[i] << " ";
		//cout << '\n';

	}

	//cout << "QuickSort(arr, " << start << ", " << left << ")\n";
	//cout << "QuickSort(arr, " << right + 2 << ", " << end << ")\n";

	QuickSort(arr, start, left);
	QuickSort(arr, right + 2, end);
}

void Print(int* arr, int size, string str)
{
	cout << str << endl;

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n'; 
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