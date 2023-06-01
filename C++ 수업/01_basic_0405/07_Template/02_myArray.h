#pragma once

template <class T> //클래스 멤버 변수 자료형을 통합하고 싶을떄
class myArray
{
public:
	myArray(int length)
		:length(length)
	{
		arr = new T[length];
	}

	~myArray()
	{
		delete[] arr;
	}

	void Print();

private:
	T* arr = nullptr;
	int length = 0;
};

//템플릿 코드의 정의와 선언을 파일에서 분리해 버리면 링크 오류가 남.(사용 시점에 구현 내용이 작성되어 있어야 하기 때문에

/*
* 템플릿 코드는 컴파일 타임에 사용될때 구현이 됨. 그때 inline화됨.->사용 시점에 구체화되어 있어야 하므로 구현부를 한꺼번에 만들어 줘야 함.
* 즉, 헤더와 cpp파일로 linking(컴파일 타임 이후)되어 연결되어 있으면 안됨.
	1. 헤더파일에 정의부를 쓴다.
	2. cpp 파일을 메인 파일에 헤더파일로 넣는다.
	3. cpp 파일을 inl파일로 만들어서 정의부 넣고 메인 파일에 헤더파일로 넣기.//inl 파일 속성에서 c/c++참여하게 적용.
*/

/*
	cpp     -> preprocess(전처리기가 #으로 시작되는 것들을 처리) -> compile(저수준으로 해석) -> assemle(저수준 언어를 기계어로 변환)
	03_.cpp		.i												 .asm/.s					.obj

	-> link(링커가 파일들을 연결시켜서 실행파일로 만들어줌)  -> load(실행파일을 읽어서 ram에 적재) -> cpu(읽기)
		.exe

	템플릿은 compile때 구체화 되므로 preprocess 전처리 시기에는 읽을 수가 없다.
	그래서 정의부가 컴파일 타임 전에 쓰여 있어야 한다(?)
*/
