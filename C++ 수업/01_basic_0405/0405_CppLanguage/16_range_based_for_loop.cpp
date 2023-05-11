#include <iostream>

using namespace std;

int main()
{

	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	//범위 기반 for문 , 범위가 있어야지만 쓸 수 있다.
	for (int i = 0; i < sizeof(fibonacci) / sizeof(int); i++)
		cout << fibonacci[i] << endl;

	for (const auto& number : fibonacci)
		cout << number << endl;

	for (const auto& number : { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 })
		cout << number << endl;

	int* test = new int[10];
	//for (auto t : test);

	return 0;
}