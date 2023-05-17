#include <iostream>
//중첩 자료형
using namespace std;

class Character
{
public:
	Character(string&& name) //값만 가져와서 명시적으로 나타낼때는 && 붙임
		: name(name)
	{}

	enum class Movement
	{
		idle = 0,
		walk,
		Run,
		Count
	};

	void SetCharacterMovement(enum class Movement inMove)
	{
		movementState = inMove;
		speed = movementSpeed[static_cast<int>(inMove)];
	}

	void PrintCurrentMovementState()
	{
		switch (movementState)
		{
		case Character::Movement::idle:
			cout << name << "의 현재 이동 상태 : idle, 현재 속도 : " << speed << endl;
			break;

		case Character::Movement::walk:
			cout << name << "의 현재 이동 상태 : walk, 현재 속도 : " << speed << endl;
			break;

		case Character::Movement::Run:
			cout << name << "의 현재 이동 상태 : Run, 현재 속도 : " << speed << endl;
			break;

		}
	}


private:
	const int movementSpeed[static_cast<int>(Movement::Count)] // count는 enum 속 변수이므로 이렇게 씀
	{
		0,
		200,
		500
	};

	enum class Movement movementState = Movement::idle;

	int speed = movementSpeed[static_cast<int>(Movement::idle)];

	string name;
};

int main()
{
	Character player(string("Player")); //실체 만들면서 생성자까지 동시에
	
	player.PrintCurrentMovementState(); //Player의 현재 이동 상태 : idle, 현재 속도 : 0
	player.SetCharacterMovement(Character::Movement::walk);
	player.PrintCurrentMovementState(); //Player의 현재 이동 상태 : walk, 현재 속도 : 200
	cout << endl;
	
	return 0;
}