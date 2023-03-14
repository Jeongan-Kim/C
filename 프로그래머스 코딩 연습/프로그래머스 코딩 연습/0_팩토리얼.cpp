#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) 
{
    int answer = 1;
    int num = 1;
    while (true)
    {
        answer++;
        num *= answer;
        if (num > n)
        {
            answer--;
            break;
        }
        else if (num == n)
            break;
 
    }
    return answer;
}

/*
���� ����
i���丮�� (i!)�� 1���� i���� ������ ���� �ǹ��մϴ�. ������� 5! = 5 * 4 * 3 * 2 * 1 = 120 �Դϴ�. ���� n�� �־��� �� ���� ������ �����ϴ� ���� ū ���� i�� return �ϵ��� solution �Լ��� �ϼ����ּ���.

i! �� n
���ѻ���
0 < n �� 3,628,800
����� ��
n	        result
3628800	    10
7	        3
����� �� ����
����� �� #1

10! = 3,628,800�Դϴ�. n�� 3628800�̹Ƿ� �ִ� ���丮���� 10�� return �մϴ�.
����� �� #2

3! = 6, 4! = 24�Դϴ�. n�� 7�̹Ƿ�, 7 ������ �ִ� ���丮���� 3�� return �մϴ�.
*/