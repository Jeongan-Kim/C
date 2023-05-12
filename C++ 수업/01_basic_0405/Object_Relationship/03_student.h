#pragma once

class Student
{
	std::string name;
	int count;

public:
	Student(const std::string& name, int count = 0)
		: name(name), count(count)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name; }

	auto GetCount() const { return count; }
	void SetCount(const std::string& count) { this->count; }
};