#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sides_len�� �迭 sides�� �����Դϴ�.
int solution(int sides[], size_t sides_len) 
{
    int answer = 0;
    int third=1;
    if (sides[0] > sides[1])
    {
        int temp = sides[0];
        sides[0] = sides[1];
        sides[1] = temp;
    }

    while (true)
    {
        if (third <= sides[1])
        {
            if (third + sides[0] > sides[1])
            {
                third++;
                answer++;
            }
            else if (third + sides[0] <= sides[1])
            {
                third++;
            }
        }
        if (third > sides[1])
        {
            if (sides[0] + sides[1] > third)
            {
                third++;
                answer++;
            }
            else
                break;
        }       
    }

    return answer;
}

/*
���� ����
���� �� ���� �ﰢ���� ����� ���ؼ��� ������ ���� ������ �����ؾ� �մϴ�.

���� �� ���� ���̴� �ٸ� �� ���� ������ �պ��� �۾ƾ� �մϴ�.
�ﰢ���� �� ���� ���̰� ��� �迭 sides�� �Ű������� �־����ϴ�. ������ �� ���� �� �� �ִ� ������ ������ return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
sides�� ���Ҵ� �ڿ����Դϴ�.
sides�� ���̴� 2�Դϴ�.
1 �� sides�� ���� �� 1,000
����� ��
sides	result
[1, 2]	1
[3, 6]	5
[11, 7]	13
����� �� ����
����� �� #1

�� ���� 1, 2 �� ��� �ﰢ���� �ϼ���Ű���� ������ �� ���� 2���� �մϴ�. ���� 1�� return�մϴ�.
����� �� #2

���� �� ���� 6�� ���
�� �� �ִ� ������ �� ���� 4, 5, 6 �� 3���Դϴ�.
������ �� ���� ���� �� ���� ���
�� �� �ִ� �� ���� 7, 8 �� 2���Դϴ�.
���� 3 + 2 = 5�� return�մϴ�.
����� �� #3

���� �� ���� 11�� ���
�� �� �ִ� ������ �� ���� 5, 6, 7, 8, 9, 10, 11 �� 7���Դϴ�.
������ �� ���� ���� �� ���� ���
�� �� �ִ� �� ���� 12, 13, 14, 15, 16, 17 �� 6���Դϴ�.
���� 7 + 6 = 13�� return�մϴ�.
*/