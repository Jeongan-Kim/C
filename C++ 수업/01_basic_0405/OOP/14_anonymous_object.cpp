#include <iostream>

using namespace std;

class A
{
public:
	void print() //한번 쓰고 말 것같은 것은 굳이 실체화하지 말고 익명객체화하자.
	{
		cout << "print" << endl; 
	}
};

int main()
{
	A().print(); // 이렇게 익명객체화하면 한번 쓰이고 삭제됨.
	return 0;
}