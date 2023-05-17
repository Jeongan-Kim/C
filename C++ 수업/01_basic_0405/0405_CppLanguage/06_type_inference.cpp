#include <iostream>
//타입 추론

using namespace std;

auto add(int x, int y) -> int; //이렇게 함수로 써줘도 됨. 계산 시간이 오래 걸릴때에는 후위 반환 타입을 명시해 줄 수 있음(그렇게 되면 편의성은 떨어짐)


int main()
{
	int a = 10;
	float b = 3.14f;
	double c = 45.0;

	//float result = a + b; 
	auto result = a + b; //int + float = float으로 컴파일러가 알아서 타입 랭킹에 따라 타입형을 추론해줌.
	return 0;
}
