#include <iostream>
#include <list>

using namespace std;
//list
//����, ������ ����ϰ� �̷������, ���ҵ��� ���������� �����Ҷ� ����ϱ� ����
/*
list�� �Ǿհ� �� �ڸ� ����ϰ� �ְ�,
���̻��� ���ҵ��� ���μ��� �յڸ� �˰� ����.
������ ��ġ ���ҿ� �ٷ� ������ �������� ���������� �����ؾ� ��.
*/
int main()
{
	list<int> list;

	for (int i = 0; i < 10; i++)
		list.push_back(i); //���� ����

	//������ ���Ҹ� ��������
	//���� ��� for�����
	for (const auto& ele : list)
		cout << ele << " ";

	cout << endl;

	return 0;
}