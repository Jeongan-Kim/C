#include <stdio.h>

/*
    Variable(변수)
    - 변할 수 있는 데이터

    Constant(상수)
    - 변하지 않는 데이터
*/

int main()
{
    // Datatype name;
    int a; //declaration
    a = 10; //initialize

    printf("%d\n", a);

    a = 11;
    printf("%d\n", a);

    int b = 20;
    printf("%d\n", b);

    b = 30;

    int result;
    result = a + b;
    printf("결과 : %d\n", result);

    //변수 표기법

    //헝가리안 표기법
    int i_age;
    int intWeight;

    int hpCount; //카멜 표기법
    int HpCount; //파스칼 표기법
    int hp_count; //스네이크 표기법

    int a1;
    //int 1a;

    //int hello world;
    //int int;
    //int for


    return 0;
}