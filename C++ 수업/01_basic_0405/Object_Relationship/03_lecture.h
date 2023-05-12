#pragma once
#include <iostream>
#include <vector>
#include "03_student.h"
#include "03_teacher.h"

class Lecture
{
	std::string name;

	Teacher* teacher;
	std::vector<Student*> students; //학생은 여러명이니 벡터로 동적할당

public:
	Lecture(const std::string& name)
		:name(name)
	{}

	void AssignmentTeacher(Teacher* teacher) //선생님 할당
	{
		this->teacher = teacher;
	}

	void AssignmentStudent(Student* student) //학생 할당
	{
		students.push_back(student);
	}

	void Print() //주소를 찍는 것
	{
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students) //학생은 벡터니까 범위기반 for문으로 찍어주자.
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}
};