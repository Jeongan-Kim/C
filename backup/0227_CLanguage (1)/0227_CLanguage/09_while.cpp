#include <stdio.h>
#include <conio.h>

/*
    while(조건식)
    {
        명령문;
    }
*/

int main()
{
    //while
    //bool study = true;

    //while (study)
    //{
    //    printf("Hello World\n");

    //    printf("공부 중인가요? [네 : 1, 아니요 : 0] -> ");
    //    int answer = -1;
    //    scanf_s("%d", &answer);

    //    if (answer == 0)
    //    {
    //        study = false;
    //        //break;
    //    }
    //}

    //char key;

    //while (true)
    //{
    //    printf("이동키 입력 : ");
    //    key = _getch();

    //    if (key == 'q')
    //        break;

    //    switch (key)
    //    {
    //    case 'w': printf("상\n"); break;
    //    case 's': printf("하\n"); break;
    //    case 'a': printf("좌\n"); break;
    //    case 'd': printf("우\n"); break;
    //    default: printf("잘못누름\n"); break;
    //    }
    //}

    //do while
    /*
        do
        {
            명령문;
        }while(조건식)
    */

    const int secretCode = 123123;

    int password = 0;
    int tryCount = 0;

    do
    {
        if (tryCount >= 3)
        {
            printf("3회 실패 계정 잠금!\n");
            break;
        }

        printf("비밀번호 입력 (3회 실패 시 잠금, 현재 실패 횟수 : %d) => ", tryCount);
        scanf_s("%d", &password);

        tryCount++;
    } while (password != secretCode);


    return 0;
}

