#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    난수
    - rand()
*/

int main()
{
    printf("%d, ", rand() % 10 + 1); // 1 ~ 10
    printf("%d, ", rand() % 10 + 1);
    printf("%d, ", rand() % 10 + 1);
    printf("%d, ", rand() % 10 + 1);
    printf("%d, ", rand() % 10 + 1);
    printf("\n\n");

    //srand()

    srand((unsigned int)time(NULL));

    printf("%d, ", rand() % 10 + 1); // 1 ~ 10
    printf("%d, ", rand() % 10 + 1);
    printf("%d, ", rand() % 10 + 1);
    printf("%d, ", rand() % 10 + 1);
    printf("%d, ", rand() % 10 + 1);
    printf("\n\n");

    return 0;
}

/*
    과제

    가위, 바위, 보 게임 만들기
    상대는 랜덤으로 가위 바위 보를 냄
    이겼는지, 졌는지, 비겼는지 출력

    Up&Down Game (1 ~ 100) 
    - 10번 내로 정답 맞히기

*/