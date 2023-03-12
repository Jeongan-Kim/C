#include <stdio.h>
#define Game 1
#define GameManual 2
#define Option 3
#define Exit 4

int main()
{
	//short s1 = 10;
	//int i = s1;

	//float f1 = 100;
	//printf("%f\n", f1);

	//int i2 = 500;
	//unsigned char c1 = i2;
	//printf("%d\n", c1);

	//float f2 = 1.25f;
	//int i3 = f2;
	//printf("%d\n", i3);

	//int a = 10, b = 4;
	//float div = (float)a / b; //a는 명시적 형변환이 된 것이고, b는 자동 형변환이 된 것이다. 둘 중 큰 형으로 바뀜.
	//printf("%f\n", div);

	//int number = 0;
	//printf("정수를 입력해 주세요 : ");
	//scanf_s("%d", &number);

	//if (number % 2 == 0)
	//	printf("짝수\n");
	//else
	//{
	//	printf("짝수가 아니네요\n");
	//	printf("홀수\n");
	//}

	//char key;

	//printf("어느 방향으로 가시겠습니다? : ");
	//scanf_s(" %c", &key, sizeof(key));

	//if (key == 'w')
	//	printf("위");
	//else if (key == 's')
	//	printf("아래");
	//else if (key == 'a')
	//	printf("왼쪽");
	//else if (key == 'd')
	//	printf("오른쪽");
	//else
	//	printf("잘못 입력하였습니다.");

	//int number2;
	//printf("숫자를 입력해 주세요 : ");
	//scanf_s("%d", &number2);
	//if (number2 < 10)
	//{
	//	if (number2 <= 5)
	//		printf("5보다 작거나 같은 수");
	//	else
	//		printf("5보다 크고 10보다 작은 수");
	//}
	//else
	//	printf("10보다 크거나 같은 수 입니다.");

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

	//char c3;
	//scanf_s("%c", &c3);
	//printf("%c", c3);


	//int selmenu;
	//printf("메뉴를 선택하세요. [1. 게임시작, 2. 게임 설명, 3. 설정, 4. 종료]");
	//scanf_s("%d", &selmenu);

	//switch (selmenu)
	//{
	//	case 1:
	//		printf("게임을 시작합니다.");
	//		break;
	//	case 2:
	//		printf("게임 설명을 봅니다.");
	//		break;
	//	case 3:
	//		printf("게임 설정");
	//		break;
	//	case 4:
	//		printf("게임을 종료합니다.");
	//		break;
	//	default:
	//		printf("잘못 입력하였습니다.");
	//		break;

	//}

	
	//int selmenu;
	//printf("메뉴를 선택하세요. [1. 게임시작, 2. 게임 설명, 3. 설정, 4. 종료]");
	//printf("\n입력 : ");
	//scanf_s("%d", &selmenu);

	//switch (selmenu)
	//{
	//case Game:
	//	printf("게임을 시작합니다.");
	//	break;
	//case GameManual:
	//	printf("게임 설명을 봅니다.");
	//	break;
	//case Option:
	//	printf("게임 설정");
	//	break;
	//case Exit:
	//	printf("게임을 종료합니다.");
	//	break;
	//default:
	//	printf("잘못 입력하였습니다.");
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
printf("잘못 입력하였습니다.\n");

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
	break;
default:
	break;
}
	return 0;
}