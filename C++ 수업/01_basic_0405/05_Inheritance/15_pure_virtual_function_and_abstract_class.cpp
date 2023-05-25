#include <iostream>
//���� ���� �Լ�(pure virtual function) : �ڽ� Ŭ���� ���ο��� �ݵ�� �������ؾ� �ϴ� �Լ�.
//Ŭ���� ���ο��� ���ǰ� �ȵ� �Լ��� ���Ѵ�. -> ��ü�� ������ �� ����.

//�߻� Ŭ����(abstract class) : �ϳ� �̻��� ���� ���� �Լ��� ������ �ִ� Ŭ����

//interface : Ư�� ����� ������ ���� ����� �߻� ����. Ŭ���� �տ� I�� �ٿ��� ���⵵ ��. -> ���� ���� �Լ��θ� �̷���� Ŭ����.

using namespace std;

#pragma region abstract class
	//
	//class animal abstract //�߻� Ŭ����. abstract �� �ٿ��൵ ��.
	//{
	//	string name;
	//
	//public:
	//	animal(const string& name) : name(name) {}
	//
	//	auto getname() const { return name; }
	//
	//	virtual void sleep() const final // �ڽ� Ŭ�������� ������ ������ ��� �޾��� �� �������̵��� ������ ���� ��(Ư���� �ٲ��� ����)�̸� final�� �ٿ�����
	//	{
	//		cout << "sleep" << endl;
	//	}
	//
	//	virtual void speak() const abstract = 0; //���� ���� �Լ�.
	//};
	//
	//class cat : public animal
	//{
	//public:
	//	cat(string name) : animal(name) {}
	//
	//	void speak() const{ cout << "�߿�" << endl; }
	//};
	//
	//class dog : public animal
	//{
	//public:
	//	dog(string name) : animal(name) {}
	//
	//	void speak() const { cout << "�۸�" << endl; }
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
	//	//animal ani("asdfsdad"); //���� �����Լ��� �ϳ��� �������� ��ü�� ���� �� ����.
	//
	//	cat c("cc");
	//	dog d("dd");
	//	//fox f("ff"); //���� ���� �Լ��� ���������� �ʾ����Ƿ� ��� �Ұ�.
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
//���� ������ ���� ������ ������
class IErrorLog //�������̽��ϱ� I�� �ٿ��� �˷���
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) = 0;//���� ���� �Լ�
	//virtual bool ReportError(const char* const error) abstract; //�̷��Ե� ��Ÿ��.
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
	//IErrorLog f; //���� �����Լ��� �־ ��ü�� ���� �� ����.
	FileErrorlog fileLog;
	ConsoleErrorlog consoleLog;

	DoSomething(fileLog);
	DoSomething(consoleLog);
	return 0;
}

#pragma endregion