#include <stdio.h>

//매크로 상수
#define Game 1
#define GameMenual 2
#define Option 3
#define Exit 4

/*
    switch(변수)
    {
    case 값 :
        명령;
        break;
    case 값2 :
        명령;
        break;
    default:
        예외명령처리
        break;
    }
*/

int main()
{
    /*int selmenu;
    printf("메뉴를 선택하세요 [1. 게임 시작, 2. 게임 설명, 3. 설정, 4. 종료]");
    printf("\n입력 : ");
    scanf_s("%d", &selmenu);

    switch (selmenu)
    {
    case Game:
        printf("\n게임을 시작합니다\n");
        break;
    case GameMenual:
        printf("게임 설명\n");
        break;
    case Option:
        printf("게임 설정\n");
        break;
    case Exit:
        printf("게임 종료\n");
        break;
    default:
        printf("잘못 입력하셨습니다\n");
        break;
    }*/


    int time = 0;
    int number = 0;

    printf("시간을 입력해주세요 : ");
    scanf_s("%d", &time);

    if (time < 12)
    {
        number = 1;
    }
    else if (time > 12)
    {
        number = 2;
    }
    else if (time == 12)
    {
        number = 3;
    }
    else
    {
        printf("잘못 입력하였습니다\n");
    }

    switch (number)
    {
    case 1:
        printf("오전\n");
        break;
    case 2:
        printf("오후\n");
        break;
    case 3:
        printf("정오\n");
    default:
        break;
    }
     

    return 0;
}