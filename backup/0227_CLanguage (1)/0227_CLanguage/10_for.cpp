#include <stdio.h>

/*
    for(�ʱ��; ���ǽ�; ������(����))
    {
        ��ɹ�;
    }
*/

int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("for�� ��ɾ� %d�� �ݺ���\n", i);
    }

    printf("\n");

    //bool => false : 0 true : 1
    for (int i = 4; i >= 0; i--) //5 4 3 2 1 0
    {
        printf("for�� ��ɾ� %d�� �ݺ���\n", i);
    }

    //for (;;)
    //{
    //    printf("���ѷ���\n");
    //}

    printf("\n");

    char num1, num2;
    for (; int count = scanf_s("%c %c", &num1, &num2);)
    {
        printf("%d\n", count);
        while (getchar() != '\n');
    }

    for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2)
    {
        printf("%d ", i);
        printf("%d\n", j);
    }

    printf("\n");

    for (int i = 1; i <= 10; i++)
    {
        if (i % 3 == 0)
            continue;

        printf("%d ", i);
    }

    printf("\n");

    for (int c = 'A'; c <= 'Z'; c++)
        printf("%c ", c);

    printf("\n");

    for (int c = 'Z'; c >= 'A'; c--)
        printf("%c ", c);

    printf("\n");

    int total = 0;
    int num = 0;

    printf("0���� num������ ���� ���ϱ�. num : ");
    scanf_s("%d", &num);

    for (int i = 0; i <= num; i++)
    {
        total += i;
    }
    printf("0���� %d������ ���� = %d\n", num, total);

    printf("\n");

    /*
        ��ø for ��
    */
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("*"); 
        }
        printf("\n");
    }
    
    for (int i = 2; i < 10; i++)
    {
        printf("***������ %d�� ����!***\n", i);

        for (int j = 1; j < 10; j++)
        {
            printf("%d * %d = %d\n", i, j, i * j);
        }

        printf("***������ %d�� ��!***\n", i);
    }

    return 0;
}

/*
    *
    **
    ***
    ****
    *****
     
    *****
    ****
    ***
    **
    * 
    
    *****
    0****
    00***
    000**
    0000*
        
        *
       **
      ***
     ****
    *****
        
      *
     ***
    *****
     ***
      *
 */