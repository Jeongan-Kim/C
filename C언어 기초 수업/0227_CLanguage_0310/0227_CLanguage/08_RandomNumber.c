#include <stdio.h>
#include <stdlib.h> //표준 함수 라이브러리
#include <time.h> //시간 관련 함수 라이브러리

/*
	난수 //랜덤한 수 출력함수, 완전 무작위는 아니고 어떠한 시드 값에 의해 뽑힘
	-rand()

*/

int main()
{
	printf("%d, ", rand() % 10); //% 라는 나머지 연산자를 사용해서 10으로 나누었을때 나머지가 0~9까지임을 이용해서 수의 범위를 제한함.
	printf("%d, ", rand() % 10 + 1); //1~10
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("\n\n");

	//srand() : 시드값을 변경해 주는 함수, 늘 변하는 시간을 넣을 수 있음

	srand((unsigned int)time(NULL)); //NULL : 아무 것도 없다는 의미, 시간은 음수가 없으므로 time 앞에 unsigned int 를 붙이는 것이 정형화된 표현

	printf("%d, ", rand() % 10 + 1); 
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("\n\n");

	return 0;
}

/*
	<과제>

	가위, 바위, 보 게임 만들기
	상대는 랜덤으로 가위 바위 보를 냄
	이겼는지, 졌는지, 비겼는지 출력되는 게임
	여러 번 실행되도록 하기

	Up&Down Game (1~100) 답은 랜덤 값으로
	- 10번 내로 정답 맞히기

*/