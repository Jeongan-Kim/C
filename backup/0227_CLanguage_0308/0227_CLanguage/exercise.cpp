#include <stdio.h>

// ����  ����  �����ϴ�  �ڿ���  a,b,c  ��  ������  ���Ͽ���.
// i) a  +  b  +  c  =  2000
// ii)  a  ��  b  >  c,  a,b,c  ��  ���  �ڿ���
int main()
{
    int a;
    int b;
    int c;
    int num = 0;

    for (c = 1; c <= 2000; c++)
    {
        for (b = c + 1; 2000 - b - c > b; b++)
        {
            a = 2000 - b - c;
            num++;
        }
    }
    printf("a, b, c�� ���� : %d", num);
    return 0;
}