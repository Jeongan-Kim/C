#include <stdio.h> //표준 입출력 도구
#include <stdbool.h> //standard bool

/*
	Data Type(자료형)
*/

/*
	bit와 byte
	bit : 가장 작은 데이터 단위
	byte : 1byte == 8bit, 수 한 자리 크기
*/

/*
	char
	int
	longlong
	float
	double
	long double
*/
int main()
{
	//char : 한 문자를 표현할 때 사용 - 1byte
	char c1 = 'A';//문자를 넣을 때에는 작은 따옴표를 써야 함
	char c2 = 65; //ASCII(아스틱)코드를 통해 숫자를 컴퓨터가 문자로 해석함

	printf("Character c1 : %c\n", c1);
	printf("Character c2 : %c\n", c2);
	printf("Character size : %d\n", sizeof(char)); //sizeof 는 그 자체의 크기(byte)를 나타냄
	printf("Character size : %d\n", sizeof(c1));

	//정수형
	short s = 1; //2byte (-32768 ~ +32767)
	int num = 0; //4byte (-21억 ~ +21억)
	printf("num : %d\n", num);
	printf("int size : %d\n", sizeof(int));

	//실수형 - 부동(떠서 돌아다닌다)소수점 방식
	float f = 0.123f; //4byte, f를 끝에 붙여줘야 함
	double d = 0.1234; //8byte, double이 float보다 기본형이기에 그냥 써줌

	printf("고정 소수점 : %f\n", f);
	printf("부동 소수점 : %e\n", f); //부동소수점을 표기하는 알파벳은 e

	//부동 소수점의 오차
	float sum = 0.1f;

	for (int i = 0; i < 1000; i++) //반복문, 0.1을 1000번 더한다는 뜻
	{
		sum += 0.1;
	}

	printf("%f\n", sum);


	//논리형
	bool isDash = true; //1byte
		//bool isDash = false라고 하면 아래 0이 출력될 것임

	printf("캐릭터 대쉬 유무 : %d\n", isDash);

	unsigned char c3; //양과 음수를 구별하지 않고 위로 두배 불리는 것 0 ~ 255
	unsigned int i2; //0 ~ 42억

	//char cc = 129;
	//printf("%d\n", cc);
	//char형은 127까지밖에 없기 때문에 넘쳐서 -127이 나온다.

	unsigned char cc = 129;
	printf("%d\n", cc);

	signed int ii;

	return 0; //int main이기 때문에 정수형으로 반환하여 프로그램을 끝내겠다는 뜻
}

/*
	<조사 과제>
	ASCII 코드가 어떤 방식으로 이루어져 있는지, 어떤 것인지 조사하기
	컴퓨터의 실수 표현 방식

*/