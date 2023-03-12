#include <stdio.h>

/*
    if(조건식)
        명령;
    else if(조건식)
    else
*/

int main()
{
    //int number = 0;
    //printf("정수를 입력해주세요 : ");
    //scanf_s("%d", &number);

    ////if (number % 2 == 0)
    ////    printf("짝수\n");

    ////if (number % 2 != 0)
    ////{
    ////    printf("짝수가 아니네요\n");
    ////    printf("홀수\n");
    ////}

    //if (number % 2 == 0)
    //    printf("짝수\n");
    //else
    //{
    //    printf("짝수가 아니네요\n");
    //    printf("홀수\n");
    //}

    //char key;

    //printf("어느 방향으로 가시겠습니까? : ");

    //scanf_s(" %c", &key, sizeof(key));

    //if (key == 'w')
    //    printf("위");
    //else if (key == 's')
    //    printf("아래");
    //else if (key == 'a')
    //    printf("왼쪽");
    //else if (key == 'd')
    //    printf("오른쪽");
    //else
    //    printf("잘못 입력하였습니다");


    ////중첩 if문

    //int number2;
    //printf("숫자를 입력해주세요 : ");
    //scanf_s("%d", &number2);

    //if (number2 < 10)
    //{
    //    if (number2 <= 5)
    //        printf("5보다 작거나 같은 수");
    //    else
    //        printf("5보다 크고 10보다 작은 수");
    //}
    //else
    //    printf("10보다 크거나 같은 수");


    //getchar
    //char c1, c2;
    //int d;

    //printf("문자를 입력하시오 : ");
    //scanf_s("%c", &c1);

    //printf("정수를 입력하시오 : ");
    //scanf_s("%d", &d);

    //getchar();

    //printf("문자를 입력하시오 : ");
    //scanf_s("%c", &c2);

    //printf("c1 : %c\n, d : %d\n, c2 : %c\n", c1, d, c2);

    char c3;
    scanf_s("%c", &c3);

    printf("%c", c3);

    return 0;
}

/*
   과제!!
    A == 65
    a == 97

    대문자 입력하면 소문자로,
    소문자 입력하면 대문자로
    출력되는 프로그램 만들기
*/