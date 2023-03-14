#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len�� �迭 numbers�� �����Դϴ�.
//int solution(int numbers[], size_t numbers_len) 
//{
//    int answer = -100000000;
//    int k;
//    for (int i = 0; i < numbers_len-1; i++)
//    {
//        for (int j = i + 1; j < numbers_len; j++)
//        {
//            k = numbers[i] * numbers[j];
//            if (answer <= k)
//                answer = k;
//        }
//    }
//    return answer;
//}

// numbers_len�� �迭 numbers�� �����Դϴ�.
void selectionSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int solution(int numbers[], size_t numbers_len) 
{
    int answer = 0;
    selectionSort(numbers, numbers_len);
    if (numbers[0] * numbers[1] >= numbers[numbers_len - 2] * numbers[numbers_len - 1])
        answer = numbers[0] * numbers[1];
    else
        answer = numbers[numbers_len - 2] * numbers[numbers_len - 1];
    return answer;
}


/*
���� ����
���� �迭 numbers�� �Ű������� �־����ϴ�. numbers�� ���� �� �� ���� ���� ���� �� �ִ� �ִ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
-10,000 �� numbers�� ���� �� 10,000
2 �� numbers �� ���� �� 100
����� ��
numbers	                    result
[1, 2, -3, 4, -5]	        15
[0, -31, 24, 10, 1, 9]	    240
[10, 20, 30, 5, 5, 20, 5]	600
����� �� ����
����� �� #1

�� ���� ���� �ִ��� -3 * -5 = 15 �Դϴ�.
����� �� #2

�� ���� ���� �ִ��� 10 * 24 = 240 �Դϴ�.
����� �� #3

�� ���� ���� �ִ��� 20 * 30 = 600 �Դϴ�.
*/