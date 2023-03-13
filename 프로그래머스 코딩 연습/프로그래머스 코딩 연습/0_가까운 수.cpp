#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len�� �迭 array�� �����Դϴ�.

int solution(int array[], size_t array_len, int n) 
{
    int answer = array[0];

   for (int i = 1; i < array_len; i++)
   {
        if (abs(n - answer) > abs(n - array[i]))
        {
                answer = array[i];
        }
        else if (abs(n - answer) == abs(n - array[i]))
        {
            if (array[i] < answer)
                answer = array[i];
        }
   }
 
    return answer;
}

/*
����� ��
���� ����
���� �迭 array�� ���� n�� �Ű������� �־��� ��, array�� ����ִ� ���� �� n�� ���� ����� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� array�� ���� �� 100
1 �� array�� ���� �� 100
1 �� n �� 100
���� ����� ���� ���� ���� ��� �� ���� ���� return �մϴ�.
����� ��
array	        n	    result
[3, 10, 28]	    20	    28
[10, 11, 12]	13	    12
����� �� ����
����� �� #1

3, 10, 28 �� 20�� ���� ����� ���� 28�Դϴ�.
����� �� #2

10, 11, 12 �� 13�� ���� ����� ���� 12�Դϴ�.
*/