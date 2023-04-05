#include <stdio.h>

int main()
{
	char arr[50] = { 0 };
	scanf_s("%s", arr, sizeof(arr));
	
	printf("%s??!", arr);
	return 0;
}