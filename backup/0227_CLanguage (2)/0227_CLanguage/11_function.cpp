#include <stdio.h>

//전달인자x, 반환값o
int getInt()
{
    printf("숫자를 입력해주세요 : ");
    
    int n;
    scanf_s("%d", &n);

    return n;
}

//전달인자, 반환값 모두 있는 경우
int add(int x, int y)
{
    //int result = x + y;
    //return result;

    return x + y;
}

//전달인자o, 반환값x
void ShowNumber(int num)
{
    printf("들어온 값은 : %d\n", num);
}

//전달 인자와 반환 값이 모두 없는 경우
void test() //function prototype
{
    printf("111111111111111111");

    return;

    printf("222222222222222222");
}

int Compare(int num1, int num2);

int main(void)
{
    int x1 = 0;
    int y1 = 0;

    //printf("숫자를 입력해주세요 : ");
    //scanf_s("%d", &x1);

    //printf("숫자를 입력해주세요 : ");
    //scanf_s("%d", &y1);

    x1 = getInt();
    y1 = getInt();

    printf("%d + %d = %d\n", x1, y1, add(x1, y1));

    int num = getInt();
    ShowNumber(num);

    test();

    printf("둘 중 더 큰 수는? %d\n", Compare(x1, y1));

    return 0;
}

int Compare(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}
