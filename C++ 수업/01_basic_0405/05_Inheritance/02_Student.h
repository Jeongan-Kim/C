#pragma once
#include "02_person.h"

//class Person; //이런 전방 선언으로는 내용을 받아오지는 않음. person 클래스가 있다는것만 알게 됨. 그래서 헤더파일을 넣어야 함

class Student : public Person //상속 접근 지정자
{
//	std::string name;

public:
	Student(const std::string& name) //자식 클래스에 없어도 부모 클래스에 변수가 있다면 초기화가 가능하다.
		:Person(name)
	{}

	void Study() {} //확장 : 자식 클래스만의 함수

	//auto GetName() const { return name; }
	//void SetName(const std::string& name) { this->name = name; }
	//부모 클래스와 겹치는 부분 삭제 가능
};
