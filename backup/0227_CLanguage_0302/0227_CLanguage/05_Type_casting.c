#include <stdio.h>

int main()
{
	//자동 형변환
	//작은 걸 큰 형으로 넣을때(데이터 손실을 줄일 수 있다.)
	short s1 = 10;
	int i = s1; //컴퓨터에서 자동 형변환이 되어 s는 int인 것처럼 됨 = (int)s1

	float f1 = 100; //100은 int형이지만 float형으로 됨 = (float)100
	printf("%f\n", f1); //실수는 정확하게 표현이 힘들기 때문에 100.00000이라고 뜸


	//큰 걸 작은 형으로 넣을때
	int i2 = 500;
	unsigned char c1 = i2; //unsigned char는 0~255이므로 넘쳐서 데이터 손실이 남
	printf("%d\n", c1);

	float f2 = 1.25f;
	int i3 = f2; //소수점 아래 수를 버리게 된다.
	printf("%d\n", i3);



	/*
	Ranking of types operations
	-long double > double > float
	-unsigned long long == long long
	-unsigned long == long
	-unsigned int == int
	-unsigned short == short
	-unsigned char == char //1byte
	-bool //1bit
	
	*/

	//명시적 형변환
	//int a = 10, b = 4;
	//float div = a / b;  //a와 b를 형 변환없이 해서 값이 틀림
	//printf("%f\n", div);

	int a = 10, b = 4;
	float div = (float)a / b; //임의로 float형으로 변환(명시적 형변환), 강제적이기에 좋은 것만은 아님
	printf("%f\n", div);

	return 0;
}