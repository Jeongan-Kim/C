#include <iostream>
//연산자( [], new, ...) 오버로딩
using namespace std;


/*
	. .* :: ?: # ## 등을 제외한 모든 연산자는 오버로딩이 가능함.

	-비트 연산자(연산 우선순위가 너무 낮은 것은 오버로딩하려면 괄호를 다 쳐줘야 함.)
	& : 둘다 1일떄만 1(참)
	| : 둘다 0일때만 1(참)
	^ : 서로 다른때만 1(참)
	
*/

class Number
{
public:
	Number(int num)
		:num(num)
	{}

	void SetNum(int num)
	{
		this->num = num;
	}

	int GetNum()
	{

		return num;
	}
private:
	int num;
};
int main()
{
	Number a(10), b(20); //생성자로 초기화 바로 해줌.

	//int result = a + b; //a, b는 int형이 아닌 사용자 정의 객체라서 불가능..

	int result = a.GetNum() + b.GetNum();
	a.SetNum(result);
	//이런 건 귀찮기 때문에 연산자 오버로딩을 배움.

	return 0;
}