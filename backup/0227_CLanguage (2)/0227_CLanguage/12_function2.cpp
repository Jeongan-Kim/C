#include <stdio.h>

/*
    營敝 л熱
    - 薄�亳�

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

/*
    0 1 1 2 3 5 8 13

    0 + 1 = 1
    1 + 1 = 2
    1 + 2 = 3

    n = (n - 1) + (n - 2)
    (n - 1) = (n - 2) + (n - 3)
*/
//int Fibonacci(int n)
//{
//    int f1 = 0, f2 = 1, f3;
//
//    if (n == 1)
//        printf("%d", f1);
//    else
//        printf("%d %d ", f1, f2);
//
//    for (int i = 2; i < n; i++)
//    {
//        f3 = f1 + f2;
//        printf("%d ", f3);
//
//        f1 = f2;
//        f2 = f3;
//    }
//
//}

int fibonaccirecu(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return fibonaccirecu(n - 1) + fibonaccirecu(n - 2);
}

int main()
{
    Recursive(3);

    int n;
    scanf_s("%d", &n);

    printf("%d", Factorial(n));


    int n2;
    scanf_s("%d", &n2);

    //Fibonacci(n);

    for (int i = 0; i < n2; i++)
    {
        printf("%d ", fibonaccirecu(i));
    }

    return 0;
}

//煎傳, 營敝