#include <iostream>

using namespace std;

class Test
{
public:
	int value = 1; //Test가 생성될때까지는 설계도만 있고 실체는 없음

	static int count; //static은 생성이 되어야 하므로 바깥에서 반드시 초기화를 해줘야 함.

	static const int test = 10; //const는 선언과 동시에 초기화가 이루어져야 하므로 이때는 초기화 가능
};

int Test::count = 10; //Test안에 있는 count

int main()
{
	Test t1, t2;

	t1.value = 10;
	t2.value = 20;

	t1.count = 30;
	t2.count = 40;

	cout << &t1.count << " " << t1.count << endl; //00007FF6F9D1D000 40
	cout << &t2.count << " " << t2.count << endl; //00007FF6F9D1D000 40
	//static은 모든 클래스에서 공유하는 것이라서 t1, t2둘다 같이 바뀜.
	cout << &Test::count << " " << Test::count << endl; //객체를 만들지 않아도 같은 값이 나옴. 그 자체로 메모리를 갖고 있기 때문에.

	return 0;
}