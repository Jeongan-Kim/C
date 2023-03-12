#include <stdio.h>

// 다음  식을  만족하는  자연수  a,b,c  의  개수를  구하여라.
// i) a  +  b  +  c  =  2000
// ii)  a  ＞  b  >  c,  a,b,c  는  모두  자연수
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
    printf("a, b, c의 개수 : %d", num);
    return 0;
}