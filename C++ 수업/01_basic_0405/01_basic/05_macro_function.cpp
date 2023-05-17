#include <iostream>

using namespace std; //std라는 이름 공간을 내 마음대로 사용하겠다.(접근 지정 없이 쓰겠다.) main 안에 넣는 게 젤 안전

//매크로 (단순히 치환 형식
#define PLUS(a, b) ((a) + (b)) // 괄호 안치면 a + b 오류 나기 쉬움
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) // 여러 자료형을 넣어도 계산 가능

//매크로 함수 : 속도가 빠르면 일반 함수에 컴퓨터가 알아서 inline화 해줌
inline int Max(int a, int b) //inline은 매크로 함수. (더 알아보기) 매크로는 괄호를 잘 쳐줘야 하는데 이건 안그래도 돼서 편함. 일반 함수보다 속도가 빠름
{
	return (a > b) ? a : b; //자료형이 정해지므로 타입을 잘 맞춰 써야 함
}

int main()
{
	cout << PLUS(1, 2) << endl;
	cout << PLUS(1, 2) * PLUS(1, 2) << endl; // 괄호가 없으면 1 + 2 * 1 + 2 = 5라고 되므로 매크로 함수는 괄호를 생활화 해야 함.

	cout << MAX(1, 2) << endl;
	cout << Max(1, 2) << endl;

	return 0;
}