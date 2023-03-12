#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int common[], size_t common_len) 
{
    int answer = 0;
    int i = common[0];
    int j = common[1];
    int k = common[2];
    if ((j-i) == (k-j))
    {
        answer = common[common_len-1] + (j - i);
    }
    else if (j / i == k / j)
    {
        answer = common[common_len-1] * (j / i);
    }
    return answer;
}

/*
���� ����
�������� Ȥ�� ������ common�� �Ű������� �־��� ��, ������ ���� �������� �� ���ڸ� return �ϵ��� solution �Լ��� �ϼ��غ�����.

���ѻ���
2 < common�� ���� < 1,000
-1,000 < common�� ���� < 2,000
common�� ���Ҵ� ��� �����Դϴ�.
�������� Ȥ�� �������� �ƴ� ���� �����ϴ�.
�������� ��� ����� 0�� �ƴ� �����Դϴ�.
����� ��
common      	result
[1, 2, 3, 4]	5
[2, 4, 8]   	16
����� �� ����
����� �� #1

[1, 2, 3, 4]�� ������ 1�� ���������̹Ƿ� ������ �� ���� 5�̴�.
����� �� #2

[2, 4, 8]�� ���� 2�� �������̹Ƿ� ������ �� ���� 16�̴�.
*/