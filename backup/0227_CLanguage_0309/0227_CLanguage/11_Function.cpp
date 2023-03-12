#include <stdio.h>

//함수 선언부()
//{
//	함수 정의부
//}

//전달인자x 반환값o 함수
int getInt(void) //중복되는 귀찮은 함수를 호출해서 쓰기 위해 먼저 씀
{
	printf("숫자를 입력해주세요 : ");

	int n;
	scanf_s("%d", &n);

	return n;
}

//전달인자o 반환값o
int add(int x, int y)
{
	//int result = x + y;
	//return result;

	return x + y;  //계산 값을 바로 반환값으로 넣어줘도됨
}

//전달인자o 반환값x 함수
void ShowNumber(int num)
{
	printf("들어온 값은 : %d\n", num);
}

//전달인자x 반환값x 함수 : 그대로 그냥 출력만 함
void test()
{
	printf("111111111111111111");

	return; //안 써도 되는데 함수를 빠져나가겠다는 의미로 그냥 리턴만 줌.

	printf("222222222222222222"); //위에서 함수를 나왔으므로 이건 무시.
}

int Compare(int num1, int num2); /////////함수 선언부 : main에서 사용하기 위해서는 위에 써 줘야함(밑에 쓰려면 컨트롤 .)


int main(void) //void : 아무것도 없다는 의미, 생략됨, 전달 인자가 들어가는 자리
{
	int x1 = 0;
	int y1 = 0;

	//printf("숫자를 입력해주세요 : ");
	//scanf_s("%d", &x1);

	//printf("숫자를 입력해주세요 : ");   //여러번 쓰기 귀찮으니 위 함수를 호출해 옴
	//scanf_s("%d", &y1);

	x1 = getInt();
	y1 = getInt();

	printf("%d + %d = %d\n", x1, y1, add(x1, y1));

	int num = getInt();
	ShowNumber(num); //함수 호출 방식은 함수 이름과 소괄호까지 가져오기, 전달인자가 있는 경우 안에 값 넣기

	test();

	printf("둘 중 더 큰 수는? %d\n", Compare(x1, y1));

	return 0;
}

int Compare(int num1, int num2) //////////함수 정의부 ( 너무 많으니 main 함수 밑으로 빼주는 것)
{
	if (num1 > num2)
		return num1;
	else
	return num2;
}
