#include <iostream>
#include <chrono>
//���� ����

using namespace std;
using namespace std::chrono;

class Timer
{
	time_point<high_resolution_clock> start_time;
public:
	Timer()
	{
		start_time = high_resolution_clock::now(); //���� �ð����� �ʱ�ȭ
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli>delta = current_time - start_time; //����� �ð� ���

		cout << delta.count() << endl;
	}
};

class Worker
{
public:
	void DoSomething()
	{
		Timer timer; //�󸶳� ���ߴ°�
		for (int i = 0; i < 100000000; i++); //�׳� �ð��� �����Բ� �� ��.
		timer.Elapsed(); //��� ������ ���� ��.
	}
};

int main()
{
	Worker w;
	w.DoSomething();

	return 0;
}

/*
	���� �� ���� ���� �ϱ�
	���� ���� �ý��� �����(���� ������, ���� ���� ������ ���鼭)
	1. ���� ����(�� ���� �Է�)
	2. �Ա�
	3. ���
	4. �������� ��ü ���
	�� ��ȣ �Է��ϸ� ����Ǵ� ���α׷�.
*/