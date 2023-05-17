#include <iostream>
//��ø �ڷ���
using namespace std;

class Character
{
public:
	Character(string&& name) //���� �����ͼ� ��������� ��Ÿ������ && ����
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
			cout << name << "�� ���� �̵� ���� : idle, ���� �ӵ� : " << speed << endl;
			break;

		case Character::Movement::walk:
			cout << name << "�� ���� �̵� ���� : walk, ���� �ӵ� : " << speed << endl;
			break;

		case Character::Movement::Run:
			cout << name << "�� ���� �̵� ���� : Run, ���� �ӵ� : " << speed << endl;
			break;

		}
	}


private:
	const int movementSpeed[static_cast<int>(Movement::Count)] // count�� enum �� �����̹Ƿ� �̷��� ��
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
	Character player(string("Player")); //��ü ����鼭 �����ڱ��� ���ÿ�
	
	player.PrintCurrentMovementState(); //Player�� ���� �̵� ���� : idle, ���� �ӵ� : 0
	player.SetCharacterMovement(Character::Movement::walk);
	player.PrintCurrentMovementState(); //Player�� ���� �̵� ���� : walk, ���� �ӵ� : 200
	cout << endl;
	
	return 0;
}