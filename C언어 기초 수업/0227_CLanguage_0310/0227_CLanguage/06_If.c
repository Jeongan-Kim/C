#include <stdio.h>


/*
	if(조건식) //조건이 참이면 명령 실행
		명령;
	else if(조건식) //이 조건이 참이면 실행
	else //위 둘다 거짓이라면 이것을 실행
*/
int main()
{
	/*int number = 0;
	printf("정수를 입력해주세요 : ");
	scanf_s("%d", &number);*/

	//if (number % 2 == 0)
	//	printf("짝수\n");
	//if (number % 2 != 0) //if문은 아래 한 문장만 속하므로 여러 문장을 쓰고 싶으면 중괄호 활용해야 함
	//{
	//	printf("짝수가 아니네요\n");
	//	printf("홀수\n");
	//}

	//if를 여러번 쓰기 귀찮으므로 if else를 활용
	//if (number % 2 == 0)
	//	printf("짝수\n");
	//else
	//{
	//	printf("짝수가 아니네요\n");
	//	printf("홀수\n");
	//}

	//char key;
	//
	//printf("어느 방향으로 가시겠습니까? : ");

	//scanf_s(" %c", &key, sizeof(key)); 
	/*
		문자형 스캔할때에는 앞에 한 칸 띄우기(앞에 쓴 공백 등등의 것들도 문자로 치기 때문에 오류가 생기므로)
		또한 문자를 쓸 때에는 오류 방지로 문자의 사이즈도 같이 명시하기도 함
	*/

	//if (key == 'w') //문자형은 작은 따옴표 넣어주기
	//	printf("위");
	//else if (key == 's')
	//	printf("아래");
	//else if (key == 'a')
	//	printf("왼쪽");
	//else if (key == 'd')
	//	printf("오른쪽");
	//else
	//	printf("잘목 입력하였습니다.\n");

	////중첩 if문(if 안에 if)

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
	//	printf("10보다 크거나 같은 수");

	////getchar 함수(%c앞에 공백 주지 않고도 오류 안나게 하는 방법)
	//char c1, c2;
	//int d;

	//printf("문자를 입력하시오 : ");
	//scanf_s("%c", &c1);

	//printf("정수를 입력하시오 : ");
	//scanf_s("%d", &d);

	//getchar(); //버퍼 공간에 데이터(공백, 엔터 포함)가 있을때 비우라는 뜻

	//printf("문자를 입력하시오 : ");
	//scanf_s("%c", &c2);

	//printf("c1 : %c\n, d : %d\n, c2 : %c\n", c1, d, c2);


	char c3;
	scanf_s("%c", &c3);

	printf("%c", c3); //입력한 문자 중 제일 첫 문자만 나옴(char형이라서), 나머지 문자는 버퍼에 저장됨

	return 0;
}

/*
*	<과제>
	A==65
	a==97
	아스키 코드를 이용하여
	대문자 입력하면 소문자로,
	소문자 입력하면 대문자로 출력되는 프로그램 만들기

*/