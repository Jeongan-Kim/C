#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int* solution(int num, int total, int* answer) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int a = 0, b = 0;
   
    int i = 0;

    while (1)
    {
        for (int k = 0; k < num; k++)
        {
            a += i;
            //printf("a = %d, i = %d\n", a, i);
            i++;

        }

        if (a == total && answer != NULL)
        {
            for (int j = 0; j < num; j++)
            {
                answer[j] = b;
                //printf("%d ", answer[j]);
                b++;
            }
            break;
        }
        else if(a < total && answer != NULL)
        {
            b++;
            i = b;
            a = 0;
        }
        else if (a > total && answer != NULL)
        {
            b--;
            i = b;
            a = 0;
        }
           
    }

    return answer;
}

int main()
{
    int num, total;
    scanf_s("%d %d", &num, &total);
    int* answer = (int*)malloc(1000);
    solution(num, total, answer);

    for (int i = 0; i < num; i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}
/*
문제 설명
연속된 세 개의 정수를 더해 12가 되는 경우는 3, 4, 5입니다. 두 정수 num과 total이 주어집니다. 연속된 수 num개를 더한 값이 total이 될 때, 정수 배열을 오름차순으로 담아 return하도록 solution함수를 완성해보세요.

제한사항
1 ≤ num ≤ 100
0 ≤ total ≤ 1000
num개의 연속된 수를 더하여 total이 될 수 없는 테스트 케이스는 없습니다.
입출력 예
num	total	result
3	12	    [3, 4, 5]
5	15	    [1, 2, 3, 4, 5]
4	14	    [2, 3, 4, 5]
5	5	    [-1, 0, 1, 2, 3]
입출력 예 설명
입출력 예 #1

num = 3, total = 12인 경우 [3, 4, 5]를 return합니다.
입출력 예 #2

num = 5, total = 15인 경우 [1, 2, 3, 4, 5]를 return합니다.
입출력 예 #3

4개의 연속된 수를 더해 14가 되는 경우는 2, 3, 4, 5입니다.
입출력 예 #4

설명 생략
*/