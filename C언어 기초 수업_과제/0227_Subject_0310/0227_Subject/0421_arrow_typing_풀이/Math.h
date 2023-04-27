#pragma once

class Math //랜덤 작업
{
public:
	static const int Random(const int& min, const int& max);
	static const float Random(const float& min, const float& max);

private:
	static std::random_device rd; //원래는 선언된 순간부터 프로그램 끝날때까지 전역변수처럼 쓰임. 모든 클래스에서 쓸 수 있음.
	static std::mt19937 mt;
};

