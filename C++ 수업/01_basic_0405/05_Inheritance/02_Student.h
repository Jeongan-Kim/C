#pragma once
#include "02_person.h"

//class Person; //�̷� ���� �������δ� ������ �޾ƿ����� ����. person Ŭ������ �ִٴ°͸� �˰� ��. �׷��� ��������� �־�� ��

class Student : public Person //��� ���� ������
{
//	std::string name;

public:
	Student(const std::string& name) //�ڽ� Ŭ������ ��� �θ� Ŭ������ ������ �ִٸ� �ʱ�ȭ�� �����ϴ�.
		:Person(name)
	{}

	void Study() {} //Ȯ�� : �ڽ� Ŭ�������� �Լ�

	//auto GetName() const { return name; }
	//void SetName(const std::string& name) { this->name = name; }
	//�θ� Ŭ������ ��ġ�� �κ� ���� ����
};
