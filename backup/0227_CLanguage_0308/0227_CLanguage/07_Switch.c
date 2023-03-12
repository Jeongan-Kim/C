#include <stdio.h> //# : 전 처리기, 이 프로그램을 시작하기 전에 포함해 주세요 라는 뜻

//매크로 상수(각 문자를 옆 숫자로 치환) : 코드는 알아보기 쉽게 만드는 게 중요하기 때문에 이를 사용하면 편함
#define Game 1
#define GameManual 2
#define Option 3
#define Exit 4
/*
	switch(변수) //break를 만나기 전까지 실행이 되는 함수
	{
	case 값 :
		명령;
		break;
	case 값2 : 
		명령;
		break;
	default :
		예외 명령 처리;
		break;
	}

*/

int main()
{
	//int selmenu;
	//printf("메뉴를 선택하세요 [1. 게임 시작, 2. 게임 설명, 3. 설정 4. 종료]"); //조건이 긴 문장이 아니라 딱딱 나뉘어 있을때에는 switch문을 씀
	//printf("\n입력 : ");
	//scanf_s("%d", &selmenu);

	//switch (selmenu)
	//{
	//case 1:
	//	printf("\n게임을 시작합니다\n");
	//	break;
	//case 2:
	//	printf("게임 설명\n");
	//	break;
	//case 3:
	//	printf("게임 설정\n");
	//	break;
	//case 4:
	//	printf("게임 종료\n");
	//	break;
	//default:
	//	printf("잘못 입력하셨습니다\n");
	//	break;
	//}

	//char selmenu;
	//printf("메뉴를 선택하세요 [1. 게임 시작, 2. 게임 설명, 3. 설정 4. 종료]"); //조건이 긴 문장이 아니라 딱딱 나뉘어 있을때에는 switch문을 씀
	//printf("\n입력 : ");
	//scanf_s(" %c", &selmenu);

	//switch (selmenu)
	//{
	//case Game:
	//	printf("\n게임을 시작합니다\n");
	//	break;
	//case GameMenual:
	//	printf("게임 설명\n");
	//	break;
	//case Option:
	//	printf("게임 설정\n");
	//	break;
	//case Exit:
	//	printf("게임 종료\n");
	//	break;
	//default:
	//	printf("잘못 입력하셨습니다\n");
	//	break;
	//}

	int time = 0;
	int number = 0;

	printf("시간을 입력해 주세요 : ");
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
		printf("정오\n"); //뒷 내용이 없어서 브레이크 딱히 안써줌..(?)
	default:
		break;  //디폴드 값이 없으면 그냥 브레이크만 걸어도 됨
	}
	return 0;
}