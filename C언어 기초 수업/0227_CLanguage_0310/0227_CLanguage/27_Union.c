#include <stdio.h>
#include <stdbool.h>

//union)공용체

void Union(); //키워드라서 맨첫단어 대문자로.
void union_and_structure();
void union_and_structure2();
void endianness();

int main()
{
	//Union();
	//union_and_structure();
	//union_and_structure2();
	endianness();
	return 0;
}

void Union() //다양한 자료형을 묶는 것. 
{
	struct myStruct
	{
		char c;
		int i;
		double d;
	};

	union myUnion //하나의 변수가 공용으로 원소들을 갖고 있는 것.
	{
		char c;
		int i;
		double d;
	};

	struct myStruct st;
	union myUnion uni;

	printf("구조체 공간의 사이즈\t : %d\n", sizeof(st)); //각 원소 크기의 합은 13인데 16으로 나옴.  가장 큰 크기로 가로 메모리 크기를 잡아서 할당함. 연달아 할당하다가 잘리면 다음 줄에 다시 할당.
	printf("구조체 멤버의 c 사이즈\t : %d\n", sizeof(st.c));
	printf("구조체 멤버의 i 사이즈\t : %d\n", sizeof(st.i));
	printf("구조체 멤버의 d사이즈\t : %d\n\n", sizeof(st.d));

	printf("유니온 공간의 사이즈\t : %d\n", sizeof(uni)); //구조체와 다르게 가장 큰 원소의 메모리 크기를 잡고, 그 메모리를 모든 멤버가 공유함.
	printf("유니온 멤버의 c 사이즈\t : %d\n", sizeof(uni.c));
	printf("유니온 멤버의 i 사이즈\t : %d\n", sizeof(uni.i));
	printf("유니온 멤버의 d사이즈\t : %d\n\n", sizeof(uni.d));

	printf("0x%p\n", &st); //구조체의 주소는 첫번째 부분을 가리킴
	printf("0x%p\n", &st.c);
	printf("0x%p\n", &st.i);
	printf("0x%p\n\n", &st.d);

	printf("0x%p\n", &uni); //그래서 유니온은 전부 같은 주소가 나옴
	printf("0x%p\n", &uni.c);
	printf("0x%p\n", &uni.i);
	printf("0x%p\n\n", &uni.d);

	uni.i = 20;
	printf("%d\n\n", uni.i);

	uni.d = 7.15;
	printf("%d\n", uni.c); //같은 주소를 공유하기에 쓰레기 값이 나옴.
	printf("%d\n", uni.i);//같은 주소를 공유하기에 쓰레기 값이 나옴.
	printf("%g\n\n", uni.d);
}

void union_and_structure()
{
	{
		struct ptr
		{
			union //메모리 낭비없이  안의 원소 중 하나를 선택해서 사용할때 쓰기 좋음.
			{
				int* ip;
				float* fp;
			};
			bool isInt;
		};

		struct ptr ptr;

		int i = 100;
		float f = 200.0f;

		ptr.ip = &i;
		ptr.isInt = true;

		if (ptr.isInt == true)
		{
			printf("ptr : %d\n", *ptr.ip);
		}
		else 
		{
			printf("ptr : %f\n\n", *ptr.fp);
		}

		ptr.fp = &f;
		ptr.isInt = false;

		if (ptr.isInt == true)
		{
			printf("ptr : %d\n", *ptr.ip);
		}
		else
		{
			printf("ptr : %f\n\n", *ptr.fp);
		}
	}

	{
		struct Location
		{
			union
			{
				struct { double x; double y; };
				struct { double arr[2]; };
			};
		};

		struct Location loc = { 1.1, 1.2 };

		printf("%lf, %lf\n", loc.x, loc.y); //첫번째 스타일을 쓴거
		printf("%lf, %lf\n", loc.arr[0], loc.arr[1]); // 두번째 스타일을 쓴거
		//%f는 그냥 실수, %lf는 더블로 롱플롯을 말함.
	}
}



//개인차 또는 회사차 골라쓰기(둘다 메모리를 잡을 필요 없이 공용체로 그때에 맞게 할당되게)

#define PERSONAL 0
#define COMPANY 1

typedef struct
{
	char rrn1[7]; //7개에는 NULL공간이 포함되어 있음, 즉 문자는 6개
	char rrn2[8];
}personalOwner;

typedef struct
{
	char crn1[4];
	char crn2[2];
	char crn3[6];
}companyOwner;

typedef struct
{
	char model[15];
	int status;

	union
	{
		personalOwner po;
		companyOwner co;
	};
}carData;

void printCar(carData data)
{
	if (data.status == PERSONAL)
	{
		printf("%s - %s\n",
			data.po.rrn1,
			data.po.rrn2);
	}
	else if (data.status == COMPANY)
	{
		printf("%s - %s - %s\n",
			data.co.crn1,
			data.co.crn2,
			data.co.crn3);
	}
}


void union_and_structure2()
{
	carData myCar =
	{
		"Avante",
		PERSONAL,
		.po.rrn1 = "111111", //C에서만 되는 선언과 동시에 초기화하는 방법
		.po.rrn2 = "1111111"
	};

	carData companyCar =
	{
		"Avante",
		COMPANY,
		.co.crn1 = "111", 
		.co.crn2 = "2",
		.co.crn3 = "33333",
	};

	printCar(myCar);
	printCar(companyCar);
}

void endianness() //주소 저장방식의 차이
{
	union myUnion
	{
		int i;
		char c;
	};

	union myUnion uni;

	uni.i = 0x12345678;

	printf("i : %x\n", uni.i); // 숫자 2개당 1바이트라서 12345678
	printf("c : %x\n", uni.c); // 12가 아니라 78? => 엔디안 저장 방식!
	//저장된 것 중 가장 마지막 단위를 가장 먼저 저장..(?)
	// => 12 34 56 78 => 78 56 34 12 (little endian 저장 방식) ==> 컴퓨터가 값을 저장할떄 가장 나중 값을 가장 먼저 저장하는 것.

	/*
		Little Endian vs Big Endian
	*/
}