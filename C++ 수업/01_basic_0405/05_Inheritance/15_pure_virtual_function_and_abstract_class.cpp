#include <iostream>
//순수 가상 함수(pure virtual function) : 자식 클래스 내부에서 반드시 재정의해야 하는 함수.
//클래스 내부에서 정의가 안된 함수를 말한다. -> 객체를 생성할 수 없음.

//추상 클래스(abstract class) : 하나 이상의 순수 가상 함수를 가지고 있는 클래스

//interface : 특정 기능을 구현할 것을 약속한 추상 형태. 클래스 앞에 I를 붙여서 쓰기도 함. -> 순수 가상 함수로만 이루어진 클래스.

using namespace std;

#pragma region abstract class
	//
	//class animal abstract //추상 클래스. abstract 안 붙여줘도 됨.
	//{
	//	string name;
	//
	//public:
	//	animal(const string& name) : name(name) {}
	//
	//	auto getname() const { return name; }
	//
	//	virtual void sleep() const final // 자식 클래스들이 공유는 하지만 상속 받았을 때 오버라이딩을 하지는 않을 것(특별히 바뀌지 않을)이면 final을 붙여버림
	//	{
	//		cout << "sleep" << endl;
	//	}
	//
	//	virtual void speak() const abstract = 0; //순수 가상 함수.
	//};
	//
	//class cat : public animal
	//{
	//public:
	//	cat(string name) : animal(name) {}
	//
	//	void speak() const{ cout << "야옹" << endl; }
	//};
	//
	//class dog : public animal
	//{
	//public:
	//	dog(string name) : animal(name) {}
	//
	//	void speak() const { cout << "멍멍" << endl; }
	//};
	//
	//class fox : public animal
	//{
	//public:
	//	fox(string name) : animal(name) {}
	//};
	//
	//int main()
	//{
	//	//animal ani("asdfsdad"); //순수 가상함수를 하나라도 가졌으면 객체를 만들 수 없다.
	//
	//	cat c("cc");
	//	dog d("dd");
	//	//fox f("ff"); //순수 가상 함수를 재정의하지 않았으므로 사용 불가.
	//
	//	c.sleep();
	//	d.sleep();
	//
	//	c.speak();
	//	d.speak();
	//	return 0;
	//}
#pragma endregion

#pragma region Interface
//파일 에러를 띄우는 구문을 만들어보자
class IErrorLog //인터페이스니까 I를 붙여서 알려줌
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) = 0;//순수 가상 함수
	//virtual bool ReportError(const char* const error) abstract; //이렇게도 나타냄.
};

class FileErrorlog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error) override
	{
		cout << "writting error to a file" << endl;
		return true;
	}
};

class ConsoleErrorlog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error) override
	{
		cout << "writting error to a console" << endl;
		return true;
	}
};

void DoSomething(IErrorLog& log)
{
	log.ReportError("Error");
}

int main()
{
	//IErrorLog f; //순수 가상함수가 있어서 객체를 만들 수 없음.
	FileErrorlog fileLog;
	ConsoleErrorlog consoleLog;

	DoSomething(fileLog);
	DoSomething(consoleLog);
	return 0;
}

#pragma endregion