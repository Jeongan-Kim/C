#include <stdio.h>
#include <conio.h> //콘솔 입출력 함수

/*
	while(조건식)
	{
		명령문; //조건이 참일 경우 명령문이 특정 조건을 만족할때까지 실행이 반복됨.
	}
*/

int main()
{
	//while
	bool study = true;

	while (study) //study 는 참이므로 무조건 실행되는 함수를 만든 것 -> 무한 루프가 되지 않게 종료 조건을 만들어 줘야 함
	{
		printf("Hello world\n");

		printf("공부 중인가요? [네 : 1, 아니요 : 0] -> ");
		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == 0)
		{
			study = false;
			//break; 도 가능
		}
	}

	char key;

	while (true) //무한 반복문
	{
		printf("이동키 입력 : ");
		key = _getch(); //scanf로 받으면 이동키가 바로바로 입력이 안되고 딜레이가 생기기에 바로바로 출력되는 함수(_getchar())

		if (key == 'q')
			break;

		switch (key)
		{
		case 'w': printf("상\n"); break;
		case 's': printf("하\n"); break;
		case 'a': printf("좌\n"); break;
		case 'd': printf("우\n"); break;
		default: printf("잘못누름\n"); break;
		}
	}

	//do while
	/*
		do
		{
			명령문;
		}while(조건식) // 반드시 한 번은 실행 되고, 조건이 참이면 그 이후도 반복됨
	*/

	const int secretCode = 123123; //constant : 상수화 시켜서 변하지 않는 고정된 수로 설정.

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

		tryCount++; //tryCount += 1;

	} while (password != secretCode);


	return 0;
}

