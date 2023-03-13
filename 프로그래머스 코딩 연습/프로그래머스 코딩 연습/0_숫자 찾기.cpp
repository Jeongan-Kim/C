#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int k) 
{
    int answer = 0;
    int num_len = 0; //num�� ����
    int k_reg = 0; //k�� �ִ� �ڸ� ��(1�� �ڸ� ������)
    while (num > 0)
    {
        num_len++;
        if (num % 10 == k)
        {
            k_reg = num_len;
        }
        num /= 10;     
    }

    if (k_reg == 0)
        answer = -1;
    else
        answer = num_len - k_reg + 1;

    return answer;
}

/*
���� num�� k�� �Ű������� �־��� ��, num�� �̷�� ���� �߿� k�� ������ num�� �� ���ڰ� �ִ� �ڸ� ���� return�ϰ� ������ -1�� return �ϵ��� solution �Լ��� �ϼ��غ�����.

���ѻ���
0 < num < 1,000,000
0 �� k < 10
num�� k�� ���� �� ������ ���� ó�� ��Ÿ���� �ڸ��� return �մϴ�.
����� ��
num	    k	result
29183	1	3
232443	4	4
123456	7	-1
����� �� ����
����� �� #1

29183���� 1�� 3��°�� �ֽ��ϴ�.
����� �� #2

232443���� 4�� 4��°�� ó�� �����մϴ�.
����� �� #3

123456�� 7�� �����Ƿ� -1�� return �մϴ�.
*/