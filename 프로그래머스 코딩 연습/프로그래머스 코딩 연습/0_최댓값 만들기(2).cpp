#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
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

// numbers_len은 배열 numbers의 길이입니다.
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
문제 설명
정수 배열 numbers가 매개변수로 주어집니다. numbers의 원소 중 두 개를 곱해 만들 수 있는 최댓값을 return하도록 solution 함수를 완성해주세요.

제한사항
-10,000 ≤ numbers의 원소 ≤ 10,000
2 ≤ numbers 의 길이 ≤ 100
입출력 예
numbers	                    result
[1, 2, -3, 4, -5]	        15
[0, -31, 24, 10, 1, 9]	    240
[10, 20, 30, 5, 5, 20, 5]	600
입출력 예 설명
입출력 예 #1

두 수의 곱중 최댓값은 -3 * -5 = 15 입니다.
입출력 예 #2

두 수의 곱중 최댓값은 10 * 24 = 240 입니다.
입출력 예 #3

두 수의 곱중 최댓값은 20 * 30 = 600 입니다.
*/