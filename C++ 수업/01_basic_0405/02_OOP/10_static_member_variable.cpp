#include <iostream>

using namespace std;

class Test
{
public:
	int value = 1; //Test�� �����ɶ������� ���赵�� �ְ� ��ü�� ����

	static int count; //static�� ������ �Ǿ�� �ϹǷ� �ٱ����� �ݵ�� �ʱ�ȭ�� ����� ��.

	static const int test = 10; //const�� ����� ���ÿ� �ʱ�ȭ�� �̷������ �ϹǷ� �̶��� �ʱ�ȭ ����
};

int Test::count = 10; //Test�ȿ� �ִ� count

int main()
{
	Test t1, t2;

	t1.value = 10;
	t2.value = 20;

	t1.count = 30;
	t2.count = 40;

	cout << &t1.count << " " << t1.count << endl; //00007FF6F9D1D000 40
	cout << &t2.count << " " << t2.count << endl; //00007FF6F9D1D000 40
	//static�� ��� Ŭ�������� �����ϴ� ���̶� t1, t2�Ѵ� ���� �ٲ�.
	cout << &Test::count << " " << Test::count << endl; //��ü�� ������ �ʾƵ� ���� ���� ����. �� ��ü�� �޸𸮸� ���� �ֱ� ������.

	return 0;
}