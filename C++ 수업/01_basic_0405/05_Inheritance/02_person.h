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

// 이렇게 두 클래스가 멤벼 변수, 함수가 겹치는 게 많을 때, 공통적인 요소를 묶는 클래스를 만들기도 함. person을 물려 받아서 각각 재정의하는 방식

class Person
{
protected: //자식에서 사용할 수 있게.
	std::string name;

public:
	Person() = default; //기본 생성자
	Person(const std::string& name) //이 생성자를 만들면서 기본 생성자가 없어지는데, 자식 클래스에서는 기본 생성자가 필요하므로 위에 기본 생성자를 만들어 줌.
		:name(name)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }
};