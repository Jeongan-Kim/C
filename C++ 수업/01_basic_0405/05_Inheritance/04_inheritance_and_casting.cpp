#include <iostream>

using namespace std;

/*
* //�θ� Ŭ������ �ڽ� Ŭ�������� �� ũ��.(���� �����Ƿ�)
	Up casting

	Down casting : �θ�Ŭ������ �����Ͱ� ����Ű�� ��ü�� �ڽ�Ŭ������ �����ͷ� ����Ű�� ��
*/

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	//Up casting
	Snack* chocochip = new ChocoChip(); //up casting �Ͻ������� ����ȯ�� �ϴ� ��.
	Snack* chitos = new Chitos();

	Snack* snack[2] = { chitos, chocochip }; //chitos, chocochip�� �ٸ� ���ε� �ڵ� ����ȯ�� �ؼ� �迭�� �����ϴ� ��.(�θ� Ŭ���� �����͸� ���ؼ�)

	//Down casting
	Chitos* test = static_cast<Chitos*>(chitos); //down casting. �̶��� ����ȯ�� ������ ��� ��.

	//Chitos* cc = new Snack(); //error
	return 0;

}