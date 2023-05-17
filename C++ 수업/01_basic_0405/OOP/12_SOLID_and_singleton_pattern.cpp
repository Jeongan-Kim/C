#include <iostream>

/*
	객체지향 4대 특징
	- 캡슐화(정보은닉)
	- 추상화
	- 상속
	- 다형성

	객체지향 설계원칙(SOLID) : 지켜야할 원칙
	- 단일 책임 원책(Single Responsibility Principle) : 모든 클래스는 각각 하나의 기능만을 책임만 가져야 한다.

	- 개방-폐쇄 원칙(Open Closed Principle) : 확장에는 열려 있고 수정에는 닫혀 있어야 한다. 기능을 추가할때 다른 코드들은 수정하지 않으면서 해야 함.

	- 리스코프 치환 원칙(Liskov Substitution Principle) : 자식 클래스는 언제나 부모 클래스를 대체할 수 있다.(자식 클래스는 부모 클래스를 그대로 받아오므로)

	- 인터페이스 분리 원칙(Interface Segregation Principle) : 한 클래스가 내가 사용하지 않을 인터페이스는 구현하지 말아야 한다.

	- 의존 역전 원칙(Dependency Inversion Principle) : 클래스끼리 엮일때, 변화가 거의 없는 것에 의존해서 만들어야 한다.
*/

/*
	디자인 패턴 : 자주 쓰는 코드를 재사용할 수 있게 하는 것.

	- 싱글톤 패턴 : 객체가 실체화 되는 것이 한 번만 일어난 것. 간단한 일만 할 경우에 쓰임.(여러 사람이 공유해서 하나를 사용하는 경우)
	=> 하지만 하나가 너무 많은 일을 담당하면 "개방-폐쇄 원칙"에 위배되므로 왠만하면 사용 지양.
	
*/

using namespace std;

class Audio
{
public:
	static Audio& GetInstance() //생성자
	{
		static Audio audio;
		return audio;
	}

	void OutSound(string music)
	{
		cout << "소리 출력 : " << music << endl;
	}

private: //프리빗으로 숨기거나 {}를 지우고 "= delete"를 붙여서 막을 수 있음. => 실체가 생성이 안됨.
	Audio() {} //기본 생성자
	Audio(const Audio& audio) = delete; //복사 생성자
	Audio& operator=(const Audio& audio) {}  //복사 개입 생성자
};

int main()
{
	//Audio a; 생성자를 다 막아놔서 생성이 안됨.

	string bgm("던전");
	Audio::GetInstance().OutSound(bgm); //싱글톤 방식. 실체를 만들면 메모리를 쓰기때문에 실체를 만들지 않고 가져다 쓰는 것.


	return 0;
}