#include "08_Calcu.h"
//�Լ� ���Ǻδ� cpp�� ���� ��찡 ����. �ڵ� inlineȭ �� ������ ���Ǻΰ� ª�� ��쿡�� ������Ͽ� �δ� �͵� ���.
Calcu::Calcu(int value) : value(value) {}

inline Calcu& Calcu::Add(int value)
{
	{ this->value += value; return *this; }
}

inline Calcu& Calcu::Sub(int value)
{
	{ this->value -= value; return *this; }
}
inline Calcu& Calcu::Mul(int value)
{
	{ this->value *= value; return *this; }
}
inline Calcu& Calcu::Div(int value)
{
	{ this->value /= value; return *this; }
}
inline Calcu& Calcu::Mod(int value)
{
	{ this->value %= value; return *this; }
}



