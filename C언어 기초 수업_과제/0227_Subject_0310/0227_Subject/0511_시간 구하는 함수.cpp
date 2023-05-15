#include <iostream>
//메인에서 프린트로 찍었을때 
/*
Hour h(1);
PrintHour(h); //1시간
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
	cout << data.getHour() << "시" << endl;
}

void PrintMinute(const Hour& data)
{
	cout << data.getHour() * 60 << "분" << endl;
}

void PrintSecond(const Hour& data)
{
	cout << data.getHour() * 60 * 60 << "초" << endl;
}

void PrintMilliSecond(const Hour& data)
{
	cout << data.getHour() * 60 * 60 * 1000 << "밀리초" << endl;
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

