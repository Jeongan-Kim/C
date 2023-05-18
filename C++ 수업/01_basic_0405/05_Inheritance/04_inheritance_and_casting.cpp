#include <iostream>

using namespace std;

/*
* //부모 클래스가 자식 클래스보다 더 크다.(물려 받으므로)
	Up casting

	Down casting : 부모클래스의 포인터가 가리키는 객체를 자식클래스의 포인터로 가리키는 것
*/

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	//Up casting
	Snack* chocochip = new ChocoChip(); //up casting 암시적으로 형변환을 하는 것.
	Snack* chitos = new Chitos();

	Snack* snack[2] = { chitos, chocochip }; //chitos, chocochip은 다른 형인데 자동 형변환을 해서 배열로 저장하는 것.(부모 클래스 포인터를 통해서)

	//Down casting
	Chitos* test = static_cast<Chitos*>(chitos); //down casting. 이때는 형변환을 직접해 줘야 함.

	//Chitos* cc = new Snack(); //error
	return 0;

}