#include <iostream>

using namespace std;
//�����ϰ� ������ �� ���� struct �� ����, ������ ��Ÿ���� �׷� ������ class�� ����.
struct person
{
private : //struct�� ���� �����ڸ� �� �� ������ private�� �������� �� classó�� �ڵ����� ���е����� ����.

	string name;
	int age;
	float height;
	float weight;
	bool favorite;
};

//class ���� ���
class Person //���� ��ü�� ĸ��ȭ, ���� �����ڸ� ���� ������ ���� ���� ������ �� ����
{
	/*string name;
	int age;
	float height;
	float weight; 
	bool favorite;*/  //�̷��� ���� �׳� ���ָ� private�� ������ �ڵ����� ���е� ������ �νĵ�.

public: //Ȱ������ �ٷ�
	void Work()
	{

	}
	
	void Sleep()
	{

	}

protected: //���� �ڽ� Ŭ���������� �� �� �ִ� ����

private: //�� �ȿ����� ��� ������ ����, ���� ������ �ٷ�
	string name;
	int age;
	float height;
	float weight;
	bool favorite;
};

int main()
{
	Person p; // �̷��� �ؾ� ��ü�� ���ܼ� object, instance��� �� �� ����
	person p1;

	//p1.age= 1;
	p.Sleep();

	return 0;
}