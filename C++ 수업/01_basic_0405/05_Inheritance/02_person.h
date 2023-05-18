#pragma once
#include <string>


//class Student
//{
//	std::string name;
//
//public:
//	Student(const std::string& name)
//		:name(name)
//	{}
//
//	auto GetName() const { return name; }
//	void SetName(const std::string& name) { this->name = name; }
//
//	void Study() { }
//};
//
//class Teacher
//{
//	std::string name;
//
//public:
//	Teacher(const std::string& name)
//		:name(name)
//	{}
//
//	auto GetName() const { return name; }
//	void SetName(const std::string& name) { this->name = name; }
//
//	void Teach() { }
//};

// �̷��� �� Ŭ������ �⺭ ����, �Լ��� ��ġ�� �� ���� ��, �������� ��Ҹ� ���� Ŭ������ ����⵵ ��. person�� ���� �޾Ƽ� ���� �������ϴ� ���

class Person
{
protected: //�ڽĿ��� ����� �� �ְ�.
	std::string name;

public:
	Person() = default; //�⺻ ������
	Person(const std::string& name) //�� �����ڸ� ����鼭 �⺻ �����ڰ� �������µ�, �ڽ� Ŭ���������� �⺻ �����ڰ� �ʿ��ϹǷ� ���� �⺻ �����ڸ� ����� ��.
		:name(name)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }
};