#include <stdio.h>

/*
    재귀 함수
    - 점화식

    4! 4 3 2 1
*/

void Recursive(int num)
{
    if (num == 0)
        return; 

    printf("Hello to myself\n");
    Recursive(num - 1);
}

int Factorial(int n)
{
    /*
        n * (n - 1) * (n - 2) * (n - 3) * ..... * (n - (n - 2)) * 2 * 1
        => n * (n - 1)!       
    */

    if (n == 0)
        return 1;

    return n * Factorial(n - 1);

    // n * n - 1 * n - 2 * 1
}

int main()
{
    Recursive(3);

    int n;
    scanf_s("%d", &n);

    printf("%d", Factorial(n));

    return 0;
}