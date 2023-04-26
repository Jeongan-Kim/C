#include "08_Calcu.h"
//함수 정의부는 cpp에 쓰는 경우가 많음. 자동 inline화 될 정도로 정의부가 짧을 경우에는 헤더파일에 두는 것도 방법.
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



