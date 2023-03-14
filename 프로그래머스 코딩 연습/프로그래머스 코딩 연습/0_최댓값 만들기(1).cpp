#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len�� �迭 numbers�� �����Դϴ�.
int solution(int numbers[], size_t numbers_len) 
{
    int answer = 0;
    int k;
    for (int i = 0; i < numbers_len-1; i++)
    {
        for (int j = i + 1; j < numbers_len; j++)
        {
            k = numbers[i] * numbers[j];
            if (answer <= k)
                answer = k;
        }
    }
    return answer;
}

/*
���� ����
���� �迭 numbers�� �Ű������� �־����ϴ�. numbers�� ���� �� �� ���� ���� ���� �� �ִ� �ִ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
0 �� numbers�� ���� �� 10,000
2 �� numbers�� ���� �� 100
����� ��
numbers	                result
[1, 2, 3, 4, 5]	        20
[0, 31, 24, 10, 1, 9]	744
����� �� ����
����� �� #1

�� ���� ���� �ִ��� 4 * 5 = 20 �Դϴ�.
����� �� #1

�� ���� ���� �ִ��� 31 * 24 = 744 �Դϴ�.
*/