#include <iostream>
//���ο��� ����Ʈ�� ������� 
/*
Hour h(1);
PrintHour(h); //1�ð�
PrintMinute(h); //60
PrintSecond(h); //60*60
PrintMilliSecond(h); //60*60*60
*/
using namespace std;

class Hour
{
	int h;

public:
	Hour(int h) : h(h) {}
	int getHour() const { return h; }
};

class Minute
{
	int m;

public:
	Minute(int m) : m(m) {}
	int getMinute() const { return m; }
};

class Second
{
	int s;

public:
	Second(int s) : s(s) {}
	int getSecond() const { return s; }
};

class MilliSecond
{
	int ms;

public:
	MilliSecond(int ms) : ms(ms) {}
	int getMilliSecond() const { return ms; }
};

void PrintHour(const Hour& data)
{
	cout << data.getHour() << "��" << endl;
}

void PrintMinute(const Hour& data)
{
	cout << data.getHour() * 60 << "��" << endl;
}

void PrintSecond(const Hour& data)
{
	cout << data.getHour() * 60 * 60 << "��" << endl;
}

void PrintMilliSecond(const Hour& data)
{
	cout << data.getHour() * 60 * 60 * 1000 << "�и���" << endl;
}

int main()
{
	Hour h(1);
	PrintHour(h);
	PrintMinute(h);
	PrintSecond(h);
	PrintMilliSecond(h);
	return 0;
}

