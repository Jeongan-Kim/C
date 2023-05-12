#pragma once

class Teacher
{
	std::string name;

public:
	Teacher(const std::string name)
		:name(name)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name; }
};