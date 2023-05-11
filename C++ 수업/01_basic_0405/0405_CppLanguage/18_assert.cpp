#include <iostream>
#include <cassert> //C버전의 assert 헤더파일

using namespace std;

int main()
{
	//디버깅에서 오류 체크를 하기 위한 구문

	int x;
	cin >> x;
	//x에 들어온 숫자가 0일 경우 오류체크를 해주고 싶다고 치자.
	
	assert(x != 0); //내부 조건이 false인 경우 터지고, true이면 지나감.
	//중간중간 성공의 유무를 따져서 디버깅한다고 보면 됨.

	//debug 모드 : 사용자가 만드는 공간
	//release 모드 : 배포하기 위한 공간  => assert 무시됨.

	//assert(false); //무조건 터지게 하는 것.
	assert(x != 0 && "x is 0"); // 오류 구문도 넣어줄 수 있음.

	//컴파일 하는 중에 터지게 하는 것도 있다. => static assert
	//static_assert(false);

	const int x1 = 8;
	const int y1 = 7;
	//static_assert(x1 < y1, "x1 is bigger than y1");

	return 0;
}