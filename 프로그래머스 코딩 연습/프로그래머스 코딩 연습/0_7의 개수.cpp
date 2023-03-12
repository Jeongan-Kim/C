#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int array[], size_t array_len) 
{
    int answer = 0;
 
    for (int i = 0; i < array_len; i++)
    {
        int number_size = 0;

        while(true)
        {
            if (array[i] % 10 == 7)
            {
                answer++;
            }
            array[i] /= 10;
           
            if (array[i] < 1)
                break;
        }
    }
    return answer;
}


/*
���� ����
�Ӿ��̴� ����� ���� 7�� ���� �����մϴ�. ���� �迭 array�� �Ű������� �־��� ��, 7�� �� �� �� �ִ��� return �ϵ��� solution �Լ��� �ϼ��غ�����.

���ѻ���
1 �� array�� ���� �� 100
0 �� array�� ���� �� 100,000
����� ��
array	    result
[7, 77, 17]	4
[10, 29]	0
����� �� ����
����� �� #1

[7, 77, 17]���� 7�� 4�� �����Ƿ� 4�� return �մϴ�.
����� �� #2

[10, 29]���� 7�� �����Ƿ� 0�� return �մϴ�.
*/