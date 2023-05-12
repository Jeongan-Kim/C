#pragma once
#include <iostream>
#include <vector>
#include "03_student.h"
#include "03_teacher.h"

class Lecture
{
	std::string name;

	Teacher* teacher;
	std::vector<Student*> students; //�л��� �������̴� ���ͷ� �����Ҵ�

public:
	Lecture(const std::string& name)
		:name(name)
	{}

	void AssignmentTeacher(Teacher* teacher) //������ �Ҵ�
	{
		this->teacher = teacher;
	}

	void AssignmentStudent(Student* student) //�л� �Ҵ�
	{
		students.push_back(student);
	}

	void Print() //�ּҸ� ��� ��
	{
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students) //�л��� ���ʹϱ� ������� for������ �������.
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}
};