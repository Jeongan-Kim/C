#include "stdafx.h"
#include "Math.h"


std::random_device Math::rd;
std::mt19937 Math::mt(rd());  //Math 클래스에 있다고 알려준 뒤, 초기화(전역에서)

const int Math::Random(const int& min, const int& max)
{
	return std::uniform_int_distribution<int>{min, max}(mt);
}

const float Math::Random(const float& min, const float& max)
{
	return std::uniform_real_distribution<float>{min, max}(mt);
}
