#include <iostream>
//������( [], new, ...) �����ε�
using namespace std;


/*
	. .* :: ?: # ## ���� ������ ��� �����ڴ� �����ε��� ������.

	-��Ʈ ������(���� �켱������ �ʹ� ���� ���� �����ε��Ϸ��� ��ȣ�� �� ����� ��.)
	& : �Ѵ� 1�ϋ��� 1(��)
	| : �Ѵ� 0�϶��� 1(��)
	^ : ���� �ٸ����� 1(��)
	
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
	Number a(10), b(20); //�����ڷ� �ʱ�ȭ �ٷ� ����.

	//int result = a + b; //a, b�� int���� �ƴ� ����� ���� ��ü�� �Ұ���..

	int result = a.GetNum() + b.GetNum();
	a.SetNum(result);
	//�̷� �� ������ ������ ������ �����ε��� ���.

	return 0;
}