#include <iostream>

//���� ������ : � Ư�� ��� ������ �ٸ� �ɷ� �ʱ�ȭ�ϰ� ������ ���

using namespace std;

class Student
{
public:
	Student(const int& id, const string& name) //�޾ƿ��鼭 �ٲ�� �ȵǴϱ� const�� �ٿ��� �����ϰ�
		:id(id), name(name) // �̸��� ���Ƶ� ��ȣ�� ���� ������ �ǹǷ� ������.
	{}

	//id�� 0���� �ΰ�, �̸��� ��� �ٲٰ� �ʹٸ�
	Student(const string& name) 
		:Student(0, name) //�ٽ� ���� �ҷ��� �̷��� �ϸ� ��.(���� ������)
	{}

private:
	int id;
	string name;
};

//�ٸ� ���
class Student2
{
public:
	Student(const int& id, const string& name)
	{
		Initialize(id, name);
	}

	Student2(const string& name)
	{
		Initialize(0, name);
	}

	void Initialize(const int& id, const string& name)
	{
		//TODO : ���߿� �ʱ�ȭ ���ֱ� // ���� - �۾���Ͽ��� �� �� ���� ( �ּ� ���� ã�� ��� )
	}

private:
	int id;
	string name;
};

int main()
{

	return 0;
}