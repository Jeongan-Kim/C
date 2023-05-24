#include <iostream>
//���� ���� �Լ�(pure virtual function) : �ڽ� Ŭ���� ���ο��� �ݵ�� �������ؾ� �ϴ� �Լ�.
//Ŭ���� ���ο��� ���ǰ� �ȵ� �Լ��� ���Ѵ�. -> ��ü�� ������ �� ����.

//�߻� Ŭ����(abstract class) : �ϳ� �̻��� ���� ���� �Լ��� ������ �ִ� Ŭ����

//interface : Ư�� ����� ������ ���� ����� �߻� ����. Ŭ���� �տ� I�� �ٿ��� ���⵵ ��. -> ���� ���� �Լ��θ� �̷���� Ŭ����.

using namespace std;

class animal abstract //�߻� Ŭ����. abstract �� �ٿ��൵ ��.
{
	string name;

public:
	animal(const string& name) : name(name) {}

	auto getname() const { return name; }

	virtual void sleep() const final // �ڽ� Ŭ�������� ������ ������ ��� �޾��� �� �������̵��� ������ ���� ��(Ư���� �ٲ��� ����)�̸� final�� �ٿ�����
	{
		cout << "sleep" << endl;
	}

	virtual void speak() const abstract = 0; //���� ���� �Լ�.
};

class cat : public animal
{
public:
	cat(string name) : animal(name) {}

	void speak() const{ cout << "�߿�" << endl; }
};

class dog : public animal
{
public:
	dog(string name) : animal(name) {}

	void speak() const { cout << "�۸�" << endl; }
};

class fox : public animal
{
public:
	fox(string name) : animal(name) {}
};

int main()
{
	//animal ani("asdfsdad"); //���� �����Լ��� �ϳ��� �������� ��ü�� ���� �� ����.

	cat c("cc");
	dog d("dd");
	//fox f("ff"); //���� ���� �Լ��� ���������� �ʾ����Ƿ� ��� �Ұ�.

	c.sleep();
	d.sleep();

	c.speak();
	d.speak();
	return 0;
}