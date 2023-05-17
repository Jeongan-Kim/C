#include <iostream>
#include <cassert> //C������ assert �������

using namespace std;

int main()
{
	//����뿡�� ���� üũ�� �ϱ� ���� ����

	int x;
	cin >> x;
	//x�� ���� ���ڰ� 0�� ��� ����üũ�� ���ְ� �ʹٰ� ġ��.
	
	assert(x != 0); //���� ������ false�� ��� ������, true�̸� ������.
	//�߰��߰� ������ ������ ������ ������Ѵٰ� ���� ��.

	//debug ��� : ����ڰ� ����� ����
	//release ��� : �����ϱ� ���� ����  => assert ���õ�.

	//assert(false); //������ ������ �ϴ� ��.
	assert(x != 0 && "x is 0"); // ���� ������ �־��� �� ����.

	//������ �ϴ� �߿� ������ �ϴ� �͵� �ִ�. => static assert
	//static_assert(false);

	const int x1 = 8;
	const int y1 = 7;
	//static_assert(x1 < y1, "x1 is bigger than y1");

	return 0;
}