#include <stdio.h>

int main()
{
	//대입 연산자 : =
	int a = 10;

	//산술 연산자 : +, -, *, /, %(나머지 연산자)
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

	//부호 연산자 : +, - 부호를 나타냄

	//복합 대입 연산자
	//a = a + b; 이건 a 변수가 중복되므로 아래와 같이 표기함
	a += b;

	//증감 연산자 : 값을 1 증가시키거나 감소시킬때 사용. ++, --
	a = 1;
	b = 1;
	a = ++b;//a에 b를 증가시켜준 다음 대입(전위 연산자)
	printf("a : %d, b : %d\n", a, b);

	a = 1;
	b = 1;
	a = b++;//a에 b를 대입한 후 b가 증가(후위 연산자)
	printf("a : %d, b : %d\n", a, b);
	//한 줄 후에 증감하냐 아니냐의 차이

/*
	비교 연산자 :같으면 true, 다르면 false
	== : 같으면 true를 반환, 다르면 false
	!= : 같으면 false를 반환, 다르면 true
	<, >, <=, >=
*/

/*
	논리 연산자
	&& (and) : 앞 뒤 문장이 둘 다 참이면 true, 그 외 false
	|| (or) : 앞 뒤 문장이 둘 중 하나라도 참이면 true, 그 외 false
	! (not) : true일 경우 false, false일 경우 true를 반환(논리를 뒤집어 주는 연산자)

	1. true (&&) false => false
	2. true (||) false => true
	3. true (&&, ||) true => true
	4. (!)true	=> false
	5. (!)false  => true
*/

	//scanf

/*
	int num;

	scanf_s("%d", &num); //_s없으면 보안때문에 오류남, 실행창에서 내가 직접 num을 초기화(수 대입)를 할 수 있게 해줌
	//scanf 안에는 \n을 쓰지 못 하고, 변수 앞에 &를 써야 함
	printf("%d\n", num);
	
*/

/*
	int num1, num2, num3;

	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("%d %d %d\n", num1, num2, num3);
*/

	//조건 연산자 - 삼항 연산자
	//조건식 ? 반환값1(참일 경우) : 반환값2(거짓일 경우)


#pragma region Attack // 코드 접었다 펼 수 있는 지역 설정
	int playerDamage = 50;
	int enemyHp = 550;

	printf("플레이어의 공격력 : %d\n", playerDamage);
	printf("현재 적의 체력 : %d\n\n", enemyHp);

	int attackCount = 0;
	printf("몇 번 공격하시겠습니까? : ");
	scanf_s("%d", &attackCount);

	enemyHp -= playerDamage * attackCount; //enemyHp = enemyHp - playerDamage * attackCount
	printf("현재 적의 체력 : %d\n\n", enemyHp);



#pragma endregion //끝나는 곳


#pragma region Grab
	int grabRange;
	int distance = 300;
	bool catchenemy = true; //true(1)나 false(0)를 출력하는 함수 bool

	printf("적과의 거리 :%d\n", distance);

	printf("그랩 사거리 : ");
	scanf_s("%d", &grabRange);

	grabRange >= distance ? catchenemy = true : catchenemy = false;

	printf("적을 처치하였나요? : %d\n", catchenemy);



#pragma endregion



	return 0;
}