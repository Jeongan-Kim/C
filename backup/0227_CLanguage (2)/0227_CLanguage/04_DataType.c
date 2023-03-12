#include <stdio.h>
#include <stdbool.h>

/*
    Data Type(자료형)
*/

/*
    bit와 byte
    bit : 가장 작은 데이터 단위
    byte : 1byte == 8bit
*/

/*
    char
    int
    longlong
    float
    double
    long double
*/

int main()
{
    //char : 한 문자를 표현할 때 사용 - 1byte
    char c1 = 'A';
    char c2 = 65; //ASCII

    printf("Character c1 : %c\n", c1);
    printf("Character c2 : %c\n", c2);
    printf("Character size : %d\n", sizeof(char));
    printf("Character size : %d\n", sizeof(c1));

    //정수형
    short s = 1; //2byte (-32768 ~ 32767)
    int num = 0; //4byte (-21억 ~ 21억)
    
    printf("num : %d\n", num);
    printf("int size : %d\n", sizeof(int));

    //실수형 - 부동소수점 방식

    float f = 0.123f; //4byte
    double d = 0.1234; //8byte

    printf("고정 소수점 : %f\n", f);
    printf("부동 소수점 : %e\n", f);

    //부동 소수점의 오차
    float sum = 0.1f;

    for (int i = 0; i < 1000; i++)
    {
        sum += 0.1;
    }

    printf("%f\n", sum);


    //논리형
    bool isDash = false; //1byte

    printf("캐릭터 대쉬 유무 : %d\n", isDash);


    unsigned char c3; //0 ~ 255
    unsigned int i2; // 0 ~ 42억

    unsigned char cc = 129;
    printf("%d\n", cc);

    signed int ii;

    return 0;
}

/*
    조사 과제

    - ASCII 코드란?
    - 컴퓨터의 실수 표현 방식
*/