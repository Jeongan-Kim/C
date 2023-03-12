#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) 
{
    int answer = 0;
    int a = 1, b = 1;
    while (true)
    {
        a = b * b;
   
        if (n == a)
        {
            answer = 1;
            break;
        }
        else if (n < a)
        {
            answer = 2;
            break;
        }
        else
            b++;
    }
    return answer;
}


/*
���� ����
� �ڿ����� �������� �� ������ ������ ��������� �մϴ�. ���� n�� �Ű������� �־��� ��, n�� ��������� 1�� �ƴ϶�� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� n �� 1,000,000
����� ��
n	result
144	1
976	2
����� �� ����
����� �� #1

144�� 12�� �����̹Ƿ� �������Դϴ�. ���� 1�� return�մϴ�.
����� �� #2

976�� �������� �ƴմϴ�. ���� 2�� return�մϴ�.
*/