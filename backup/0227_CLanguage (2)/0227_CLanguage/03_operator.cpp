#include <stdio.h>

int main()
{
    //대입 연산자 : =
    int a = 10;

    //산술 연산자 : + - * / %
    int b = 3;
    int result;

    result = a + b;
    printf("%d\n", result);

    result = a - b;
    printf("%d\n", result);

    result = a * b;
    printf("%d\n", result);

    result = a / b;
    printf("%d\n", result);

    result = a % b;
    printf("%d\n", result);

    //부호 연산자 : + -

    //복합 대입 연산자
    a += b; //a = a + b

    //증감 연산자 : ++ --
    a = 1;
    b = 1;

    a = ++b; //전위
    printf("a : %d, b : %d\n", a, b);

    a = 1;
    b = 1;

    a = b++; //후위
    printf("a : %d, b : %d\n", a, b);
  
 /*
     비교 연산자 
     == : 같으면 true, 다르면 false
     != : 같으면 false, 다르면 true
     < > <= >=
 */

/*
    논리 연산자
    && (and) : 둘 다 참이면 true, 그 외 false
    || (or)  : 둘 중 하나라도 참이면 true 그 외 false
    ! (not)  : true일 경우 false, false일 경우 true

    1. true && false => false
    2. true || false => true

    3. true && true  => true
    3. true || true  => true

    4. !true        => false
    5. !false       => true
*/

    // scanf

    //int num1, num2, num3;

    //scanf_s("%d %d %d", &num1, &num2, &num3);
    //printf("%d %d %d\n", num1, num2, num3);
     
    //조건 연산자 - 삼항 연산자
    //조건식 ? 반환값1 : 반환값2

#pragma region Attack
    int playerDamage = 50;
    int enemyHp = 550;

    printf("플레이어의 공격력 : %d\n", playerDamage);
    printf("현재 적의 체력 : %d\n\n", enemyHp);

    int attackCount = 0;
    printf("몇 번 공격하시겠습니까? : ");
    scanf_s("%d", &attackCount);

    enemyHp -= playerDamage * attackCount;
    printf("현재 적의 체력 : %d\n\n", enemyHp);

#pragma endregion

#pragma region Grab
    int grabRange;
    int distance = 300;
    bool catchenemy = true; // 1 0

    printf("적과의 거리 : %d\n", distance);

    printf("그랩 사거리 : ");
    scanf_s("%d", &grabRange);

    grabRange >= distance ? catchenemy = true : catchenemy = false;

    printf("적을 처치하였나요? : %d\n", catchenemy);
#pragma endregion


    return 0;
}