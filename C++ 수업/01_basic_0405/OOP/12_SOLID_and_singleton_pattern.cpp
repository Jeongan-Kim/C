#include <iostream>

/*
	��ü���� 4�� Ư¡
	- ĸ��ȭ(��������)
	- �߻�ȭ
	- ���
	- ������

	��ü���� �����Ģ(SOLID) : ���Ѿ��� ��Ģ
	- ���� å�� ��å(Single Responsibility Principle) : ��� Ŭ������ ���� �ϳ��� ��ɸ��� å�Ӹ� ������ �Ѵ�.

	- ����-��� ��Ģ(Open Closed Principle) : Ȯ�忡�� ���� �ְ� �������� ���� �־�� �Ѵ�. ����� �߰��Ҷ� �ٸ� �ڵ���� �������� �����鼭 �ؾ� ��.

	- �������� ġȯ ��Ģ(Liskov Substitution Principle) : �ڽ� Ŭ������ ������ �θ� Ŭ������ ��ü�� �� �ִ�.(�ڽ� Ŭ������ �θ� Ŭ������ �״�� �޾ƿ��Ƿ�)

	- �������̽� �и� ��Ģ(Interface Segregation Principle) : �� Ŭ������ ���� ������� ���� �������̽��� �������� ���ƾ� �Ѵ�.

	- ���� ���� ��Ģ(Dependency Inversion Principle) : Ŭ�������� ���϶�, ��ȭ�� ���� ���� �Ϳ� �����ؼ� ������ �Ѵ�.
*/

/*
	������ ���� : ���� ���� �ڵ带 ������ �� �ְ� �ϴ� ��.

	- �̱��� ���� : ��ü�� ��üȭ �Ǵ� ���� �� ���� �Ͼ ��. ������ �ϸ� �� ��쿡 ����.(���� ����� �����ؼ� �ϳ��� ����ϴ� ���)
	=> ������ �ϳ��� �ʹ� ���� ���� ����ϸ� "����-��� ��Ģ"�� ����ǹǷ� �ظ��ϸ� ��� ����.
	
*/

using namespace std;

class Audio
{
public:
	static Audio& GetInstance() //������
	{
		static Audio audio;
		return audio;
	}

	void OutSound(string music)
	{
		cout << "�Ҹ� ��� : " << music << endl;
	}

private: //���������� ����ų� {}�� ����� "= delete"�� �ٿ��� ���� �� ����. => ��ü�� ������ �ȵ�.
	Audio() {} //�⺻ ������
	Audio(const Audio& audio) = delete; //���� ������
	Audio& operator=(const Audio& audio) {}  //���� ���� ������
};

int main()
{
	//Audio a; �����ڸ� �� ���Ƴ��� ������ �ȵ�.

	string bgm("����");
	Audio::GetInstance().OutSound(bgm); //�̱��� ���. ��ü�� ����� �޸𸮸� ���⶧���� ��ü�� ������ �ʰ� ������ ���� ��.


	return 0;
}