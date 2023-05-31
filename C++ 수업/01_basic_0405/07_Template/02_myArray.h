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
* 템플릿 코드는 컴파일 타임에 사용될때 구현이 됨. 그때 inline화됨.->사용 시점에 구체화되어 있어야 하므로 구현 부를 한꺼번에 만들어 줘야 함.
* 즉, 헤더와 cpp파일로 linking(컴파일 타임 이후)되어 연결되어 있으면 안됨.
	1. 헤더파일에 정의부를 쓴다.
	2. cpp 파일을 메인 파일에 헤더파일로 넣는다.
	3. cpp 파일을 inl파일로 만들어서 정의부 넣고 메인 파일에 헤더파일로 넣기.//inl 파일 속성에서 c/c++참여하게 적용.
*/
