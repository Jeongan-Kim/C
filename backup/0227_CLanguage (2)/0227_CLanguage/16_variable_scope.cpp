#include <stdio.h>

/*
    ����(local)����
    ����(global)����
*/

//��������
int global;

char var1 = 'G';

int main()
{
    printf("�ʱ�ȭ ���� ���� global �� : %d\n", global);


    printf("main������ var1 : %c\n", var1);
    //���� ����
    {
        char var1 = 'L';
        printf("{}������ var1 : %c\n", var1);
    }

    printf("main������ var1 : %c\n", var1);


    return 0;
}