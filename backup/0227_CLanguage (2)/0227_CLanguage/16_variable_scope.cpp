#include <stdio.h>

/*
    지역(local)변수
    전역(global)변수
*/

//전역변수
int global;

char var1 = 'G';

int main()
{
    printf("초기화 하지 않은 global 값 : %d\n", global);


    printf("main에서의 var1 : %c\n", var1);
    //지역 변수
    {
        char var1 = 'L';
        printf("{}에서의 var1 : %c\n", var1);
    }

    printf("main에서의 var1 : %c\n", var1);


    return 0;
}