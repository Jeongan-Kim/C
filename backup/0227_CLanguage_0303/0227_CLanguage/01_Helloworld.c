#include <stdio.h> //std + io
/*
기본도구들!
std : standard
io : input/output
.h : 헤더파일

*/

int main() //main 함수, 프로그래밍을 하는 것, 프로그래밍의 시작점, 괄호 자체가 함수
/*
{ 함수의 시작
} 함수의 끝
*/
{
	printf("Hello, World!\n"); //출력, \n : 줄바꿈, ; : 문장이 끝났다는 의미(꼭 붙이기!!)
	/*
	Escape sequence(여러가지 알아오기-과제)
	-\n, \t(탭, 여러 칸 띄우기, 8칸). \a....

	*/
	
	printf("10\n");
	printf("%d\n", 10); //d 안에 10을 넣으라는 의미, d는 정수, format specifier(conversion specifier,서식 지정자)
	printf("%d\t %d %d %d %d\n", 1, 2, 3, 4, 5);
	
	printf("안녕하세요. 김정안입니다.\n 나이는 % d살이고, 취미는 게임과 요리입니다.\n 제 mbti는 ENFP입니다.\n", 29);

	return 0; //반환, 함수가 종료될때 반환 값을 반환함으로써 종료를 알림
}

/*
이름 : 
나이 : 
취미 :
MBTI :

*/

/*
조사 과제
-Escape sequence
-format specifier

*/
