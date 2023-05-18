#pragma once
#include "02_person.h"

class Teacher
{
//	std::string name;

public:
	Teacher(const std::string& name)
		:Person(name)
	{}

//	auto GetName() const { return name; }
//	void SetName(const std::string& name) { this->name = name; }

	void Teach() { } //»Æ¿Â
};