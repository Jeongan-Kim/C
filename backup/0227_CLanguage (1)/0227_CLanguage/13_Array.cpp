#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 5

int get_2(void)
{
    return 2;
}

void randomnumber();

int main()
{
    int floor101, floor102, floor103, floor104;
    int floor201, floor202, floor203, floor204;

    //배열
    int floor[40];
    float farr[3];
    double darr[5];


    int arr1[3] = { 1, 2, 3 };
    int arr2[3] = { 0 };
    int arr3[5] = { 1, 2, 3 }; // 1 2 3 0 0 
    int arr4[ARRSIZE] = { 0 };
    int arr5[] = { 1, 2, 3 };

    char arr6[5] = { 'A', 'B', 'C' }; //0 1 2 3 4
    int a = 1;
    printf("%c, %c, %c\n", arr6[0], arr6[a], arr6[get_2()]);

    //printf("%c", arr6[5]);

    printf("\n");

    int arr7[3] = { 0, 1, 2 }; //0 1 2
    printf("%d %d %d\n", arr7[0], arr7[1], arr7[2]);
    printf("%p %p %p\n", &arr7[0], &arr7[1], &arr7[2]);

    printf("%d\n", sizeof(arr7) / sizeof(int));

    int size = sizeof(arr7) / sizeof(int); //3

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr7[i]);
    }

    printf("\n");

    randomnumber();

    return 0;
}

void randomnumber()
{
    srand((unsigned int)time(NULL));

    int number[10] = { 0 };

    for (int i = 0; i < 10; i++)
    {      
        number[i] = rand() % 10 + 1;

        for (int j = 0; j < i; j++)
        {
            if (number[i] == number[j])
            {
                i--;
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", number[i]);
    }
}

/*
    로또 만들기
    1 2 3 4 5 6 B
*/
