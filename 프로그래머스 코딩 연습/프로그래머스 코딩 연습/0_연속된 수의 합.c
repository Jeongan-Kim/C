#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int* solution(int num, int total, int* answer) 
{
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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
���� ����
���ӵ� �� ���� ������ ���� 12�� �Ǵ� ���� 3, 4, 5�Դϴ�. �� ���� num�� total�� �־����ϴ�. ���ӵ� �� num���� ���� ���� total�� �� ��, ���� �迭�� ������������ ��� return�ϵ��� solution�Լ��� �ϼ��غ�����.

���ѻ���
1 �� num �� 100
0 �� total �� 1000
num���� ���ӵ� ���� ���Ͽ� total�� �� �� ���� �׽�Ʈ ���̽��� �����ϴ�.
����� ��
num	total	result
3	12	    [3, 4, 5]
5	15	    [1, 2, 3, 4, 5]
4	14	    [2, 3, 4, 5]
5	5	    [-1, 0, 1, 2, 3]
����� �� ����
����� �� #1

num = 3, total = 12�� ��� [3, 4, 5]�� return�մϴ�.
����� �� #2

num = 5, total = 15�� ��� [1, 2, 3, 4, 5]�� return�մϴ�.
����� �� #3

4���� ���ӵ� ���� ���� 14�� �Ǵ� ���� 2, 3, 4, 5�Դϴ�.
����� �� #4

���� ����
*/