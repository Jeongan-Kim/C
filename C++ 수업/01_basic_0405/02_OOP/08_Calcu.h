#pragma once
class Calcu
{
	int value;

public:
	Calcu(int value) : value(value) {}

	//void Add(int value) { this->value += value; }
	//void Sub(int value) { this->value -= value; }
	//void Mul(int value) { this->value *= value; }
	//void Div(int value) { this->value /= value; }
	//void Mod(int value) { this->value %= value; }

	Calcu& Add(int value); 
	Calcu& Sub(int value); 
	Calcu& Mul(int value); 
	Calcu& Div(int value); 
	Calcu& Mod(int value); 
};

