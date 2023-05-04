#include <iostream>
//new : 동적 배열 할당. 메모리가 잡힘. 

using namespace std;

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}

	void* operator new(size_t size) //클래스에 맞게 형 변환이 되어야 함. 메모리 공간도 알아야 함.
	{
		//컴파일러에 의해 몇 바이트의 크기로 할당해서 받아올지 결정됨.
		void* adr = new char[size];
		return adr; 
		//컴파일러는 메모리 공간에 초기화해줘서 객체가 완성되고, 클래스에 맞게 형변환까지 해줌. 생성자까지 호출해준다는 것이 new와의 차이점.
	}

	void operator delete (void* adr) //할당 해제하는 것
	{
		delete[] adr;
	}
};

int main()
{
	Point* ptr = new Point(3, 4); //static으로 밖에 만들어진 형태.
	
	//멤버 함수는 객체가 생성된 다음에 호출이 될 수 있는데, new 나 delete오버로딩연산자는 static 함수 같은 것이라서 가능하다. 
	//Point p; 이렇게 객체가 생성된 
	return 0;
}