#include <iostream>
#include <chrono>
//의존 관계

using namespace std;
using namespace std::chrono;

class Timer
{
	time_point<high_resolution_clock> start_time;
public:
	Timer()
	{
		start_time = high_resolution_clock::now(); //현재 시간으로 초기화
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli>delta = current_time - start_time; //경과된 시간 계산

		cout << delta.count() << endl;
	}
};

class Worker
{
public:
	void DoSomething()
	{
		Timer timer; //얼마나 일했는가
		for (int i = 0; i < 100000000; i++); //그냥 시간만 보내게끔 쓴 것.
		timer.Elapsed(); //잠깐 가져다 쓰는 것.
	}
};

int main()
{
	Worker w;
	w.DoSomething();

	return 0;
}

/*
	지난 주 못한 과제 하기
	은행 계좌 시스템 만들기(복사 생성자, 복사 대입 생성자 쓰면서)
	1. 계좌 개설(고객 정보 입력)
	2. 입금
	3. 출금
	4. 계좌정보 전체 출력
	각 번호 입력하면 실행되는 프로그램.
*/