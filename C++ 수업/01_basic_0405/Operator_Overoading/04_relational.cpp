#include <iostream>
#include <vector>
#include <algorithm>
//���� ������
using namespace std;

class Won
{
	int value;
	int value1;

public:
	Won(int value = 0) : value(value){}
	auto Getvalue() const { return value; }
	void Setvalue(const int& value) { this->value = value; }


	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	//== != < >
	bool operator==(const Won& rhs) const
	{
		return value == rhs.value && value1 == rhs.value1; //class�ȿ� ���� 2���� �Ѵ� Ȯ������� ���� �ȳ�
	}

	bool operator!=(const Won& rhs) const
	{
		return !(*this == rhs); //this ���� ���� ���̹Ƿ� �ѹ��� Ȯ���ϰ� ��.
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend bool test(const Won& lhs, const Won& rhs);
};

bool test(const Won& lhs, const Won& rhs)
{
	return lhs.Getvalue() > rhs.Getvalue();
}

int main()
{
	Won w1(10), w2(20);

	if (w1 == w2)
		cout << "����" << endl;
	else if (w1 != w2)
		cout << "�ٸ���" << endl;

	//vector :���� �迭, new�� ������ ������ �ߴµ� vector�� �ڵ����� ������ ��.
	std::vector<Won> wons(20);

	int i = 1;
	for (auto& won : wons)
	{
		won.Setvalue(i);
		i++;
	}

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	random_shuffle(wons.begin(), wons.end()); //�˰��� ����� �ִ� ���� �Լ�

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	sort(wons.begin(), wons.end()); //���� �������� ���ĵ�.(��ü���� ������ �����ε��� �� ���¶� ����)
	
	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	sort(wons.begin(), wons.end(), test); //���� ��������(test�Լ��� �̿�)

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	//���ٽ� �Լ� : �Ű� ������ �Լ��� �ִ� ��. ��û�� ȣ���� ���ÿ� �Ͼ�� �ʴ� ��(?) ���͸� ������ ������ �Ǵ� ��.
	sort(wons.begin(), wons.end(), [](const Won& lhs, const Won& rhs)
		{
			return lhs.Getvalue() < rhs.Getvalue();
		}
	); //[]�Լ��� �Ű������� �־��� �ǵ� �Լ��� ���ٴ� �ǹ̷� �������. ���Ǹ� �� �ȿ��� �ع���.

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;
	return 0;
}
