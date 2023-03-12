#include <stdio.h>

int main()
{
    //자동 형변환
    short s1 = 10; 
    int i1 = s1; //(int)s1

    float f1 = 100; //(float)100
    printf("%f\n", f1);

    int i2 = 500;
    unsigned char c1 = i2;
    printf("%d\n", c1);

    float f2 = 1.25f;
    int i3 = f2;
    printf("%d\n", i3);

    /*
        Ranking of types operations
        - long double > double > float
        - unsinged long long == long long
        - unsinged long == long
        - unsinged int == int
        - unsigned short == short
        - unsinged char == char
        - bool 
    */

    //명시적 형변환
    //int a = 10, b = 4;
    //float div = a / b;
    //printf("%f\n", div);

    int a = 10, b = 4;
    float div = (float)a / b;
    printf("%f\n", div);
   

    return 0;
}